#include "DxLib.h"
#include "GameInit.h"
#include "GameStatus.h"
#include "GamePlay.h"
#include "Player.h"
#include "Colt.h"

int play_gh;
extern int game_status;
extern int key_enter;


//タイトルを再生する
void Title_set(void){

	Test_init();
	Title_init();
	Title();
	Title_delete();
	GetControllerState();

}

//キャラクターシーンを再生する
void CharaSelect_set(void){

	CharaSelect_init();
	CharaSelect();
	GetControllerState();
	DispControllerState();
	DispCursol();

}

//ゲーム画面を再生する
void TestScene_set(void){

	TestScene();
	GetControllerState();
	DispCursol();
	menu_input();
	Colt1_Update();
	Colt2_Update();
	FG_Draw();

	

}

//スコアシーンを再生する
void Score_set(void){

	//Score();
	GetControllerState();
	Score_Draw();

}