#include "GameInit.h"
#include "Game_Info.h"
#include "Controller.h"
#include "Colt.h"

 int game_init(void){
	// ウインドウモードに変更
	 SetGraphMode(WINDOW_WIGHT, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE);
	//ウィンドウリサイズ設定
	SetWindowSizeChangeEnableFlag(true);
	//ウィンドウタイトル
	SetMainWindowText("SampleGame");

	//背景色設定
	//SetBackgroundColor(0, 0, 0);
	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1) return -1;

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);
	//マウスの非表示
	SetMouseDispFlag(FALSE);

	Controller_Init();
	//colt初期化
	Colt1_init();
	
	return 0;
}