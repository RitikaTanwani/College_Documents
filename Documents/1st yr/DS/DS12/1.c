#include<stdio.h>
#include<stdlib.h>
int main()
{
	int z,test;
	scanf("%d\n",&test);
	char ch,a[test][100];
int num[test];
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
				if(t==4)
				{
					scanf("%c",&ch);
					break;}
			}
			scanf("%c",&ch);
		}
		a[z][i]='\0';
		t=0;
		scanf("%d",&num[z]);
		scanf("%c",&ch);
	}
	int j,min=100000,rec1,rec2;
	for(z=0;z<test-1;z++)
	{
		for(j=z+1;j<test;j++)
		{
			if((abs(num[z]-num[j]))<min)
			{
				min=abs(num[z]-num[j]);
				rec1=z;rec2=j;         
			}
		}
	}
	j=0;
	int flag1=0;
	while(j!=9)
	{
		if(a[rec1][j]==a[rec2][j])
		{j++;}
		else if(a[rec1][j]<a[rec2][j])
		{flag1=1;
			break;}
		else
		{flag1=2;
			break;}
	}
//       printf("%d*%d,",rec1,rec2,flag1);
	if(flag1==1)
	{j=rec1;
		while(flag1!=3)
		{
			z=0;
			while(a[j][z]!='\0')
			{
				printf("%c",a[j][z]);
				z++;
			}
			printf(" %d\n",num[j]);
			j=rec2;
			flag1++;
		}
	}
	else if(flag1==2)
	{
		j=rec2;
		while(flag1!=4)
		{
			z=0;
			while(a[j][z]!='\0')
			{
				printf("%c",a[j][z]);
				z++;
			}
			printf(" %d\n",num[j]);
			j=rec1;
			flag1++;
		}
	}
	return 0;
}


























