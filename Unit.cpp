//�e�L�����̃��j�b�g�\���@8/28�ǉ�

#include "DxLib.h"
#include "GameInit.h"
#include "Colt.h"

//1p�̑I����� 1�̓R�}�@��I�� 2�̓R�}�A��I�� 3�̓R�}�B��I��
extern int colt_select_1p;
//�Qp�̑I����� 11�̓R�}�@��I�� 12�̓R�}�A��I�� 13�̓R�}�B��I��
extern int colt_select_2p;


//�Ԃ�����p
int RedHood_unit[6];
//����P�p
int SnowWhite_unit[6];

//1P��2P�̃��j�b�g�ʒu
int UnitSet_1p = 80, UnitSet_2p = 1104;
//���j�b�g�g�p�\���_��
//01�̓R�}�@�A02�̓R�}�A�A03�̓R�}�B
int Unit01 = 20, Unit02 = 136, Unit03 = 252;




//�C���[�W���[�h
void Unit_Init(void){

	LoadDivGraph("colt_img/LittleRedRidingHood_Unit.png", 6, 2, 3, 96, 96, RedHood_unit);
	LoadDivGraph("colt_img/SnowWhite_Unit.png", 6, 2, 3, 96, 96, SnowWhite_unit);

}


//�Ԃ�����̃��j�b�g�\��
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


//����P�̃��j�b�g�\��
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