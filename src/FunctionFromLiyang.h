int carry_op(OpType op)
{
	run.steps++;

	switch(op)
	{
		case MOV :
			switch(game.map_run.robot.dir)
			{ 
				case UP:
					if(game.map_run.robot.pos.y>0)
					{
						if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y-1].height)//高度相同 
							game.map_run.robot.pos.y--;	
						else
							cout<<"cant move!"<<endl;
					}
					break;
				case DOWN:
					if(game.map_run.robot.pos.y<game.map_run.row-1)
					{
						if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y+1].height)//高度相同 
							game.map_run.robot.pos.y++;
						else
							cout<<"cant move!"<<endl;
					}
					break;
				case LEFT:
					if(game.map_run.robot.pos.x>0) 
					{
						if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x-1][game.map_run.robot.pos.y].height)//高度相同 
							game.map_run.robot.pos.x--;
						else
							cout<<"cant move!"<<endl;
					}
					break;
				case RIGHT:
					if(game.map_run.robot.pos.x<game.map_run.col-1)
					{   
						if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x+1][game.map_run.robot.pos.y].height)//高度相同 
							game.map_run.robot.pos.x++;	
						else
							cout<<"cant move!"<<endl;
					} 
					else
					cout<<"THE space is not enough!"<<endl;
					break;
			}	
			break;
		case TL :             
			switch(game.map_run.robot.dir)
			{
				case LEFT:
					game.map_run.robot.dir=DOWN;
					break;
				case DOWN:
					game.map_run.robot.dir=RIGHT;
					break;
				case RIGHT:
					game.map_run.robot.dir=UP;
					break;
				case UP:
					game.map_run.robot.dir=LEFT;
					break;	
			}
			break;
		case TR	:     	
			switch(game.map_run.robot.dir)
			{
				case LEFT:
					game.map_run.robot.dir=UP;
					break;
				case UP:
					game.map_run.robot.dir=RIGHT;
					break;
				case RIGHT:
					game.map_run.robot.dir=DOWN;
					break;
				case DOWN:
					game.map_run.robot.dir=LEFT;
					break;	
			}
			break;
		case LIT :	
			if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].light_id!=-1)
			{ 
				for(int l=0;l<game.map_run.num_lights;l++)
				{
					if((game.map_run.lights[l].pos.x==game.map_run.robot.pos.x)&&(game.map_run.lights[l].pos.y==game.map_run.robot.pos.y))//寻找灯的编号
					{
						if(game.map_run.lights[l].lighten==false) 
							game.map_run.lights[l].lighten=true;
						else
							cout<<"THE light has been lighten"<<endl; 
						break;
					}	
				}
			}
			else
				cout<<"There is not any light"<<endl; 
			break;
case JMP :
			switch(game.map_run.robot.dir)
			{ 
				case UP:
					if(game.map_run.robot.pos.y>0) 
					{
						if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y-1].height!=0)//判断前一格存在 
							if((game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y-1].height+1)
							||(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y-1].height-1) )//高度相差1 
								game.map_run.robot.pos.y--;	
							else
								cout<<"Can not jump"<<endl;
					}
					else
								cout<<"Can not jump"<<endl;
					break;
				case DOWN:
					if(game.map_run.robot.pos.y<game.map_run.row-1)
					{
						if(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y+1].height!=0) 
							if((game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y+1].height+1)
							||(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y+1].height-1) )//高度相差1 
								game.map_run.robot.pos.y++;	
							else
								cout<<"Can not jump"<<endl;
					}
					else
								cout<<"Can not jump"<<endl;
					break;
				case LEFT:
					if(game.map_run.robot.pos.x>0) 
					{
						if(game.map_run.cells[game.map_run.robot.pos.x-1][game.map_run.robot.pos.y].height!=0)
							if((game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x-1][game.map_run.robot.pos.y].height+1)
							||(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x-1][game.map_run.robot.pos.y].height-1) )//高度相差1 
								game.map_run.robot.pos.x--;	
							else
								cout<<"Can not jump"<<endl;
					}
					else
								cout<<"Can not jump"<<endl;
					break;
				case RIGHT:
					if(game.map_run.robot.pos.x<game.map_run.col-1)
					{
						if(game.map_run.cells[game.map_run.robot.pos.x+1][game.map_run.robot.pos.y].height!=0) 
							if((game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x+1][game.map_run.robot.pos.y].height+1)
							||(game.map_run.cells[game.map_run.robot.pos.x][game.map_run.robot.pos.y].height==game.map_run.cells[game.map_run.robot.pos.x+1][game.map_run.robot.pos.y].height-1) )//高度相差1 
								game.map_run.robot.pos.x++;
							else
								cout<<"Can not jump"<<endl;	
					}
					else
								cout<<"Can not jump"<<endl;
					break;	
			}
			break;		
		default :
			int p=op-5;
			if(p<opseq.count)
			{
				for(int i=0;i<opseq.procs[p].count;i++)
				{
					carry_op(opseq.procs[p].ops[i]);
					if(run.result!=DARK)
						return 0;
				}
			} 
			else
				cout<<"<System>:The optype is illegal.\n";
			break;
	}
	auto_save();
	bool finish=true;
	for(int i=0;i<game.map_run.num_lights;i++) 
	{	
		if(game.map_run.lights[i].lighten==false) 
		{
			finish=false;
			break; 
		}
	}
	if(finish==true)
	{
		run.result=LIGHT;
		return 0;
	}
	if(run.steps>=game.limit)
	{
		run.result=LIMIT;
		return 0;
	}
}

Result robot_run(const char * path)
{
	game.map_run=game.map_init;
	ifstream fin;
	fin.open(path);
	fin>>opseq.count;
	
	for(int opseq_num=0;opseq_num<opseq.count;opseq_num++)
	{	
		fin>>opseq.procs[opseq_num].count;
		for(int ops_num=0;ops_num<opseq.procs[opseq_num].count;ops_num++)
		{
			char str[10];
			fin>>str;
			if(strcmp("LIT",str)==0)
				opseq.procs[opseq_num].ops[ops_num]=LIT;
			else if(strcmp("JMP",str)==0)
				opseq.procs[opseq_num].ops[ops_num]=JMP;
			else if(strcmp("MOV",str)==0)
				opseq.procs[opseq_num].ops[ops_num]=MOV;
			else if(strcmp("TL",str)==0)
				opseq.procs[opseq_num].ops[ops_num]=TL;
			else if(strcmp("TR",str)==0)
				opseq.procs[opseq_num].ops[ops_num]=TR;
			else opseq.procs[opseq_num].ops[ops_num]=OpType(str[1]-48+5);
		}
	}
	
	fin.close();
	run.result=DARK;
	carry_op(CALL);
	return run;	
}