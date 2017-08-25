#include "DxLib.h"
#include "Event.h"
#include "map.h"
#include "Player.h"
#include <string.h>

struct EventObj{
	//char msg[255];
	char *msg;
};


struct EventObj Evt[EVENTNUM+1];

int drawpos_x, drawpos_y;
int width, height;
int event_gh;
int eventflg;
int event_no;
unsigned int font_Color;
extern struct game_obj PC;
// �C�x���g�̃f�[�^
int EventData[MAP_HEIGHT][MAP_WIDTH] =
{
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

};

int EventData_BK[MAP_HEIGHT][MAP_WIDTH];
// �C�x���g���b�Z�[�W
char message[EVENTNUM + 1][255] =
{
	"�_�~�[",
	"���̉ʂĂł��B",
	"���̉ʂĂł��B",
	"�������J����B",
};


void Eventinit(void){
	event_gh = LoadGraph("event_img\\frame01.png");
	drawpos_x = 50;
	drawpos_y = 300;
	eventflg = 0;
	font_Color = GetColor(0, 0, 0);

	//strcpy(Evt[1].msg, "���̉ʂĂł��B");
	//strcpy(Evt[2].msg, "���̉ʂĂł��B");
	//strcpy(Evt[3].msg, "�������J����B");
	//Evt[1].msg[] = "���̉ʂĂł��B";
	for (int i = 0; i <= EVENTNUM; i++){
		Evt[i].msg = message[i];
	}
	memcpy(EventData_BK, EventData, sizeof(EventData));

}
void Event_check(void){
	if (EventData[PC.mapy + PC.DirY][PC.mapx + PC.DirX] !=0){
		eventflg= 1;
		event_no = EventData[PC.mapy + PC.DirY][PC.mapx + PC.DirX];
	}
	else{
		eventflg= 0;
	}

}
void EventDraw(void){
	if (eventflg){
		DrawGraph(drawpos_x, drawpos_y, event_gh, TRUE);
		DrawString(drawpos_x+50, drawpos_y+30, Evt[event_no].msg,font_Color,GetColor(255,255,255));
	}
}