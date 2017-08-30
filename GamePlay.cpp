#include "DxLib.h"
#include "GameInit.h"
#include "GameStatus.h"
#include "GamePlay.h"
#include "Player.h"
#include "Colt.h"

int play_gh;
extern int game_status;
extern int key_enter;


//�^�C�g�����Đ�����
void Title_set(void){

	Test_init();
	Title_init();
	Title();
	Title_delete();
	GetControllerState();

}

//�L�����N�^�[�V�[�����Đ�����
void CharaSelect_set(void){

	CharaSelect_init();
	CharaSelect();
	GetControllerState();
	DispControllerState();
	DispCursol();

}

//�Q�[����ʂ��Đ�����
void TestScene_set(void){

	TestScene();
	GetControllerState();
	DispCursol();
	menu_input();
	Colt1_Update();
	Colt2_Update();
	FG_Draw();

	

}

//�X�R�A�V�[�����Đ�����
void Score_set(void){

	//Score();
	GetControllerState();
	Score_Draw();

}