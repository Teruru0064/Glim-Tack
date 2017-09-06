#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Controller.h"
#include "Colt.h"

extern int Board_X, Board_Y;

//�R�}�A�̃O���t�B�b�N�n���h��
struct Coltgame_obj colt3_1[3], colt3_2[3];

int AnimeCounter3;

int move3_x[3] = { 0, 0, 0 }, move3_y[3] = { 0, 0, 0 };

int move3_x02[3] = { 0, 0, 0 }, move3_y02[3] = { 0, 0, 0 };

int StartTime3;

//�R�}�A�̏���������
void Colt3_init(void){

	for (int i = 0; i < 3; i++){
		//�R�}�@�̃L�����`�b�v�̓ǂݍ���
		LoadDivGraph("colt_img\\colt3_1p.png", 12, 3, 4, 64, 63, colt3_1[i].anime_gh);
		LoadDivGraph("colt_img\\colt3_2p.png", 12, 3, 4, 64, 63, colt3_2[i].anime_gh);
		//PC���A����
		colt3_1[i].width = 64;
		colt3_1[i].height = 64;

		colt3_2[i].width = 64;
		colt3_2[i].height = 64;
		//PC�A�j���[�V�����J�n�E�I���ʒu
		colt3_1[i].AnimStart = 0;
		colt3_1[i].AnimEnd = 2;

		colt3_2[i].AnimStart = 0;
		colt3_2[i].AnimEnd = 2;
		//�A�j���[�V�������x�i�傫���قǒx���j
		colt3_1[i].AnimSpeed = 20;

		colt3_2[i].AnimSpeed = 20;
		//�A�j���[�V�����t���[����
		colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;

		colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
		//���݂̃A�j���t���[��
		colt3_1[i].CurFrame = colt3_1[i].AnimStart;

		colt3_2[i].CurFrame = colt3_2[i].AnimStart;
		//�ړ����t���O
		colt3_1[i].move = 0;

		colt3_2[i].move = 0;
		//�A�j���J�E���^�[
		AnimeCounter3 = 0;
		//�}�b�v��̏����ʒu
		colt3_1[i].MoveCounter = 0;
		colt3_1[i].active = 0;

		colt3_2[i].MoveCounter = 0;
		colt3_2[i].active = 0;

		colt3_1[i].mapx = MapMaxX - 1; colt3_1[i].mapy = MapMaxY - 1;

		colt3_2[i].mapx = 0; colt3_2[i].mapy = 0;

	}

	colt3_1[0].active = 1;

	colt3_2[0].active = 1;

	StartTime3 = GetNowCount();
}


//�R�}�A�̃A�b�v�f�[�g����
void Colt3_Update(void){

	// ���݌o�ߎ��Ԃ𓾂�
	/*if ((GetNowCount() - StartTime > 5000) && colt3_1[1].active != 1){
	colt3_1[1].mapx = MapMaxX - 1; colt3_1[1].mapy = MapMaxY - 1;
	if (colt3_1[0].mapx != MapMaxX - 1 && colt3_1[0].mapy != MapMaxY - 1){
	colt3_1[1].mapx = MapMaxX - 1; colt3_1[1].mapy = MapMaxY - 1;
	colt3_1[1].active = 1;
	StartTime = GetNowCount();
	}

	}*/


	if (mapdata[MapMaxX - 1][MapMaxY - 1] == 1){
		colt3_1[0].active = 1;
	}

	if (mapdata[0][0] == 1){
		colt3_2[0].active = 1;

	}

}


//�R�}�A�̕\��
void Colt3_Draw(void){

	//DrawFormatString(250, 0, GetColor(255, 255, 255), "%d", colt3_1[0].active);



	//colt3_1[0].active = 1;

	for (int i = 0; i < 3; i++){
		if (colt3_1[i].active){

			//for (int i = 0; i < 12){
			//	DrawGraph(0+64*i,200,colt3_1[i].gh)
			//}


			//�}�b�v�Œ�p
			DrawGraph((colt3_1[i].mapx) * MAP_SIZE + Board_X + move3_x[i],
				(colt3_1[i].mapy) * MAP_SIZE + Board_Y + move3_y[i], colt3_1[i].anime_gh[colt3_1[i].CurFrame], TRUE);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", colt3_1[i].CurFrame);
			AnimeCounter3++;

			colt3_1[i].CurFrame = AnimeCounter3 / colt3_1[i].AnimSpeed % colt3_1[i].AnimFrameNum + colt3_1[i].AnimStart;
		}
	}

	for (int i = 0; i < 3; i++){
		if (colt3_2[i].active){

			//for (int i = 0; i < 12){
			//	DrawGraph(0+64*i,200,colt3_1[i].gh)
			//}


			//�}�b�v�Œ�p
			DrawGraph((colt3_2[i].mapx) * MAP_SIZE + Board_X + move3_x02[i],
				(colt3_2[i].mapy) * MAP_SIZE + Board_Y + move3_y02[i], colt3_2[i].anime_gh[colt3_2[i].CurFrame], TRUE);

			DrawFormatString(0, 0, GetColor(255, 255, 255), "%d", colt3_2[i].CurFrame);
			AnimeCounter3++;

			colt3_2[i].CurFrame = AnimeCounter3 / colt3_2[i].AnimSpeed % colt3_2[i].AnimFrameNum + colt3_2[i].AnimStart;
		}
	}
}


//�R�}�A��1P�̉��ɓ�������
void Colt3_move1p_down(void){

	for (int i = 0; i < 3; i++){

		colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
		if (colt3_1[i].move){
			move3_y[i]++;
		}

		if (move3_y[i] % MAP_SIZE == 0) {
			colt3_1[i].AnimStart = 0;
			colt3_1[i].AnimEnd = 2;
			move3_y[i] = 0;

			colt3_1[i].mapy++;


		}
	}

	/*for (int i = 0; i < 3; i++){

	colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
	if (colt3_1[i].move){
	move_y02[i]++;
	}

	if (move_y02[i] % MAP_SIZE == 0) {
	colt3_2[i].AnimStart = 0;
	colt3_2[i].AnimEnd = 2;
	move_y02[i] = 0;

	colt3_2[i].mapy++;


	}
	}*/
}


//�R�}�A��1P�̍��ɓ�������
void Colt3_move1p_left(void){

	for (int i = 0; i < 3; i++){
		colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
		if (colt3_1[i].move){
			move3_x[i]--;
		}

		if (move3_x[i] % MAP_SIZE == 0) {
			colt3_1[i].AnimStart = 3;
			colt3_1[i].AnimEnd = 5;
			move3_x[i] = 0;

			colt3_1[i].mapx--;

		}
	}

	/*for (int i = 0; i < 3; i++){
	colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
	if (colt3_2[i].move){
	move_x02[i]--;
	}

	if (move_x02[i] % MAP_SIZE == 0) {
	colt3_2[i].AnimStart = 3;
	colt3_2[i].AnimEnd = 5;
	move_x02[i] = 0;

	colt3_2[i].mapx--;

	}
	}*/
}


//�R�}�A��1P�̉E�ɓ�������
void Colt3_move1p_right(void){

	for (int i = 0; i < 3; i++){
		colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
		if (colt3_1[i].move){
			move3_x[i]++;
		}

		if (move3_x[i] % MAP_SIZE == 0) {
			colt3_1[i].AnimStart = 6;
			colt3_1[i].AnimEnd = 8;
			move3_x[i] = 0;

			colt3_1[i].mapx++;

		}
	}

	/*for (int i = 0; i < 3; i++){
	colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
	if (colt3_2[i].move){
	move_x02[i]++;
	}

	if (move_x02[i] % MAP_SIZE == 0) {
	colt3_2[i].AnimStart = 6;
	colt3_2[i].AnimEnd = 8;
	move_x02[i] = 0;

	colt3_2[i].mapx++;

	}
	}*/
}


//�R�}�A��1P�̏�ɓ�������
void Colt3_move1p_up(void){

	for (int i = 0; i < 3; i++){
		colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
		if (colt3_1[i].move){
			move3_y[i]--;
		}

		if (move3_y[i] % MAP_SIZE == 0) {
			colt3_1[i].AnimStart = 9;
			colt3_1[i].AnimEnd = 11;
			move3_y[i] = 0;

			colt3_1[i].mapy--;


		}
	}

	/*for (int i = 0; i < 3; i++){
	colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
	if (colt3_2[i].move){
	move_y02[i]--;
	}

	if (move_y02[i] % MAP_SIZE == 0) {
	colt3_2[i].AnimStart = 9;
	colt3_2[i].AnimEnd = 11;
	move_y02[i] = 0;

	colt3_2[i].mapy--;


	}
	}*/
}


//�R�}�A��2P�̉��ɓ�������
void Colt3_move2p_down(void){

	/*for (int i = 0; i < 3; i++){

	colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
	if (colt3_1[i].move){
	move_y[i]++;
	}

	if (move_y[i] % MAP_SIZE == 0) {
	colt3_1[i].AnimStart = 0;
	colt3_1[i].AnimEnd = 2;
	move_y[i] = 0;

	colt3_1[i].mapy++;


	}
	}*/

	for (int i = 0; i < 3; i++){

		colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
		if (colt3_1[i].move){
			move3_y02[i]++;
		}

		if (move3_y02[i] % MAP_SIZE == 0) {
			colt3_2[i].AnimStart = 0;
			colt3_2[i].AnimEnd = 2;
			move3_y02[i] = 0;

			colt3_2[i].mapy++;


		}
	}
}


//�R�}�A��2P�̍��ɓ�������
void Colt3_move2p_left(void){

	/*for (int i = 0; i < 3; i++){
	colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
	if (colt3_1[i].move){
	move_x[i]--;
	}

	if (move_x[i] % MAP_SIZE == 0) {
	colt3_1[i].AnimStart = 3;
	colt3_1[i].AnimEnd = 5;
	move_x[i] = 0;

	colt3_1[i].mapx--;

	}
	}*/

	for (int i = 0; i < 3; i++){
		colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
		if (colt3_2[i].move){
			move3_x02[i]--;
		}

		if (move3_x02[i] % MAP_SIZE == 0) {
			colt3_2[i].AnimStart = 3;
			colt3_2[i].AnimEnd = 5;
			move3_x02[i] = 0;

			colt3_2[i].mapx--;

		}
	}
}


//�R�}�A��2P�̉E�ɓ�������
void Colt3_move2p_right(void){

	/*for (int i = 0; i < 3; i++){
	colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
	if (colt3_1[i].move){
	move_x[i]++;
	}

	if (move_x[i] % MAP_SIZE == 0) {
	colt3_1[i].AnimStart = 6;
	colt3_1[i].AnimEnd = 8;
	move_x[i] = 0;

	colt3_1[i].mapx++;

	}
	}*/

	for (int i = 0; i < 3; i++){
		colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
		if (colt3_2[i].move){
			move3_x02[i]++;
		}

		if (move3_x02[i] % MAP_SIZE == 0) {
			colt3_2[i].AnimStart = 6;
			colt3_2[i].AnimEnd = 8;
			move3_x02[i] = 0;

			colt3_2[i].mapx++;

		}
	}
}


//�R�}�A��2P�̏�ɓ�������
void Colt3_move2p_up(void){

	/*for (int i = 0; i < 3; i++){
	colt3_1[i].AnimFrameNum = colt3_1[i].AnimEnd - colt3_1[i].AnimStart + 1;
	if (colt3_1[i].move){
	move_y[i]--;
	}

	if (move_y[i] % MAP_SIZE == 0) {
	colt3_1[i].AnimStart = 9;
	colt3_1[i].AnimEnd = 11;
	move_y[i] = 0;

	colt3_1[i].mapy--;


	}
	}*/

	for (int i = 0; i < 3; i++){
		colt3_2[i].AnimFrameNum = colt3_2[i].AnimEnd - colt3_2[i].AnimStart + 1;
		if (colt3_2[i].move){
			move3_y02[i]--;
		}

		if (move3_y02[i] % MAP_SIZE == 0) {
			colt3_2[i].AnimStart = 9;
			colt3_2[i].AnimEnd = 11;
			move3_y02[i] = 0;

			colt3_2[i].mapy--;


		}
	}
}

