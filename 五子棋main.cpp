#include<iostream>
#include<easyx.h>
#include<time.h>
#include<stdlib.h>
int winr(int a[][33])
{
	int i,j;
	int c = 0;
	
	
	for(i = 1;i<=33;i++)
	{
		for(j = 1;j<=33;j++)
		{
			if(c == 0)
			{
				if(a[i][j] == 1)
				{
					c = 1;
				}
			}
			else
			{
				if(a[i][j] == 1)
				{
					c++;
					
					if(c == 5)
					{
						return 1;
					}		
				}
				else
				{
					c = 0;
				}
				
			}
		}
	}
	
	
	
	return 0;
}

int winc(int a[][33])
{
	
	int i,j;
	int c = 0;
	
	
	for(i = 1;i<=33;i++)
	{
		for(j = 1;j<=33;j++)
		{
			if(c == 0)
			{
				if(a[j][i] == 1)
				{
					c = 1;
				}
			}
			else
			{
				if(a[j][i] == 1)
				{
					c++;
					if(c == 5)
					{
						return 1;
					}		
				}
				else
				{
					c = 0;
				}
				
			}
		}
	}
	
	
	return 0;
}


int winx(int a[][33])
{
	int i;
	int j;
	int c = 0;
	for(i = 4;i<=32;i++)
	{
		c = 0;
		for(j = 1;j<=i;j++)
		{
			if(c == 0)
			{
				if(a[j][i-j] == 1)
				{
					c = 1;
				}
			}
			else
			{
				if(a[j][i-j] == 1)
				{
					c++;
					if(c == 5)
					{
						return 1;
					}
					
				}
				else
				{
					c = 0;
				}
			}
		}
	}
	
	return 0;
}

int winx1(int a[][33])
{
	
	int i,j;
	int c = 0;
	for(i = 1;i<=32;i++)
	{
		c = 0;
		for(j = 1;j<=33-i;j++)
		{
			if(c == 0)
			{
				if(a[i+j-1][j] == 1)
				{
					c = 1;	
				}
			}
			else
			{
				if(a[i+j-1][j] == 1)
				{
					c++;
					if(c == 5)
					{
						return 1;
					}
				}
				else
				{
					c = 0;
				}
			}
		}
	}
	
	return 0;
}

int winx2(int a[][33])
{
	int i;
	int j;
	int c = 0;
	for(i = 34;i<=64;i++)
	{
		c = 0;
		for(j = 1;j<=65-i;j++)
		{
			if(c == 0)
			{
				if(a[33-j][i-33+j] == 1)
				{
					c = 1;
				}
			}
			else
			{
				if(a[33-j][i-33+j] == 1)
				{
					c++;
					if(c == 5)
					{
						return 1;
					}
					
				}
				else
				{
					c = 0;
				}
			}
		}
	}
	
	return 0;
}
int winx3(int a[][33])
{
	
	int i,j;
	int c = 0;
	for(i = 2;i<=32;i++)
	{
		c = 0;
		for(j = 1;j<=33-i;j++)
		{
			
			if(c == 0)
			{
				if(a[j][j+i-1] == 1)
				{
					c = 1;	
				}
			}
			else
			{
				if(a[j][j+i-1] == 1)
				{
					c++;
					if(c == 5)
					{
						return 1;
					}
				}
				else
				{
					c = 0;
				}
			}
		}
	}
	
	return 0;
}
int main(int argc, char** argv) 
{
	int x,y;
	int i,j;
	int k,l;
	int i1,j1;
	int a[33][33] = {0};
	int b[33][33] = {0};
	ExMessage msg;
	int count = 0;
	initgraph(640,640,EX_SHOWCONSOLE);
	setbkcolor(WHITE);
	setlinecolor(BLACK);
	setfillcolor(BLACK); 
	settextcolor(BLACK);  
	cleardevice();
	for(i = 0;i<=64;i++)
	{
		line(i*20,0,i*20,640);
	}
	for(j = 0;j<=64;j++)
	{
		line(0,j*20,640,j*20);
	}
	for(k = 0;k<=7;k+=4)
	{
		 outtextxy(6+k*20,4,49+k);
	}
	outtextxy(3+9*20,4,"10");
	
	outtextxy(3+14*20,4,"15");
	
	outtextxy(3+19*20,4,"20");
	
	outtextxy(3+24*20,4,"25");
	
	outtextxy(3+29*20,4,"30");
	
	outtextxy(5,3+4*20,"5");
	
	outtextxy(2,3+9*20,"10");
	
	outtextxy(2,3+14*20,"15");
	
	outtextxy(2,3+19*20,"20");
	
	outtextxy(2,3+24*20,"25");
	
	outtextxy(2,3+29*20,"30");
	
	while(1)
	{
		getmessage(&msg);
		
		
			if(msg.message == WM_LBUTTONDOWN)
			{
				
				if(count % 2 == 0)
				{
					circle((msg.x/20)*20+10,(msg.y/20)*20+10,10);
					a[msg.x/20+1][msg.y/20+1] = 1;
					count++;
					if(winr(a) == 1||winc(a) == 1||winx(a) == 1||winx1(a) == 1||winx2(a) == 1||winx3(a) == 1){
						printf("white win");
						break;
					}
				}
				else
				{
					solidcircle((msg.x/20)*20+10,(msg.y/20)*20+10,10);
					b[msg.x/20+1][msg.y/20+1] = 1;
					count++;
					if(winr(b) == 1||winc(b) == 1||winx(b) == 1||winx1(a) == 1||winx2(a) == 1||winx3(a) == 1){
						printf("black win");
						break;
					}
						
				}
				
			}
		
		
	}
	
	
	
	
	
	
	getchar();
	
	
	
	return 0;
}