#pragma once
#include <Siv3D.hpp>
#include "SoundMakeController.hpp"

namespace tw
{
	namespace god
	{
		const Color dark_color(U"#994311");
		const Color font_color(U"#DEC418");
		const Color accent_color(U"#DE1895");
		const Color theme_color(U"#18DFC4");
		const Color sad_color(U"#119987");

		std::wstring driver_name;
		SoundMakeController* controller;

		Serial serial;
		SerialPortInfo serialInformation;

		bool succeeded = true;
		bool start_flag = false;
		bool not_use_serial = false;
	}
}