#pragma once
#include <Siv3D.hpp>
#include "TinyASIO/TinyASIO.hpp"

namespace tw
{
	namespace god
	{
		const Color dark_color(U"#994311");
		const Color font_color(U"#DEC418");
		const Color accent_color(U"#DE1895");
		const Color theme_color(U"#18DFC4");
		const Color sad_color(U"#119987");
	}

	class SoundMakeController : public asio::ControllerBase
	{
		static asio::OutputBuffer* output;

	public:
		
	};

	asio::OutputBuffer* tw::SoundMakeController::output = nullptr;
}