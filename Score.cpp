#include "DxLib.h"
#include "GameInit.h"
#include "Score.h"

extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;
extern int ScoreStart;


//�R���g���[���[���g�p���邽�߂̊֐�
extern XINPUT_STATE XInputState1, XInputState2;
extern int InputState1, InputState2;


//�X�R�A�p�ϐ�
extern int sumscore_1p;		//�v���C���[�P�X�R�A
extern int sumscore_2p;		//�v���C���[�Q�X�R�A

//�v���C���[�J���[(01��1P�A02��2P)
int color_01,color_02;


//�L�����N�^�[�̃O���t�B�b�N�n���h��

//����P(00�͑ҋ@���A01�͏����A02�͕����A03�͈�������)
int SW00_gh, SW01_gh, SW02_gh, SW03_gh;
//�Ԃ�����(00�͑ҋ@���A01�͏����A02�͕����A03�͈�������)
int LRRH00_gh, LRRH01_gh, LRRH02_gh, LRRH03_gh;
/*
//�w���[���ƃO���[�e��(00�͑ҋ@���A01�͏����A02�͕����A03�͈�������)
int HaG00_gh, HaG01_gh, HaG02_gh, HaG03_gh;
//���v���c�F��(00�͑ҋ@���A01�͏����A02�͕����A03�͈�������)
int Rap00_gh, Rap01_gh, Rap02_gh, Rap03_gh;
*/

//�X�R�A�w�i
int score_BG_gh;
//vs�̃O���t�B�b�N�n���h��
int vs_gh;
//�{�^��
int button_gh[2];

//���s���ʂ̃e�L�X�g(�����A�����A��������)
int win_gh, lose_gh, draw_gh;

//���s����(�e�L�X�g)��X���W
int TextX_1p = 164;
int TextX_2p = 800;
//��������(�e�L�X�g)��X���W
int TextdrawX = 417;
//���s����(�e�L�X�g)��Y���W
int TextY = 65;


//�������t���O
static int score_init_flag = 0;

void Score_Init(void){

	//�摜�̓ǂݍ���
	score_BG_gh = LoadGraph("score_img\\Score_BG.png");
	vs_gh = LoadGraph("score_img\\vs.png");
	win_gh = LoadGraph("score_img\\win.png");
	lose_gh = LoadGraph("score_img\\lose.png");
	draw_gh = LoadGraph("score_img\\draw.png");
	button_gh[0] = LoadGraph("score_img\\button_01.png");
	button_gh[1] = LoadGraph("score_img\\button_02.png");
	//����P
	SW00_gh = LoadGraph("score_img\\SnowWhite_Stay.png");
	SW01_gh = LoadGraph("score_img\\SnowWhite_Win.png");
	SW02_gh = LoadGraph("score_img\\SnowWhite_Lose.png");
	SW03_gh = LoadGraph("score_img\\SnowWhite_Draw.png");
	//�Ԃ�����
	LRRH00_gh = LoadGraph("score_img\\LRRH_Stay.png");
	LRRH01_gh = LoadGraph("score_img\\LRRH_Win.png");
	LRRH02_gh = LoadGraph("score_img\\LRRH_Lose.png");
	LRRH03_gh = LoadGraph("score_img\\LRRH_Draw.png");
	/*
	//�w���[���ƃO���[�e��
	HaG00_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG01_gh = LoadGraph("score_img\\H and G_Score01.png");
	HaG02_gh = LoadGraph("score_img\\H and G_Score02.png");
	HaG03_gh = LoadGraph("score_img\\H and G_Score03.png");
	//���v���c�F��
	Rap00_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap01_gh = LoadGraph("score_img\\Rapunzel_Score01.png");
	Rap02_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	Rap03_gh = LoadGraph("score_img\\Rapunzel_Score02.png");
	*/
	

	color_01 = GetColor(245, 57, 77);	//�ԐF
	color_02 = GetColor(45, 135, 246);	//�F



	//�������O���t
	score_init_flag = 1;
}


//��������(���ׂẲ摜)
void Score_Delete(void){

	DeleteGraph(score_BG_gh);
	DeleteGraph(vs_gh);
	DeleteGraph(button_gh[0]);
	DeleteGraph(button_gh[1]);
	DeleteGraph(win_gh);
	DeleteGraph(lose_gh);
	DeleteGraph(draw_gh);

	//�Ԃ�����
	DeleteGraph(LRRH00_gh);
	DeleteGraph(LRRH01_gh);
	DeleteGraph(LRRH02_gh);
	DeleteGraph(LRRH03_gh);

	//����P
	DeleteGraph(SW00_gh);
	DeleteGraph(SW01_gh);
	DeleteGraph(SW02_gh);
	DeleteGraph(SW03_gh);
}

//��������(�ҋ@��Ԃ̃L�����N�^�[�̂�)
	void ScoreChara_Delete(void){
		//�Ԃ�����
		DeleteGraph(LRRH00_gh);
		//����P
		DeleteGraph(SW00_gh);

	}


void Score_Draw(void){

	//�܂����������Ă��Ȃ��Ƃ��͏���������������
	if (!score_init_flag){
		Score_Init();
	}

	//�w�i�`��
	DrawGraph(0, 0, score_BG_gh, TRUE);
	//�Q�[���I�����̔Ֆʂ�\��
	Board_draw();
	//�L�����N�^�[�`��
	DrawGraph(92, 243, LRRH00_gh, TRUE);
	DrawTurnGraph(866, 238, SW00_gh, TRUE);
	//UI�̕`��
	DrawGraph(579, 319, vs_gh, TRUE);

	//�����ݒ�

	//�T�C�Y�ݒ�
	SetFontSize(80);
	//�t�H���g�ݒ�
	ChangeFont("mini-�킭�킭");


	//���s�̏o��

	//�X�R�A��ʂɃV�[���؂�ւ�����4�b��ɕ\��
	if (GetNowCount() - ScoreStart > 4000){
		//1P�̃X�R�A��2P��荂��������1P�Ɂu�����v2P�Ɂu�܂��v��\��
		if (sumscore_1p > sumscore_2p){
			//����
			DrawGraph(TextX_1p, TextY, win_gh, TRUE);
			//����
			DrawGraph(TextX_2p, TextY, lose_gh, TRUE);
			//���s���ʂ��o��1�b��ɃL�����N�^�[��\��
			if (GetNowCount() - ScoreStart > 5000){
				//�ҋ@���̃L�����N�^�[���폜
				ScoreChara_Delete();
				//1P��2P�̃L�����N�^�[�\��

				//1P����
				DrawGraph(-70, 254, LRRH01_gh, TRUE);
				//2P����(���]�`��)
				DrawTurnGraph(938, 332, SW02_gh, TRUE);
			}
		}
		//1P�̃X�R�A��2P���Ⴉ������1P�Ɂu�܂��v2P�Ɂu�����v��\��
		else if (sumscore_1p < sumscore_2p){
			//����
			DrawGraph(TextX_2p, TextY, lose_gh, TRUE);
			//����
			DrawGraph(TextX_1p, TextY, win_gh, TRUE);
			//���s���ʂ��o��1�b��ɃL�����N�^�[��\��
			if (GetNowCount() - ScoreStart > 5000){
				//�ҋ@���̃L�����N�^�[���폜
				ScoreChara_Delete();

				//1P��2P�̃L�����N�^�[�\��

				//1P����
				DrawGraph(147, 346, LRRH02_gh, TRUE);
				//2P����
				DrawTurnGraph(850, 212, SW01_gh, TRUE);
			}
		}
		//1P��2P�̃X�R�A�������Ȃ�΁u�Ђ��킯�v��\��
		else if (sumscore_1p == sumscore_1p){
			//��������
			DrawGraph(TextdrawX, TextY, draw_gh, TRUE);
			//���s���ʂ��o��1�b��ɃL�����N�^�[��\��
			if (GetNowCount() - ScoreStart > 5000){
				//�ҋ@���̃L�����N�^�[���폜
				ScoreChara_Delete();

				//1P��2P�̃L�����N�^�[�\��(��������)
				DrawGraph(138, 263, LRRH03_gh, TRUE);
				DrawTurnGraph(908, 233, SW03_gh, TRUE);
			}
		}
	}

	//�X�R�A�\��

	//�R�P�^�̐������P�b�ԃ����_���ɕ\��������
	if (GetNowCount() - ScoreStart < 1000){
		DrawFormatString(400, 320, color_01, "%03d", GetRand(999));
		DrawFormatString(710, 320, color_02, "%03d", GetRand(999));
	}
	//�P�P�^�ڐ�����1�b��ɕ\��������
	else if (GetNowCount() - ScoreStart < 2000){
		DrawFormatString(400, 320, color_01, "%03d", GetRand(99) * 10 + sumscore_1p % 10);
		DrawFormatString(710, 320, color_02, "%03d", GetRand(99) * 10 + sumscore_2p % 10);
	}
	//�Q�P�^�ڐ�����2�b��ɕ\��������
	else if (GetNowCount() - ScoreStart < 3000){
		DrawFormatString(400, 320, color_01, "%03d", GetRand(9) * 100 + sumscore_1p % 100);
		DrawFormatString(710, 320, color_02, "%03d", GetRand(9) * 100 + sumscore_2p % 100);
	}
	else{
		//1P��2P�̃X�R�A�S�\��
		DrawFormatString(400, 320, color_01, "%03d", sumscore_1p);
		DrawFormatString(710, 320, color_02, "%03d", sumscore_2p);
	}

	//�X�R�A��ʂɃV�[���؂�ւ�����6�b��Ƀ{�^���̕\��
	if (GetNowCount() - ScoreStart > 6000){
		//�{�^���̕\��
		DrawGraph(449, 588, button_gh[GetNowCount() / 500 % 2], TRUE);
		//�PP�R���g���[���[�Z�b�g
		GetJoypadXInputState(DX_INPUT_PAD1, &XInputState1);
		//Enter�Ń^�C�g����
		if (CheckHitKey(KEY_INPUT_RETURN) == 1 || XInputState1.Buttons[13]) {
			if (key_enter == 0){
				game_status = TITLE;
				ScoreChara_Delete();
				key_enter = 1;
				Test_init();
				//Title_init();
			}
		}
		else{
			key_enter = 0;
		}
	}
}