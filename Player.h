void Player_init(void);
void Player_Input();
void Player_Draw();
void Player_Update(void);
void Player_HitCheck(void);
//int hitcheck(int Ax1, int Ay1, int Aw, int Ah, int Bx1, int By1, int Bw, int Bh);
//int hitcheck2(int Ax1, int Ay1, int Aw, int Ah, float ratio1, int Bx1, int By1, int Bw, int Bh, float ratio2);
int movecheck_R(int x, int y);
int movecheck_L(int x, int y);
int Player_MoveCheck(int MoveX, int MoveY);
void Player_Move(int MoveX, int MoveY);

struct game_obj{
	int x, y;
	int mapx, mapy;
	int scene1x, scene1y;
	int world_x, world_y;
	int gh;
	int anime_gh[96];
	int active;
	int width, height;
	int speed;
	int AnimStart;
	int AnimEnd;
	int AnimSpeed;
	int AnimFrameNum;
	int CurFrame;
	int Turn;
	float JumpPower;
	int damage;
	int hp;
	int state;
	int move;
	int MoveX, MoveY;
	int Enm;
	int DirX, DirY;	//Œü‚«
	int MoveCounter;
	int ScrollX, ScrollY;
	int Scrollmode;
	int menu;
	enum State { Idle, Jump, Fall, STOP };


};