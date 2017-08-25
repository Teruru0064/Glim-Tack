//���[�� 5/29
#include "DxLib.h"
#include "GameInit.h"
#include "Score.h"

int score_gh;
extern char KeyBuf[];
extern int key_enter;
extern int return_sh;
extern int game_status;
extern int GameTime;

//�������t���O
static int score_init_flag = 0;

void Score_init(void){
	//�摜�̓ǂݍ���
	score_gh = LoadGraph("game_img\\Score.png");
	//�������O���t
	score_init_flag = 1;
}

void Score_delete(void){
	DeleteGraph(score_gh);
}

void Score(void){
	//�܂����������Ă��Ȃ��Ƃ��͏���������������
	if (!score_init_flag){
		Score_init();
	}
	//�w�i�`��
	DrawGraph(0, 0, score_gh, TRUE);

	//Enter�Ń^�C�g����
	if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
		if (key_enter == 0){
			game_status = TITLE;
			GameTime = 6 * 60;
			key_enter = 1;
		}
	}
	else{
		key_enter = 0;
	}
			
}