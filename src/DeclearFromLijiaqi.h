#include <cstring>
#include <string>
#include <sstream> 
#pragma pack(1)
using namespace std;
typedef struct BMPheader{
  short  bfType=0x4D42;//"BM"
  int bfSize;//Size of my BMP file
  short  bfReserved1=0;//useless
  short  bfReserved2=0;//useless 2
  int bfOffBits=0x36;//Size of header
} ;
typedef struct BMPINFOHeader {
  int biSize=0x28;//size of infoheader(header2)
  int biWidth;//width of picture
  int biHeight;//height of picture
  short biPlanes=0x1;//"Tu Ceng",1 is ok
  short biBitCount=0x18;//"Se Cai Shen Du",24(18 in HEX) is ok
  int biCompression=0;//Compression , useless
  int biSizeImage;//Size of image(size of file-size of headers)
  int biXPelsPerMeter=0;//Something just like BPI ,useless
  int biYPelsPerMeter=0;//As above ,useless
  int biClrUsed=0;//useless
  int biClrImportant=0;//useless
} ;
typedef struct Pixel{
	char B,G,R;//Blue Green Red
};


void Draw_Robot(int ,int ,int ,int );
void save(const char * );
void auto_save() ;
void Create_Header(); 
string Make_Map_Name(int, int);
void Create_Background();
void Draw_Dot(int ,int ,int );
void Draw_Dot3(int ,int ,int );
void Draw_Light(int ,int ,int );
void Draw_Dot2(int ,int ,int );
void Draw_Surface(int ,int ,int );
void Draw_Light_Surface(int ,int ,int );
void Draw_Light_Surface1(int ,int ,int );
void Draw_Wall(int ,int ,int );
void Draw_Dot_Robot(int ,int ,int );
void Draw_Shadow(int ,int ,int );
void Draw_Web1 (int );
void Draw_Web (int );
void block(int ,int ,int );
void light_block(int ,int ,int );
void light_block1(int ,int ,int );
void Draw_Pile(int ,int ,int ,int ,int ,int );
int Calculate_L(int ,int ,int );
void Get_Map();
void Draw_Map();
void Write_Map_File(int ,int );
void Get_Robot();
void Draw_Robot(int ,int ,int ,int );
void save(const char * );

const int WIDTH =1920;
const int HEIGHT=1200;
const float SQRT3=1.732050;
int PileNum=-1,L;
BMPheader bmpheader;//create fileheader
BMPINFOHeader bmpinfoheader;//create info header
Pixel graf[HEIGHT][WIDTH];//the graph to write in map file
Pixel BG[HEIGHT][WIDTH];// backgroud 
Pixel robo[1400][700];//robot image
