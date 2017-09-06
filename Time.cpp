#include "DxLib.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Time.h"

extern int game_status;

//制限時間を作る
int GameTime;
int GameTime_Minute;	//分表示用
int nonanim = 0;
//メニュー画面のフラグ
extern int menu_flg;

//しゅ～りょ～のグラフィックハンドル
int End_gh;
int text_x ;

//スコア画面の開始時間
int ScoreStart;

void Time_Init(void){
	//イメージロード
	End_gh = LoadGraph("game_img\\end.png");

	//ゲームの制限時間
	GameTime = 5 * 60;
	GameTime_Minute = 0;
	text_x = 1280;
}

void Time_Update(void){

	//ゲーム起動中は時間を減少させる
	//ゲーム終了
	if (!menu_flg && !(GameTime_Minute == 0 && GameTime==0))GameTime--;

	if (GameTime == 0 && GameTime_Minute == 0) {

		//game_status = SCORE;
		//しゅ～りょ～の表示
		DrawGraph(text_x, 200, End_gh, TRUE);
		text_x -= 12;
		if (text_x < -1700) game_status = SCORE;
			nonanim = 1;
			ScoreStart = GetNowCount();
	}
	else{
		nonanim = 0;
	}

	if (GameTime <= 0 && GameTime_Minute!=0){
		GameTime = 5 * 60;
		--GameTime_Minute;
	}

	//ゲームタイム表示
	DrawFormatString(545, 50, GetColor(255, 255, 255), "のこり %d:%02d", GameTime_Minute, GameTime / 60);


	//しゅ～りょ～の表示
	//DrawGraph(0, 200, End_gh, TRUE);
}