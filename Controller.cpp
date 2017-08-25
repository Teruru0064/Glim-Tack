//////////////////////////////////////////////////////////
///		  　　コントローラーの設定　1P and 2P		 　///
//////////////////////////////////////////////////////////

#include "DxLib.h"
#include "GameInit.h"
#include "Controller.h"
#include "GameStatus.h"

int PadNum;
int InputType1, InputType2;
int InputState1, InputState2;
XINPUT_STATE XInputState1, XInputState2;
DINPUT_JOYSTATE DInputState;
int cur_gh[2];
int P1_x = 100, P1_y = 0, P2_x = 600, P2_y = 0;
int cur_speed = 5;
extern int game_status;

void Controller_Init(){
	cur_gh[0] = LoadGraph("game_img/Cursor_1P.png");
	cur_gh[1] = LoadGraph("game_img/Cursor_2P.png");
	SetJoypadDeadZone(DX_INPUT_PAD1, 0.4f);
}

void GetControllerState(){
	PadNum = GetJoypadNum();

	switch (PadNum){
	case 1:
		InputType1 = DX_INPUT_PAD1;
		InputState1 = GetJoypadXInputState(InputType1, &XInputState1);
		break;
	case 2:
		InputType1 = DX_INPUT_PAD1;
		InputType2 = DX_INPUT_PAD2;
		InputState1 = GetJoypadXInputState(InputType1, &XInputState1);
		InputState2 = GetJoypadXInputState(InputType2, &XInputState2);
		break;

	default:
		InputType1 = DX_INPUT_KEY;

	}
	//InputState=GetJoypadInputState(InputType);
	//InputState1 = GetJoypadXInputState(InputType1, &XInputState);

	//1P・2Pのコントローラーの呼出し
	GetJoypadDirectInputState(InputType1, &DInputState);
	GetJoypadDirectInputState(InputType2, &DInputState);

	///////////////////////////
	///コントローラー1の処理///
	///////////////////////////

	//アナログスティック処理

	//↑の処理
	if (XInputState1.ThumbLY > 5000){
		P1_y -= XInputState1.ThumbLY / 3000;
	}
	//↓の処理
	if (XInputState1.ThumbLY < -5000){
		P1_y += XInputState1.ThumbLY / -3000;
	}
	//←の処理
	if (XInputState1.ThumbLX < -5000){
		P1_x -= XInputState1.ThumbLX / -3000;
	}
	//→の処理
	if (XInputState1.ThumbLX > 5000){
		P1_x += XInputState1.ThumbLX / 3000;
	}

	if (XInputState1.Buttons[0]){
		P1_y -= cur_speed;
	}

	if (XInputState1.Buttons[1]){
		P1_y += cur_speed;
	}

	if (XInputState1.Buttons[2]){
		P1_x -= cur_speed;
	}

	if (XInputState1.Buttons[3]){
		P1_x += cur_speed;
	}

	if (XInputState1.Buttons[4]){
		game_status = GAMEMAIN;
		Board_init();
	}

	///////////////////////////
	///コントローラー2の処理///
	///////////////////////////

	//アナログスティック処理

	//↑の処理
	if (XInputState2.ThumbLY > 5000){
		P2_y -= XInputState2.ThumbLY / 3000;
	}
	//↓の処理
	if (XInputState2.ThumbLY < -5000){
		P2_y += XInputState2.ThumbLY / -3000;
	}
	//←の処理
	if (XInputState2.ThumbLX < -5000){
		P2_x -= XInputState2.ThumbLX / -3000;
	}
	//→の処理
	if (XInputState2.ThumbLX > 5000){
		P2_x += XInputState2.ThumbLX / 3000;
	}

	if (XInputState2.Buttons[0]){
		P2_y -= cur_speed;
	}

	if (XInputState2.Buttons[1]){
		P2_y += cur_speed;
	}

	if (XInputState2.Buttons[2]){
		P2_x -= cur_speed;
	}

	if (XInputState2.Buttons[3]){
		P2_x += cur_speed;
	}
	if (XInputState2.Buttons[4]){
		game_status = GAMEMAIN;
		Board_init();
	}

}

void DispControllerState(){


	DrawFormatString(0, 0, GetColor(255, 255, 255), "PadNum=%d", PadNum);
	//DrawFormatString(0, 50, GetColor(255, 255, 255), "InputState=%d", InputState);

	//XInput
	for (int i = 0; i < 16; i++){
		DrawFormatString(0 + i * 70, 30, GetColor(255, 255, 255), "[%2d]", i);
		DrawFormatString(25 + i * 70, 60, GetColor(255, 255, 255), "%d", XInputState1.Buttons[i]);

	}
	for (int i = 0; i < 16; i++){
		DrawFormatString(0 + i * 70, 90, GetColor(255, 255, 255), "[%2d]", i);
		DrawFormatString(25 + i * 70, 120, GetColor(255, 255, 255), "%d", XInputState2.Buttons[i]);

	}

	DrawFormatString(0, 160, GetColor(255, 255, 255), "LeftTrigger=%d", XInputState1.LeftTrigger);
	DrawFormatString(300, 160, GetColor(255, 255, 255), "RightTrigger=%d", XInputState1.RightTrigger);

	DrawFormatString(0, 200, GetColor(255, 255, 255), "ThumbLX=%d", XInputState1.ThumbLX);
	DrawFormatString(300, 200, GetColor(255, 255, 255), "ThumbLY=%d", XInputState1.ThumbLY);

	DrawFormatString(0, 240, GetColor(255, 255, 255), "ThumbRX=%d", XInputState1.ThumbRX);
	DrawFormatString(300, 240, GetColor(255, 255, 255), "ThumbRY=%d", XInputState1.ThumbRY);



	//DirectInput
	for (int i = 0; i < 16; i++){
		DrawFormatString(0 + i * 70, 300 + 30, GetColor(255, 255, 255), "[%2d]", i);
		DrawFormatString(25 + i * 70, 300 + 60, GetColor(255, 255, 255), "%d", DInputState.Buttons[i]);

	}
	for (int i = 16; i <32; i++){
		DrawFormatString(0 + (i - 16) * 70, 300 + 90, GetColor(255, 255, 255), "[%2d]", i);
		DrawFormatString(25 + (i - 16) * 70, 300 + 120, GetColor(255, 255, 255), "%d", DInputState.Buttons[i]);

	}


	DrawFormatString(0, 470, GetColor(255, 255, 255), " POV[0]= %d  ", DInputState.POV[0]);
	DrawFormatString(0, 500, GetColor(255, 255, 255), " X= %d  ", DInputState.X);
	DrawFormatString(0, 530, GetColor(255, 255, 255), " Y= %d  ", DInputState.Y);


}

void DispCursol(){
	//カーソルの表示
	DrawGraph(P1_x, P1_y, cur_gh[0], TRUE);
	DrawGraph(P2_x, P2_y, cur_gh[1], TRUE);
}