//���[�� 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "CharaSelect.h"
#include "Controller.h"

int selectBG_gh;

//�Ԃ�����
int LRRHselect_gh,LRRHdecide_gh;
//����P
int SWselect_gh,SWdecide_gh;

//OK�e�L�X�g�̊֐�
int OK_Text[2];

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
	LRRHselect_gh = LoadGraph("select_img\\LRRH_select.png");
	SWselect_gh = LoadGraph("select_img\\SW_select.png");
	LRRHdecide_gh = LoadGraph("select_img\\LRRH_Decide.png");
	SWdecide_gh = LoadGraph("select_img\\SW_Decide.png");
	
	//OK�e�L�X�g�̉摜
	OK_Text[0] = LoadGraph("select_img\\OK_Text1.png");
	OK_Text[1] = LoadGraph("select_img\\OK_Text2.png");

	//�������O���t
	score_init_flag = 1;

	Redy_flag_1p = 0;
	Redy_flag_2p = 0;
	key_enter2 = 0;
}

void ChaarSelect_delete(void){

	DeleteGraph(LRRHselect_gh);
	DeleteGraph(SWselect_gh);

}


void CharaSelect_Draw(void){

	//�܂����������Ă��Ȃ��Ƃ��͏���������������
	if (!score_init_flag){
		Score_Init();
	}

	//�w�i�`��
	DrawGraph(0, 0, selectBG_gh, TRUE);
	if (Redy_flag_1p){
		DeleteGraph(LRRHselect_gh);
		DrawGraph(0, 0, LRRHdecide_gh, TRUE);
	}
	if (Redy_flag_2p){
		DeleteGraph(SWselect_gh);
		DrawGraph(0, 0, SWdecide_gh, TRUE);
	}

	DrawGraph(0, 0, LRRHselect_gh, TRUE);
	DrawGraph(0, 0, SWselect_gh, TRUE);


	//OK�e�L�X�g�̕\��
	DrawGraph(0, 0, OK_Text[GetNowCount() / 1200 % 2], TRUE);

	//Enter�Ń^�C�g����
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[4]) {
		if (key_enter == 0){
			Redy_flag_1p = 1;
			key_enter = 1;

			//2P������OK�ł͂Ȃ�������ŏ��̉���炷
			if (!Redy_flag_2p){
				PlaySoundFile("sound\\Decide01.mp3", DX_PLAYTYPE_BACK);
			}
			//����OK���������̉���炷
			else{
				PlaySoundFile("sound\\Decide02.mp3", DX_PLAYTYPE_BACK);
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