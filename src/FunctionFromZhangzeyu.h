




OpSeq opseq_init; 

void getFiles(string path, vector <string> & files)
{
    long hFile = 0;
    struct _finddata_t fileinfo;
    string pathp;
    if ((hFile = _findfirst(pathp.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
    {
        do
        {
            if ((fileinfo.attrib &  _A_SUBDIR))
            {
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
                {					
                    continue;
                }
            }
            else
            {
                string filestr = fileinfo.name;
				files.push_back(pathp.assign(path).append("/").append(filestr));
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}



bool LOAD(const char* path){
    
    ifstream fin;
    fin.open(path,ios::in);
    if(!fin.is_open()){
        printf("<System>:Failed to open the map\n");
        return false ;
    }
    
    char buff[1024]={'0'};
    int det_buff[1024]={0};
    int turns=0;
    	while(fin>>det_buff[turns]){
       	 	turns++;
    	}
   
    game.map_init.row=det_buff[0];
    game.map_init.col=det_buff[1];
    game.map_init.num_lights=det_buff[2];
    game.map_init.num_procs=det_buff[3];
    int number_of=4;
    for(int i=0;i<game.map_init.row;i++){
        for(int j=0;j<game.map_init.col;j++){
            game.map_init.cells[j][i].height=det_buff[number_of];
            game.map_init.cells[j][i].light_id=-1;
            game.map_init.cells[j][i].robot=false;
            number_of++;
        }
    }
    
    for(int i=0;i<game.map_init.num_lights;i++){
        int a=det_buff[number_of];
        int b=det_buff[number_of+1];
            game.map_init.cells[a][b].light_id=i;
            game.map_init.lights[i].pos.x=a;
            game.map_init.lights[i].pos.y=b;
            number_of+=2;
    }
    opseq_init.count=game.map_init.num_procs;
    for(int i=0;i<game.map_init.num_procs;i++){
        int procs_n=det_buff[number_of];

        opseq_init.procs[i].count=procs_n;
        number_of++;
        
    }
    game.map_init.robot.pos.x=det_buff[number_of];
    cout<<"x "<<game.map_init.robot.pos.x<<" ";
    number_of++;
    game.map_init.robot.pos.y=det_buff[number_of];
    cout<<"y "<<game.map_init.robot.pos.y<<" ";
    number_of++;
    game.map_init.cells[game.map_init.robot.pos.x][game.map_init.robot.pos.y].robot=true;
    game.map_init.robot.dir = (Direction)det_buff[number_of];
    cout<<"dir "<<game.map_init.robot.dir<<endl;
    number_of++;
     for(int j=0;j<game.map_init.row;j++){
        for(int i=0;i<game.map_init.col;i++){
            if(game.map_init.cells[i][j].height>0){
                if(game.map_init.robot.pos.x==i&&game.map_init.robot.pos.y==j){
                    if(game.map_init.cells[i][j].light_id==10000){
                        int a=game.map_init.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[91;103;1m%d\e[0m",a );
						cout<< str;
                        
                    }
                    else if(game.map_init.cells[i][j].light_id==-1){
                        int a=game.map_init.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[91;100;1m%d\e[0m",a );
						cout<< str;
                    }
                    else{
                        int a=game.map_init.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[91;104;1m%d\e[0m",a );
						cout<< str;
                }
				}
                else{
                    if(game.map_init.cells[i][j].light_id==10000){
                        int a=game.map_init.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[92;103;1m%d\e[0m",a );
						cout<< str;
                        
                    }
                    else if(game.map_init.cells[i][j].light_id==-1){
                        int a=game.map_init.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[92;100;1m%d\e[0m",a );
						cout<< str;
                    }
                    else{
                        int a=game.map_init.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[92;104;1m%d\e[0m",a );
						cout<< str;
                    }
                }
            }
            else{
            	cout<<" ";
			}
           
        }
        cout<<endl;
    }
    fin.close();
    return true;
}





void STATUS(){
    printf("<System>:");
    cout<<"Map name:"<<game.map_name<<endl;
    cout<<"Autosave:"<<game.save_path<<endl;
    cout<<"Step limit:"<<game.limit<<endl;
    cout<<"Robot position:"<<game.map_run.robot.pos.x<<" "<<game.map_run.robot.pos.y<<endl;
    for(int j=0;j<game.map_run.row;j++){
        for(int i=0;i<game.map_run.col;i++){
            if(game.map_run.cells[i][j].height>0){
                if(game.map_run.robot.pos.x==i&&game.map_run.robot.pos.y==j){
                    if(game.map_run.cells[i][j].light_id>-1&&game.map_run.lights[game.map_run.cells[i][j].light_id].lighten==true){
                        int a=game.map_run.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[91;103;1m%d\e[0m",a );
						cout<< str;
                        
                    }
                    else if(game.map_run.cells[i][j].light_id==-1){
                        int a=game.map_run.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[91;100;1m%d\e[0m",a );
						cout<< str;
                    }
                    else{
                        int a=game.map_run.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[91;104;1m%d\e[0m",a );
						cout<< str;
                    }
                }
                else{
                    if(game.map_run.cells[i][j].light_id>-1&&game.map_run.lights[game.map_run.cells[i][j].light_id].lighten==true){
                        int a=game.map_run.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[92;103;1m%d\e[0m",a );
						cout<< str;
                        
                    }
                    else if(game.map_run.cells[i][j].light_id==-1){
                        int a=game.map_run.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[92;100;1m%d\e[0m",a );
						cout<< str;
                    }
                    else{
                        int a=game.map_run.cells[i][j].height;
						char str[80];
						sprintf(str,"\e[92;104;1m%d\e[0m",a );
						cout<< str;
                    }
                }
            }
            else{
            	cout<<" ";
			}
           
        }
        cout<<endl;
    }
    
    cout<<"The robot is facing:";
    if(game.map_run.robot.dir==0){
    	cout<<"up"<<endl;
	}
	else if(game.map_run.robot.dir==1){
    	cout<<"down"<<endl;
	}
	else if(game.map_run.robot.dir==2){
    	cout<<"left"<<endl;
	}
	else if(game.map_run.robot.dir==3){
    	cout<<"right"<<endl;
	}
	cout<<"PROC Limit:[";
	for(int i=0;i<MAX_PROCS;i++){
		if(opseq_init.procs[i].count>0){
			cout<<opseq_init.procs[i].count<<" ";
		}
	}
	cout<<"]"<<endl;
}




void OP(const char * path){
    ofstream fout;
    fout.open(path);
    if(!fout){
        printf("<System>:Failed to open the file\n");
        return ;
    }
    else{
    	printf("<System>:Succeeded to open the file\n");
    	printf("<User>:");
        int op_role=0;
        scanf("%d",&op_role);
        fout<<op_role<<endl;
        for(int i=0;i<op_role;i++){
            int inner_role=0;
            scanf("%d",&inner_role);
			fout<<inner_role;
            fout<<" ";
            for(int j=0;j<inner_role;j++){
                char op_type_word[10];
                cin>>op_type_word;
				fout<<op_type_word;
				fout<<" ";
            }
            
           fout<<" "<<endl;
        }
    }
    fout.close();
    printf("<System>:Successfully read_in\n");
    return ;
    
}

void HELP(){
	printf("<System>:\n");
	printf("LOAD:you can type in LOAD to load a map\n");
	printf("OP:you can type in OP to create a list of optype\n");
	printf("STATUS:you can type in STATUS to know the information of your game\n");
	printf("LIMIT:you can type in LIMIT to set the limit (less than 100)\n");
	printf("RUN:type in RUN to start the game!\n");
	printf("press 1 to exit\n");
	int help_p=0;
	scanf("%d",&help_p);
	if(help_p==1){
		return ;
	}
}

void OPEN(){
	cout << "\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[0m";
 	cout << "\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[0m"  ;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[0m" << endl;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[0m";
 	cout << "\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[0m"  ;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[0m" << endl;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[0m";
 	cout << "\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[0m"  ;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[0m" << endl;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[0m";
 	cout << "\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[0m"  ;
 	cout << "\e[92;100;1m0\e[92;100;1m0\e[92;104;1m0\e[92;100;1m0\e[92;100;1m0\e[91;104;1m0\e[0m" << endl;
 	
 	cout<<"----------------------------------Clightbot---------------------------------------"<<endl;

}