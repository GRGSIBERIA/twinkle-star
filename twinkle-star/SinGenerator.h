#pragma once
#include <vector>

namespace tw
{
	/**
	* サイン波クラス
	*/
	class Sin
	{
		int tick;
		int size;
		double power;
		std::vector<short> sin_array;

	public:
		Sin(const double frequency, const int sampling_rate, const double power);

		const short getSin();
	};

	/**
	* サイン波のジェネレータクラス
	*/
	class SinGenerator
	{
	public:

	};

	/**
	* 波形を記憶するためのクラス
	*/
	class Stack
	{
		std::vector<short> stack;

	public:
		Stack(const size_t sample_size);

		void addSin(Sin& sin_wave);

		void clear();
	};
}