#include "GameInit.h" 

//グローバル変数
int game_status = TITLE;
int key_enter = 0;
char KeyBuf[256];

// WinMain関数
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	//ゲーム初期化処理
	game_init();

	//メインループ
	while (game_status!=GAMEEND)
	{
		// 画面に描かれているものを一回全部消す
		ClearDrawScreen();

		//ステータスに応じた処理分け
		switch (game_status){

		case TITLE:
			Title_set();
			break;
		case CHARASELECT:
			CharaSelect_set();
			break;
		case GAMEMAIN:
			TestScene_set();
			break;
		case SCORE:
			Score_set();
			break;


		}


		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1) break;

		// ＥＳＣキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

	}

	// ＤＸライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了
	return 0;
}
