#include "DxLib.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Time.h"

extern int game_status;

//制限時間を作る
int GameTime;
int GameTime_Minute;	//分表示用

//メニュー画面のフラグ
extern int menu_flg;

void Time_Init(void){

	//ゲームの制限時間
	GameTime = 20 * 60;
	GameTime_Minute = 0;

}

void Time_Update(void){

	//ゲーム起動中は時間を減少させる
	//ゲーム終了
	if (!menu_flg)GameTime--;

	if (GameTime == 0 && GameTime_Minute == 0) {
		game_status = SCORE;
	}

	if (GameTime <= 0){
		GameTime = 60 * 60;
		--GameTime_Minute;
	}

	//ゲームタイム表示
	DrawFormatString(545, 50, GetColor(255, 255, 255), "のこり %d:%02d", GameTime_Minute, GameTime / 60);

}