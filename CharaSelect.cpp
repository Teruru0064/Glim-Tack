//こーき 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "CharaSelect.h"
#include "Controller.h"

//int score_gh;
extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;

//初期化フラグ
static int score_init_flag = 0;

//コントローラー1P・2Pのボタン振り分けするときに呼び出さないといけない関数
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;

void CharaSelect_init(void){
	//画像の読み込み
	//score_gh = LoadGraph("game_img\\Score.png");
	//初期化グラフ
	score_init_flag = 1;
}

void ChaarSelect_delete(void){
	//DeleteGraph(score_gh);
}


//1P・2Pのコントローラーの呼出し
//GetJoypadDirectInputState(InputType1, &DInputState);
//GetJoypadDirectInputState(InputType2, &DInputState);


void CharaSelect(void){
	//まだ初期化していないときは初期化処理をする
	if (!score_init_flag){
		Score_Init();
	}
	//背景描画
	//DrawGraph(0, 0, score_gh, TRUE);

	//Enterでタイトルへ
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[4]) {
		if (key_enter == 0){
			game_status = GAMEMAIN;
			Board_init();
			Test_init();

			key_enter = 1;
		}
	}
	else{
		key_enter = 0;
	}

}