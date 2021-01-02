#include <stdio.h>
#include <windows.h>
#include <string.h>
int main()
{

	Node sizestrlen;
	Init2048(&sizestrlen);
	Sidelength(&sizestrlen);
	while(1)
	{
		char str[1]={0};
		scanf_s("%c",str);
		system("cls");
		if(strncmp(str,"w",1)==0)
		{
			Wword(&sizestrlen);
			//fflush(stdin);
		}
		if(strncmp(str,"s",1)==0)
		{
			Sword(&sizestrlen);
			//fflush(stdin);
		}
		if(strncmp(str,"a",1)==0)
		{
			Aword(&sizestrlen);
			//fflush(stdin);
		}
		if(strncmp(str,"d",1)==0)
		{
			Dword(&sizestrlen);
			//fflush(stdin);
		}
		Show(&sizestrlen);
		if(Exit2048(&sizestrlen)==0)
		{
			printf("\n\n            失败了！请从新开始2048游戏哦！ \n\n");
			break;
		}
		if(Exit2048(&sizestrlen) == 1)
		{
			printf("\n\n            恭喜你通关成功2048！你真棒！ \n\n");
			break;
		}
	}
	printf("\n\n 请按q键结束游戏 \n\n");
	while(1)
	{
		
		char str1[1]={0};
		scanf_s("%c",str1);
		if(strncmp(str1,"q",1)==0)
		{
			break;
		}
		else
		continue;
		
	}

}

