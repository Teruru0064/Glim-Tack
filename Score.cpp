//こーき 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "Score.h"

int score_gh;
extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;

//初期化フラグ
static int score_init_flag = 0;

void Score_init(void){
	//画像の読み込み
	score_gh = LoadGraph("game_img\\Score.png");
	//初期化グラフ
	score_init_flag = 1;
}

void Score_delete(void){
	DeleteGraph(score_gh);
}

void Score(void){
	//まだ初期化していないときは初期化処理をする
	if (!score_init_flag){
		Score_init();
	}
	//背景描画
	DrawGraph(0, 0, score_gh, TRUE);

	//Enterでタイトルへ
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (key_enter == 0){
			game_status = TITLE;
			GameTime = 6 * 60;
			key_enter = 1;
		}
	}
	else{
		key_enter = 0;
	}
			
}