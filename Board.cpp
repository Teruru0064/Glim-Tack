#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"

int Board_X, Board_Y;		//�{�[�h�̕\���ʒu(X:256,Y128px)
int img_board;

//���_�}�X
//0=�_�~�[,1=�Ԃ�����,2=����P,3=�w���O��,4=���v���c�F��
#define HOMESPOT_REDFOOD 100
#define HOMESPOT_SNOWWHITE 200
int homespot[5];

//���}�X�f�U�C��
//0=�{�[�h(�󔒃}�X),1=�Ԃ�����,2=����P,3=�w���O��,4=���v���c�F��
enum PaintBoardNo{
	PAINTBPARD_NULL,		//0�����������
	PAINTBPARD_REDFOOD,		//1�Ԃ�����
	PAINTBPARD_SNOWWHITE,	//2����P
	PAINTBPARD_HOMESPOT_3,	//3�w���O��
	PAINTBPARD_4,			//4���v���`�F��
	PAINTBPARD_MAX		//5�R�}�ő吔
};
int paint[PAINTBPARD_MAX];

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

	//�P���̏����ʒu
	mapdata[0][MapMaxY - 1] = HOMESPOT_REDFOOD;
	//�Q���̏����ʒu
	mapdata[MapMaxX - 1][0] = HOMESPOT_SNOWWHITE;
}

void Board_draw(void){
	//if (CheckSoundFile() == 0){
	//	PlaySoundFile("sound\\Main_BGM.mp3", DX_PLAYTYPE_BACK);
	//}
	//�F�̕\��
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata[i][j]){
			case PAINTBPARD_NULL:
				//�{�[�h�̕\��
				DrawGraph((i * MAP_SIZE) + Board_X, (j * MAP_SIZE) + Board_Y, paint[PAINTBPARD_NULL], true);
				break;
			case PAINTBPARD_REDFOOD:
				DrawGraph((i * MAP_SIZE) + Board_X, (j * MAP_SIZE) + Board_Y, paint[PAINTBPARD_REDFOOD], true);
				break;
			case PAINTBPARD_SNOWWHITE:
				DrawGraph((i * MAP_SIZE) + Board_X, (j * MAP_SIZE) + Board_Y, paint[PAINTBPARD_SNOWWHITE], true);
				break;
			case HOMESPOT_REDFOOD:
				DrawGraph((i * MAP_SIZE) + Board_X, (j * MAP_SIZE) + Board_Y, homespot[1], true);
				break;
			case HOMESPOT_SNOWWHITE:
				DrawGraph((i * MAP_SIZE) + Board_X, (j * MAP_SIZE) + Board_Y, homespot[2], true);
				break;
			}
		}
	}
}