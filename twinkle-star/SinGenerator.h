#pragma once
#include <vector>

namespace tw
{
	class Sin
	{
		int tick;
		int size;
		std::vector<short> sin_array;

	public:
		Sin(const double frequency, const int sampling_rate);
	};

	class SinGenerator
	{
	public:

	};
}