#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "Controller.h"

int title01_gh, title02_gh;
int name_gh, window_gh, Button1_gh, Button2_gh, start_gh, end_gh;
extern int game_status;
extern char KeyBuf[];
//スタート・おわりのフラグ宣言
extern int key_enter;
int select_flg = 0;
int returnflg = 0;
int selected = 0;
int Button_num = 2, Button_top = 470;
int Buttonkey_enter1, Buttonkey_enter2;
int select_sh, return_sh;

int title_init_flag = 0;
int opening_no;
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;


//初期化処理
void Title_init(void){

	//イメージのロード
	title01_gh = LoadGraph("title_img\\Title_BG.png");
	title02_gh = LoadGraph("title_img\\Title_BG.png");
	name_gh = LoadGraph("img\\Titlename.png");
	window_gh = LoadGraph("img\\Window.png");
	Button1_gh = LoadGraph("img\\Button1.png");
	Button2_gh = LoadGraph("img\\Button2.png");
	start_gh = LoadGraph("img\\Title_start.png");
	end_gh = LoadGraph("img\\Title_end.png");
	SetFontSize(32);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	title_init_flag = 1;
}

void Title_delete(void){

	//イメージのデリート
	DeleteGraph(title01_gh);
	DeleteGraph(title02_gh);
	DeleteGraph(name_gh);
	DeleteGraph(Button1_gh);
	DeleteGraph(Button2_gh);
	DeleteGraph(start_gh);
	DeleteGraph(end_gh);

	title_init_flag = 0;
}

void Title(void){
	if (!title_init_flag){
		Title_init();
	}
	//背景描画
	DrawGraph(0, 0, title01_gh, TRUE);
	DrawGraph(0, 0, title02_gh, TRUE);
	DrawGraph(454, 440, window_gh, TRUE);
	DrawGraph(225, 50, name_gh, TRUE);

	for (int i = 0; i < Button_num; i++){
		if (i == selected){
			DrawGraph(465, Button_top + 110 * i, Button1_gh, TRUE);
		}
	}
	GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {

		if (key_enter == 0){
			PlaySoundMem(return_sh, DX_PLAYTYPE_NORMAL, TRUE);
			switch (selected){
			case 0:
				opening_no = 0;
				game_status = CHARASELECT;
				break;
			case 1:game_status = GAMEEND;
				break;
			}
			key_enter = 1;
			Title_delete();

		}

	}
	else{
		key_enter = 0;
	}

	

	if (CheckHitKey(KEY_INPUT_DOWN) == 1 || XInputState1.Buttons[1]) {

		if (Buttonkey_enter1 == 0){
			PlaySoundMem(select_sh, DX_PLAYTYPE_BACK, TRUE);
			selected++;
			if (selected >= Button_num)selected = 0;
			Buttonkey_enter1 = 1;
		}

	}
	else{
		Buttonkey_enter1 = 0;
	}
	if (CheckHitKey(KEY_INPUT_UP) == 1 || XInputState1.Buttons[0]) {

		if (Buttonkey_enter2 == 0){
			PlaySoundMem(select_sh, DX_PLAYTYPE_BACK, TRUE);

			selected--;
			if (selected < 0)selected = Button_num - 1;
			Buttonkey_enter2 = 1;
		}

	}
	else{
		Buttonkey_enter2 = 0;
	}
	//スタート・おわりの文字描画
	DrawGraph(489, 480, start_gh, TRUE);
	DrawGraph(529, 590, end_gh, TRUE);
}
