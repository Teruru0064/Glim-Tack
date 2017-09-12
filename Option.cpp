#include "DxLib.h"
#include "GameStatus.h"
#include "Title.h"
#include "Option.h"
#include "Controller.h"
#include "Game_Info.h"

extern int game_status;
extern char KeyBuf[];
extern int key_enter;

//コントローラーの呼出し
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;

//説明画像の関数
int img_Option01,img_Option02;

//画像変更フラグ
int Next_Flag;


void Option_Init(void){

	//イメージロード
	img_Option01 = LoadGraph("option_img\\option01.png");
	img_Option02 = LoadGraph("option_img\\option02.png");

	Next_Flag = 0;
}

void Option_Delete(void){

	DeleteGraph(img_Option01);
	DeleteGraph(img_Option02);

}

void Option_Draw(void){

	//まだ初期化していないときは初期化処理をする
	if (!Next_Flag){
		Option_Init();
	}

	//背景描画
	DrawGraph(0, 0, img_Option01, TRUE);

	//１Pコントローラーセット
	GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);

	if (key_enter == 1){
	//Bボタンで進む
		if (XInputState1.Buttons[13]) {
			//DeleteGraph(img_Option01);
			DrawGraph(0, 0, img_Option02, TRUE);
			Next_Flag++;
		}
		else if (Next_Flag > 3){
			game_status = TITLE;
			Title_init();
	}


			/*if (XInputState1.Buttons[13]){
					DeleteGraph(img_Option02);
					game_status = TITLE;
					Title_init();*/
					//}
	}
}


void Option_Input(void){
}
