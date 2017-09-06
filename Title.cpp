#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "Controller.h"
#include "Game_Info.h"

extern int game_status;
extern char KeyBuf[];
extern int key_enter;

//コントローラーの呼出し
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;

//ラッテンフェンガー(笛吹き男)
int Ratten_gh[2];

int little[12];

int LittleX_01 = 1350, LittleX_02 = 1650, LittleX_03 = 1950, LittleX_04 = 2250;

//フラグ宣言
int select_flg = 0;
int returnflg = 0;
int selected = 0;
int Button_num = 2, Button_top = 470;
int Buttonkey_enter1, Buttonkey_enter2;
int select_sh, return_sh;
int title_init_flag ;
int opening_no;



//タイトル名のグラフィックハンドル
int titleName_gh;
//タイトルバックグラウンド(01は風景、02は洞窟の区切り)
int title01_gh, title02_gh;
//ボタン類のグラフィックハンドル
int window_gh, Button1_gh, Button2_gh, start_gh, end_gh;



//初期化処理
void Title_init(void){

	//イメージのロード
	title01_gh = LoadGraph("title_img\\Title_BG01.png");
	title02_gh = LoadGraph("title_img\\Title_BG02.png");
	titleName_gh = LoadGraph("title_img\\TitleName.png");
	//ラッテンフェンガー
	Ratten_gh[0] = LoadGraph("title_img\\Rattenfanger01.png");
	Ratten_gh[1] = LoadGraph("title_img\\Rattenfanger02.png");
	
	
	window_gh = LoadGraph("img\\Window.png");
	Button1_gh = LoadGraph("img\\Button1.png");
	Button2_gh = LoadGraph("img\\Button2.png");
	start_gh = LoadGraph("img\\Title_start.png");
	end_gh = LoadGraph("img\\Title_end.png");

	//リトルのキャラチップの読み込み
	LoadDivGraph("title_img\\Little.png", 12, 3, 4, 160, 160, little);

	LittleX_01 = 1350;
	LittleX_02 = 1650;
	LittleX_03 = 1950;
	LittleX_04 = 2250;

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	title_init_flag = 1;
}

void Title_delete(void){

	//イメージのデリート
	DeleteGraph(title01_gh);
	DeleteGraph(title02_gh);
	DeleteGraph(titleName_gh);


	DeleteGraph(Button1_gh);
	DeleteGraph(Button2_gh);
	DeleteGraph(start_gh);
	DeleteGraph(end_gh);

	//ハーメルン
	DeleteGraph(Ratten_gh[0]);
	DeleteGraph(Ratten_gh[1]);

	title_init_flag = 0;
}

void Title(void){
	if (!title_init_flag){
		Title_init();
	}

	//背景描画
	DrawGraph(0, 0, title01_gh, TRUE);

	DrawGraph(454, 440, window_gh, TRUE);

	//タイトルの位置
	DrawGraph(641, 36, titleName_gh, TRUE);

	//ハーメルンの表示
	DrawTurnGraph(-300, 0, Ratten_gh[GetNowCount() / 1200 % 2], TRUE);

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

	//スタート・おわり(テキスト)描画
	DrawGraph(489, 480, start_gh, TRUE);
	DrawGraph(529, 590, end_gh, TRUE);


	DrawGraph(LittleX_01, 500, little[GetNowCount() / 700 % 3], TRUE);
	DrawGraph(LittleX_02, 500, little[((GetNowCount() / 700) + 1) % 3 + 3], TRUE);
	DrawGraph(LittleX_03, 500, little[((GetNowCount() / 700) + 2) % 3 + 6], TRUE);
	DrawGraph(LittleX_04, 500, little[((GetNowCount() / 700) + 3) % 3 + 9], TRUE);


	LittleX_01 -= 3;
	if (LittleX_01 < 0)LittleX_01 = 1300;
	LittleX_02 -= 3;
	if (LittleX_02 < 0)LittleX_02 = 1300;
	LittleX_03 -= 3;
	if (LittleX_03 < 0)LittleX_03 = 1300;
	LittleX_04 -= 3;
	if (LittleX_04 < 0)LittleX_04 = 1300;

	DrawGraph(0, 0, title02_gh, TRUE);
}
