#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"

int Board_X, Board_Y;
int img_board;

//拠点マス
//0=ダミー,1=赤ずきん,2=白雪姫,3=ヘングレ,4=ラプンツェル
int homespot[5];

//自マスデザイン
//0=ボード(空白マス),1=赤ずきん,2=白雪姫,3=ヘングレ,4=ラプンツェル
int paint[5];

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


}

void Board_draw(void){

	////１ｐの初期位置
	//mapdata[0][MapMaxY - 1] = 100;
	////２ｐの初期位置
	//mapdata[MapMaxX - 1][0] = 200;


	//色の表示
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata[i][j]){
			case 0:
				//ボードの表示
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