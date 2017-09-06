#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Controller.h"
#include "Colt.h"

extern int Board_X, Board_Y;
extern int nonanim;
//コマ①のグラフィックハンドル
struct Coltgame_obj colt1[3],colt1_2[3];

int AnimeCounter;

int move_x[3] = { 0, 0, 0 }, move_y[3] = { 0, 0, 0 };

int move_x02[3] = { 0, 0, 0 }, move_y02[3] = { 0, 0, 0 };

int StartTime;

//コマ①の初期化処理
void Colt1_init(void){

	for (int i = 0; i < 3; i++){
		//コマ①のキャラチップの読み込み
		LoadDivGraph("colt_img\\Colt1_1p.png", 12, 3, 4, 64, 64, colt1[i].anime_gh);
		LoadDivGraph("colt_img\\Colt1_2p.png", 12, 3, 4, 64, 63, colt1_2[i].anime_gh);
		//PC幅、高さ
		colt1[i].width = 64;
		colt1[i].height = 64;

		colt1_2[i].width = 64;
		colt1_2[i].height = 64;
		//PCアニメーション開始・終了位置
		colt1[i].AnimStart = 0;
		colt1[i].AnimEnd = 2;

		colt1_2[i].AnimStart = 0;
		colt1_2[i].AnimEnd = 2;
		//アニメーション速度（大きいほど遅い）
		colt1[i].AnimSpeed = 20;

		colt1_2[i].AnimSpeed = 20;
		//アニメーションフレーム数
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;

		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		//現在のアニメフレーム
		colt1[i].CurFrame = colt1[i].AnimStart;

		colt1_2[i].CurFrame = colt1_2[i].AnimStart;
		//移動中フラグ
		colt1[i].move = 0;

		colt1_2[i].move = 0;
		//アニメカウンター
		AnimeCounter = 0;
		//マップ上の初期位置
		colt1[i].MoveCounter = 0;
		colt1[i].active = 0;

		colt1_2[i].MoveCounter = 0;
		colt1_2[i].active = 0;

		colt1[i].mapx = 0; colt1[i].mapy = MapMaxY - 1;

		colt1_2[i].mapx = MapMaxX - 1; colt1_2[i].mapy = 0;

	}

	colt1[0].active = 1;

	colt1_2[0].active = 1;

	StartTime = GetNowCount();
}


//コマ①のアップデート処理
void Colt1_Update(void){

	// 現在経過時間を得る
	/*if ((GetNowCount() - StartTime > 5000) && colt1[1].active != 1){
		colt1[1].mapx = MapMaxX - 1; colt1[1].mapy = MapMaxY - 1;
		if (colt1[0].mapx != MapMaxX - 1 && colt1[0].mapy != MapMaxY - 1){
			colt1[1].mapx = MapMaxX - 1; colt1[1].mapy = MapMaxY - 1;
			colt1[1].active = 1;
			StartTime = GetNowCount();
		}

	}*/


	if (mapdata[MapMaxX - 1][MapMaxY - 1] == 1){
		colt1[0].active = 1;
	}

	if (mapdata[0][0] == 1){
		colt1_2[0].active = 1;

	}

}


//コマ①の表示
void Colt1_Draw(void){

	//DrawFormatString(250, 0, GetColor(255, 255, 255), "%d", colt1[0].active);



	//colt1[0].active = 1;

	if (!nonanim) AnimeCounter++;
	//AnimeCounter++;
	for (int i = 0; i < 3; i++){
		if (colt1[i].active){

			//for (int i = 0; i < 12){
			//	DrawGraph(0+64*i,200,colt1[i].gh)
			//}


			//マップ固定用
			DrawGraph((colt1[i].mapx) * MAP_SIZE + Board_X + move_x[i],
				(colt1[i].mapy) * MAP_SIZE + Board_Y + move_y[i], colt1[i].anime_gh[colt1[i].CurFrame], TRUE);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", colt1[i].CurFrame);
			// AnimeCounter++;

			colt1[i].CurFrame = AnimeCounter / colt1[i].AnimSpeed % colt1[i].AnimFrameNum + colt1[i].AnimStart;
		}
	}

	for (int i = 0; i < 3; i++){
		if (colt1_2[i].active){

			//for (int i = 0; i < 12){
			//	DrawGraph(0+64*i,200,colt1[i].gh)
			//}


			//マップ固定用
			DrawGraph((colt1_2[i].mapx) * MAP_SIZE + Board_X + move_x02[i],
				(colt1_2[i].mapy) * MAP_SIZE + Board_Y + move_y02[i], colt1_2[i].anime_gh[colt1_2[i].CurFrame], TRUE);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", colt1_2[i].CurFrame);
			//if (!nonanim) AnimeCounter++;

			colt1_2[i].CurFrame = AnimeCounter / colt1_2[i].AnimSpeed % colt1_2[i].AnimFrameNum + colt1_2[i].AnimStart;
		}
	}
}


//コマ①の1Pの下に動く処理
void Colt1_move1p_down(void){

	for (int i = 0; i < 3; i++){
	
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_y[i]++;
		}

		if (move_y[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 0;
			colt1[i].AnimEnd = 2;
			move_y[i] = 0;
			
				colt1[i].mapy++;
			

		}
	}

	/*for (int i = 0; i < 3; i++){

		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1[i].move){
			move_y02[i]++;
		}

		if (move_y02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 0;
			colt1_2[i].AnimEnd = 2;
			move_y02[i] = 0;

			colt1_2[i].mapy++;


		}
	}*/
}


//コマ①の1Pの左に動く処理
void Colt1_move1p_left(void){

	for (int i = 0; i < 3; i++){
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_x[i]--;
		}

		if (move_x[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 3;
			colt1[i].AnimEnd = 5;
			move_x[i] = 0;
			
				colt1[i].mapx--;
			
		}
	}

	/*for (int i = 0; i < 3; i++){
		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1_2[i].move){
			move_x02[i]--;
		}

		if (move_x02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 3;
			colt1_2[i].AnimEnd = 5;
			move_x02[i] = 0;

			colt1_2[i].mapx--;

		}
	}*/
}


//コマ①の1Pの右に動く処理
void Colt1_move1p_right(void){

	for (int i = 0; i < 3; i++){
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_x[i]++;
		}

		if (move_x[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 6;
			colt1[i].AnimEnd = 8;
			move_x[i] = 0;
			
				colt1[i].mapx++;
			
		}
	}

	/*for (int i = 0; i < 3; i++){
		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1_2[i].move){
			move_x02[i]++;
		}

		if (move_x02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 6;
			colt1_2[i].AnimEnd = 8;
			move_x02[i] = 0;

			colt1_2[i].mapx++;

		}
	}*/
}


//コマ①の1Pの上に動く処理
void Colt1_move1p_up(void){

	for (int i = 0; i < 3; i++){
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_y[i]--;
		}

		if (move_y[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 9;
			colt1[i].AnimEnd = 11;
			move_y[i] = 0;
			
				colt1[i].mapy--;
			

		}
	}

	/*for (int i = 0; i < 3; i++){
		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1_2[i].move){
			move_y02[i]--;
		}

		if (move_y02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 9;
			colt1_2[i].AnimEnd = 11;
			move_y02[i] = 0;

			colt1_2[i].mapy--;


		}
	}*/
}


//コマ①の2Pの下に動く処理
void Colt1_move2p_down(void){

	/*for (int i = 0; i < 3; i++){

		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_y[i]++;
		}

		if (move_y[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 0;
			colt1[i].AnimEnd = 2;
			move_y[i] = 0;

			colt1[i].mapy++;


		}
	}*/

	for (int i = 0; i < 3; i++){

		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1[i].move){
			move_y02[i]++;
		}

		if (move_y02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 0;
			colt1_2[i].AnimEnd = 2;
			move_y02[i] = 0;

			colt1_2[i].mapy++;


		}
	}
}


//コマ①の2Pの左に動く処理
void Colt1_move2p_left(void){

	/*for (int i = 0; i < 3; i++){
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_x[i]--;
		}

		if (move_x[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 3;
			colt1[i].AnimEnd = 5;
			move_x[i] = 0;

			colt1[i].mapx--;

		}
	}*/

	for (int i = 0; i < 3; i++){
		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1_2[i].move){
			move_x02[i]--;
		}

		if (move_x02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 3;
			colt1_2[i].AnimEnd = 5;
			move_x02[i] = 0;

			colt1_2[i].mapx--;

		}
	}
}


//コマ①の2Pの右に動く処理
void Colt1_move2p_right(void){

	/*for (int i = 0; i < 3; i++){
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_x[i]++;
		}

		if (move_x[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 6;
			colt1[i].AnimEnd = 8;
			move_x[i] = 0;

			colt1[i].mapx++;

		}
	}*/

	for (int i = 0; i < 3; i++){
		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1_2[i].move){
			move_x02[i]++;
		}

		if (move_x02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 6;
			colt1_2[i].AnimEnd = 8;
			move_x02[i] = 0;

			colt1_2[i].mapx++;

		}
	}
}


//コマ①の2Pの上に動く処理
void Colt1_move2p_up(void){

	/*for (int i = 0; i < 3; i++){
		colt1[i].AnimFrameNum = colt1[i].AnimEnd - colt1[i].AnimStart + 1;
		if (colt1[i].move){
			move_y[i]--;
		}

		if (move_y[i] % MAP_SIZE == 0) {
			colt1[i].AnimStart = 9;
			colt1[i].AnimEnd = 11;
			move_y[i] = 0;

			colt1[i].mapy--;


		}
	}*/

	for (int i = 0; i < 3; i++){
		colt1_2[i].AnimFrameNum = colt1_2[i].AnimEnd - colt1_2[i].AnimStart + 1;
		if (colt1_2[i].move){
			move_y02[i]--;
		}

		if (move_y02[i] % MAP_SIZE == 0) {
			colt1_2[i].AnimStart = 9;
			colt1_2[i].AnimEnd = 11;
			move_y02[i] = 0;

			colt1_2[i].mapy--;


		}
	}
}

