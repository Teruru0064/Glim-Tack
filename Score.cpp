#include "DxLib.h"
#include "GameInit.h"
#include "Score.h"

extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;
extern int ScoreStart;


//コントローラーを使用するための関数
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;


//スコア用変数
extern int sumscore_1p;		//プレイヤー１スコア
extern int sumscore_2p;		//プレイヤー２スコア

//プレイヤーカラー(01は1P、02は2P)
int color_01,color_02;


//キャラクターのグラフィックハンドル

//白雪姫(00は待機中、01は勝ち、02は負け、03は引き分け)
int SW00_gh, SW01_gh, SW02_gh, SW03_gh;
//赤ずきん(00は待機中、01は勝ち、02は負け、03は引き分け)
int LRRH00_gh, LRRH01_gh, LRRH02_gh, LRRH03_gh;
/*
//ヘンゼルとグレーテル(00は待機中、01は勝ち、02は負け、03は引き分け)
int HaG00_gh, HaG01_gh, HaG02_gh, HaG03_gh;
//ラプンツェル(00は待機中、01は勝ち、02は負け、03は引き分け)
int Rap00_gh, Rap01_gh, Rap02_gh, Rap03_gh;
*/

//スコア背景
int score_BG_gh;
//vsのグラフィックハンドル
int vs_gh;
//ボタン
int button_gh[2];

//勝敗結果のテキスト(勝ち、負け、引き分け)
int win_gh, lose_gh, draw_gh;

//勝敗結果(テキスト)のX座標
int TextX_1p = 164;
int TextX_2p = 800;
//引き分け(テキスト)のX座標
int TextdrawX = 417;
//勝敗結果(テキスト)のY座標
int TextY = 65;


//初期化フラグ
static int score_init_flag = 0;

void Score_Init(void){

	//画像の読み込み
	score_BG_gh = LoadGraph("score_img\\Score_BG.png");
	vs_gh = LoadGraph("score_img\\vs.png");
	win_gh = LoadGraph("score_img\\win.png");
	lose_gh = LoadGraph("score_img\\lose.png");
	draw_gh = LoadGraph("score_img\\draw.png");
	button_gh[0] = LoadGraph("score_img\\button_01.png");
	button_gh[1] = LoadGraph("score_img\\button_02.png");
	//白雪姫
	SW00_gh = LoadGraph("score_img\\SnowWhite_Stay.png");
	SW01_gh = LoadGraph("score_img\\SnowWhite_Win.png");
	SW02_gh = LoadGraph("score_img\\SnowWhite_Lose.png");
	SW03_gh = LoadGraph("score_img\\SnowWhite_Draw.png");
	//赤ずきん
	LRRH00_gh = LoadGraph("score_img\\LRRH_Stay.png");
	LRRH01_gh = LoadGraph("score_img\\LRRH_Win.png");
	LRRH02_gh = LoadGraph("score_img\\LRRH_Lose.png");
	LRRH03_gh = LoadGraph("score_img\\LRRH_Draw.png");
	/*
	//ヘンゼルとグレーテル
	HaG00_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG01_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG02_gh = LoadGraph("score_img\\H and G_Score02.png");
	HaG03_gh = LoadGraph("score_img\\H and G_Score03.png");
	//ラプンツェル
	Rap00_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap01_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap02_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	Rap03_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	*/
	

	color_01 = GetColor(245, 57, 77);	//赤色
	color_02 = GetColor(45, 135, 246);	//青色



	//初期化グラフ
	score_init_flag = 1;
}


//消去処理(すべての画像)
void Score_Delete(void){

	DeleteGraph(score_BG_gh);
	DeleteGraph(vs_gh);
	DeleteGraph(button_gh[0]);
	DeleteGraph(button_gh[1]);
	DeleteGraph(win_gh);
	DeleteGraph(lose_gh);
	DeleteGraph(draw_gh);

	//赤ずきん
	DeleteGraph(LRRH00_gh);
	DeleteGraph(LRRH01_gh);
	DeleteGraph(LRRH02_gh);
	DeleteGraph(LRRH03_gh);

	//白雪姫
	DeleteGraph(SW00_gh);
	DeleteGraph(SW01_gh);
	DeleteGraph(SW02_gh);
	DeleteGraph(SW03_gh);
}

//消去処理(待機状態のキャラクターのみ)
	void ScoreChara_Delete(void){
		//赤ずきん
		DeleteGraph(LRRH00_gh);
		//白雪姫
		DeleteGraph(SW00_gh);

	}


void Score_Draw(void){

	//まだ初期化していないときは初期化処理をする
	if (!score_init_flag){
		Score_Init();
	}

	//背景描画
	DrawGraph(0, 0, score_BG_gh, TRUE);
	//ゲーム終了時の盤面を表示
	Board_draw();
	//キャラクター描画
	DrawGraph(92, 243, LRRH00_gh, TRUE);
	DrawTurnGraph(866, 238, SW00_gh, TRUE);
	//UIの描画
	DrawGraph(579, 319, vs_gh, TRUE);

	//文字設定

	//サイズ設定
	SetFontSize(80);
	//フォント設定
	ChangeFont("mini-わくわく");


	//勝敗の出力

	//スコア画面にシーン切り替えして4秒後に表示
	if (GetNowCount() - ScoreStart > 4000){
		//1Pのスコアが2Pより高かったら1Pに「かち」2Pに「まけ」を表示
		if (sumscore_1p > sumscore_2p){
			//勝ち
			DrawGraph(TextX_1p, TextY, win_gh, TRUE);
			//負け
			DrawGraph(TextX_2p, TextY, lose_gh, TRUE);
			//勝敗結果が出て1秒後にキャラクターを表示
			if (GetNowCount() - ScoreStart > 5000){
				//待機中のキャラクターを削除
				ScoreChara_Delete();
				//1Pと2Pのキャラクター表示

				//1P勝ち
				DrawGraph(-70, 254, LRRH01_gh, TRUE);
				//2P負け(反転描画)
				DrawTurnGraph(938, 332, SW02_gh, TRUE);
			}
		}
		//1Pのスコアが2Pより低かったら1Pに「まけ」2Pに「かち」を表示
		else if (sumscore_1p < sumscore_2p){
			//負け
			DrawGraph(TextX_2p, TextY, lose_gh, TRUE);
			//勝ち
			DrawGraph(TextX_1p, TextY, win_gh, TRUE);
			//勝敗結果が出て1秒後にキャラクターを表示
			if (GetNowCount() - ScoreStart > 5000){
				//待機中のキャラクターを削除
				ScoreChara_Delete();

				//1Pと2Pのキャラクター表示

				//1P負け
				DrawGraph(147, 346, LRRH02_gh, TRUE);
				//2P勝ち
				DrawTurnGraph(850, 212, SW01_gh, TRUE);
			}
		}
		//1Pと2Pのスコアが同じならば「ひきわけ」を表示
		else if (sumscore_1p == sumscore_1p){
			//引き分け
			DrawGraph(TextdrawX, TextY, draw_gh, TRUE);
			//勝敗結果が出て1秒後にキャラクターを表示
			if (GetNowCount() - ScoreStart > 5000){
				//待機中のキャラクターを削除
				ScoreChara_Delete();

				//1Pと2Pのキャラクター表示(引き分け)
				DrawGraph(138, 263, LRRH03_gh, TRUE);
				DrawTurnGraph(908, 233, SW03_gh, TRUE);
			}
		}
	}

	//スコア表示

	//３ケタの数字を１秒間ランダムに表示させる
	if (GetNowCount() - ScoreStart < 1000){
		DrawFormatString(400, 320, color_01, "%03d", GetRand(999));
		DrawFormatString(710, 320, color_02, "%03d", GetRand(999));
	}
	//１ケタ目数字を1秒後に表示させる
	else if (GetNowCount() - ScoreStart < 2000){
		DrawFormatString(400, 320, color_01, "%03d", GetRand(99) * 10 + sumscore_1p % 10);
		DrawFormatString(710, 320, color_02, "%03d", GetRand(99) * 10 + sumscore_2p % 10);
	}
	//２ケタ目数字を2秒後に表示させる
	else if (GetNowCount() - ScoreStart < 3000){
		DrawFormatString(400, 320, color_01, "%03d", GetRand(9) * 100 + sumscore_1p % 100);
		DrawFormatString(710, 320, color_02, "%03d", GetRand(9) * 100 + sumscore_2p % 100);
	}
	else{
		//1Pと2Pのスコア全表示
		DrawFormatString(400, 320, color_01, "%03d", sumscore_1p);
		DrawFormatString(710, 320, color_02, "%03d", sumscore_2p);
	}

	//スコア画面にシーン切り替えして6秒後にボタンの表示
	if (GetNowCount() - ScoreStart > 6000){
		//ボタンの表示
		DrawGraph(449, 588, button_gh[GetNowCount() / 500 % 2], TRUE);
		//１Pコントローラーセット
		GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
		//Enterでタイトルへ
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {
			if (key_enter == 0){
				game_status = TITLE;
				ScoreChara_Delete();
				key_enter = 1;
				Test_init();
				//Title_init();
			}
		}
		else{
			key_enter = 0;
		}
	}
}