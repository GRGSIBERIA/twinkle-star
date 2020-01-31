#define _USE_MATH_DEFINES
#include <cmath>
#include "SinGenerator.h"


inline const int computeSize(const double frequency, const int sampling_rate)
{
	return std::ceil((double)sampling_rate / frequency);
}


inline const short computeSin(const double frequency, const double time)
{
	return (short)(sin(2.0 * M_PI * frequency * time) * 32767.);
}


tw::Sin::Sin(const double frequency, const int sampling_rate)
	: tick(0), size(computeSize(frequency, sampling_rate)), sin_array()
{
	const double delta_time = 1. / sampling_rate;

	sin_array.resize(size, 0);
	for (int i = 0; i < size; ++i)
	{
		sin_array[i] = computeSin(frequency, delta_time * (double)i);
	}

	sin_array[(size_t)size - 1] = 0;
}
