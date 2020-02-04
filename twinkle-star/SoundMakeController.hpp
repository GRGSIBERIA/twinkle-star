#pragma once
#include "TinyASIO/TinyASIO.hpp"

namespace tw
{
	class SoundMakeController : public asio::ControllerBase
	{
		static asio::OutputBuffer* output;

		int output_channel = -1;

	public:
		SoundMakeController(const std::wstring& driverName)
			: ControllerBase(driverName)
		{
			
		}

		const int NumberOfOutputChannels() const
		{
			return channelManager->NumberOfOutputs();
		}

		bool InitializeDriver(const int output_channel_index)
		{
			try
			{
				output_channel = output_channel_index;
				CreateBuffer({ channelManager->Outputs(output_channel) }, &BufferSwitch);
				output = &bufferManager->Output(0);
			}
			catch (...)
			{
				return false;
			}

			return true;
		}

		static void BufferSwitch(long index, long)
		{
			// int型でバッファリングしている
			void* output_memory = output->GetBuffer(index);
			memset(output_memory, 0, BufferSize());
		}
	};

	asio::OutputBuffer* tw::SoundMakeController::output = nullptr;
}