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

//リトル関数
int little[12];

//リトルのキャラチップの段数(01は1段目、02は2段目、03は3段目、04は4段目)
int LittleX_01, LittleX_02, LittleX_03, LittleX_04;

//タイトルバックグラウンド(01は風景、02は洞窟の区切り)
int title01_gh, title02_gh;

//タイトル名関数
int titleName_gh;

//雲の関数
int cloud_gh;
int cloud01_X, cloud02_X;

//背景の関数
int signboard_gh, sky_gh;
int start_gh, end_gh, option_gh;

//画像の座標
int coordinates = 0;

//テキスト座礁
int titleText_X = 853;

//矢印の関数
int arrowsign_gh;
int ArrowSign_X, ArrowSign_Y;
int Arrow_num = 3;


//フラグ宣言
int select_flg = 0;
int returnflg = 0;
int selected = 0;
int Buttonkey_enter1, Buttonkey_enter2;
int select_sh, return_sh;
int title_init_flag;




//初期化処理
void Title_init(void){

	//イメージのロード
	title01_gh = LoadGraph("title_img\\Title_BG01.png");
	title02_gh = LoadGraph("title_img\\Title_BG02.png");
	sky_gh = LoadGraph("title_img\\Sky.png");
	titleName_gh = LoadGraph("title_img\\TitleName.png");
	cloud_gh = LoadGraph("title_img\\Cloud.png");
	signboard_gh = LoadGraph("title_img\\signboard.png");
	arrowsign_gh = LoadGraph("title_img\\ArrowSign.png");
	start_gh = LoadGraph("title_img\\Start.png");
	end_gh = LoadGraph("title_img\\End.png");
	option_gh = LoadGraph("title_img\\Option.png");

	//ラッテンフェンガー
	Ratten_gh[0] = LoadGraph("title_img\\Rattenfanger01.png");
	Ratten_gh[1] = LoadGraph("title_img\\Rattenfanger02.png");


	//リトルのキャラチップの読み込み
	LoadDivGraph("title_img\\Little.png", 12, 3, 4, 160, 160, little);
	//リトルの初期座標
	LittleX_01 = 1350;
	LittleX_02 = 1650;
	LittleX_03 = 1950;
	LittleX_04 = 2250;

	//雲のX座標(01は一枚目、02は二枚目)
	cloud01_X = 0;
	cloud02_X = 1850;
	
	//矢印の座標
	ArrowSign_X = 800;
	ArrowSign_Y = 260;

	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);
	title_init_flag = 1;
}

void Title_delete(void){

	//イメージのデリート
	DeleteGraph(title01_gh);
	DeleteGraph(title02_gh);
	DeleteGraph(titleName_gh);
	DeleteGraph(cloud_gh);
	DeleteGraph(signboard_gh);
	DeleteGraph(arrowsign_gh);
	DeleteGraph(option_gh);
	DeleteGraph(start_gh);
	DeleteGraph(end_gh);

	//ラッテンフェンガー
	DeleteGraph(Ratten_gh[0]);
	DeleteGraph(Ratten_gh[1]);

	title_init_flag = 0;
}

void Title(void){

	if (!title_init_flag){
		Title_init();
	}

	//空の描画
	DrawGraph(coordinates, coordinates, sky_gh, TRUE);

	//雲の描画
	DrawGraph(cloud01_X, coordinates, cloud_gh, TRUE);
	DrawGraph(cloud02_X, coordinates, cloud_gh, TRUE);
	cloud01_X -= 1;
	if (cloud01_X < -1800)cloud01_X = 1900;
	cloud02_X -= 1;
	if (cloud02_X < -1800)cloud02_X = 1900;
	

	//背景描画
	DrawGraph(coordinates, coordinates, title01_gh, TRUE);

	//タイトル名の位置
	DrawGraph(641, 36, titleName_gh, TRUE);
	//看板
	DrawGraph(coordinates, coordinates, signboard_gh, TRUE);

	//スタート・おわり(テキスト)描画
	DrawGraph(titleText_X, 265, start_gh, TRUE);
	DrawGraph(titleText_X, 315, option_gh, TRUE);
	DrawGraph(titleText_X, 365, end_gh, TRUE);

	//矢印の表示
	DrawGraph(ArrowSign_X, ArrowSign_Y + (selected*50), arrowsign_gh, TRUE);

	//ハーメルンの表示
	DrawTurnGraph(-300, coordinates, Ratten_gh[GetNowCount() / 1200 % 2], TRUE);

	GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {

		if (key_enter == 0){
			PlaySoundMem(return_sh, DX_PLAYTYPE_NORMAL, TRUE);
			switch (selected){
			case 0:
				game_status = CHARASELECT;
				break;
			case 1:
				///game_status = GAMEEND;
				break;
			case 2:
				game_status = GAMEEND;
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
			if (selected >= Arrow_num)selected = 0;
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
			if (selected < 0)selected = Arrow_num - 1;
			Buttonkey_enter2 = 1;
		}

	}
	else{
		Buttonkey_enter2 = 0;
	}


	//妖精のアニメーション設定
	DrawGraph(LittleX_01, 500, little[GetNowCount() / 700 % 3], TRUE);
	DrawGraph(LittleX_02, 500, little[((GetNowCount() / 700) + 1) % 3 + 3], TRUE);
	DrawGraph(LittleX_03, 500, little[((GetNowCount() / 700) + 2) % 3 + 6], TRUE);
	DrawGraph(LittleX_04, 500, little[((GetNowCount() / 700) + 3) % 3 + 9], TRUE);

	//リトルの動く速さと再描画位置
	LittleX_01 -= 3;
	if (LittleX_01 < 0)LittleX_01 = 1300;
	LittleX_02 -= 3;
	if (LittleX_02 < 0)LittleX_02 = 1300;
	LittleX_03 -= 3;
	if (LittleX_03 < 0)LittleX_03 = 1300;
	LittleX_04 -= 3;
	if (LittleX_04 < 0)LittleX_04 = 1300;

	//背景の洞窟描画
	DrawGraph(coordinates, coordinates, title02_gh, TRUE);
}
