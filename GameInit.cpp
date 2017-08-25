#include "GameInit.h"
#include "Game_Info.h"
#include "Controller.h"
#include "Colt.h"

 int game_init(void){
	// �E�C���h�E���[�h�ɕύX
	 SetGraphMode(WINDOW_WIGHT, WINDOW_HEIGHT, 32);
	ChangeWindowMode(TRUE);
	//�E�B���h�E���T�C�Y�ݒ�
	SetWindowSizeChangeEnableFlag(true);
	//�E�B���h�E�^�C�g��
	SetMainWindowText("SampleGame");

	//�w�i�F�ݒ�
	//SetBackgroundColor(0, 0, 0);
	// �c�w���C�u��������������
	if (DxLib_Init() == -1) return -1;

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);
	//�}�E�X�̔�\��
	SetMouseDispFlag(FALSE);

	Controller_Init();
	//colt������
	Colt1_init();
	
	return 0;
}