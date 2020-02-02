#pragma once
#include "TinyASIO/TinyASIO.hpp"

namespace tw
{
	class SoundMakeController : public asio::ControllerBase
	{
		static asio::OutputBuffer* output;

		void* output_memory = nullptr;

	public:
		SoundMakeController(const std::wstring& driverName)
			: ControllerBase(driverName)
		{
			
		}

		const int NumberOfOutputChannels() const
		{
			return channelManager->NumberOfOutputs();
		}

		static void BufferSwitch(long index, long)
		{

		}
	};

	asio::OutputBuffer* tw::SoundMakeController::output = nullptr;
}