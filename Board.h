#define MapMaxX 12
#define MapMaxY 9

#define MAP_SIZE 64

extern int mapdata[MapMaxX][MapMaxY];//�`��p�}�b�v
extern int mapdata2[MapMaxX][MapMaxY];//����ԗp
extern int mapdata3[MapMaxX][MapMaxY];//�����ԗp
extern int mapdata4[MapMaxX][MapMaxY];//����p
extern int mapdata5[MapMaxX][MapMaxY];//�����p
extern int mapdata6[MapMaxX][MapMaxY];//�`�F�b�N���`��

extern int mapdata11[MapMaxX][MapMaxY];//1p���m1��1�@�e�R�}�̍s���ׂ��}�b�v�f�[�^
extern int mapdata12[MapMaxX][MapMaxY];//1p���m1��2
extern int mapdata13[MapMaxX][MapMaxY];//1p���m1��3
extern int mapdata15[MapMaxX][MapMaxY];//1p���m3��1
extern int mapdata16[MapMaxX][MapMaxY];//1p���m3��2

extern int mapdata21[MapMaxX][MapMaxY];//2p���m1��1
extern int mapdata22[MapMaxX][MapMaxY];//2p���m1��2
extern int mapdata23[MapMaxX][MapMaxY];//2p���m1��3
extern int mapdata25[MapMaxX][MapMaxY];//2p���m3��1
extern int mapdata26[MapMaxX][MapMaxY];//2p���m3��2


void Board_init(void);
void Board_draw(void);