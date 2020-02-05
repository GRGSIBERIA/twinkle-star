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
		double frequency;
		std::vector<int> sin_array;

	public:
		/**
		* @param frequency ���g��
		* @param sampling_rate �T���v�����O���g��
		* @param power �����g�̋��x�C0�`1
		*/
		Sin(const double frequency, const int sampling_rate, const double power);

		const int getSin();

		const double getFrequency() const;

		const double getPower() const;

		const int getSize() const;

		const int getTick() const;
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

	/**
	* �T�C���g�̊Ǘ��N���X
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