#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"

int Board_X, Board_Y;
int img_board;

//���_�}�X
//0=�_�~�[,1=�Ԃ�����,2=����P,3=�w���O��,4=���v���c�F��
int homespot[5];

//���}�X�f�U�C��
//0=�{�[�h(�󔒃}�X),1=�Ԃ�����,2=����P,3=�w���O��,4=���v���c�F��
int paint[5];

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

	LoadDivGraph("map_img/HomeSpot.png", 64, 5, 1, 64, 64, homespot);
	LoadDivGraph("map_img/paint.jpg", 64, 5, 1, 64, 64, paint);

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

	////�P���̏����ʒu
	//mapdata[0][MapMaxY - 1] = 100;
	////�Q���̏����ʒu
	//mapdata[MapMaxX - 1][0] = 200;


	//�F�̕\��
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata[i][j]){
			case 0:
				//�{�[�h�̕\��
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, paint[0], true);
				break;
			case 1:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, paint[1], true);
				break;
			case 2:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, paint[2], true);
				break;
			case 100:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, homespot[1], true);
				break;
			case 200:
				DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, homespot[2], true);
				break;
			}
		}
	}
}