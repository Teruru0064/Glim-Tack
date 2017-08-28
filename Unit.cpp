//�e�L�����̃��j�b�g�\���@8/28�ǉ�

#include "DxLib.h"
#include "GameStatus.h"
#include "Player.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Colt.h"



//unit1�͐Ԃ�����p�Aunit2�͔���p
//int unit_1[6], unit_2[6];




//1p�̑I����� 1�̓R�}�@��I�� 2�̓R�}�A��I�� 3�̓R�}�B��I��
extern int colt_select_1p;
//�Qp�̑I����� 11�̓R�}�@��I�� 12�̓R�}�A��I�� 13�̓R�}�B��I��
extern int colt_select_2p;


//�Ԃ�����p
int RedHood_unit[6];
//����P�p
int SnowWhite_unit[6];



//�C���[�W���[�h
void Unit_Init(void){

	////�Q�[�����n�܂����Ƃ��ɃR�}1��I���������
	//colt_select_1p = 1;
	//colt_select_2p = 11;

	LoadDivGraph("colt_img/LittleRedRidingHood_Unit.png", 96, 2, 3, 96, 96, RedHood_unit);
	LoadDivGraph("colt_img/SnowWhite_Unit.png", 96, 2, 3, 96, 96, SnowWhite_unit);

}



//�Ԃ�����̃��j�b�g�\��
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


//����P�̃��j�b�g�\��
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