
#include <Siv3D.hpp> // OpenSiv3D v0.4.2
#include "TinyASIO/TinyASIO.hpp"

#include "God.hpp"
#include "Scene.hpp"


void Main()
{
	// 背景を水色にする
	Scene::SetBackground(tw::god::dark_color);

	const Font font(24);
	tw::State state = tw::State::SELECT_INTERFACE;

	while (System::Update())
	{
		switch (state)
		{
		case tw::State::SELECT_INTERFACE:
			state = tw::SelectInterface(font);
			break;
		case tw::State::SELECT_OUTPUT_CHANNEL:
			state = tw::SelectOutputChannel(font);
			break;
		case tw::State::CREATE_SOUND_SOURCE:
			state = tw::CreateSoundSource(font);
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
