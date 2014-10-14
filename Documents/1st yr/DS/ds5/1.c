#include<stdio.h>
int main()
{
	int i=0,j=0,t1,t2,ath,ppr,ap,pp;
	char ch1,ch2,ch3,ch4;
	scanf("%d%d%d%d\n",&ath,&ppr,&ap,&pp);
	int c[ppr+1],n[ppr+1],x[ath+1][ppr+1];
	for(i=1;i<=ppr;i++)
	{c[i]=0;
	}
	for(i=1;i<=ath;i++)
	{
		n[i]=0;
	}
	for(i=1;i<=ath;i++)
	{
		for(j=1;j<=ppr;j++)
		{
			x[i][j]=0;
		}
	}
	for(i=0;i<ap;i++)
	{
		scanf("%c%d%c%c%d%c",&ch1,&t1,&ch2,&ch3,&t2,&ch4);
		x[t1][t2]=1;
		n[t1]++;
	}
	int l,h,u;
	for(i=0;i<pp;i++)
	{
		scanf("%c%d%c%c%d%c",&ch1,&t1,&ch2,&ch3,&t2,&ch4);
		c[t1]++;
	}
	for(i=1;i<=ath;i++)
	{
		h=n[i];
		u=0;
		l=0;
		for(j=1;j<=ppr;j++)
		{
			//printf("%d\n",c[j]);
			if(h==0)
			{printf("0\n");
				break;
			}
			if(x[i][j]==1)
			{
				u++;
				if(c[j]>=h)
				{l++;}
				if(l==h)
				{
					printf("%d\n",l);
					break;
				}
				if(u==n[i] && l!=h)
				{h--;
					u=0;
					j=0;
					l=0;
				}
			}
		}
	}



	return 0;
}
