//TODO：ゲームフロー
//１．手持ちのコマをフィールドに配置(READY)
//２．コマを選択肢、移動先をクリックすると、そこまで移動する
//３．目的地にだどりついたら、色を変える動作を行う。
//以下、２，３を繰り返し、制限時間内に色の数が多い方が勝ち。

//コマをおいたら色を変えるようにする
//コマを持って、動かしたら、コマ自身が移動するようにする
//コマの特殊動作ができるようにする（要仕様と相談）
//CPU戦をつくる(時間があれば)


#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"

extern int game_status;
extern int Board_X, Board_Y;
extern struct Coltgame_obj colt1[], colt1_2[];


char KeyBuf[];

//1Pの現在地
int moveto_x, moveto_y;
int moveto_x2, moveto_y2;
int moveto_x3, moveto_y3;
//2Pの現在地
int moveto2_x, moveto2_y;
int moveto2_x2, moveto2_y2;
int moveto2_x3, moveto2_y3;

//背景
int img_BG;
int img_BG_02;
int img_book;


int Test_init_flag = 0;
extern int img_pallet[5];
int img_pallet2[5];


//unit1は赤ずきん用、unit2は白雪用
int unit_1[6], unit_2[6];
int RedHood;
int SnowWhite;

//移動先を指定した時の到着地点のx.y座標(1はコマ①.2はコマ②.3はコマ③)
int ArrivalPoint_1p_1x, ArrivalPoint_1p_1y;
int ArrivalPoint_2p_1x, ArrivalPoint_2p_1y;


//選択なう
//1pの選択状態 1はコマ①を選択中 2はコマ②を選択中 3はコマ③を選択中
int colt_select_1p = 1;
//２pの選択状態 11はコマ①を選択中 12はコマ②を選択中 13はコマ③を選択中
int colt_select_2p = 0;
//カーソルの状態1p
int testselect2 = 0;
//カーソルの状態2p
int testselect3 = 0;
//スコア用変数
int sumred = 0;
int sumblue = 0;

//extern int mapdata[MapMaxX][MapMaxY];//描画用マップ
//extern int mapdata2[MapMaxX][MapMaxY];//光る赤用
//extern int mapdata3[MapMaxX][MapMaxY];//消す赤用
//extern int mapdata4[MapMaxX][MapMaxY];//光る青用
//extern int mapdata5[MapMaxX][MapMaxY];//消す青用
//extern int mapdata6[MapMaxX][MapMaxY];//チェック裏描画
//
//extern int mapdata11[MapMaxX][MapMaxY];//1p兵士1の1　各コマの行くべきマップデータ
//extern int mapdata12[MapMaxX][MapMaxY];//1p兵士1の2
//extern int mapdata13[MapMaxX][MapMaxY];//1p兵士1の3
//extern int mapdata15[MapMaxX][MapMaxY];//1p兵士3の1
//extern int mapdata16[MapMaxX][MapMaxY];//1p兵士3の2
//
//extern int mapdata21[MapMaxX][MapMaxY];//2p兵士1の1
//extern int mapdata22[MapMaxX][MapMaxY];//2p兵士1の2
//extern int mapdata23[MapMaxX][MapMaxY];//2p兵士1の3
//extern int mapdata25[MapMaxX][MapMaxY];//2p兵士3の1
//extern int mapdata26[MapMaxX][MapMaxY];//2p兵士3の2

int mouseX, mouseY;

int mouseX02, mouseY02;

int mouseX2, mouseY2;

int colt_1p_mapX, colt_1p_mapY;
int colt_2p_mapX, colt_2p_mapY;

int mapX11, mapY11;//兵士1の1兵士行くべき場所
int mapX12, mapY12;//兵士1の2
int mapX13, mapY13;//兵士1の3
int mapX14, mapY14;//兵士2の1
int end_mapX14, end_mapY14;//兵士2の1
int mapX15, mapY15;//兵士3の1
int mapX16, mapY16;//兵士3の2

int mapX21, mapY21;//2p兵士1の1
int mapX22, mapY22;//2p兵士1の2
int mapX23, mapY23;//2p兵士1の3
int mapX24, mapY24;//2p兵士2の1
int end_mapX24, end_mapY24;//2p兵士2の1
int mapX25, mapY25;//2p兵士3の1
int mapX26, mapY26;//2p兵士3の2
//制限時間を作る
int GameTime = 0;
int GameTime_Minute=0;	//分表示用

//兵士管理用フラグ兵士を使っているか使ってないか
int RedTimeFlag11 = 0;//兵士1の1
int RedTimeFlag12 = 0;//兵士1の2
int RedTimeFlag13 = 0;//兵士1の3
int RedTimeFlag15 = -1;//兵士3の1
int RedTimeFlag16 = 0;//兵士3の2

int BlueTimeFlag11 = 0;//2p兵士1の1
int BlueTimeFlag12 = 0;//2p兵士1の2
int BlueTimeFlag13 = 0;//2p兵士1の3
int BlueTimeFlag15 = -1;//2p兵士3の1
int BlueTimeFlag16 = 0;//2p兵士3の2

//移動時間管理
int RedTime11 = 0;//兵士1の1　塗れるまでの時間
int RedTime12 = 0;//兵士1の2
int RedTime13 = 0;//兵士1の2
int RedTime15 = 10 * 60;//兵士3の1
int RedTime16 = 0;//兵士3の2

int BlueTime11 = 0;//2p兵士1の1
int BlueTime12 = 0;//2p兵士1の2
int BlueTime13 = 0;//2p兵士1の2
int BlueTime15 = 10 * 60;//2p兵士3の1
int BlueTime16 = 0;//2p兵士3の2

int BlueTime1 = 0;
int startfont;
int White;


extern XINPUT_STATE XInputState1, XInputState2;
extern int P1_x , P1_y, P2_x , P2_y ;
extern int menu_flg;





int t = 0;
int now_mapx, now_mapy;

//初期化処理
void Test_init(void){

	//画像の読み込み
	LoadDivGraph("map_img/pallet2.png", 64, 5, 1, 64, 64, img_pallet2);		//移動可能地点の光
	LoadDivGraph("colt_img/LittleRedRidingHood_Unit.png", 96, 2, 3, 96, 96, unit_1);
	LoadDivGraph("colt_img/SnowWhite_Unit.png", 96, 2, 3, 96, 96, unit_2);
	RedHood = LoadGraph("char_img/LittleRedRidingHood.png");
	SnowWhite = LoadGraph("char_img/SnowWhite.png");
	img_BG = LoadGraph("bg_img/BG.png");
	img_BG_02 = LoadGraph("bg_img/BG_02.png");
	img_book = LoadGraph("bg_img/book00.png");

	ArrivalPoint_1p_1x = 0;
	ArrivalPoint_1p_1y = 0;

	ArrivalPoint_2p_1x = 0;
	ArrivalPoint_2p_1y = 0;




	Test_init_flag = 1;	//初期化完了

	//ゲームが始まったときにコマ1を選択した状態
	colt_select_1p = 1;
	colt_select_2p = 11;
	testselect2 = 0;
	testselect3 = 0;

	sumred = 0;
	sumblue = 0;

	//ゲームの制限時間
	GameTime = 60 * 60;
	GameTime_Minute = 2;

	RedTimeFlag11 = 0;
	RedTimeFlag12 = 0;
	RedTimeFlag13 = 0;
	RedTimeFlag15 = -1;

	BlueTimeFlag11 = 0;
	BlueTimeFlag12 = 0;
	BlueTimeFlag13 = 0;
	BlueTimeFlag15 = -1;

	RedTime11 = 3 * 60;
	RedTime12 = 3 * 60;
	RedTime13 = 3 * 60;

	BlueTime11 = 3 * 60;
	BlueTime12 = 3 * 60;
	BlueTime13 = 3 * 60;

	SetFontSize(32);
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8);

	White = GetColor(255, 255, 255); // 白色の値を取得
}

//兵士管理(赤　1-1)
void RedFlag11(int mapX, int mapY){
	if (RedTimeFlag11 == 0){
			mapdata[mapX11][mapY11] = 1;
			RedTimeFlag11 = -1;
	}
}
//兵士管理(赤　1-2)
void RedFlag12(int mapX, int mapY){
	if (RedTimeFlag12 == 0){
		mapdata[mapX12][mapY12] = 1;
		RedTimeFlag11 = -1;
	}
}
//兵士管理(赤　1-3)
void RedFlag13(int mapX, int mapY){
	if (RedTimeFlag13 == 0){
		mapdata[mapX13][mapY13] = 1;
		//testselect = 0;
	}
}

//兵士管理(赤　3-1)
void RedFlag15(int mapX, int mapY){
	if (RedTimeFlag15 == 0){
		mapdata[mapX15][mapY15] = 1;//その場
		mapdata[mapX15 + 1][mapY15] = 1;//右
		mapdata[mapX15 + 1][mapY15 - 1] = 1;//右上
		mapdata[mapX15 + 1][mapY15 + 1] = 1;//右下
		mapdata[mapX15 - 1][mapY15] = 1;//左
		mapdata[mapX15 - 1][mapY15 - 1] = 1;//左上
		mapdata[mapX15 - 1][mapY15 + 1] = 1;//左下
		mapdata[mapX15][mapY15 + 1] = 1;//下
		mapdata[mapX15][mapY15 - 1] = 1;//上
		RedTimeFlag15 = -1;
	}
}
//兵士管理(青　1-1)
void BlueFlag11(int mapX, int mapY){
	if (BlueTimeFlag11 == 0){
		mapdata[mapX21][mapY21] = 2;
		BlueTimeFlag11 = -1;
	}
}
//兵士管理(青　1-2)
void BlueFlag12(int mapX, int mapY){
	if (BlueTimeFlag12 == 0){
		mapdata[mapX22][mapY22] = 2;
		BlueTimeFlag11 = -1;
	}
}
//兵士管理(青　1-3)
void BlueFlag13(int mapX, int mapY){
	if (BlueTimeFlag13 == 0){
		mapdata[mapX23][mapY23] = 2;
		//testselect = 0;
	}
}
//兵士管理(青　3-1)
void BlueFlag15(int mapX, int mapY){
	if (BlueTimeFlag15 == 0){
		mapdata[mapX25][mapY25] = 2;//その場
		mapdata[mapX25 + 1][mapY25] = 2;//右
		mapdata[mapX25 + 1][mapY25 - 1] = 2;//右上
		mapdata[mapX25 + 1][mapY25 + 1] = 2;//右下
		mapdata[mapX25 - 1][mapY25] = 2;//左
		mapdata[mapX25 - 1][mapY25 - 1] = 2;//左上
		mapdata[mapX25 - 1][mapY25 + 1] = 2;//左下
		mapdata[mapX25][mapY25 + 1] = 2;//下
		mapdata[mapX25][mapY25 - 1] = 2;//上
		
	}
}
//スコア関数
void ScoreCheck(void){
	sumred = 0;
	sumblue = 0;
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata[i][j]){
			case 0:
				break;
			case 1:
				sumred += 1;
				break;
			case 2:
				sumblue += 1;
				break;
			}
		}
	}
}

//兵士1塗り場所確定(自分)
void TestFirstRed2(int mapX, int mapY){
	if (mapdata2[mapX][mapY] == 1){
		if (RedTimeFlag11 == 0){
			RedTimeFlag11 = 1;
			//コマを↓ここ
			mapdata11[mapX][mapY] = 1;
			mapX11 = mapX;
			mapY11 = mapY;
			moveto_x = mapX11; moveto_y = mapY11;
			colt_select_1p = 1;
			RedFlag11(mapX, mapY);
		}
		else if (RedTimeFlag12 == 0){
			RedTimeFlag12 = 1;
			mapdata12[mapX][mapY] = 1;
			mapX12 = mapX;
			mapY12 = mapY;
			moveto_x2 = mapX; moveto_y2 = mapY;
			colt_select_1p = 1;
			RedFlag12(mapX, mapY);
		}
		else if (RedTimeFlag13 == 0){
			RedTimeFlag13 = 1;
			mapdata13[mapX][mapY] = 1;
			mapX13 = mapX;
			mapY13 = mapY;
			moveto_x3 = mapX; moveto_y3 = mapY;
			colt_select_1p = 1;
			RedFlag13(mapX, mapY);
		}
		else{
			DrawString(1000, 64, "これ以上置けないよ", White);
		}
	}
}
//兵士1塗り場所確定(相手)
void TestFirstBlue2(int mapX, int mapY){
	if (mapdata4[mapX][mapY] == 2){
		if (BlueTimeFlag11 == 0){
			BlueTimeFlag11 = 1;
			//↓ここ
			mapdata21[mapX][mapY] = 1;
			mapX21 = mapX;
			mapY21 = mapY;
			moveto2_x = mapX21; moveto2_y = mapY21;
			colt_select_2p = 11;
			BlueFlag11(mapX, mapY);
		}
		else if (BlueTimeFlag12 == 0){
			BlueTimeFlag12 = 1;
			mapdata22[mapX][mapY] = 1;
			mapX22 = mapX;
			mapY22 = mapY;
			moveto2_x2 = mapX22; moveto2_y2 = mapY22;
			colt_select_2p = 11;
			BlueFlag12(mapX, mapY);
		}
		else if (BlueTimeFlag13 == 0){
			BlueTimeFlag13 = 1;
			mapdata23[mapX][mapY] = 1;
			mapX23 = mapX;
			mapY23 = mapY;
			moveto2_x3 = mapX23; moveto2_y3 = mapY23;
			colt_select_2p = 11;
			BlueFlag13(mapX, mapY);
		}
		else{
			DrawString(1000, 64, "これ以上置けないよ", White);
		}
	}
}
//兵士1(自分)
void TestFirstRed(int mapX, int mapY){

	for (int i = 0; i < 3; i++){
		if (colt1[i].mapx == mapX && colt1[i].mapy == mapY ){
		//if (colt1[i].mapx == now_mapx && colt1[i].mapy == now_mapy && colt1[i].active==1){
			colt1[i].move = 1;
		}

	}
	colt_select_1p = 4;


	////////////////////////////////
	ArrivalPoint_1p_1x = mapX;
	ArrivalPoint_1p_1y = mapY;
	////////////////////////////////


	//checkMapはファイル参照外をなくす
	//上3つを計算する。（ただし、—になる場合は0にする）
	int checkMapX = mapX;
	int checkMapX2 = mapX;
	int checkMapY = mapY;
	int checkMapY2 = mapY;
	//上の判定を行うので、Yのみ計算する
	if (checkMapY - 1 < 0){
		checkMapY = -1;
	}
	else if (checkMapY - 2 < 0){
		checkMapY = -2;
	}
	else{
		checkMapY = mapY - 2;
	}
	//下の判定を行うので、Yのみ計算する
	if (checkMapY2 + 1 > MapMaxY){
		checkMapY2 = MapMaxY;
	}
	else if (checkMapY2 + 2 > MapMaxY){
		checkMapY2 = MapMaxY + 2;
	}
	else{
		checkMapY2 = mapY + 2;
	}
	//TODO：以下同じ事を繰り返す
	//左の判定を行うので、Yのみ計算する
	if (checkMapX - 1 < 0){
		checkMapX = -1;
	}
	else if (checkMapX - 2 < 0){
		checkMapX = -2;
	}
	else{
		checkMapX = mapX - 2;
	}

	if (checkMapX2 + 2 > MapMaxX){
		checkMapX2 = MapMaxX + 1;
	}
	else if (checkMapX2 + 1 > MapMaxX){
		checkMapX2 = MapMaxX;
	}
	else{
		checkMapX2 = mapX + 2;
	}
	//上
	if ((checkMapY >= 0) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY] != 100) mapdata2[mapX - 1][checkMapY] = 1;
	}
	if ((checkMapY >= 0) && (checkMapX2 != (MapMaxX + 1))){
		if (mapdata[mapX + 1][checkMapY] != 100) mapdata2[mapX + 1][checkMapY] = 1;
	}

	//下
	if ((checkMapY2 < MapMaxY) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY2] != 100) mapdata2[mapX - 1][checkMapY2] = 1;
	}
	if (checkMapY2 < MapMaxY){
		if (mapdata[mapX + 1][checkMapY2] != 100) mapdata2[mapX + 1][checkMapY2] = 1;
	}

	//左
	if ((checkMapX >= 0) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX][mapY + 1] != 100) mapdata2[checkMapX][mapY + 1] = 1;
	}
	if ((checkMapX >= 0) && (checkMapY != -1)){
		if (mapdata[checkMapX][mapY - 1] != 100) mapdata2[checkMapX][mapY - 1] = 1;
	}

	//右
	if ((checkMapX2 < MapMaxX) && (checkMapY != -1)){
		//ファイル参照内だったら無条件で表示させる　　　
		if (mapdata[checkMapX2][mapY - 1] != 100) 
			mapdata2[checkMapX2][mapY - 1] = 1;
	}
	if ((checkMapX2 < MapMaxX) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX2][mapY + 1] != 100) 
			mapdata2[checkMapX2][mapY + 1] = 1;
	}
}
//兵士1(相手)
void TestFirstBlue(int mapX, int mapY){

	for (int i = 0; i < 3; i++){
		if (colt1_2[i].mapx == mapX && colt1_2[i].mapy == mapY){
			//if (colt1[i].mapx == now_mapx && colt1[i].mapy == now_mapy && colt1[i].active==1){
			colt1_2[i].move = 1;
		}

	}
	colt_select_2p = 14;
	ArrivalPoint_2p_1x = mapX;
	ArrivalPoint_2p_1y = mapY;
	//上3つを計算する。（ただし、—になる場合は0にする）
	int checkMapX = mapX;
	int checkMapX2 = mapX;
	int checkMapY = mapY;
	int checkMapY2 = mapY;
	//上の判定を行うので、Yのみ計算する
	if (checkMapY - 1 < 0){
		checkMapY = -1;
	}
	else if (checkMapY - 2 < 0){
		checkMapY = -2;
	}
	else{
		checkMapY = mapY - 2;
	}
	//下の判定を行うので、Yのみ計算する
	if (checkMapY2 + 1 > MapMaxY){
		checkMapY2 = MapMaxY;
	}
	else if (checkMapY2 + 2 > MapMaxY){
		checkMapY2 = MapMaxY + 2;
	}
	else{
		checkMapY2 = mapY + 2;
	}
	//TODO：以下同じ事を繰り返す
	//左の判定を行うので、Yのみ計算する
	if (checkMapX - 1 < 0){
		checkMapX = -1;
	}
	else if (checkMapX - 2 < 0){
		checkMapX = -2;
	}
	else{
		checkMapX = mapX - 2;
	}

	if (checkMapX2 + 2 > MapMaxX){
		checkMapX2 = MapMaxX + 1;
	}
	else if (checkMapX2 + 1 > MapMaxX){
		checkMapX2 = MapMaxX;
	}
	else{
		checkMapX2 = mapX + 2;
	}
	//上
	if ((checkMapY >= 0) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY] != 200) mapdata4[mapX - 1][checkMapY] = 2;
	}
	if ((checkMapY >= 0) && (checkMapX2 != (MapMaxX + 1))){
		if (mapdata[mapX + 1][checkMapY] != 200) mapdata4[mapX + 1][checkMapY] = 2;
	}

	//下
	if ((checkMapY2 < MapMaxY) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY2] != 200) mapdata4[mapX - 1][checkMapY2] = 2;
	}
	if (checkMapY2 < MapMaxY){
		if (mapdata[mapX + 1][checkMapY2] != 200) mapdata4[mapX + 1][checkMapY2] = 2;
	}

	//左
	if ((checkMapX >= 0) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX][mapY + 1] != 200) mapdata4[checkMapX][mapY + 1] = 2;
	}
	if ((checkMapX >= 0) && (checkMapY != -1)){
		if (mapdata[checkMapX][mapY - 1] != 200) mapdata4[checkMapX][mapY - 1] = 2;
	}

	//右
	if ((checkMapX2 < MapMaxX) && (checkMapY != -1)){
		if (mapdata[checkMapX2][mapY - 1] != 200) mapdata4[checkMapX2][mapY - 1] = 2;
	}
	if ((checkMapX2 < MapMaxX) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX2][mapY + 1] != 200) mapdata4[checkMapX2][mapY + 1] = 2;
	}




}
//兵士2　（自分）
void TestSecondRed(int mapX, int mapY){
	//左3マス以下右1マス
	if ((mapdata[mapX - 3][mapY] == 1) && (mapdata[mapX + 1][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX - 1][mapY] = 1;
		mapdata[mapX - 2][mapY] = 1;
	}
	else if ((mapdata[mapX - 2][mapY] == 1) && (mapdata[mapX + 1][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX - 1][mapY] = 1;
	}
	else if ((mapdata[mapX - 1][mapY] == 1) && (mapdata[mapX + 1][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
	}
	//左2マス以下右2マス以下
	if ((mapdata[mapX - 2][mapY] == 1) && (mapdata[mapX + 2][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX - 1][mapY] = 1;
		mapdata[mapX + 1][mapY] = 1;
	}
	else if ((mapdata[mapX - 1][mapY] == 1) && (mapdata[mapX + 1][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
	}
	//左1マス右3マス以下
	if ((mapdata[mapX -1][mapY] == 1) && (mapdata[mapX + 3][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX + 1][mapY] = 1;
		mapdata[mapX + 2][mapY] = 1;
	}
	else if ((mapdata[mapX - 1][mapY] == 1) && (mapdata[mapX + 2][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX + 1][mapY] = 1;
	}
	else if ((mapdata[mapX - 1][mapY] == 1) && (mapdata[mapX + 1][mapY] == 1)){
		mapdata[mapX][mapY] = 1;
	}
	//上3マス以下下1マス
	if ((mapdata[mapX][mapY - 3] == 1) && (mapdata[mapX][mapY + 1] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX][mapY - 1] = 1;
		mapdata[mapX][mapY - 2] = 1;
	}
	else if ((mapdata[mapX][mapY - 2] == 1) && (mapdata[mapX][mapY + 1] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX][mapY - 1] = 1;
	}
	else if ((mapdata[mapX][mapY - 1] == 1) && (mapdata[mapX][mapY + 1] == 1)){
		mapdata[mapX][mapY] = 1;
	}
	//上2マス以下下2マス以下
	if ((mapdata[mapX][mapY - 2] == 1) && (mapdata[mapX][mapY + 2] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX][mapY - 1] = 1;
		mapdata[mapX][mapY + 1] = 1;
	}
	else if ((mapdata[mapX][mapY - 1] == 1) && (mapdata[mapX][mapY + 1] == 1)){
		mapdata[mapX][mapY] = 1;
	}
	//上1マス下3マス以下
	if ((mapdata[mapX][mapY - 1] == 1) && (mapdata[mapX][mapY + 3] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX][mapY + 1] = 1;
		mapdata[mapX][mapY + 2] = 1;
	}
	else if ((mapdata[mapX][mapY - 1] == 1) && (mapdata[mapX][mapY + 2] == 1)){
		mapdata[mapX][mapY] = 1;
		mapdata[mapX][mapY + 1] = 1;
	}
	else if ((mapdata[mapX][mapY - 1] == 1) && (mapdata[mapX][mapY + 1] == 1)){
		mapdata[mapX][mapY] = 1;
	}
}
//兵士２　（相手）
void TestSecondBlue(int mapX, int mapY){
	//左3マス以下右1マス
	if ((mapdata[mapX - 3][mapY] == 2) && (mapdata[mapX + 1][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX - 1][mapY] = 2;
		mapdata[mapX - 2][mapY] = 2;
	}
	else if ((mapdata[mapX - 2][mapY] == 2) && (mapdata[mapX + 1][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX - 1][mapY] = 2;
	}
	else if ((mapdata[mapX - 1][mapY] == 2) && (mapdata[mapX + 1][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
	}
	//左2マス以下右2マス以下
	if ((mapdata[mapX - 2][mapY] == 2) && (mapdata[mapX + 2][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX - 1][mapY] = 2;
		mapdata[mapX + 1][mapY] = 2;
	}
	else if ((mapdata[mapX - 1][mapY] == 2) && (mapdata[mapX + 1][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
	}
	//左1マス右3マス以下
	if ((mapdata[mapX - 1][mapY] == 2) && (mapdata[mapX + 3][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX + 1][mapY] = 2;
		mapdata[mapX + 2][mapY] = 2;
	}
	else if ((mapdata[mapX - 1][mapY] == 2) && (mapdata[mapX + 2][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX + 1][mapY] = 2;
	}
	else if ((mapdata[mapX - 1][mapY] == 2) && (mapdata[mapX + 1][mapY] == 2)){
		mapdata[mapX][mapY] = 2;
	}
	//上3マス以下下1マス
	if ((mapdata[mapX][mapY - 3] == 2) && (mapdata[mapX][mapY + 1] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX][mapY - 1] = 2;
		mapdata[mapX][mapY - 2] = 2;
	}
	else if ((mapdata[mapX][mapY - 2] == 2) && (mapdata[mapX][mapY + 1] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX][mapY - 1] = 2;
	}
	else if ((mapdata[mapX][mapY - 1] == 2) && (mapdata[mapX][mapY + 1] == 2)){
		mapdata[mapX][mapY] = 2;
	}
	//上2マス以下下2マス以下
	if ((mapdata[mapX][mapY - 2] == 2) && (mapdata[mapX][mapY + 2] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX][mapY - 1] = 2;
		mapdata[mapX][mapY + 1] = 2;
	}
	else if ((mapdata[mapX][mapY - 1] == 2) && (mapdata[mapX][mapY + 1] == 2)){
		mapdata[mapX][mapY] = 2;
	}
	//上1マス下3マス以下
	if ((mapdata[mapX][mapY - 1] == 2) && (mapdata[mapX][mapY + 3] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX][mapY + 1] = 2;
		mapdata[mapX][mapY + 2] = 2;
	}
	else if ((mapdata[mapX][mapY - 1] == 2) && (mapdata[mapX][mapY + 2] == 2)){
		mapdata[mapX][mapY] = 2;
		mapdata[mapX][mapY + 1] = 2;
	}
	else if ((mapdata[mapX][mapY - 1] == 2) && (mapdata[mapX][mapY + 1] == 2)){
		mapdata[mapX][mapY] = 2;
	}
}
//兵士3塗り場所確定（自分）
void TestThirdRed2(int mapX, int mapY){
	if (mapdata2[mapX][mapY] == 1){
		if (RedTimeFlag15 == 0){
			RedTimeFlag15 = 1;
			mapdata15[mapX][mapY] = 1;
			mapX15 = mapX;
			mapY15 = mapY;
			colt_select_1p = 3;
			RedFlag15(mapX, mapY);
		}
		else {
			DrawString(1000, 64, "使用できません", White);
		}
	}
}
//兵士3(自分)
void TestThirdRed(int mapX, int mapY){
	colt_select_1p = 5;

	//上3つを計算する。（ただし、—になる場合は0にする）
	int checkMapX = mapX;
	int checkMapX2 = mapX;
	int checkMapY = mapY;
	int checkMapY2 = mapY;
	//上の判定を行うので、Yのみ計算する
	if (checkMapY - 1 < 0){
		checkMapY = -1;
	}
	else if (checkMapY - 2 < 0){
		checkMapY = -2;
	}
	else{
		checkMapY = mapY - 2;
	}
	//下の判定を行うので、Yのみ計算する
	if (checkMapY2 + 1 > MapMaxY){
		checkMapY2 = MapMaxY;
	}
	else if (checkMapY2 + 2 > MapMaxY){
		checkMapY2 = MapMaxY + 2;
	}
	else{
		checkMapY2 = mapY + 2;
	}
	//TODO：以下同じ事を繰り返す
	//左の判定を行うので、Yのみ計算する
	if (checkMapX - 1 < 0){
		checkMapX = -1;
	}
	else if (checkMapX - 2 < 0){
		checkMapX = -2;
	}
	else{
		checkMapX = mapX - 2;
	}

	if (checkMapX2 + 2 > MapMaxX){
		checkMapX2 = MapMaxX + 1;
	}
	else if (checkMapX2 + 1 > MapMaxX){
		checkMapX2 = MapMaxX;
	}
	else{
		checkMapX2 = mapX + 2;
	}
	//上
	if ((checkMapY >= 0) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY] == 2) mapdata2[mapX - 1][checkMapY] = 1;
	}
	/*if (checkMapY >= 0){
	if (mapdata[mapX][checkMapY] != 1) mapdata2[mapX][checkMapY] = 1;
	}*/
	if ((checkMapY >= 0) && (checkMapX2 != (MapMaxX + 1))){
		if (mapdata[mapX + 1][checkMapY] == 2) mapdata2[mapX + 1][checkMapY] = 1;
	}

	//下
	if ((checkMapY2 < MapMaxY) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY2] == 2) mapdata2[mapX - 1][checkMapY2] = 1;
	}
	/*if (checkMapY2 < MapMaxY){
	if (mapdata[mapX][checkMapY2] != 1) mapdata2[mapX][checkMapY2] = 1;
	}*/
	if (checkMapY2 < MapMaxY){
		if ((mapdata[mapX + 1][checkMapY2] == 2) && (mapdata[mapX + 1][checkMapY2] != 1)) mapdata2[mapX + 1][checkMapY2] = 1;
	}

	//左
	/*if (checkMapX >= 0){
	if (mapdata[checkMapX][mapY] != 1) mapdata2[checkMapX][mapY] = 1;
	}*/
	if ((checkMapX >= 0) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX][mapY + 1] == 2) mapdata2[checkMapX][mapY + 1] = 1;
	}
	if ((checkMapX >= 0) && (checkMapY != -1)){
		if (mapdata[checkMapX][mapY - 1] == 2) mapdata2[checkMapX][mapY - 1] = 1;
	}

	//右
	if ((checkMapX2 < MapMaxX) && (checkMapY != -1)){
		if (mapdata[checkMapX2][mapY - 1] == 2) mapdata2[checkMapX2][mapY - 1] = 1;
	}
	/*if (checkMapX2 < MapMaxX){
	if (mapdata[checkMapX2][mapY] != 1) mapdata2[checkMapX2][mapY] = 1;
	}*/
	if ((checkMapX2 < MapMaxX) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX2][mapY + 1] == 2) mapdata2[checkMapX2][mapY + 1] = 1;
	}
}
//兵士3塗り場所確定（相手）
void TestThirdBlue2(int mapX, int mapY){
	if (mapdata4[mapX][mapY] == 2){
		if (BlueTimeFlag15 == 0){
			BlueTimeFlag15 = 1;
			mapdata25[mapX][mapY] = 1;
			mapX25 = mapX;
			mapY25 = mapY;
			colt_select_2p = 13;
			BlueFlag15(mapX, mapY);
		}
		else {
			DrawString(0, 64, "使用できません", White);
		}
	}
}
//兵士3（相手）
void TestThirdBlue(int mapX, int mapY){
	colt_select_2p = 15;

	//上3つを計算する。（ただし、—になる場合は0にする）
	int checkMapX = mapX;
	int checkMapX2 = mapX;
	int checkMapY = mapY;
	int checkMapY2 = mapY;
	//上の判定を行うので、Yのみ計算する
	if (checkMapY - 1 < 0){
		checkMapY = -1;
	}
	else if (checkMapY - 2 < 0){
		checkMapY = -2;
	}
	else{
		checkMapY = mapY - 2;
	}
	//下の判定を行うので、Yのみ計算する
	if (checkMapY2 + 1 > MapMaxY){
		checkMapY2 = MapMaxY;
	}
	else if (checkMapY2 + 2 > MapMaxY){
		checkMapY2 = MapMaxY + 2;
	}
	else{
		checkMapY2 = mapY + 2;
	}
	//TODO：以下同じ事を繰り返す
	//左の判定を行うので、Yのみ計算する
	if (checkMapX - 1 < 0){
		checkMapX = -1;
	}
	else if (checkMapX - 2 < 0){
		checkMapX = -2;
	}
	else{
		checkMapX = mapX - 2;
	}

	if (checkMapX2 + 2 > MapMaxX){
		checkMapX2 = MapMaxX + 1;
	}
	else if (checkMapX2 + 1 > MapMaxX){
		checkMapX2 = MapMaxX;
	}
	else{
		checkMapX2 = mapX + 2;
	}
	//上
	if ((checkMapY >= 0) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY] == 1) mapdata4[mapX - 1][checkMapY] = 2;
	}
	/*if (checkMapY >= 0){
	if ((mapdata[mapX][checkMapY] != 2) && (mapdata[mapX][checkMapY] != 1)) mapdata4[mapX][checkMapY] = 2;
	}*/
	if ((checkMapY >= 0) && (checkMapX2 != (MapMaxX + 1))){
		if (mapdata[mapX + 1][checkMapY] == 1) mapdata4[mapX + 1][checkMapY] = 2;
	}

	//下
	if ((checkMapY2 < MapMaxY) && (checkMapX != -1)){
		if (mapdata[mapX - 1][checkMapY2] == 1) mapdata4[mapX - 1][checkMapY2] = 2;
	}
	/*if (checkMapY2 < MapMaxY){
	if ((mapdata[mapX][checkMapY2] != 2) && (mapdata[mapX][checkMapY2] != 1)) mapdata4[mapX][checkMapY2] = 2;
	}*/
	if (checkMapY2 < MapMaxY){
		if (mapdata[mapX + 1][checkMapY2] == 1) mapdata4[mapX + 1][checkMapY2] = 2;
	}

	//左
	/*if (checkMapX >= 0){
	if ((mapdata[checkMapX][mapY] != 2) && (mapdata[checkMapX][mapY] != 1)) mapdata4[checkMapX][mapY] = 2;
	}*/
	if ((checkMapX >= 0) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX][mapY + 1] == 1) mapdata4[checkMapX][mapY + 1] = 2;
	}
	if ((checkMapX >= 0) && (checkMapY != -1)){
		if (mapdata[checkMapX][mapY - 1] == 1) mapdata4[checkMapX][mapY - 1] = 2;
	}

	//右
	if ((checkMapX2 < MapMaxX) && (checkMapY != -1)){
		if (mapdata[checkMapX2][mapY - 1] == 1) mapdata4[checkMapX2][mapY - 1] = 2;
	}
	/*if (checkMapX2 < MapMaxX){
	if ((mapdata[checkMapX2][mapY] != 2) && (mapdata[checkMapX2][mapY] != 1)) mapdata4[checkMapX2][mapY] = 2;
	}*/
	if ((checkMapX2 < MapMaxX) && (checkMapY2 != (MapMaxY + 2))){
		if (mapdata[checkMapX2][mapY + 1] == 1) mapdata4[checkMapX2][mapY + 1] = 2;
	}
}


void TestScene(void){

	if (!Test_init_flag){
		Test_init();
		FG_Init();
	}
	/////////////////////////////////////////////////////

	//背景描画
	DrawGraph(0, 0, img_BG, TRUE);
	DrawGraph(15, 620, img_book, TRUE);
	DrawGraph(1035, 620, img_book, TRUE);
	DrawGraph(0, 0, img_BG_02, TRUE);
	//キャラクター描画
	DrawGraph(1039, 370, RedHood, TRUE);
	DrawGraph(20, 384, SnowWhite, TRUE);




	//////////////////////////////////////////////////////

	/////////////////////////////////////////////////

	//ゲーム起動中は時間を減少させる
	//ゲーム終了
	if (!menu_flg)GameTime--;

	if (GameTime == 0 && GameTime_Minute == 0) {
		game_status = SCORE;
	}
	if (GameTime <= 0){
		GameTime = 60 * 60;
		--GameTime_Minute;
	}


	/////////////////////////////////////////////////
	//コマ3使用可能時間
	if (GameTime == (180 * 60) - (30 * 60)){
		RedTimeFlag15 = 0;
		BlueTimeFlag15 = 0;
	}

	//DrawFormatString(1000, 400, White, "時間 %d", RedTime11);
	//DrawFormatString(1000, 450, White, "時間 %d", RedTime12);
	//DrawFormatString(1000, 700, White, "フラグ %d", RedTimeFlag11);
	//DrawFormatString(1000, 600, White, "現在位置 %d", mapX11);

	//兵士1の1
	if (RedTimeFlag11 == 1){
		RedTime11--;
	}
	if (RedTime11 <= 0){
		RedTimeFlag11 = 0;
		RedFlag11(mapX11, mapY11);
		RedTime11 = 5 * 60;
	}
	//兵士1の2
	if (RedTimeFlag12 == 1){
		RedTime12--;
	}
	if (RedTime12 <= 0){
		RedTimeFlag12 = 0;
		RedFlag12(mapX12, mapY12);
		RedTime12 = 3 * 60;
	}
	//兵士1の3
	if (RedTimeFlag13 == 1){
		RedTime13--;
		RedTimeFlag13 = 1;
	}
	if (RedTime13 <= 0){
		RedTimeFlag13 = 0;
		RedFlag13(mapX13, mapY13);
		RedTime13 = 3 * 60;
	}
	//兵士3の1
	if (RedTimeFlag15 == 1){
		RedTime15--;
		RedTimeFlag15 = 1;
	}
	if (RedTime15 <= 0){
		RedTimeFlag15 = 0;
		RedFlag15(mapX15, mapY15);
		RedTime15 = 10 * 60;
	}
	//2p兵士1の1
	if (BlueTimeFlag11 == 1){
		BlueTime11--;
		BlueTimeFlag11 = 1;
	}
	if (BlueTime11 <= 0){
		BlueTimeFlag11 = 0;
		BlueFlag11(mapX21, mapY21);
		BlueTime11 = 3 * 60;
	}
	//2p兵士1の2
	if (BlueTimeFlag12 == 1){
		BlueTime12--;
		BlueTimeFlag12 = 1;
	}
	if (BlueTime12 <= 0){
		BlueTimeFlag12 = 0;
		BlueFlag12(mapX22, mapY22);
		BlueTime12 = 3 * 60;
	}
	//2p兵士1の3
	if (BlueTimeFlag13 == 1){
		BlueTime13--;
		BlueTimeFlag13 = 1;
	}
	if (BlueTime13 <= 0){
		BlueTimeFlag13 = 0;
		BlueFlag13(mapX23, mapY23);
		BlueTime13 = 3 * 60;
	}
	//2p兵士3の1
	if (BlueTimeFlag15 == 1){
		BlueTime15--;
		BlueTimeFlag15 = 1;
	}
	if (BlueTime15 <= 0){
		BlueTimeFlag15 = 0;
		BlueFlag15(mapX25, mapY25);
		BlueTime15 = 10 * 60;
	}

	//マウスクリックした所を色を変える
	GetMousePoint(&mouseX, &mouseY);
	GetMousePoint(&mouseX02, &mouseY02);

	mouseX = P1_x; mouseY = P1_y;
	mouseX02 = P2_x; mouseY02 = P2_y;

	int mouseX2 = (mouseX - Board_X) / 64;
	int mouseY2 = (mouseY - Board_Y) / 64;


	//１ｐの初期位置
	mapdata[MapMaxX - 1][MapMaxY - 1] = 100;
	//２ｐの初期位置
	mapdata[0][0] = 200;


	GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);

	//1pのボタン振り分け
	if (XInputState1.Buttons[15]){
		colt_select_1p = 1;
	}
	if (XInputState1.Buttons[14]){
		colt_select_1p = 2;
	}
	if (XInputState1.Buttons[12]){
		colt_select_1p = 3;
	}


	//マウスの位置をマップのどこに押したか判定する
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0 || XInputState1.Buttons[13]){
		//マウスの位置からマップ座標を計算し、代入
		int mapX = (mouseX - Board_X) / 64;
		int mapY = (mouseY - Board_Y) / 64;
		//兵士選択
		if (mapX == 11 && mapY == 0){
			colt_select_1p = 1;
		}
		if (mapX == 11 && mapY == 1){
			colt_select_1p = 2;
		}
		if (mapX == 11 && mapY == 2){
			colt_select_1p = 3;
		}

		//光る場所の初期化(塗る用)
		if ((colt_select_1p != 4) && (colt_select_1p != 5)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata2[i][j] = 0;
				}
			}
		}
		//光る場所の初期化(消す用)
		if ((colt_select_1p != 5)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata3[i][j] = 0;
				}
			}
		}
		//裏描画の初期化(消す用)
		if ((colt_select_1p != 2)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata6[i][j] = 0;
				}
			}
		}
		//兵士1の1の初期化(塗る用)
		if ((RedTimeFlag11 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata11[i][j] = 0;
				}
			}
		}
		//兵士1の2の初期化(塗る用)
		if ((RedTimeFlag12 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata12[i][j] = 0;
				}
			}
		}
		//兵士1の3の初期化(塗る用)
		if ((RedTimeFlag13 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata13[i][j] = 0;
				}
			}
		}
		//兵士3の1の初期化(塗る用)
		if ((RedTimeFlag15 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata15[i][j] = 0;
				}
			}
		}
		if ((mapX < 0 || mapX < MapMaxX) && (mapY < 0 || mapY < MapMaxY)){

			if ((mapdata[mapX][mapY] == 1) || (mapdata[mapX][mapY] == 100)){
				if (colt_select_1p == 1) {

					now_mapx = mapX; now_mapy = mapY;
					TestFirstRed(mapX, mapY);
				}

			}
			if (colt_select_1p == 2){
				TestSecondRed(mapX, mapY);
			}
			if (colt_select_1p == 4){
				TestFirstRed2(mapX, mapY);
			}
			if (mapdata[mapX][mapY] == 1){
				if (colt_select_1p == 3){
					TestThirdRed(mapX, mapY);
				}
			}
			if (colt_select_1p == 5){
				TestThirdRed2(mapX, mapY);
			}
			ScoreCheck();
		}
	}

	GetJoypadXInputState(DX_INPUT_PAD2, &XInputState2);

	//２pのボタン振り分け
	if (XInputState2.Buttons[15]){
		colt_select_2p = 11;
	}
	if (XInputState2.Buttons[14]){
		colt_select_2p = 12;
	}
	if (XInputState2.Buttons[12]){
		colt_select_2p = 13;
	}
	//マウスの位置をマップのどこに押したか判定する
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0 || XInputState2.Buttons[13]){
		//マウスの位置からマップ座標を計算し、代入
		int mapX = (mouseX02 - Board_X) / 64;
		int mapY = (mouseY02 - Board_Y) / 64;

		//兵士選択
		if (mapX == -3 && mapY == 0){
			colt_select_2p = 11;
		}
		if (mapX == -3 && mapY == 1){
			colt_select_2p = 12;
		}
		if (mapX == -3 && mapY == 2){
			colt_select_2p = 13;
		}
		//光る場所の初期化(塗る用)
		if ((colt_select_2p != 14) && (colt_select_2p != 15)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata4[i][j] = 0;
				}
			}
		}
		//光る場所の初期化(消す用)
		if ((colt_select_2p != 15)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata5[i][j] = 0;
				}
			}
		}
		//2p兵士1の1の初期化(塗る用)
		if ((BlueTimeFlag11 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata21[i][j] = 0;
				}
			}
		}
		//2p兵士1の2の初期化(塗る用)
		if ((BlueTimeFlag12 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata22[i][j] = 0;
				}
			}
		}
		//2p兵士1の3の初期化(塗る用)
		if ((BlueTimeFlag13 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata23[i][j] = 0;
				}
			}
		}
		//2p兵士3の1の初期化(塗る用)
		if ((BlueTimeFlag15 == 0)){
			for (int i = 0; i < MapMaxX; i++){
				for (int j = 0; j < MapMaxY; j++){
					mapdata25[i][j] = 0;
				}
			}
		}
		if ((mapX < 0 || mapX < MapMaxX) && (mapY < 0 || mapY < MapMaxY)){
			//相手の色があるところには置けない
			if (mapdata[mapX][mapY] == 0 || mapdata[mapX][mapY] == 2){
				if (colt_select_2p == 12){
					TestSecondBlue(mapX, mapY);
				}
			}
			if ((mapdata[mapX][mapY] == 2) || (mapdata[mapX][mapY] == 200)){
				if (colt_select_2p == 11){
					TestFirstBlue(mapX, mapY);
				}
			}
			if (colt_select_2p == 14){
				TestFirstBlue2(mapX, mapY);
			}
			if (mapdata[mapX][mapY] == 2){
				if (colt_select_2p == 13){
					TestThirdBlue(mapX, mapY);
				}
			}
			if (colt_select_2p == 15){
				TestThirdBlue2(mapX, mapY);
			}
			ScoreCheck();
		}
	}
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			mapdata5[i][j] = 0;
		}
	}



	//ボードと色の表示
	Board_draw();

	//コマ①使用時その場コマ表示
	if (colt_select_1p == 4){
		//DrawGraph((test1 * 64) + Board_X, (test2 * 64) + Board_Y, unit_1[0], true);
		//DrawGraph((test1 * 64) + Board_X, (test2 * 64) + Board_Y, colt1.anime_gh[colt1.CurFrame], true);

		colt1[t].mapx = ArrivalPoint_1p_1x; colt1[t].mapy = ArrivalPoint_1p_1y;
		//colt1[t].active = 1;
	}

	if (colt_select_2p == 14){

		colt1_2[t].mapx = ArrivalPoint_2p_1x; colt1_2[t].mapy = ArrivalPoint_2p_1y;
	}

	//colt1[t].mapx = 11; colt1[t].mapy = 8;

	//colt1[t].active = 1;

	//光るマップの表示(塗り用)
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata2[i][j]){
			case 1:
				if (colt_select_1p == 4 || colt_select_1p == 5)
					//ここでコマの画像を表示させる場合

					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				break;
			}
		}
	}

	//光るマップの表示(消す用)
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata3[i][j]){
			case 1:
				if (colt_select_1p == 5)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				break;
			}
		}
	}

	//光るマップの表示(塗り用)青用
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata4[i][j]){
			case 2:
				if (colt_select_2p == 14 || colt_select_2p == 15)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				break;
			}
		}
	}

	//光るマップの表示(消す用)青用
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata5[i][j]){
			case 2:
				if (colt_select_2p == 15)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				break;
			}
		}
	}

	//塗り確定時（赤 1-1）点滅
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata11[i][j]){
			case 1:
				if (RedTimeFlag11 == 1){
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
					if (colt1[t].mapy < moveto_y) {
						Colt1_move1p_down();
					}
					else if (colt1[t].mapx > moveto_x){
						Colt1_move1p_left();
					}
					else if (colt1[t].mapx < moveto_x){
						Colt1_move1p_right();
					}
					else if (colt1[t].mapy > moveto_y){
						Colt1_move1p_up();
					}
				}
				break;
			}
		}
	}
	//塗り確定時（赤 1-2）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata12[i][j]){
			case 1:
				if (RedTimeFlag12 == 1){
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
					if (colt1[t].mapy < moveto_y2) {
						Colt1_move1p_down();
					}
					else if (colt1[t].mapx > moveto_x2){
						Colt1_move1p_left();
					}
					else if (colt1[t].mapx < moveto_x2){
						Colt1_move1p_right();
					}
					else if (colt1[t].mapy > moveto_y2){
						Colt1_move1p_up();
					}
				}
				break;
			}
		}
	}
	//塗り確定時（赤 1-3）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata13[i][j]){
			case 1:
				if (RedTimeFlag13 == 1){
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[1], true);
					if (colt1[t].mapy < moveto_y3) {
						Colt1_move1p_down();
					}
					else if (colt1[t].mapx > moveto_x3){
						Colt1_move1p_left();
					}
					else if (colt1[t].mapx < moveto_x3){
						Colt1_move1p_right();
					}
					else if (colt1[t].mapy > moveto_y3){
						Colt1_move1p_up();
					}
				}
				break;
			}
		}
	}
	//塗る確定時（赤 3-1）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata15[i][j]){
			case 1:
				if (RedTimeFlag15 == 1)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[1], true);
				break;
			}
		}
	}
	//塗り確定時（青 1-1）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata21[i][j]){
			case 1:
				if (BlueTimeFlag11 == 1){
					//↓ここ画像する
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
					if (colt1_2[t].mapy < moveto2_y) {
						Colt1_move2p_down();
					}
					else if (colt1_2[t].mapx > moveto2_x){
						Colt1_move2p_left();
					}
					else if (colt1_2[t].mapx < moveto2_x){
						Colt1_move2p_right();
					}
					else if (colt1_2[t].mapy > moveto2_y){
						Colt1_move2p_up();
					}
				}
				break;
			}
		}
	}



	//塗り確定時（青　1-2）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata22[i][j]){
			case 1:
				if (BlueTimeFlag12 == 1)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				if (colt1_2[t].mapy < moveto2_y) {
					Colt1_move2p_down();
				}
				else if (colt1_2[t].mapx > moveto2_x){
					Colt1_move2p_left();
				}
				else if (colt1_2[t].mapx < moveto2_x){
					Colt1_move2p_right();
				}
				else if (colt1_2[t].mapy > moveto2_y){
					Colt1_move2p_up();
				}
			}
			break;
		}
	}

	//塗り確定時（青　1-3）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata23[i][j]){
			case 1:
				if (BlueTimeFlag13 == 1)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				if (colt1_2[t].mapy < moveto2_y) {
					Colt1_move2p_down();
				}
				else if (colt1_2[t].mapx > moveto2_x){
					Colt1_move2p_left();
				}
				else if (colt1_2[t].mapx < moveto2_x){
					Colt1_move2p_right();
				}
				else if (colt1_2[t].mapy > moveto2_y){
					Colt1_move2p_up();
				}
			}
			break;
		}
	}
	
	//塗る確定時（青 3-1）
	for (int i = 0; i < MapMaxX; i++){
		for (int j = 0; j < MapMaxY; j++){
			switch (mapdata25[i][j]){
			case 1:
				if (BlueTimeFlag15 == 1)
					DrawGraph((i * 64) + Board_X, (j * 64) + Board_Y, img_pallet2[2], true);
				break;
			}
		}
	}

	//1Pのユニット表示
	if ((testselect2 != 1) && (colt_select_1p != 1)){
		DrawGraph(1104, 20, unit_1[0], true);
		//Colt_Draw();
	}
	else{
		DrawGraph(1104, 20, unit_1[1], true);
	}
	if ((testselect2 != 2) && (colt_select_1p != 2)){
		DrawGraph(1104, 136, unit_1[2], true);
	}
	else{
		DrawGraph(1104, 136, unit_1[3], true);
	}
	if ((testselect2 != 3) && (colt_select_1p != 3)){
		DrawGraph(1104, 252, unit_1[4], true);
	}
	else
	{
		DrawGraph(1104, 252, unit_1[5], true);
	}


	//2Pのユニット表示
	if ((testselect2 != 6) && (colt_select_2p != 11)){
		DrawGraph(80, 20, unit_2[0], true);
	}
	else{
		DrawGraph(80, 20, unit_2[1], true);
	}
	if ((testselect2 != 7) && (colt_select_2p != 12)){
		DrawGraph(80, 136, unit_2[2], true);
	}
	else{
		DrawGraph(80, 136, unit_2[3], true);
	}
	if ((testselect2 != 8) && (colt_select_2p != 13)){
		DrawGraph(80, 252, unit_2[4], true);
	}
	else{
		DrawGraph(80, 252, unit_2[5], true);
	}

	//colt表示
	Colt1_Draw();


	DrawFormatString(545, 50, White, "のこり %d:%02d", GameTime_Minute,GameTime / 60); //文字列表示
	//スコア表示
	DrawFormatString(920, 55, White, "%d", sumred);
	DrawFormatString(340, 55, White, "%d", sumblue);
	

	//DrawFormatString(0, 0, White, "select %d", colt_select_1p);
	//DrawFormatString(0, 30, White, "select2 %d",colt_select_2p);
	
	//DrawFormatString(0, 150,White,"mx:%dmy%d",moveto_x,moveto_y); //文字列表示
	//DrawFormatString(0, 200, White, "mx:%dmy%d", moveto_x2, moveto_y2); //文字列表示
	//DrawFormatString(0, 250, White, "mx:%dmy%d", moveto_x3, moveto_y3); //文字列表示


}

