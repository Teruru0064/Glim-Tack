//各キャラのユニット表示　8/28追加

#include "DxLib.h"
#include "GameInit.h"
#include "Colt.h"

//1pの選択状態 1はコマ�@を選択中 2はコマ�Aを選択中 3はコマ�Bを選択中
extern int colt_select_1p;
//２pの選択状態 11はコマ�@を選択中 12はコマ�Aを選択中 13はコマ�Bを選択中
extern int colt_select_2p;


//赤ずきん用
int RedHood_unit[6];
//白雪姫用
int SnowWhite_unit[6];



//イメージロード
void Unit_Init(void){

	LoadDivGraph("colt_img/LittleRedRidingHood_Unit.png", 6, 2, 3, 96, 96, RedHood_unit);
	LoadDivGraph("colt_img/SnowWhite_Unit.png", 6, 2, 3, 96, 96, SnowWhite_unit);

}



//赤ずきんのユニット表示
void RedHood_Unit_Draw(void){

	if (colt_select_1p != 1){
		DrawGraph(1104, 20, RedHood_unit[0], true);
	}
	else{
		DrawGraph(1104, 20, RedHood_unit[1], true);
	}
	if (colt_select_1p != 2){
		DrawGraph(1104, 136, RedHood_unit[2], true);
	}
	else{
		DrawGraph(1104, 136, RedHood_unit[3], true);
	}
	if (colt_select_1p != 3){
		DrawGraph(1104, 252, RedHood_unit[4], true);
	}
	else{
		DrawGraph(1104, 252, RedHood_unit[5], true);
	}
}


//白雪姫のユニット表示
void SnowWhite_Unit_Draw(void){

	if (colt_select_2p != 11){
		DrawGraph(80, 20, SnowWhite_unit[0], true);
	}
	else{
		DrawGraph(80, 20, SnowWhite_unit[1], true);
	}
	if (colt_select_2p != 12){
		DrawGraph(80, 136, SnowWhite_unit[2], true);
	}
	else{
		DrawGraph(80, 136, SnowWhite_unit[3], true);
	}
	if (colt_select_2p != 13){
		DrawGraph(80, 252, SnowWhite_unit[4], true);
	}
	else{
		DrawGraph(80, 252, SnowWhite_unit[5], true);
	}
}