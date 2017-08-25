#include "DxLib.h"
#include "Player.h"
#include "GameInit.h"
#include "Controller.h"

extern int game_status;
extern int game_obj;
int BG_gh, Window_gh;
int MenuWindow_gh;
int Button01_gh;
int menuSelected;
extern int menu_flg;
extern int Buttonkey_enter1, Buttonkey_enter2;
extern int key_enter;
int Button_num2 = 3;
extern int selected;
int menu;
int menuSelect_sh, menuReturn_sh;

extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;




void FG_Init(void){
	
	//イメージロード
	BG_gh = LoadGraph("menu_img/BackGuround.png");
	MenuWindow_gh = LoadGraph("menu_img/MenuWindow.png");
	Button01_gh = LoadGraph("menu_img\\button.png");

	menu = 1;
	
}

void FG_Delete(void){

	//イメージのデリート
	DeleteGraph(BG_gh);
	DeleteGraph(MenuWindow_gh);
	DeleteGraph(Button01_gh);
}

void FG_Draw(void){

	if (menu_flg){
		DrawGraph(0, 0, BG_gh, TRUE);
		DrawGraph(0, 0, MenuWindow_gh, TRUE);

		for (int i = 0; i < Button_num2; i++){
			if (i == selected){
				DrawGraph(399, 239 + selected * 78, Button01_gh, TRUE);
			}
		}
		GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {

			if (key_enter == 0){
				PlaySoundMem(menuReturn_sh, DX_PLAYTYPE_NORMAL, TRUE);
				switch (selected){
				case 0:
					//CheckHitKey(KEY_INPUT_Z) == 1;
					break;
				case 1:
					game_status = GAMEEND;
					break;
				case 2:
					game_status = TITLE;
					break;
				}
				key_enter = 1;
				FG_Delete();

			}

		}
		else{
			key_enter = 0;
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN) == 1) {

		if (Buttonkey_enter1 == 0){
			//PlaySoundMem(select_sh, DX_PLAYTYPE_BACK, TRUE);
			selected++;
			if (selected >= Button_num2)selected = 0;
			Buttonkey_enter1 = 1;
		}

	}
	else{
		Buttonkey_enter1 = 0;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1) {

		if (Buttonkey_enter2 == 0){
			//PlaySoundMem(select_sh, DX_PLAYTYPE_BACK, TRUE);

			selected--;
			if (selected < 0)selected = Button_num2 - 1;
			Buttonkey_enter2 = 1;
		}

	}
	else{
		Buttonkey_enter2 = 0;
	}

}

