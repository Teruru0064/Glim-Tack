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


//スコア用変数
extern int sumred;		//プレイヤー１スコア
extern int sumblue;		//プレイヤー２スコア

extern int White;


//キャラクターのグラフィックハンドル

//白雪姫(00は待機中、01は勝ち、02は負け)
int SW00_gh, SW01_gh, SW02_gh;
//赤ずきん(00は待機中、01は勝ち、02は負け)
int LRRH00_gh, LRRH01_gh, LRRH02_gh;
/*
//ヘンゼルとグレーテル(00は待機中、01は勝ち、02は負け)
int HaG00_gh, HaG01_gh, HaG02_gh;
//ラプンツェル(00は待機中、01は勝ち、02は負け)
int Rap00_gh, Rap01_gh, Rap02_gh;
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
	win_gh = LoadGraph("score_img\\win.png");
	lose_gh = LoadGraph("score_img\\lose.png");
	draw_gh = LoadGraph("score_img\\draw.png");
	vs_gh = LoadGraph("score_img\\vs.png");
	//白雪姫
	SW00_gh = LoadGraph("score_img\\SnowWhite_Stay.png");
	//SW01_gh = LoadGraph("score_img\\SnowWhite_Win.png");
	SW02_gh = LoadGraph("score_img\\SnowWhite_Lose.png");
	//赤ずきん
	LRRH00_gh = LoadGraph("score_img\\LRRH_Stay.png");
	LRRH01_gh = LoadGraph("score_img\\LRRH_Win.png");
	LRRH02_gh = LoadGraph("score_img\\LRRH_Lose.png");
	/*
	//ヘンゼルとグレーテル
	HaG00_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG01_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG02_gh = LoadGraph("score_img\\H and G_Score02.png");
	//ラプンツェル
	Rap00_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap01_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap02_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	*/
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

void Score_Draw(void){

	//まだ初期化していないときは初期化処理をする
	if (!score_init_flag){
		Score_init();
	}

	//背景描画
	DrawGraph(0, 0, score_BG_gh, TRUE);

	//キャラクター描画
	//DrawGraph(333, 352, SW00_gh, TRUE);
	//DrawGraph(709, 370, LRRH00_gh, TRUE);

	//UIの描画
	DrawGraph(579, 319, vs_gh, TRUE);


	//勝敗の出力

	//1Pのスコアが2Pより高かったら1Pに「かち」2Pに「まけ」を表示
	if (sumred > sumblue){
		//かち
		DrawGraph(800, 65, win_gh, TRUE);
		//まけ
		DrawGraph(164, 65, lose_gh, TRUE);

		//1Pと2Pのキャラクター表示

		//1Pかち
		DrawGraph(856, 242, LRRH01_gh, TRUE);
		//2Pまけ
		DrawGraph(156, 350, SW02_gh, TRUE);

	}
	//1Pのスコアが2Pより低かったら1Pに「まけ」2Pに「かち」を表示
	else if (sumred < sumblue){
		//まけ
		DrawGraph(800, 65, lose_gh, TRUE);
		//かち
		DrawGraph(164, 65, win_gh, TRUE);

		//1Pと2Pのキャラクター表示
		//1Pかち
		DrawGraph(156, 350, SW02_gh, TRUE);
		//2Pまけ
		DrawGraph(891, 400, LRRH02_gh, TRUE);
	}
	//1Pと2Pのスコアが同じならば「ひきわけ」を表示
	else if (sumred == sumblue){
		//ひきわけ
		DrawGraph(417, 65, draw_gh, TRUE);
		//1Pと2Pのキャラクター表示
		DrawGraph(333, 352, SW00_gh, TRUE);
		DrawGraph(709, 370, LRRH00_gh, TRUE);
	}
	


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


	//スコア表示
	DrawFormatString(737, 360, White, "%d", sumred);
	DrawFormatString(540, 360, White, "%d", sumblue);

}