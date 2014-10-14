#include<stdio.h>
#include<math.h>
int main()
{
	int z,test,temp;
	scanf("%d\n",&test);
	int r1,r2,u[test],sal[test],age[test];
	scanf("%d %d\n",&r1,&r2);
if(r1>r2)
{
temp=r1;r1=r2;r2=temp;
}

	char a[test][100],ch;
	for(z=0;z<test;z++)
	{
		int t=0,i=0;
		scanf("%c",&ch);
		while(1)
		{
			a[z][i]=ch;
			i++;
			if(ch==',')
			{t++;
				if(t==2)
				{
					scanf("%c",&ch);
					scanf("%d",&age[z]);
				}
				if(t==4)
				{
					scanf("%c",&ch);
					scanf("%d",&sal[z]);
					break;
				}
			}
			scanf("%c",&ch);
		}
		a[z][i]='\0';
		scanf("%c",&ch);
	}
	int y=0;
	for(z=0;z<test;z++)
	{
		if(age[z]>=r1 && age[z]<=r2)
		{
			u[y]=sal[z];
			y++;
		}
	}
double avg=0;
	for(z=0;z<y;z++)
	{
		avg=avg+u[z];
	}
float b=avg/(y*1.0);       
	printf("%.4f\n",b);
	return 0;
}


























