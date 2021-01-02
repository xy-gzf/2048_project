#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

#include "2048game.h"

//int *sizestrlen[SIDE*SIDE];
void Init2048(NodePtr sizestrlen)
{
	NodePtr s=(NodePtr)malloc(64);
	s->length=DATA;
}
void Sidelength(NodePtr sizestrlen)
{
	srand((unsigned int)time(NULL));
	for(int j=1;j<=SIDE*SIDE;j++)
	{
		int p=2;
		sizestrlen->data[j]=p;
		printf("     %d    \t",sizestrlen->data[j]);
		if(j%4==0)
		{
			printf("\n\n");
		}
	}
}



void Wword(NodePtr sizestrlen)
{

	for(int i=0;i<SIDE;i++)
	{
		//srand((unsigned int)time(NULL));
		int r=rand()%2;
		if(r==1)
		{
			r=2;
		}
		else
		{
			r=0;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i]==0&&sizestrlen->data[9+i]==0&&sizestrlen->data[13+i]==0)
		{
			sizestrlen->data[1+i]=r;
			sizestrlen->data[5+i]=sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i]!=0&&sizestrlen->data[9+i]!=0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[5+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[5+i];
				if(sizestrlen->data[9+i]==sizestrlen->data[13+i])
				{
					sizestrlen->data[5+i]=sizestrlen->data[9+i]+sizestrlen->data[13+i];
					sizestrlen->data[9+i]=r;
					sizestrlen->data[13+i]=0;
				}
				else
				{
					sizestrlen->data[5+i]=sizestrlen->data[9+i];
					sizestrlen->data[9+i]=sizestrlen->data[13+i];
					sizestrlen->data[13+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[5+i]==sizestrlen->data[9+i])
			{
				if(sizestrlen->data[13+i]==0)
				{
					sizestrlen->data[5+i]=sizestrlen->data[5+i]+sizestrlen->data[9+i];
					sizestrlen->data[9+i]=r;
					sizestrlen->data[13+i]=0;
				}
				else
				{
					sizestrlen->data[5+i]=sizestrlen->data[5+i]+sizestrlen->data[9+i];
					sizestrlen->data[9+i]=sizestrlen->data[13+i];
					sizestrlen->data[13+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[9+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[9+i]=sizestrlen->data[9+i]+sizestrlen->data[13+i];
				sizestrlen->data[13+i]=r;
				continue ;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i]==0&&sizestrlen->data[9+i]==0&&sizestrlen->data[13+i]==0)
		{
			sizestrlen->data[5+i]=r;
			sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]==0&& sizestrlen->data[5+i] !=0&&sizestrlen->data[9+i] == 0&&sizestrlen->data[13+i]==0)
		{
			sizestrlen->data[1+i]=sizestrlen->data[5+i];
			sizestrlen->data[5+i]=r;
			sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			continue ;
		}	
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i] ==0&&sizestrlen->data[9+i] != 0&&sizestrlen->data[13+i]==0)
		{
			sizestrlen->data[1+i]=sizestrlen->data[9+i];
			sizestrlen->data[5+i]=r;
			sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i] ==0&&sizestrlen->data[9+i] == 0&&sizestrlen->data[13+i]!=0)
		{
			sizestrlen->data[1+i]=sizestrlen->data[13+i];
			sizestrlen->data[5+i]=r;
			sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i]!=0&&sizestrlen->data[9+i]==0 && sizestrlen->data[13+i] == 0)
		{
			if(sizestrlen->data[1+i] == sizestrlen->data[5+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[5+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i] ==0&&sizestrlen->data[9+i] != 0&&sizestrlen->data[13+i]==0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[9+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[5+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i] ==0&&sizestrlen->data[9+i] == 0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[15+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[5+i]=sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i] !=0&&sizestrlen->data[9+i] != 0&&sizestrlen->data[13+i]==0)
		{
			if(sizestrlen->data[5+i] ==sizestrlen->data[9+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i]+sizestrlen->data[9+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i] !=0&&sizestrlen->data[9+i] == 0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[5+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i]+sizestrlen->data[15+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			continue ;
		}	
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i] ==0&&sizestrlen->data[9+i] != 0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[9+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[9+i]+sizestrlen->data[13+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[9+i]=sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[9+i];
				sizestrlen->data[5+i]=sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			continue ;
		}

		if(sizestrlen->data[1+i]!=0 &&sizestrlen->data[5+i]!=0 && sizestrlen->data[9+i] !=0 &&sizestrlen->data[13+i] == 0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[5+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else if(sizestrlen->data[5+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[5+i]=sizestrlen->data[5+i]+sizestrlen->data[9+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[13+i]=r;		
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i] !=0&&sizestrlen->data[9+i] == 0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[5+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else if(sizestrlen->data[5+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[5+i]=sizestrlen->data[5+i]+sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[9+i]=sizestrlen->data[13+i];
				sizestrlen->data[13+i]=r;

			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[5+i] ==0&&sizestrlen->data[9+i] != 0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[9+i];
				sizestrlen->data[5+i]=sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else 	if(sizestrlen->data[9+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[5+i]=sizestrlen->data[9+i]+sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[5+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[13+i];
				sizestrlen->data[13+i]=r;	
			}
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[5+i] !=0&&sizestrlen->data[9+i] != 0&&sizestrlen->data[13+i]!=0)
		{
			if(sizestrlen->data[5+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i]+sizestrlen->data[9+i];
				sizestrlen->data[5+i]=sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else if(sizestrlen->data[9+i]==sizestrlen->data[13+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[9+i]+sizestrlen->data[13+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[13+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[13+i];
				sizestrlen->data[13+i]=r;

			}
		}
	}
}
void Aword(NodePtr sizestrlen)
{
	for(int i=0;i<SIDE*SIDE;i=i+4)
	{
		//srand((unsigned int)time(NULL));
		int r=rand()%2;
		if(r==1)
		{
			r=2;
		}
		else
		{
			r=0;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i]==0&&sizestrlen->data[3+i]==0&&sizestrlen->data[4+i]==0)
		{
			sizestrlen->data[1+i]=r;
			sizestrlen->data[2+i]=sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i]!=0&&sizestrlen->data[3+i]!=0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[2+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[2+i];
				if(sizestrlen->data[3+i]==sizestrlen->data[4+i])
				{
					sizestrlen->data[2+i]=sizestrlen->data[3+i]+sizestrlen->data[4+i];
					sizestrlen->data[3+i]=r;
					sizestrlen->data[4+i]=0;
				}
				else
				{
					sizestrlen->data[2+i]=sizestrlen->data[3+i];
					sizestrlen->data[3+i]=sizestrlen->data[4+i];
					sizestrlen->data[4+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[2+i]==sizestrlen->data[3+i])
			{
				if(sizestrlen->data[4+i]==0)
				{
					sizestrlen->data[2+i]=sizestrlen->data[2+i]+sizestrlen->data[3+i];
					sizestrlen->data[3+i]=r;
					sizestrlen->data[4+i]=0;
				}
				else
				{
					sizestrlen->data[2+i]=sizestrlen->data[2+i]+sizestrlen->data[3+i];
					sizestrlen->data[3+i]=sizestrlen->data[4+i];
					sizestrlen->data[4+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[3+i]==sizestrlen->data[4+i])
			{
				sizestrlen->data[3+i]=sizestrlen->data[3+i]+sizestrlen->data[4+i];
				sizestrlen->data[4+i]=r;
				continue ;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i]==0&&sizestrlen->data[3+i]==0&&sizestrlen->data[4+i]==0)
		{
			sizestrlen->data[2+i]=r;
			sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]==0&& sizestrlen->data[2+i] !=0&&sizestrlen->data[3+i] == 0&&sizestrlen->data[4+i]==0)
		{
			sizestrlen->data[1+i]=sizestrlen->data[2+i];
			sizestrlen->data[2+i]=r;
			sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			continue ;
		}	
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i] ==0&&sizestrlen->data[3+i] != 0&&sizestrlen->data[4+i]==0)
		{
			sizestrlen->data[1+i]=sizestrlen->data[3+i];
			sizestrlen->data[2+i]=r;
			sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i] ==0&&sizestrlen->data[3+i] == 0&&sizestrlen->data[4+i]!=0)
		{
			sizestrlen->data[1+i]=sizestrlen->data[4+i];
			sizestrlen->data[2+i]=r;
			sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i]!=0&&sizestrlen->data[3+i]==0 && sizestrlen->data[4+i] == 0)
		{
			if(sizestrlen->data[1+i] == sizestrlen->data[2+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[2+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i] ==0&&sizestrlen->data[3+i] != 0&&sizestrlen->data[4+i]==0)
		{
			if(sizestrlen->data[1+i] == sizestrlen->data[3+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[3+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[2+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i] ==0&&sizestrlen->data[3+i] == 0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[1+i] == sizestrlen->data[4+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[4+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[2+i]=sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i] !=0&&sizestrlen->data[3+i] != 0&&sizestrlen->data[4+i]==0)
		{
			if(sizestrlen->data[2+i] ==sizestrlen->data[3+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i]+sizestrlen->data[3+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i] !=0&&sizestrlen->data[3+i] == 0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[2+i] == sizestrlen->data[4+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i]+sizestrlen->data[4+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			continue ;
		}	
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i] ==0&&sizestrlen->data[3+i] != 0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[3+i]==sizestrlen->data[4+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[3+i]+sizestrlen->data[4+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[3+i]=sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[3+i];
				sizestrlen->data[2+i]=sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			continue ;
		}

		if(sizestrlen->data[1+i]!=0 &&sizestrlen->data[2+i]!=0 && sizestrlen->data[3+i] !=0 &&sizestrlen->data[4+i] == 0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[2+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else if(sizestrlen->data[2+i]==sizestrlen->data[3+i])
			{
				sizestrlen->data[2+i]=sizestrlen->data[2+i]+sizestrlen->data[3+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[4+i]=r;		
			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i] !=0&&sizestrlen->data[3+i] == 0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[2+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else if(sizestrlen->data[2+i]==sizestrlen->data[4+i])
			{
				sizestrlen->data[2+i]=sizestrlen->data[2+i]+sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[3+i]=sizestrlen->data[4+i];
				sizestrlen->data[4+i]=r;

			}
			continue ;
		}
		if(sizestrlen->data[1+i]!=0&&sizestrlen->data[2+i] ==0&&sizestrlen->data[3+i] != 0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[1+i]==sizestrlen->data[3+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[1+i]+sizestrlen->data[3+i];
				sizestrlen->data[2+i]=sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else if(sizestrlen->data[3+i]==sizestrlen->data[4+i])
			{
				sizestrlen->data[2+i]=sizestrlen->data[3+i]+sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[2+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[4+i];
				sizestrlen->data[4+i]=r;	
			}
			continue ;
		}
		if(sizestrlen->data[1+i]==0&&sizestrlen->data[2+i] !=0&&sizestrlen->data[3+i] != 0&&sizestrlen->data[4+i]!=0)
		{
			if(sizestrlen->data[2+i]==sizestrlen->data[3+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i]+sizestrlen->data[3+i];
				sizestrlen->data[2+i]=sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}

			else if(sizestrlen->data[3+i]==sizestrlen->data[4+i])
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[3+i]+sizestrlen->data[4+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[4+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[4+i];
				sizestrlen->data[4+i]=r;

			}
			continue ;
		}
	}
}
void Sword(NodePtr sizestrlen)
{
	for(int i=0;i<SIDE;i++)
	{
		//srand((unsigned int)time(NULL));
		int r=rand()%2;
		if(r==1)
		{
			r=2;
		}
		else
		{
			r=0;
		}
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i]==0&&sizestrlen->data[5+i]==0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[13+i]=r;
			sizestrlen->data[9+i]=sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i]!=0&&sizestrlen->data[5+i]!=0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[13+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[9+i];
				if(sizestrlen->data[5+i]==sizestrlen->data[1+i])
				{
					sizestrlen->data[9+i]=sizestrlen->data[5+i]+sizestrlen->data[1+i];
					sizestrlen->data[5+i]=r;
					sizestrlen->data[1+i]=0;
				}
				else
				{
					sizestrlen->data[9+i]=sizestrlen->data[5+i];
					sizestrlen->data[5+i]=sizestrlen->data[1+i];
					sizestrlen->data[1+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[9+i]==sizestrlen->data[5+i])
			{
				if(sizestrlen->data[1+i]==0)
				{
					sizestrlen->data[9+i]=sizestrlen->data[9+i]+sizestrlen->data[5+i];
					sizestrlen->data[5+i]=r;
					sizestrlen->data[1+i]=0;
				}
				else
				{
					sizestrlen->data[9+i]=sizestrlen->data[9+i]+sizestrlen->data[5+i];
					sizestrlen->data[5+i]=sizestrlen->data[1+i];
					sizestrlen->data[1+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[5+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[5+i]=sizestrlen->data[5+i]+sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;
				continue ;
			}
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i]==0&&sizestrlen->data[5+i]==0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[9+i]=r;
			sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[13+i]==0&& sizestrlen->data[9+i] !=0&&sizestrlen->data[5+i] == 0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[13+i]=sizestrlen->data[9+i];
			sizestrlen->data[9+i]=r;
			sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			continue ;
		}	
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i] ==0&&sizestrlen->data[5+i] != 0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[13+i]=sizestrlen->data[5+i];
			sizestrlen->data[9+i]=r;
			sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i] ==0&&sizestrlen->data[5+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			sizestrlen->data[13+i]=sizestrlen->data[1+i];
			sizestrlen->data[9+i]=r;
			sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i]!=0&&sizestrlen->data[5+i]==0 && sizestrlen->data[1+i] == 0)
		{
			if(sizestrlen->data[13+i] == sizestrlen->data[9+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[9+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i] ==0&&sizestrlen->data[5+i] != 0&&sizestrlen->data[1+i]==0)
		{
			if(sizestrlen->data[13+i] == sizestrlen->data[5+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[5+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[9+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i] ==0&&sizestrlen->data[5+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[13+i] == sizestrlen->data[1+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[1+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[9+i]=sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i] !=0&&sizestrlen->data[5+i] != 0&&sizestrlen->data[1+i]==0)
		{
			if(sizestrlen->data[9+i] ==sizestrlen->data[5+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i]+sizestrlen->data[5+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i] !=0&&sizestrlen->data[5+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[9+i] == sizestrlen->data[1+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i]+sizestrlen->data[1+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}	
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i] ==0&&sizestrlen->data[5+i] != 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[5+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[5+i]+sizestrlen->data[1+i];
				sizestrlen->data[9+i]=r;
				sizestrlen->data[5+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[13+i]=sizestrlen->data[5+i];
				sizestrlen->data[9+i]=sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}

		if(sizestrlen->data[13+i]!=0 &&sizestrlen->data[9+i]!=0 && sizestrlen->data[5+i] !=0 &&sizestrlen->data[1+i] == 0)
		{
			if(sizestrlen->data[13+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else if(sizestrlen->data[9+i]==sizestrlen->data[5+i])
			{
				sizestrlen->data[9+i]=sizestrlen->data[9+i]+sizestrlen->data[5+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=r;		
			}
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i] !=0&&sizestrlen->data[5+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[13+i]==sizestrlen->data[9+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else if(sizestrlen->data[9+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[9+i]=sizestrlen->data[9+i]+sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[5+i]=sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;

			}
			continue ;
		}
		if(sizestrlen->data[13+i]!=0&&sizestrlen->data[9+i] ==0&&sizestrlen->data[5+i] != 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[13+i]==sizestrlen->data[5+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[13+i]+sizestrlen->data[5+i];
				sizestrlen->data[9+i]=sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else if(sizestrlen->data[5+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[9+i]=sizestrlen->data[5+i]+sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[9+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;	
			}
			continue ;
		}
		if(sizestrlen->data[13+i]==0&&sizestrlen->data[9+i] !=0&&sizestrlen->data[5+i] != 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[9+i]==sizestrlen->data[5+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i]+sizestrlen->data[5+i];
				sizestrlen->data[9+i]=sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}

			else if(sizestrlen->data[5+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[5+i]+sizestrlen->data[1+i];
				sizestrlen->data[5+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[13+i]=sizestrlen->data[9+i];
				sizestrlen->data[9+i]=sizestrlen->data[5+i];
				sizestrlen->data[5+i]=sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;

			}
			continue ;
		}
	}
}
void Dword(NodePtr sizestrlen)
{
	for(int i=0;i<SIDE*SIDE;i=i+4)
	{
		//srand((unsigned int)time(NULL));
		int r=rand()%2;
		if(r==1)
		{
			r=2;
		}
		else
		{
			r=0;
		}


		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i]==0&&sizestrlen->data[2+i]==0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[4+i]=r;
			sizestrlen->data[3+i]=sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i]!=0&&sizestrlen->data[2+i]!=0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[4+i]==sizestrlen->data[3+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[3+i];
				if(sizestrlen->data[2+i]==sizestrlen->data[1+i])
				{
					sizestrlen->data[3+i]=sizestrlen->data[2+i]+sizestrlen->data[1+i];
					sizestrlen->data[2+i]=r;
					sizestrlen->data[1+i]=0;
				}
				else
				{
					sizestrlen->data[3+i]=sizestrlen->data[2+i];
					sizestrlen->data[2+i]=sizestrlen->data[1+i];
					sizestrlen->data[1+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[3+i]==sizestrlen->data[2+i])
			{
				if(sizestrlen->data[1+i]==0)
				{
					sizestrlen->data[3+i]=sizestrlen->data[3+i]+sizestrlen->data[2+i];
					sizestrlen->data[2+i]=r;
					sizestrlen->data[1+i]=0;
				}
				else
				{
					sizestrlen->data[3+i]=sizestrlen->data[3+i]+sizestrlen->data[2+i];
					sizestrlen->data[2+i]=sizestrlen->data[1+i];
					sizestrlen->data[1+i]=r;
				}
				continue ;
			}
			else if(sizestrlen->data[2+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[2+i]=sizestrlen->data[2+i]+sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;
				continue ;
			}
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i]==0&&sizestrlen->data[2+i]==0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[3+i]=r;
			sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[4+i]==0&& sizestrlen->data[3+i] !=0&&sizestrlen->data[2+i] == 0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[4+i]=sizestrlen->data[3+i];
			sizestrlen->data[3+i]=r;
			sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			continue ;
		}	
		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i] ==0&&sizestrlen->data[2+i] != 0&&sizestrlen->data[1+i]==0)
		{
			sizestrlen->data[4+i]=sizestrlen->data[2+i];
			sizestrlen->data[3+i]=r;
			sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i] ==0&&sizestrlen->data[2+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			sizestrlen->data[4+i]=sizestrlen->data[1+i];
			sizestrlen->data[3+i]=r;
			sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i]!=0&&sizestrlen->data[2+i]==0 && sizestrlen->data[1+i] == 0)
		{
			if(sizestrlen->data[4+i] == sizestrlen->data[3+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[3+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i] ==0&&sizestrlen->data[2+i] != 0&&sizestrlen->data[1+i]==0)
		{
			if(sizestrlen->data[4+i] == sizestrlen->data[2+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[2+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[3+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i] ==0&&sizestrlen->data[2+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[4+i] == sizestrlen->data[1+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[1+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[3+i]=sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i] !=0&&sizestrlen->data[2+i] != 0&&sizestrlen->data[1+i]==0)
		{
			if(sizestrlen->data[3+i] ==sizestrlen->data[2+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i]+sizestrlen->data[2+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}
		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i] !=0&&sizestrlen->data[2+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[3+i] == sizestrlen->data[1+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i]+sizestrlen->data[1+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}	
		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i] ==0&&sizestrlen->data[2+i] != 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[2+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[2+i]+sizestrlen->data[1+i];
				sizestrlen->data[3+i]=r;
				sizestrlen->data[2+i]=sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[4+i]=sizestrlen->data[2+i];
				sizestrlen->data[3+i]=sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			continue ;
		}

		if(sizestrlen->data[4+i]!=0 &&sizestrlen->data[3+i]!=0 && sizestrlen->data[2+i] !=0 &&sizestrlen->data[1+i] == 0)
		{
			if(sizestrlen->data[4+i]==sizestrlen->data[3+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else if(sizestrlen->data[3+i]==sizestrlen->data[2+i])
			{
				sizestrlen->data[3+i]=sizestrlen->data[3+i]+sizestrlen->data[2+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[1+i]=r;		
			}
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i] !=0&&sizestrlen->data[2+i] == 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[4+i]==sizestrlen->data[3+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else if(sizestrlen->data[3+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[3+i]=sizestrlen->data[3+i]+sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[2+i]=sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;

			}
			continue ;
		}
		if(sizestrlen->data[4+i]!=0&&sizestrlen->data[3+i] ==0&&sizestrlen->data[2+i] != 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[4+i]==sizestrlen->data[2+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[4+i]+sizestrlen->data[2+i];
				sizestrlen->data[3+i]=sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else if(sizestrlen->data[2+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[3+i]=sizestrlen->data[2+i]+sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[3+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;	
			}
			continue ;
		}
		if(sizestrlen->data[4+i]==0&&sizestrlen->data[3+i] !=0&&sizestrlen->data[2+i] != 0&&sizestrlen->data[1+i]!=0)
		{
			if(sizestrlen->data[3+i]==sizestrlen->data[2+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i]+sizestrlen->data[2+i];
				sizestrlen->data[3+i]=sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}

			else if(sizestrlen->data[2+i]==sizestrlen->data[1+i])
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[2+i]+sizestrlen->data[1+i];
				sizestrlen->data[2+i]=r;
				sizestrlen->data[1+i]=0;
			}
			else
			{
				sizestrlen->data[4+i]=sizestrlen->data[3+i];
				sizestrlen->data[3+i]=sizestrlen->data[2+i];
				sizestrlen->data[2+i]=sizestrlen->data[1+i];
				sizestrlen->data[1+i]=r;

			}
			continue ;
		}
	}
}
int Exit2048(NodePtr sizestrlen)
{
	if(sizestrlen->data[1] !=sizestrlen->data[5]&&sizestrlen->data[5] !=sizestrlen->data[9]
	&&sizestrlen->data[9] !=sizestrlen->data[13]&&sizestrlen->data[2] !=sizestrlen->data[6]
	&&sizestrlen->data[6] !=sizestrlen->data[10]&&sizestrlen->data[10] !=sizestrlen->data[14]
	&&sizestrlen->data[3] !=sizestrlen->data[7]&&sizestrlen->data[7] !=sizestrlen->data[11]
	&&sizestrlen->data[11] !=sizestrlen->data[15]&&sizestrlen->data[4] !=sizestrlen->data[8]
	&&sizestrlen->data[8] !=sizestrlen->data[12]&&sizestrlen->data[12] !=sizestrlen->data[16]
	&&sizestrlen->data[1] !=sizestrlen->data[2]&&sizestrlen->data[2] !=sizestrlen->data[3]
	&&sizestrlen->data[3] !=sizestrlen->data[4]&&sizestrlen->data[5] !=sizestrlen->data[6]
	&&sizestrlen->data[6] !=sizestrlen->data[7]&&sizestrlen->data[7] !=sizestrlen->data[8]
	&&sizestrlen->data[9] !=sizestrlen->data[10]&&sizestrlen->data[10] !=sizestrlen->data[11]
	&&sizestrlen->data[11] !=sizestrlen->data[12]&&sizestrlen->data[13] !=sizestrlen->data[14]
	&&sizestrlen->data[14] !=sizestrlen->data[15]&&sizestrlen->data[15] !=sizestrlen->data[16]
	&&sizestrlen->data[1]!=0&&sizestrlen->data[2]!=0&&sizestrlen->data[3]!=0&&sizestrlen->data[4]!=0
	&&sizestrlen->data[5]!=0&&sizestrlen->data[6]!=0&&sizestrlen->data[7]!=0&&sizestrlen->data[8]!=0
	&&sizestrlen->data[9]!=0&&sizestrlen->data[10]!=0&&sizestrlen->data[11]!=0&&sizestrlen->data[12]!=0
	&&sizestrlen->data[13]!=0&&sizestrlen->data[14]!=0&&sizestrlen->data[15]!=0&&sizestrlen->data[16]!=0)
	{
		return 0;
	}

	for(int j=1;j<=SIDE*SIDE;j++)
	{
		if(sizestrlen->data[j]==2048)
		{
			return 1;
		}
	}
}

void Show(NodePtr sizestrlen)
{
	for(int j=1;j<=SIDE*SIDE;j++)
	{
		printf("     %d    \t",sizestrlen->data[j]);
		if(j%4==0)
		{
			printf("\n\n");
		}
	}
}

