#pragma once
#include <Siv3D.hpp>

#include "God.hpp"

namespace tw
{
	enum State {
		SELECT_INTERFACE,
		SELECT_OUTPUT_CHANNEL,
		CREATE_SOUND_SOURCE
	};

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

					return tw::State::SELECT_OUTPUT_CHANNEL;
				}
			}
		}
		return tw::State::SELECT_INTERFACE;
	}

	State CreateSoundSource(const Font& font)
	{
		return tw::State::CREATE_SOUND_SOURCE;
	}
}