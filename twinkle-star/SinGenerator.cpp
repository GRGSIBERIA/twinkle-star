#define _USE_MATH_DEFINES
#include <cmath>
#include <assert.h>
#include "SinGenerator.h"


inline const int computeSize(const double frequency, const int sampling_rate)
{
	return (int)std::ceil((double)sampling_rate / frequency);
}


inline const int computeSin(const double frequency, const double time, const double power)
{
	return (int)(power * sin(2.0 * M_PI * frequency * time) * INT_MAX);
}


tw::Sin::Sin(const double frequency, const int sampling_rate, const double power)
	: tick(0), size(computeSize(frequency, sampling_rate)), sin_array(), power(power)
{
	const double delta_time = 1. / sampling_rate;

	assert(power <= 1.0 || power >= 0.0);

	sin_array.resize(size, 0);
	for (int i = 0; i < size; ++i)
	{
		sin_array[i] = computeSin(frequency, delta_time * (double)i, power);
	}

	sin_array[(size_t)size - 1] = 0;
}

const int tw::Sin::getSin()
{
	const int val = sin_array[tick];
	
	if (++tick >= size)
		tick = 0;

	return val;
}

tw::Stack::Stack(const size_t sample_size)
	: stack()
{
	stack.resize(sample_size, 0);
}

void tw::Stack::addSin(Sin& sin_wave)
{
	for (size_t i = 0; i < stack.size(); ++i)
		stack[i] += sin_wave.getSin();	// オーバーフローについては未定義
}

void tw::Stack::clear()
{
	std::fill(stack.begin(), stack.end(), 0);
}
