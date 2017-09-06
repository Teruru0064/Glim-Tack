#include "DxLib.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Time.h"

extern int game_status;

//�������Ԃ����
int GameTime;
int GameTime_Minute;	//���\���p
int nonanim = 0;
//���j���[��ʂ̃t���O
extern int menu_flg;

//����`���`�̃O���t�B�b�N�n���h��
int End_gh;
int text_x ;

//�X�R�A��ʂ̊J�n����
int ScoreStart;

void Time_Init(void){
	//�C���[�W���[�h
	End_gh = LoadGraph("game_img\\end.png");

	//�Q�[���̐�������
	GameTime = 5 * 60;
	GameTime_Minute = 0;
	text_x = 1280;
}

void Time_Update(void){

	//�Q�[���N�����͎��Ԃ�����������
	//�Q�[���I��
	if (!menu_flg && !(GameTime_Minute == 0 && GameTime==0))GameTime--;

	if (GameTime == 0 && GameTime_Minute == 0) {

		//game_status = SCORE;
		//����`���`�̕\��
		DrawGraph(text_x, 200, End_gh, TRUE);
		text_x -= 12;
		if (text_x < -1700) game_status = SCORE;
			nonanim = 1;
			ScoreStart = GetNowCount();
	}
	else{
		nonanim = 0;
	}

	if (GameTime <= 0 && GameTime_Minute!=0){
		GameTime = 5 * 60;
		--GameTime_Minute;
	}

	//�Q�[���^�C���\��
	DrawFormatString(545, 50, GetColor(255, 255, 255), "�̂��� %d:%02d", GameTime_Minute, GameTime / 60);


	//����`���`�̕\��
	//DrawGraph(0, 200, End_gh, TRUE);
}