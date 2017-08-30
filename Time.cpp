#include "DxLib.h"
#include "GameInit.h"
#include "Game_Info.h"
#include "Time.h"

extern int game_status;

//�������Ԃ����
int GameTime;
int GameTime_Minute;	//���\���p

//���j���[��ʂ̃t���O
extern int menu_flg;

void Time_Init(void){

	//�Q�[���̐�������
	GameTime = 20 * 60;
	GameTime_Minute = 0;

}

void Time_Update(void){

	//�Q�[���N�����͎��Ԃ�����������
	//�Q�[���I��
	if (!menu_flg)GameTime--;

	if (GameTime == 0 && GameTime_Minute == 0) {
		game_status = SCORE;
	}

	if (GameTime <= 0){
		GameTime = 60 * 60;
		--GameTime_Minute;
	}

	//�Q�[���^�C���\��
	DrawFormatString(545, 50, GetColor(255, 255, 255), "�̂��� %d:%02d", GameTime_Minute, GameTime / 60);

}