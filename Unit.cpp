//各キャラのユニット表示　8/28追加

#include "DxLib.h"
#include "GameInit.h"
#include "Colt.h"

//1pの選択状態 1はコマ①を選択中 2はコマ②を選択中 3はコマ③を選択中
extern int colt_select_1p;
//２pの選択状態 11はコマ①を選択中 12はコマ②を選択中 13はコマ③を選択中
extern int colt_select_2p;


//赤ずきん用
int RedHood_unit[6];
//白雪姫用
int SnowWhite_unit[6];

//1Pと2Pのユニット位置
int UnitSet_1p = 80, UnitSet_2p = 1104;
//ユニット使用可能時点灯
//01はコマ①、02はコマ②、03はコマ③
int Unit01 = 20, Unit02 = 136, Unit03 = 252;




//イメージロード
void Unit_Init(void){

	LoadDivGraph("colt_img/LittleRedRidingHood_Unit.png", 6, 2, 3, 96, 96, RedHood_unit);
	LoadDivGraph("colt_img/SnowWhite_Unit.png", 6, 2, 3, 96, 96, SnowWhite_unit);

}


//赤ずきんのユニット表示
void RedHood_Unit_Draw(void){

	if (colt_select_1p != 1){
		DrawGraph(UnitSet_1p, Unit01, RedHood_unit[0], true);
	}
	else{
		DrawGraph(UnitSet_1p, Unit01, RedHood_unit[1], true);
	}
	if (colt_select_1p != 2){
		DrawGraph(UnitSet_1p, Unit02, RedHood_unit[2], true);
	}
	else{
		DrawGraph(UnitSet_1p, Unit02, RedHood_unit[3], true);
	}
	if (colt_select_1p != 3){
		DrawGraph(UnitSet_1p, Unit03, RedHood_unit[4], true);
	}
	else{
		DrawGraph(UnitSet_1p, Unit03, RedHood_unit[5], true);
	}
}


//白雪姫のユニット表示
void SnowWhite_Unit_Draw(void){

	if (colt_select_2p != 11){
		DrawGraph(UnitSet_2p, Unit01, SnowWhite_unit[0], true);
	}
	else{
		DrawGraph(UnitSet_2p, Unit01, SnowWhite_unit[1], true);
	}
	if (colt_select_2p != 12){
		DrawGraph(UnitSet_2p, Unit02, SnowWhite_unit[2], true);
	}
	else{
		DrawGraph(UnitSet_2p, Unit02, SnowWhite_unit[3], true);
	}
	if (colt_select_2p != 13){
		DrawGraph(UnitSet_2p, Unit03, SnowWhite_unit[4], true);
	}
	else{
		DrawGraph(UnitSet_2p, Unit03, SnowWhite_unit[5], true);
	}
}