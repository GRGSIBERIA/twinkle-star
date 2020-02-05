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
		double frequency;
		std::vector<int> sin_array;

	public:
		/**
		* @param frequency 周波数
		* @param sampling_rate サンプリング周波数
		* @param power 正弦波の強度，0～1
		*/
		Sin(const double frequency, const int sampling_rate, const double power);

		const int getSin();

		const double getFrequency() const;

		const double getPower() const;

		const int getSize() const;

		const int getTick() const;
	};

	/**
	* 波形を記憶するためのクラス
	*/
	class Stack
	{
		std::vector<int> stack;

	public:
		Stack(const size_t sample_size);

		void addSin(Sin& sin_wave);

		void clear();
	};

	/**
	* サイン波の管理クラス
	*/
	class SinManager
	{
		std::vector<Sin> sines;
		Stack stack;

	public:
		SinManager(const int sample_size);

		void addSin(const double frequency, const int sampling_rate, const double power);

		const int count() const;

		Sin& getSin(const int index);

		const Stack& getStack();
	};
}