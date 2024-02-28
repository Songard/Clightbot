//Create all needed BMP file headers
void Create_Header(){
	bmpheader.bfSize=WIDTH*HEIGHT*3+36;
	bmpinfoheader.biWidth =WIDTH;
	bmpinfoheader.biHeight=HEIGHT;
	bmpinfoheader.biSizeImage=WIDTH*HEIGHT*3;
	return ;
}
string Make_Map_Name(int x,int n){
	stringstream map_num ;
    string map_name;
	int I=0;
	while(game.save_path[I]!='\0' && game.save_path[I]!='/'){
		map_num<<game.save_path[I];
		I++;
	} 
	map_num<<game.save_path[I]; 
	for(int i=1;i<(int)(game.save_path[I+2]-'0');i++)
	    if(x<pow(10,i))map_num<<"0";
	        map_num<<x%(int)pow(10,(game.save_path[I+2]-'0'));
	I+=4;
	while(game.save_path[I]!='\0'){
		map_num<<game.save_path[I];
		I++;
	} 
    map_num>>map_name;
	return map_name;	
}
void Create_Background(){
    for(int i=0;i<HEIGHT;i++){
		for(int j=0;j<WIDTH;j++){
			graf[i][j].R=(char)(210+45*((float)(j)/(2*WIDTH)));
			graf[i][j].G=(char)(100+155*(1-(float)(j)/(2*HEIGHT)));
			graf[i][j].B=(char)(50+195*(1-(float)(i)/(2*HEIGHT)-(float)(j)/(2*WIDTH)));
			BG[i][j].R=(char)(210+45*((float)(j)/(2*WIDTH)));
			BG[i][j].G=(char)(100+155*(1-(float)(j)/(2*HEIGHT)));
			BG[i][j].B=(char)(50+195*(1-(float)(i)/(2*HEIGHT)-(float)(j)/(2*WIDTH)));
		}
	}	
	return ;
}
void Draw_Dot(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j]={(char)0,(char)0,(char)0}; 
		}
	}
	return ;
}
void Draw_Dot3(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j]={(char)153,(char)160,(char)61}; 
		}
	}
	return ;
}
void Draw_Light(int x,int y,int r){
	for(int i=max(0,x-2*r);i<=min(HEIGHT-1,x+3*r);i+=9){
		for(int j=max(0,y-2*r);j<=min(WIDTH-1,y+3*r);j+=9){
			graf[i][j]={(char)203,(char)240,(char)141}; 
		}
	}
	return ;
}
void Draw_Dot2(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=255-BG[i][j].R; 
			graf[i][j].G=255-BG[i][j].B;			
			graf[i][j].B=255-BG[i][j].G;			
		}
	}
	return ;
}
void Draw_Surface(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=(BG[i][j].R)/2; 
			graf[i][j].G=(BG[i][j].G)/2;			
			graf[i][j].B=(255-BG[i][j].B);			
		}
	}
	return ;
}
void Draw_Light_Surface(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=(BG[i][j].R)/2; 
			graf[i][j].G=(char)20;			
			graf[i][j].B=(255-BG[i][j].B);			
		}
	}
	return ;
}
void Draw_Light_Surface1(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=(char)169; 
			graf[i][j].G=(char)132;			
			graf[i][j].B=(255-BG[i][j].B);			
		}
	}
	return ;
}
void Draw_Wall(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=(BG[i][j].R); 
			graf[i][j].G=(BG[i][j].G)/1.5;			
			graf[i][j].B=(255-BG[i][j].B);			
		}
	}
	return ;
}
void Draw_Dot_Robot(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=(BG[i][j].R)/0.8; 
			graf[i][j].G=(BG[i][j].G)/0.8;			
			graf[i][j].B=(char)240;			
		}
	}
	return ;
}
void Draw_Shadow(int x,int y,int r){
	for(int i=max(0,x-r);i<=min(HEIGHT-1,x+r);i++){
		for(int j=max(0,y-r);j<=min(WIDTH-1,y+r);j++){
			graf[i][j].R=(BG[i][j].R)/0.8; 
			graf[i][j].G=(BG[i][j].G)/0.8;			
			graf[i][j].B=(255-BG[i][j].B);			
		}
	}
	return ;
}
void Draw_Web1 (int line_num){
	for(int i=0;i*3<HEIGHT;i++){
		for(int j=-line_num;j<=line_num;j++){
			Draw_Dot2(i*3+j*HEIGHT/line_num,i*3,10);	
			Draw_Dot2(i*3+j*HEIGHT/line_num,WIDTH-i*3,10);
		}
	}
	return ;
}
void Draw_Web (int line_num){
	int line_gap=HEIGHT*SQRT3/(2*line_num)+2;
	for(int i=0;i*3<HEIGHT;i++){
		for(int j=-line_num;j<=line_num;j++){
			Draw_Dot2(i*3+j*HEIGHT/line_num,i*3*SQRT3,6);	
			Draw_Dot2(i*3+j*HEIGHT/line_num,WIDTH-i*3*SQRT3,6);
		}
		
		for(int j=0;j*line_gap<=WIDTH;j++){
			Draw_Dot2(i*3,j*line_gap+3,6);
		}
	}
	return ;	
}
void block(int x,int y,int l){
	int breadth=l/30+1;
	for(int i=0;i<l;i++){		
		for(int j=-i*SQRT3;j<=i*SQRT3;j++){
			Draw_Surface(y+l-i,x+j,0);
			Draw_Surface(y-l+i,x+j,0);
		}	
		for(int j=-l*SQRT3;j<=l*SQRT3;j++){
		Draw_Surface(y,x+j,0);
	    }
		for(int j=1;j<=l-breadth*SQRT3;j++){
			Draw_Wall(y-i-j,x-(l-i)*SQRT3,1);
			Draw_Shadow(y-i-j,x+(l-i)*SQRT3,1);
		}	
	}
	for(int i=0;i<l;i++){
		Draw_Dot(y+l-i,x+i*SQRT3,breadth);
		Draw_Dot(y+l-i,x-i*SQRT3,breadth);
		Draw_Dot(y-l+i,x+i*SQRT3,breadth);
	    Draw_Dot(y-l+i,x-i*SQRT3,breadth);
	    Draw_Dot(y-i,x-l*SQRT3,breadth);
	    Draw_Dot(y-l-i,x,breadth);
	    Draw_Dot(y-i,x+l*SQRT3,breadth);
	}
	return ;
} 
void light_block(int x,int y,int l){
	int breadth=l/30+1;
	for(int i=0;i<l;i++){		
		for(int j=-i*SQRT3;j<=i*SQRT3;j++){
			Draw_Light_Surface(y+l-i,x+j,0);
			Draw_Light_Surface(y-l+i,x+j,0);
		}	
		for(int j=-l*SQRT3;j<=l*SQRT3;j++){
		Draw_Light_Surface(y,x+j,0);
	    }
		for(int j=1;j<=l-breadth*SQRT3;j++){
			Draw_Wall(y-i-j,x-(l-i)*SQRT3,1);
			Draw_Shadow(y-i-j,x+(l-i)*SQRT3,1);
		}	
	}
	for(int i=0;i<l;i++){
		Draw_Dot(y+l-i,x+i*SQRT3,breadth);
		Draw_Dot(y+l-i,x-i*SQRT3,breadth);
		Draw_Dot(y-l+i,x+i*SQRT3,breadth);
	    Draw_Dot(y-l+i,x-i*SQRT3,breadth);
	    Draw_Dot(y-i,x-l*SQRT3,breadth);
	    Draw_Dot(y-l-i,x,breadth);
	    Draw_Dot(y-i,x+l*SQRT3,breadth);
	}
	return ;
} 
void light_block1(int x,int y,int l){
	int breadth=l/30+1;
	for(int i=0;i<l;i++){		
		for(int j=-i*SQRT3;j<=i*SQRT3;j++){
			Draw_Light_Surface1(y+l-i,x+j,0);
			Draw_Light_Surface1(y-l+i,x+j,0);
		}	
		for(int j=-l*SQRT3;j<=l*SQRT3;j++){
		Draw_Light_Surface1(y,x+j,0);
	    }
		for(int j=1;j<=l-breadth*SQRT3;j++){
			Draw_Wall(y-i-j,x-(l-i)*SQRT3,1);
			Draw_Shadow(y-i-j,x+(l-i)*SQRT3,1);
		}	
	}for(int i=0;i<l;i++){
		Draw_Dot(y-l-i,x,breadth);
		Draw_Dot(y-i,x-l*SQRT3,breadth);	    
	    Draw_Dot(y-i,x+l*SQRT3,breadth);
	}
	
	for(int i=0;i<l-breadth/3;i++){	    
		Draw_Dot(y+l-i,x+i*SQRT3,breadth);
		Draw_Dot(y+l-i,x-i*SQRT3,breadth);
		Draw_Dot(y-l+i,x+i*SQRT3,breadth);
	    Draw_Dot(y-l+i,x-i*SQRT3,breadth);
	    
	}
	return ;
}
void Draw_Pile(int row,int col,int r,int c,int l,int h){
	if(h==0)return;
	int x=(WIDTH-(2*c-row-1)*l*SQRT3+(2*r-col-1)*l*SQRT3)/2;
	int y=(HEIGHT-(2*c-row-1)*l-(2*r-col+2)*l)/2-(PileNum-col)*l/2;
	for(int i=0;i<h-1;i++){
		block(x,y+i*l,l);
	}
	if(game.map_run.cells[r-1][c-1].light_id!=-1){
		if(game.map_run.lights[game.map_run.cells[r-1][c-1].light_id].lighten)
		light_block(x,y+(h-1)*l,l);
		else 		light_block1(x,y+(h-1)*l,l);
	} else{
		block(x,y+(h-1)*l,l);
	}
	if(r-1==game.map_run.robot.pos.x && c-1==game.map_run.robot.pos.y){
		Draw_Robot(y+(h-1)*l-l/4,x-l*3/4,l*3/2,game.map_run.robot.dir);
	}
	return ;
}
int Calculate_L(int row,int col,int pil){
	float ll=min(WIDTH/((row+col+2)*SQRT3),HEIGHT/(row+col+(float)3+pil));
	return (int)ll;	
}
void Get_Map(){

	for(int i=0;i<game.map_run.row;i++){
		for(int j=0;j<game.map_run.col;j++){
			if(PileNum+i+j<game.map_run.cells[i][j].height)PileNum=game.map_run.cells[i][j].height; 
		}
	}
	return ;
}
void Draw_Map(){
	L=Calculate_L(game.map_run.row,game.map_run.col,PileNum+2);
    for(int i=0;i<game.map_run.col;i++){
    	for(int j=0;j<game.map_run.row;j++){
    	    Draw_Pile(game.map_run.row,game.map_run.col,i+1,j+1,L,game.map_run.cells[i][j].height);
		}
	}
	return ; 
}
void Write_Map_File(int Fnum,int n){
    ofstream fout;
	fout.open(Make_Map_Name(Fnum,n).c_str(),ios::binary);
	fout.write((char*)&bmpheader,sizeof(bmpheader));
	fout.write((char*)&bmpinfoheader,sizeof(bmpinfoheader));
	fout.write((char*)&graf,sizeof(graf));
	fout.close();
	return ;
}
void Get_Robot(){
	ifstream fin;
	fin.open("robot.bmp",ios::binary);
	BMPheader robotbfh;
	BMPINFOHeader robotbih;
	fin.read((char*)&robotbfh,sizeof(robotbfh));
	fin.read((char*)&robotbih,sizeof(robotbih));	
	fin.read((char*)&robo,sizeof(robo));
	fin.close();
	return;
}
void Draw_Robot(int x,int y,int l,int direction){
    int RobotDir[4][2]={{350,700},{0,0},{0,700},{350,0}};
	for(int i=0;i<2*l;i++)
		for(int j=0;j<l;j++)		   
		    if(robo[RobotDir[direction][1]+i*350/l][RobotDir[direction][0]+j*350/l].G>=84)
		   	    Draw_Light(x+i,y+j,l/25);
	for(int i=0;i<2*l;i++){
		for(int j=0;j<l;j++){
		    if(robo[RobotDir[direction][1]+i*350/l][RobotDir[direction][0]+j*350/l].G<=38)
		        Draw_Dot_Robot(x+i,y+j,0);
		    if(robo[RobotDir[direction][1]+i*350/l][RobotDir[direction][0]+j*350/l].G>=84)
			    Draw_Dot3(x+i,y+j,l/50);	    
		   	if(robo[RobotDir[direction][1]+i*350/l][RobotDir[direction][0]+j*350/l].G>=84)
			    Draw_Dot(x+i,y+j,1);
		}
	}
	for(int i=0;i<2*l;i++)
		for(int j=0;j<l;j++)		    
		    if(robo[RobotDir[direction][1]+i*350/l][RobotDir[direction][0]+j*350/l].G>=84)Draw_Dot(x+i,y+j,l/180+1);	
	return ;
}
void save(const char * path){//save a bmpfile with the name *path 
	Create_Header(); 
	Create_Background();
	Get_Map();
	Get_Robot();	
	Draw_Map();    
	ofstream fout;
	fout.open(path,ios::binary);
	fout.write((char*)&bmpheader,sizeof(bmpheader));
	fout.write((char*)&bmpinfoheader,sizeof(bmpinfoheader));
	fout.write((char*)&graf,sizeof(graf));
	fout.close();
	return ;
}
void auto_save(){//save the map_run in a bmpfile named game.save_path
	if(game.save_path[0]!='\0'){
		Create_Header(); 
	    Create_Background();
	    Get_Map();
     	Get_Robot();	
    	Draw_Map();     	
	    Write_Map_File(game.auto_save_id++,3);
	}
	return ;
}
