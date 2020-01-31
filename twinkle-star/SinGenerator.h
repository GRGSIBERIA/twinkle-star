#pragma once
#include <vector>

namespace tw
{
	/**
	* �T�C���g�N���X
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
	* �T�C���g�̃W�F�l���[�^�N���X
	*/
	class SinGenerator
	{
	public:

	};

	/**
	* �g�`���L�����邽�߂̃N���X
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