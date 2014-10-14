#include<stdio.h>
#include<string.h>
void shift(char [],int);
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		char a[1000],b[1000];
		int k;
		scanf("%s %d",a,&k);
		int len=strlen(a);
		int j,h=0;
		for(j=0;j<len;j++)
		{
			if(a[j]!='a'&&a[j]!='e'&&a[j]!='i'&&a[j]!='o'&&a[j]!='u')
			{
				b[h]=a[j];
				h++;
			}
		}	
		for(j=0;j<k;j++)
		{
			shift(b,len);
			printf("%s heel\n",b);
		}
		printf("hello\n");
		int x=0;
		for(j=0;j<len;j++)
		{
			if(a[j]!='a'&&a[j]!='e'&&a[j]!='i'&&a[j]!='o'&&a[j]!='u')
			{
				a[j]=b[x];
				x++;
			}
		}
	//	printf("%s\n",a);
	}
	return 0;
}
void shift(char b[],int len)
{
	int y;
	char temp=b[len-1];
	for(y=len-1;y>0;y--)
	{
		b[y]=b[y-1];
	}
	b[0]=temp;
	return;
}
