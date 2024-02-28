#include<windows.h>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<malloc.h>
#include<vector>
#include<algorithm>
#include <ctype.h>
using namespace std; 
enum ResultType {
 LIGHT=0, // 结束条件1，点亮了全部灯，干得漂亮
 LIMIT, // 结束条件2，到达操作数上限
 DARK // 结束条件3，MAIN过程执行完毕
};

struct Result {            
 int steps; 
 ResultType result; 
};
enum OpType s2e(char* buff){
    if(strcmp(buff, "TL")==0) return  TL;
    if(strcmp(buff, "TR")==0) return  TR;
    if(strcmp(buff, "MOV")==0) return  MOV;
    if(strcmp(buff, "JMP")==0) return  JMP;
    if(strcmp(buff, "LIT")==0) return  LIT;
    if(strcmp(buff, "CALL")==0) return  CALL;
    

}
OpSeq opseq; 
Result run;
