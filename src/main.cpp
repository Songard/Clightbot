#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "PublicHeaderFile.h"
#include "DeclearFromLijiaqi.h" 
#include "DeclearFromZhangzeyu.h"
#include "DeclearFromLiyang.h"
#include "FunctionFromLijiaqi.h" 
#include "FunctionFromZhangzeyu.h"
#include "FunctionFromLiyang.h" 
using namespace std;
int main(){
	OPEN();
	
	printf("<System>:Welcome to use Clightbot!\n");
	printf("<System>:Please type in the optype,you can type in 'HELP' for help.\n");
	string PATH="maps";
	vector <string> files;
	getFiles(PATH,files);
	printf("<System>:There are maps to be selected:\n");
	int filenum = files.size();
    for (int i = 0; i < filenum; i++)
    {
        cout << files[i] << endl;
    }
    game.limit=100;
    game.auto_save_id=0;

    string op_type;
    while(printf("<User>:"),getline(cin,op_type),op_type!="EXIT"){
        //LOAD接口
        if((op_type.substr(0,4)=="LOAD"&&op_type.size()==4)){
            printf("<System>:Command Format:*LOAD <MAP_PATH>*\n");
        }
        else if(op_type.substr(0,5)=="LOAD "){
            //LOAD MAP
            if(LOAD(op_type.substr(5).c_str())){
                printf("<System>LOAD MAP SUCCESSFULLY From<");
                cout<<op_type.substr(5);
                printf(">\n");
                string str=op_type.substr(5);
                strcpy(game.map_name,str.c_str());
            }
            else{
                printf("<Error>:Can Not Find The File!\n");
            }
        }
        //RUN接口
        else if(op_type.substr(0,4)=="RUN"&&op_type.size()==3){
            printf("<System>:Command Format:*RUN <OP_PATH>\n");
        }
        else if(op_type.substr(0,4)=="RUN "){
            robot_run(op_type.substr(4).c_str());
            printf("<System>:Executing finished.\n");
        }
        //STATUS接口
        else if(op_type.substr(0,6)=="STATUS"&&op_type.size()==6){
            STATUS();
        }
        //LIMIT接口
        else if(op_type.substr(0,5)=="LIMIT"&&op_type.size()==5){
            printf("<System>:Command Format:*LIMIT <OPS>\n");
        }
        else if(op_type.substr(0,6)=="LIMIT "){
            string stoi_num=op_type.substr(6);
            int stoinum=std::stoi(stoi_num);
                if(stoinum>0&&stoinum<10000){
                    game.limit=stoinum;
                    printf("<System>:Set Limit of Step to:");
                    printf("%d\n",game.limit);
                }
                else{
                    printf("<Error>:The Step Number is not Legal!Type *HELP* for Help\n");
                }
        }
        //AUTOSAVE接口
        else if(op_type.substr(0,9)=="AUTOSAVE "){
            if(op_type.substr(9)=="OFF"){
                game.save_path[0]='\0';
            }
            else{
                auto_save();
                strcpy(game.save_path,op_type.substr(9).c_str());
                printf("<System>:Successfully saved\n");
            }
        }
        //OP接口
        else if(op_type.substr(0,2)=="OP"&&op_type.size()==2){
            printf("<System>:Command Format:*OP <OP_PATH>\n");
        }
        else if(op_type.substr(0,3)=="OP "){
            OP(op_type.substr(3).c_str());
        }
        else if(op_type.substr(0,4)=="HELP"){
        	HELP();
		}

    }
    if(op_type.substr(0,4)=="EXIT"){
        printf("<System>:Please Waiting...\n");
        system("pause");
        printf("<System>:Thanks for playing!\n");
        exit;
    }
    return 0;
}
