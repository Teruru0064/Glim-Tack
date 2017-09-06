#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Controller.h"
#include "Colt.h"

extern int Board_X, Board_Y;

//コマ②のグラフィックハンドル
struct Coltgame_obj colt2_1[3], colt2_2[3];

int AnimeCounter2;

int move2_x[3] = { 0, 0, 0 }, move2_y[3] = { 0, 0, 0 };

int move2_x02[3] = { 0, 0, 0 }, move2_y02[3] = { 0, 0, 0 };

int StartTime2;

//コマ②の初期化処理
void Colt2_init(void){

	for (int i = 0; i < 3; i++){
		//コマ①のキャラチップの読み込み
		LoadDivGraph("colt_img\\colt2_1p.png", 12, 3, 4, 64, 63, colt2_1[i].anime_gh);
		LoadDivGraph("colt_img\\colt2_2p.png", 12, 3, 4, 64, 63, colt2_2[i].anime_gh);
		//PC幅、高さ
		colt2_1[i].width = 64;
		colt2_1[i].height = 64;

		colt2_2[i].width = 64;
		colt2_2[i].height = 64;
		//PCアニメーション開始・終了位置
		colt2_1[i].AnimStart = 0;
		colt2_1[i].AnimEnd = 2;

		colt2_2[i].AnimStart = 0;
		colt2_2[i].AnimEnd = 2;
		//アニメーション速度（大きいほど遅い）
		colt2_1[i].AnimSpeed = 20;

		colt2_2[i].AnimSpeed = 20;
		//アニメーションフレーム数
		colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;

		colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
		//現在のアニメフレーム
		colt2_1[i].CurFrame = colt2_1[i].AnimStart;

		colt2_2[i].CurFrame = colt2_2[i].AnimStart;
		//移動中フラグ
		colt2_1[i].move = 0;

		colt2_2[i].move = 0;
		//アニメカウンター
		AnimeCounter2 = 0;
		//マップ上の初期位置
		colt2_1[i].MoveCounter = 0;
		colt2_1[i].active = 0;

		colt2_2[i].MoveCounter = 0;
		colt2_2[i].active = 0;

		colt2_1[i].mapx = MapMaxX - 1; colt2_1[i].mapy = MapMaxY - 1;

		colt2_2[i].mapx = 0; colt2_2[i].mapy = 0;

	}

	colt2_1[0].active = 1;

	colt2_2[0].active = 1;

	StartTime2 = GetNowCount();
}


//コマ②のアップデート処理
void Colt2_Update(void){

	// 現在経過時間を得る
	/*if ((GetNowCount() - StartTime > 5000) && colt2_1[1].active != 1){
	colt2_1[1].mapx = MapMaxX - 1; colt2_1[1].mapy = MapMaxY - 1;
	if (colt2_1[0].mapx != MapMaxX - 1 && colt2_1[0].mapy != MapMaxY - 1){
	colt2_1[1].mapx = MapMaxX - 1; colt2_1[1].mapy = MapMaxY - 1;
	colt2_1[1].active = 1;
	StartTime = GetNowCount();
	}

	}*/


	if (mapdata[MapMaxX - 1][MapMaxY - 1] == 1){
		colt2_1[0].active = 1;
	}

	if (mapdata[0][0] == 1){
		colt2_2[0].active = 1;

	}

}


//コマ②の表示
void Colt2_Draw(void){

	//DrawFormatString(250, 0, GetColor(255, 255, 255), "%d", colt2_1[0].active);



	//colt2_1[0].active = 1;

	for (int i = 0; i < 3; i++){
		if (colt2_1[i].active){

			//for (int i = 0; i < 12){
			//	DrawGraph(0+64*i,200,colt2_1[i].gh)
			//}


			//マップ固定用
			DrawGraph((colt2_1[i].mapx) * MAP_SIZE + Board_X + move2_x[i],
				(colt2_1[i].mapy) * MAP_SIZE + Board_Y + move2_y[i], colt2_1[i].anime_gh[colt2_1[i].CurFrame], TRUE);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", colt2_1[i].CurFrame);
			AnimeCounter2++;

			colt2_1[i].CurFrame = AnimeCounter2 / colt2_1[i].AnimSpeed % colt2_1[i].AnimFrameNum + colt2_1[i].AnimStart;
		}
	}

	for (int i = 0; i < 3; i++){
		if (colt2_2[i].active){

			//for (int i = 0; i < 12){
			//	DrawGraph(0+64*i,200,colt2_1[i].gh)
			//}


			//マップ固定用
			DrawGraph((colt2_2[i].mapx) * MAP_SIZE + Board_X + move2_x02[i],
				(colt2_2[i].mapy) * MAP_SIZE + Board_Y + move2_y02[i], colt2_2[i].anime_gh[colt2_2[i].CurFrame], TRUE);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", colt2_2[i].CurFrame);
			AnimeCounter2++;

			colt2_2[i].CurFrame = AnimeCounter2 / colt2_2[i].AnimSpeed % colt2_2[i].AnimFrameNum + colt2_2[i].AnimStart;
		}
	}
}


//コマ②の1Pの下に動く処理
void Colt2_move1p_down(void){

	for (int i = 0; i < 3; i++){

		colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
		if (colt2_1[i].move){
			move2_y[i]++;
		}

		if (move2_y[i] % MAP_SIZE == 0) {
			colt2_1[i].AnimStart = 0;
			colt2_1[i].AnimEnd = 2;
			move2_y[i] = 0;

			colt2_1[i].mapy++;


		}
	}

	/*for (int i = 0; i < 3; i++){

	colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
	if (colt2_1[i].move){
	move_y02[i]++;
	}

	if (move_y02[i] % MAP_SIZE == 0) {
	colt2_2[i].AnimStart = 0;
	colt2_2[i].AnimEnd = 2;
	move_y02[i] = 0;

	colt2_2[i].mapy++;


	}
	}*/
}


//コマ②の1Pの左に動く処理
void Colt2_move1p_left(void){

	for (int i = 0; i < 3; i++){
		colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
		if (colt2_1[i].move){
			move2_x[i]--;
		}

		if (move2_x[i] % MAP_SIZE == 0) {
			colt2_1[i].AnimStart = 3;
			colt2_1[i].AnimEnd = 5;
			move2_x[i] = 0;

			colt2_1[i].mapx--;

		}
	}

	/*for (int i = 0; i < 3; i++){
	colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
	if (colt2_2[i].move){
	move_x02[i]--;
	}

	if (move_x02[i] % MAP_SIZE == 0) {
	colt2_2[i].AnimStart = 3;
	colt2_2[i].AnimEnd = 5;
	move_x02[i] = 0;

	colt2_2[i].mapx--;

	}
	}*/
}


//コマ②の1Pの右に動く処理
void Colt2_move1p_right(void){

	for (int i = 0; i < 3; i++){
		colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
		if (colt2_1[i].move){
			move2_x[i]++;
		}

		if (move2_x[i] % MAP_SIZE == 0) {
			colt2_1[i].AnimStart = 6;
			colt2_1[i].AnimEnd = 8;
			move2_x[i] = 0;

			colt2_1[i].mapx++;

		}
	}

	/*for (int i = 0; i < 3; i++){
	colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
	if (colt2_2[i].move){
	move_x02[i]++;
	}

	if (move_x02[i] % MAP_SIZE == 0) {
	colt2_2[i].AnimStart = 6;
	colt2_2[i].AnimEnd = 8;
	move_x02[i] = 0;

	colt2_2[i].mapx++;

	}
	}*/
}


//コマ②の1Pの上に動く処理
void Colt2_move1p_up(void){

	for (int i = 0; i < 3; i++){
		colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
		if (colt2_1[i].move){
			move2_y[i]--;
		}

		if (move2_y[i] % MAP_SIZE == 0) {
			colt2_1[i].AnimStart = 9;
			colt2_1[i].AnimEnd = 11;
			move2_y[i] = 0;

			colt2_1[i].mapy--;


		}
	}

	/*for (int i = 0; i < 3; i++){
	colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
	if (colt2_2[i].move){
	move_y02[i]--;
	}

	if (move_y02[i] % MAP_SIZE == 0) {
	colt2_2[i].AnimStart = 9;
	colt2_2[i].AnimEnd = 11;
	move_y02[i] = 0;

	colt2_2[i].mapy--;


	}
	}*/
}


//コマ②の2Pの下に動く処理
void Colt2_move2p_down(void){

	/*for (int i = 0; i < 3; i++){

	colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
	if (colt2_1[i].move){
	move_y[i]++;
	}

	if (move_y[i] % MAP_SIZE == 0) {
	colt2_1[i].AnimStart = 0;
	colt2_1[i].AnimEnd = 2;
	move_y[i] = 0;

	colt2_1[i].mapy++;


	}
	}*/

	for (int i = 0; i < 3; i++){

		colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
		if (colt2_1[i].move){
			move2_y02[i]++;
		}

		if (move2_y02[i] % MAP_SIZE == 0) {
			colt2_2[i].AnimStart = 0;
			colt2_2[i].AnimEnd = 2;
			move2_y02[i] = 0;

			colt2_2[i].mapy++;


		}
	}
}


//コマ②の2Pの左に動く処理
void Colt2_move2p_left(void){

	/*for (int i = 0; i < 3; i++){
	colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
	if (colt2_1[i].move){
	move_x[i]--;
	}

	if (move_x[i] % MAP_SIZE == 0) {
	colt2_1[i].AnimStart = 3;
	colt2_1[i].AnimEnd = 5;
	move_x[i] = 0;

	colt2_1[i].mapx--;

	}
	}*/

	for (int i = 0; i < 3; i++){
		colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
		if (colt2_2[i].move){
			move2_x02[i]--;
		}

		if (move2_x02[i] % MAP_SIZE == 0) {
			colt2_2[i].AnimStart = 3;
			colt2_2[i].AnimEnd = 5;
			move2_x02[i] = 0;

			colt2_2[i].mapx--;

		}
	}
}


//コマ②の2Pの右に動く処理
void Colt2_move2p_right(void){

	/*for (int i = 0; i < 3; i++){
	colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
	if (colt2_1[i].move){
	move_x[i]++;
	}

	if (move_x[i] % MAP_SIZE == 0) {
	colt2_1[i].AnimStart = 6;
	colt2_1[i].AnimEnd = 8;
	move_x[i] = 0;

	colt2_1[i].mapx++;

	}
	}*/

	for (int i = 0; i < 3; i++){
		colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
		if (colt2_2[i].move){
			move2_x02[i]++;
		}

		if (move2_x02[i] % MAP_SIZE == 0) {
			colt2_2[i].AnimStart = 6;
			colt2_2[i].AnimEnd = 8;
			move2_x02[i] = 0;

			colt2_2[i].mapx++;

		}
	}
}


//コマ②の2Pの上に動く処理
void Colt2_move2p_up(void){

	/*for (int i = 0; i < 3; i++){
	colt2_1[i].AnimFrameNum = colt2_1[i].AnimEnd - colt2_1[i].AnimStart + 1;
	if (colt2_1[i].move){
	move_y[i]--;
	}

	if (move_y[i] % MAP_SIZE == 0) {
	colt2_1[i].AnimStart = 9;
	colt2_1[i].AnimEnd = 11;
	move_y[i] = 0;

	colt2_1[i].mapy--;


	}
	}*/

	for (int i = 0; i < 3; i++){
		colt2_2[i].AnimFrameNum = colt2_2[i].AnimEnd - colt2_2[i].AnimStart + 1;
		if (colt2_2[i].move){
			move2_y02[i]--;
		}

		if (move2_y02[i] % MAP_SIZE == 0) {
			colt2_2[i].AnimStart = 9;
			colt2_2[i].AnimEnd = 11;
			move2_y02[i] = 0;

			colt2_2[i].mapy--;


		}
	}
}