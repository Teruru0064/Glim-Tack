struct Coltgame_obj{

	int x, y;

	int scene1x, scene1y;
	int world_x, world_y;
	int gh;
	int anime_gh[12];
	int active;
	int width, height;
	int speed;
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


	
	int mapx, mapy;

	int AnimStart;
	int AnimEnd;
	int AnimSpeed;

	int little;
};


////////////////ƒRƒ}‡@//////////////////////
void Colt1_Draw(void);
void Colt1_init(void);
void Colt1_Update(void);
void Colt1_move1p_down(void);
void Colt1_move1p_left(void);
void Colt1_move1p_right(void);
void Colt1_move1p_up(void);
void Colt1_move2p_down(void);
void Colt1_move2p_left(void);
void Colt1_move2p_right(void);
void Colt1_move2p_up(void);
////////////////////////////////////////////

////////////////ƒRƒ}‡A//////////////////////
void Colt2_Draw(void);
void Colt2_init(void);
void Colt2_Update(void);
void Colt2_move1p_down(void);
void Colt2_move1p_left(void);
void Colt2_move1p_right(void);
void Colt2_move1p_up(void);
void Colt2_move2p_down(void);
void Colt2_move2p_left(void);
void Colt2_move2p_right(void);
void Colt2_move2p_up(void);
////////////////////////////////////////////

////////////////ƒRƒ}‡B//////////////////////
void Colt3_Draw(void);
void Colt3_init(void);
void Colt3_Update(void);
void Colt3_move1p_down(void);
void Colt3_move1p_left(void);
void Colt3_move1p_right(void);
void Colt3_move1p_up(void);
void Colt3_move2p_down(void);
void Colt3_move2p_left(void);
void Colt3_move2p_right(void);
void Colt3_move2p_up(void);
////////////////////////////////////////////