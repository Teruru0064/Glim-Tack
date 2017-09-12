#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"

int Board_X, Board_Y;		//ボードの表示位置(X:256,Y128px)
int img_board;

//拠点マス
//0=ダミー,1=赤ずきん,2=白雪姫,3=ヘングレ,4=ラプンツェル
#define HOMESPOT_REDFOOD 100
#define HOMESPOT_SNOWWHITE 200
int homespot[5];

//自マスデザイン
//0=ボード(空白マス),1=赤ずきん,2=白雪姫,3=ヘングレ,4=ラプンツェル
enum PaintBoardNo{
	PAINTBPARD_NULL,		//0何も無い状態
	PAINTBPARD_REDFOOD,		//1赤ずきん
	PAINTBPARD_SNOWWHITE,	//2白雪姫
	PAINTBPARD_HOMESPOT_3,	//3ヘングレ
	PAINTBPARD_4,			//4ラプンチェル
	PAINTBPARD_MAX		//5コマ最大数
};
int paint[PAINTBPARD_MAX];

int mapdata[MapMaxX][MapMaxY];//描画用マップ

int mapdata2[MapMaxX][MapMaxY];//光る赤用
int mapdata3[MapMaxX][MapMaxY];//消す赤用
int mapdata4[MapMaxX][MapMaxY];//光る青用
int mapdata5[MapMaxX][MapMaxY];//消す青用
int mapdata6[MapMaxX][MapMaxY];//チェック裏描画

int mapdata11[MapMaxX][MapMaxY];//1p兵士1の1　各コマの行くべきマップデータ
int mapdata12[MapMaxX][MapMaxY];//1p兵士1の2
int mapdata13[MapMaxX][MapMaxY];//1p兵士1の3
int mapdata15[MapMaxX][MapMaxY];//1p兵士3の1
int mapdata16[MapMaxX][MapMaxY];//1p兵士3の2

int mapdata21[MapMaxX][MapMaxY];//2p兵士1の1
int mapdata22[MapMaxX][MapMaxY];//2p兵士1の2
int mapdata23[MapMaxX][MapMaxY];//2p兵士1の3
int mapdata25[MapMaxX][MapMaxY];//2p兵士3の1
int mapdata26[MapMaxX][MapMaxY];//2p兵士3の2





void Board_init(void){

	LoadDivGraph("map_img/HomeSpot.png", 64, 5, 1, 64, 64, homespot);
	LoadDivGraph("map_img/paint.jpg", 64, 5, 1, 64, 64, paint);

	//マップデータの初期化
	//ZeroMemory(mapdata, sizeof(int));
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			mapdata[i][j] = 0;
		}
	}
	Board_X = 256;
	Board_Y = 128;

	//１ｐの初期位置
	mapdata[0][MapMaxY - 1] = HOMESPOT_REDFOOD;
	//２ｐの初期位置
	mapdata[MapMaxX - 1][0] = HOMESPOT_SNOWWHITE;
}

void Board_draw(void){
	//if (CheckSoundFile() == 0){
	//	PlaySoundFile("sound\\Main_BGM.mp3", DX_PLAYTYPE_BACK);
	//}
	//色の表示
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata[i][j]){
			case PAINTBPARD_NULL:
				//ボードの表示
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