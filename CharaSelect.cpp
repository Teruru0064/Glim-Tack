//���[�� 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "CharaSelect.h"
#include "Controller.h"

//int score_gh;
extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;

//�������t���O
static int score_init_flag = 0;

//�R���g���[���[1P�E2P�̃{�^���U�蕪������Ƃ��ɌĂяo���Ȃ��Ƃ����Ȃ��֐�
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;

void CharaSelect_init(void){
	//�摜�̓ǂݍ���
	//score_gh = LoadGraph("game_img\\Score.png");
	//�������O���t
	score_init_flag = 1;
}

void ChaarSelect_delete(void){
	//DeleteGraph(score_gh);
}


//1P�E2P�̃R���g���[���[�̌ďo��
//GetJoypadDirectInputState(InputType1, &DInputState);
//GetJoypadDirectInputState(InputType2, &DInputState);


void CharaSelect(void){
	//�܂����������Ă��Ȃ��Ƃ��͏���������������
	if (!score_init_flag){
		Score_Init();
	}
	//�w�i�`��
	//DrawGraph(0, 0, score_gh, TRUE);

	//Enter�Ń^�C�g����
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[4]) {
		if (key_enter == 0){
			game_status = GAMEMAIN;
			Board_init();
			Test_init();

			key_enter = 1;
		}
	}
	else{
		key_enter = 0;
	}

}