
#include <Siv3D.hpp> // OpenSiv3D v0.4.2
#include "TinyASIO/TinyASIO.hpp"

#include "God.hpp"


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
				
				return State::SELECT_OUTPUT_CHANNEL;
			}
		}
	}
	return State::SELECT_INTERFACE;
}

State CreateSoundSource(const Font& font)
{
	return State::CREATE_SOUND_SOURCE;
}


void Main()
{
	// 背景を水色にする
	Scene::SetBackground(tw::god::dark_color);

	const Font font(24);
	State state = State::SELECT_INTERFACE;

	while (System::Update())
	{
		switch (state)
		{
		case SELECT_INTERFACE:
			state = SelectInterface(font);
			break;
		case CREATE_SOUND_SOURCE:
			state = CreateSoundSource(font);
			break;
		default:
			break;
		}
	}
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
