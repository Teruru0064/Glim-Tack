#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"

int Board_X, Board_Y;
int img_board;

//���_�}�X
int homepallet[5];

int img_pallet[5];



int mapdata[MapMaxX][MapMaxY];//�`��p�}�b�v
int mapdata2[MapMaxX][MapMaxY];//����ԗp
int mapdata3[MapMaxX][MapMaxY];//�����ԗp
int mapdata4[MapMaxX][MapMaxY];//����p
int mapdata5[MapMaxX][MapMaxY];//�����p
int mapdata6[MapMaxX][MapMaxY];//�`�F�b�N���`��

int mapdata11[MapMaxX][MapMaxY];//1p���m1��1�@�e�R�}�̍s���ׂ��}�b�v�f�[�^
int mapdata12[MapMaxX][MapMaxY];//1p���m1��2
int mapdata13[MapMaxX][MapMaxY];//1p���m1��3
int mapdata15[MapMaxX][MapMaxY];//1p���m3��1
int mapdata16[MapMaxX][MapMaxY];//1p���m3��2

int mapdata21[MapMaxX][MapMaxY];//2p���m1��1
int mapdata22[MapMaxX][MapMaxY];//2p���m1��2
int mapdata23[MapMaxX][MapMaxY];//2p���m1��3
int mapdata25[MapMaxX][MapMaxY];//2p���m3��1
int mapdata26[MapMaxX][MapMaxY];//2p���m3��2





void Board_init(void){

	LoadDivGraph("map_img/HomePallet.png", 64, 5, 1, 64, 64, homepallet);
	LoadDivGraph("map_img/pallet.jpg", 64, 5, 1, 64, 64, img_pallet);

	//�}�b�v�f�[�^�̏�����
	//ZeroMemory(mapdata, sizeof(int));
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			mapdata[i][j] = 0;
		}
	}
	Board_X = 256;
	Board_Y = 128;
}

void Board_draw(void){

	//�F�̕\��
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata[i][j]){
			case 0:
				//�{�[�h�̕\��
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet[0], true);
				break;
			case 1:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet[1], true);
				break;
			case 2:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet[2], true);
				break;
			case 100:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, homepallet[1], true);
				break;
			case 200:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, homepallet[2], true);
				break;
			}
		}
	}
}