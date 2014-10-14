#include<stdio.h>
	int main()
	{
		char ch,sv;
		int count=0,m=0;
		while(scanf("%c",&ch)!=EOF)
		{if(ch!='/'&& count==0)
			{
				printf("%c",ch);
				if(ch=='"')
				{m++;}
			}
			else if(ch=='/' && m!=0)
			{printf("%c",ch);}
		
			else if(ch=='/'&& m==0)
			{sv=ch;
				scanf("%c",&ch);
				if(ch=='*')
				{count++;}
				else
				{printf("%c%c",sv,ch);}
			}
			else if(ch=='*' && count!=0)
			{
				scanf("%c",&ch);
				if(ch=='/')
				{count--;}
			}
		}
	return 0;
	}
