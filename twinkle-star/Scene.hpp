#pragma once
#include <Siv3D.hpp>

#include "God.hpp"

namespace tw
{
	enum State {
		SELECT_INTERFACE,
		SELECT_OUTPUT_CHANNEL,
		SELECT_ARDUINO,
		CREATE_SOUND_SOURCE
	};


	const bool CreateDriver(const std::wstring& driver_name)
	{
		try
		{
			god::controller = new SoundMakeController(driver_name);
		}
		catch (...)
		{
			return false;
		}
		return true;
	}


	// オーディオインターフェースの選択
	State SelectInterface(const Font& font)
	{
		font(U"使用するドライバを選択してください").draw(0, 0, tw::god::font_color);

		const auto driver_pathes = asio::Registry::GetAsioDriverPathes();

		for (int i = 0; i < driver_pathes.Count(); ++i)
		{
			const auto subkey = driver_pathes.Items(i).driverName;
			const auto region = font(subkey).draw(16, 32 * (i + 1), tw::god::font_color);

			if (region.mouseOver())
			{
				Circle(8, 32 * (i + 2) - 16, 4).draw(tw::god::font_color);
				if (region.leftClicked())
				{
					god::driver_name = subkey;
					god::succeeded = CreateDriver(subkey);
					if (!god::succeeded)
						return State::SELECT_INTERFACE;
					return tw::State::SELECT_OUTPUT_CHANNEL;
				}
			}

			if (!god::succeeded)
			{
				const auto text = U"Does not creates ASIO driver, please connect an audio interface.\nPlease, restart this software.";
				font(text).draw(0, driver_pathes.Count() * 32 + 32, tw::god::font_color);
			}
		}
		return State::SELECT_INTERFACE;
	}


	// 出力チャンネルを選択する
	State SelectOutputChannel(const Font& font)
	{
		font(U"出力するチャンネル番号を選択してください（イヤホン・スピーカーはそこへ繋げ）").draw(0, 0, god::font_color);

		const int numof_outputs = god::controller->NumberOfOutputChannels();

		for (int i = 0; i < numof_outputs; ++i)
		{
			const auto numch = i + 1;
			const auto region = font(numch).draw(16, 32 * numch, god::font_color);
			
			if (region.mouseOver())
			{
				Circle(8, 32 * (numch + 1) - 16, 4).draw(god::font_color);
				if (region.leftClicked())
				{
					if (god::succeeded = god::controller->InitializeDriver(i))
						return State::SELECT_ARDUINO;
				}
			}

			if (!god::succeeded)
				font(U"HA HA YOUR DEAD!").draw(0, numof_outputs * 32 + 32, god::font_color);
		}
		
		return State::SELECT_OUTPUT_CHANNEL;
	}

	State SelectArduinoPort(const Font& font)
	{
		font(U"楽器のCOMポートを選択してください").draw(0, 0, god::font_color);

		const Array<SerialPortInfo> ports = System::EnumerateSerialPorts();
		const Array<String> informations = ports.map([](const SerialPortInfo& info) {
			return U"{}, {}"_fmt(info.port, info.description);
		}) << U"none";

		for (int i = 0; i < ports.size(); ++i)
		{
			const auto region = font(informations[i]).draw(32, (i + 1) * 32, god::font_color);

			if (region.mouseOver())
			{
				Circle(8, 32 * (i + 1) - 16, 4).draw(god::font_color);
				if (region.leftClicked())
				{
					god::serial = Serial();
					god::serialInformation = ports[i];
					// god::serial.open(god::serialInformation.port);
				}
			}
		}

		return State::SELECT_ARDUINO;
	}

	State CreateSoundSource(const Font& font)
	{
		if (s3d::SimpleGUI::Button(U"再生", Vec2(0, 0), unspecified, !god::start_flag))
		{
			god::start_flag = true;
			god::controller->Start();
		}

		if (s3d::SimpleGUI::Button(U"停止", Vec2(64 + 64, 0), unspecified, god::start_flag))
		{
			god::start_flag = false;
			god::controller->Stop();
		}

		if (s3d::SimpleGUI::Button(U"追加", Vec2(0, 64), unspecified, !god::start_flag))
		{

		}

		return State::CREATE_SOUND_SOURCE;
	}
}