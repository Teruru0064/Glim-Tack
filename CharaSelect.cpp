//こーき 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "CharaSelect.h"
#include "Controller.h"

int selectBG_gh;

//赤ずきん
int LRRHselect_gh;
//白雪姫
int SWselect_gh;

extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;
int key_enter2;
//初期化フラグ
static int score_init_flag = 0;

//準備OKフラグ
int Redy_flag_1p,Redy_flag_2p;
int Count_Down = 180;
//コントローラー1P・2Pのボタン振り分けするときに呼び出さないといけない関数
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;

void CharaSelect_init(void){
	//画像の読み込み
	selectBG_gh = LoadGraph("select_img\\select_BG.png");
	LRRHselect_gh = LoadGraph("char_img\\LittleRedRidingHood.png");
	SWselect_gh = LoadGraph("char_img\\SnowWhite.png");
	
	//初期化グラフ
	score_init_flag = 1;

	Redy_flag_1p = 0;
	Redy_flag_2p = 1;
	key_enter2 = 0;
}

void ChaarSelect_delete(void){
	//DeleteGraph(score_gh);
}


//1P・2Pのコントローラーの呼出し
//GetJoypadDirectInputState(InputType1, &DInputState);
//GetJoypadDirectInputState(InputType2, &DInputState);


void CharaSelect_Draw(void){

	//まだ初期化していないときは初期化処理をする
	if (!score_init_flag){
		Score_Init();
	}

	//背景描画
	DrawGraph(0, 0, selectBG_gh, TRUE);
	if (Redy_flag_1p){
		DrawGraph(170, 200, LRRHselect_gh, TRUE);
	}
	if (Redy_flag_2p){
		DrawGraph(800, 200, SWselect_gh, TRUE);
	}

	//Enterでタイトルへ
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[4]) {
		if (key_enter == 0){
			Redy_flag_1p = 1;
			key_enter = 1;

			//2Pが準備OKではなかったら最初の音を鳴らす
			if (!Redy_flag_2p){
				
			}
			//準備OKだったら後の音を鳴らす
			else{

			}
		}
	}
	else{
		key_enter = 0;
	}

	//if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState2.Buttons[4]) {
	if (XInputState2.Buttons[4]) {
		if (key_enter2 == 0){
			//game_status = GAMEMAIN;
			//Board_init();
			//Test_init();
			Redy_flag_2p = 1;
			key_enter2 = 1;
		}
	}
	else{
		key_enter2 = 0;
	}

	if (Redy_flag_1p && Redy_flag_2p){

		Count_Down -= 1;
		if (Count_Down < 0){
			game_status = GAMEMAIN;
			Board_init();
			Test_init();
		}
	}

}