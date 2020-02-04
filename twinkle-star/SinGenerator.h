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
		std::vector<int> sin_array;

	public:
		/**
		* @param frequency ���g��
		* @param sampling_rate �T���v�����O���g��
		* @param power �����g�̋��x�C0�`1
		*/
		Sin(const double frequency, const int sampling_rate, const double power);

		const int getSin();
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
		std::vector<int> stack;

	public:
		Stack(const size_t sample_size);

		void addSin(Sin& sin_wave);

		void clear();
	};
}