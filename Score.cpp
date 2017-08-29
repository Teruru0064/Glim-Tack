#include "DxLib.h"
#include "GameInit.h"
#include "Score.h"

extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;

//コントローラーを使用するための関数
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;


//キャラクターのグラフィックハンドル

//赤ずきん(01は勝ち、02は負け)
int LRRH01_gh, LRRH02_gh;
//白雪姫(01は勝ち、02は負け)
int SW01_gh, SW02_gh;
/*
//ヘンゼルとグレーテル(01は勝ち、02は負け)
int HaG01_gh, HaG02_gh;
//ラプンツェル(01は勝ち、02は負け)
int Rap01_gh, Rap02_gh;
*/

//スコア背景
int score_BG_gh;

//勝敗結果のテキスト画像(勝ち、負け、引き分け)
int win_gh, lose_gh, draw_gh;

//スコアのvs画像
int vs_gh;
/*
//0～9までの数字テキスト
int zero_gh,one_gh, tow_gh, three_gh, four_gh,
	five_gh,six_gh, seven_gh, eight_gh, nine_gh;
*/

//初期化フラグ
static int score_init_flag = 0;

void Score_init(void){

	//画像の読み込み
	score_BG_gh = LoadGraph("score_img\\Score_BG.png");
	win_gh = LoadGraph("score_img\\win_BG.png");
	lose_gh = LoadGraph("score_img\\lose.png");
	draw_gh = LoadGraph("score_img\\draw.png");
	LRRH01_gh = LoadGraph("score_img\\LRRH_Score01.png");
	//LRRH02_gh = LoadGraph("score_img\\LRRH_Score02.png");
	SW01_gh = LoadGraph("score_img\\SnowWhite_Score01.png");
	//SW02_gh = LoadGraph("score_img\\SnowWhite_Score02.png");
	/*
	HaG01_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG02_gh = LoadGraph("score_img\\H and G_Score02.png");
	Rap01_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap02_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	*/
	vs_gh = LoadGraph("score_img\\vs.png");
	/*
	zero_gh = LoadGraph("score_img\\zero.png");
	one_gh = LoadGraph("score_img\\one.png");
	tow_gh = LoadGraph("score_img\\tow.png");
	three_gh = LoadGraph("score_img\\three.png");
	four_gh = LoadGraph("score_img\\four.png");
	five_gh = LoadGraph("score_img\\five.png");
	six_gh = LoadGraph("score_img\\six.png");
	seven_gh = LoadGraph("score_img\\seven.png");
	eight_gh = LoadGraph("score_img\\eight.png");
	nine_gh = LoadGraph("score_img\\nine.png");
	*/

	//初期化グラフ
	score_init_flag = 1;
}

void Score_delete(void){
	DeleteGraph(score_BG_gh);
}

void Score(void){

	//まだ初期化していないときは初期化処理をする
	if (!score_init_flag){
		Score_init();
	}

	//背景描画
	DrawGraph(0, 0, score_BG_gh, TRUE);

	//１Pコントローラーセット
	GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
	//Enterでタイトルへ
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {
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