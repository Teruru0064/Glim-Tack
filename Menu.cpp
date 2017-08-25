#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
#include "GameInit.h"

extern char KeyBuf[];
extern int game_status;
int zkeyflag = 0;
int menu_flg = 0;
extern int menu;

void menu_init(void){


}

void menu_input(void){
	GetHitKeyStateAll(KeyBuf);
	if (KeyBuf[KEY_INPUT_Z]){
		if (!zkeyflag){
			if (!menu_flg){
				menu_flg = 1;
			}
			else{
				switch (menu){
				case 0:
					zkeyflag = 0;
					break;
				case 1:
					menu_flg = 0;
					break;
				case 2:
					menu_flg = 0;
					break;

				}

			}
			zkeyflag = 1;
		}

	}
	else{
		zkeyflag = 0;
	}


}
