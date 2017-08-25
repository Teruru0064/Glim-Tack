#define MapMaxX 12
#define MapMaxY 9

#define MAP_SIZE 64

extern int mapdata[MapMaxX][MapMaxY];//描画用マップ
extern int mapdata2[MapMaxX][MapMaxY];//光る赤用
extern int mapdata3[MapMaxX][MapMaxY];//消す赤用
extern int mapdata4[MapMaxX][MapMaxY];//光る青用
extern int mapdata5[MapMaxX][MapMaxY];//消す青用
extern int mapdata6[MapMaxX][MapMaxY];//チェック裏描画

extern int mapdata11[MapMaxX][MapMaxY];//1p兵士1の1　各コマの行くべきマップデータ
extern int mapdata12[MapMaxX][MapMaxY];//1p兵士1の2
extern int mapdata13[MapMaxX][MapMaxY];//1p兵士1の3
extern int mapdata15[MapMaxX][MapMaxY];//1p兵士3の1
extern int mapdata16[MapMaxX][MapMaxY];//1p兵士3の2

extern int mapdata21[MapMaxX][MapMaxY];//2p兵士1の1
extern int mapdata22[MapMaxX][MapMaxY];//2p兵士1の2
extern int mapdata23[MapMaxX][MapMaxY];//2p兵士1の3
extern int mapdata25[MapMaxX][MapMaxY];//2p兵士3の1
extern int mapdata26[MapMaxX][MapMaxY];//2p兵士3の2


void Board_init(void);
void Board_draw(void);