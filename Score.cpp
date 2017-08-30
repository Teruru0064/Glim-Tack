#include "DxLib.h"
#include "GameInit.h"
#include "Score.h"

extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;

//�R���g���[���[���g�p���邽�߂̊֐�
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;


//�X�R�A�p�ϐ�
extern int sumred;		//�v���C���[�P�X�R�A
extern int sumblue;		//�v���C���[�Q�X�R�A

extern int White;


//�L�����N�^�[�̃O���t�B�b�N�n���h��

//����P(00�͑ҋ@���A01�͏����A02�͕���)
int SW00_gh, SW01_gh, SW02_gh;
//�Ԃ�����(00�͑ҋ@���A01�͏����A02�͕���)
int LRRH00_gh, LRRH01_gh, LRRH02_gh;
/*
//�w���[���ƃO���[�e��(00�͑ҋ@���A01�͏����A02�͕���)
int HaG00_gh, HaG01_gh, HaG02_gh;
//���v���c�F��(00�͑ҋ@���A01�͏����A02�͕���)
int Rap00_gh, Rap01_gh, Rap02_gh;
*/

//�X�R�A�w�i
int score_BG_gh;

//���s���ʂ̃e�L�X�g�摜(�����A�����A��������)
int win_gh, lose_gh, draw_gh;

//�X�R�A��vs�摜
int vs_gh;
/*
//0�`9�܂ł̐����e�L�X�g
int zero_gh,one_gh, tow_gh, three_gh, four_gh,
	five_gh,six_gh, seven_gh, eight_gh, nine_gh;
*/

//�������t���O
static int score_init_flag = 0;

void Score_init(void){

	//�摜�̓ǂݍ���
	score_BG_gh = LoadGraph("score_img\\Score_BG.png");
	win_gh = LoadGraph("score_img\\win_BG.png");
	lose_gh = LoadGraph("score_img\\lose.png");
	draw_gh = LoadGraph("score_img\\draw.png");
	SW00_gh = LoadGraph("score_img\\SnowWhite_Score01.png");
	//SW01_gh = LoadGraph("score_img\\SnowWhite_Score01.png");
	//SW02_gh = LoadGraph("score_img\\SnowWhite_Score02.png");
	LRRH00_gh = LoadGraph("score_img\\LRRH_Stay.png");
	LRRH01_gh = LoadGraph("score_img\\LRRH_Win.png");
	LRRH02_gh = LoadGraph("score_img\\LRRH_Lose.png");
	/*
	HaG01_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG02_gh = LoadGraph("score_img\\H and G_Score02.png");
	Rap01_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap02_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	*/
	vs_gh = LoadGraph("score_img\\vs.png");
	/*
	zero_gh = LoadGraph("score_img\\zero.png");
	one_gh = LoadGraph("score_img\\one.png");
	tow_gh = LoadGraph("score_img\\tow.png");
	three_gh = LoadGraph("score_img\\three.png");
	four_gh = LoadGraph("score_img\\four.png");
	five_gh = LoadGraph("score_img\\five.png");
	six_gh = LoadGraph("score_img\\six.png");
	seven_gh = LoadGraph("score_img\\seven.png");
	eight_gh = LoadGraph("score_img\\eight.png");
	nine_gh = LoadGraph("score_img\\nine.png");
	*/

	//�������O���t
	score_init_flag = 1;
}

void Score_delete(void){
	DeleteGraph(score_BG_gh);
}

void Score_Draw(void){

	//�܂����������Ă��Ȃ��Ƃ��͏���������������
	if (!score_init_flag){
		Score_init();
	}

	//�w�i�`��
	DrawGraph(0, 0, score_BG_gh, TRUE);
	//�L�����N�^�[�`��
	DrawGraph(333, 352, SW00_gh, TRUE);
	DrawGraph(709, 370, LRRH00_gh, TRUE);
	//UI�̕`��
	DrawGraph(315, 90, win_gh, TRUE);
	DrawGraph(579, 90, lose_gh, TRUE);
	DrawGraph(579, 90, vs_gh, TRUE);


	//�PP�R���g���[���[�Z�b�g
	GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
	//Enter�Ń^�C�g����
	if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {
		if (key_enter == 0){
			game_status = TITLE;
			GameTime = 6 * 60;
			key_enter = 1;
		}
	}
	else{
		key_enter = 0;
	}


	//�X�R�A�\��
	DrawFormatString(920, 55, White, "%d", sumred);
	DrawFormatString(340, 55, White, "%d", sumblue);

}