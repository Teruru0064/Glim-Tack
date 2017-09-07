//���[�� 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "CharaSelect.h"
#include "Controller.h"

int selectBG_gh;

//�Ԃ�����
int LRRHselect_gh;
//����P
int SWselect_gh;

extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;
int key_enter2;
//�������t���O
static int score_init_flag = 0;

//����OK�t���O
int Redy_flag_1p,Redy_flag_2p;
int Count_Down = 180;
//�R���g���[���[1P�E2P�̃{�^���U�蕪������Ƃ��ɌĂяo���Ȃ��Ƃ����Ȃ��֐�
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;

void CharaSelect_init(void){
	//�摜�̓ǂݍ���
	selectBG_gh = LoadGraph("select_img\\select_BG.png");
	LRRHselect_gh = LoadGraph("char_img\\LittleRedRidingHood.png");
	SWselect_gh = LoadGraph("char_img\\SnowWhite.png");
	
	//�������O���t
	score_init_flag = 1;

	Redy_flag_1p = 0;
	Redy_flag_2p = 1;
	key_enter2 = 0;
}

void ChaarSelect_delete(void){
	//DeleteGraph(score_gh);
}


//1P�E2P�̃R���g���[���[�̌ďo��
//GetJoypadDirectInputState(InputType1, &DInputState);
//GetJoypadDirectInputState(InputType2, &DInputState);


void CharaSelect_Draw(void){

	//�܂����������Ă��Ȃ��Ƃ��͏���������������
	if (!score_init_flag){
		Score_Init();
	}

	//�w�i�`��
	DrawGraph(0, 0, selectBG_gh, TRUE);
	if (Redy_flag_1p){
		DrawGraph(170, 200, LRRHselect_gh, TRUE);
	}
	if (Redy_flag_2p){
		DrawGraph(800, 200, SWselect_gh, TRUE);
	}

	//Enter�Ń^�C�g����
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[4]) {
		if (key_enter == 0){
			Redy_flag_1p = 1;
			key_enter = 1;

			//2P������OK�ł͂Ȃ�������ŏ��̉���炷
			if (!Redy_flag_2p){
				
			}
			//����OK���������̉���炷
			else{

			}
		}
	}
	else{
		key_enter = 0;
	}

	//if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState2.Buttons[4]) {
	if (XInputState2.Buttons[4]) {
		if (key_enter2 == 0){
			//game_status = GAMEMAIN;
			//Board_init();
			//Test_init();
			Redy_flag_2p = 1;
			key_enter2 = 1;
		}
	}
	else{
		key_enter2 = 0;
	}

	if (Redy_flag_1p && Redy_flag_2p){

		Count_Down -= 1;
		if (Count_Down < 0){
			game_status = GAMEMAIN;
			Board_init();
			Test_init();
		}
	}

}