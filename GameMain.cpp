#include "GameInit.h" 

//�O���[�o���ϐ�
int game_status = TITLE;
int key_enter = 0;
char KeyBuf[256];

// WinMain�֐�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{

	//�Q�[������������
	game_init();

	//���C�����[�v
	while (game_status!=GAMEEND)
	{
		// ��ʂɕ`����Ă�����̂����S������
		ClearDrawScreen();

		//�X�e�[�^�X�ɉ�������������
		switch (game_status){

		case TITLE:
			Title_set();
			break;
		case CHARASELECT:
			CharaSelect_set();
			break;
		case GAMEMAIN:
			TestScene_set();
			break;
		case SCORE:
			Score_set();
			break;


		}


		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1) break;

		// �d�r�b�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;

	}

	// �c�w���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}
