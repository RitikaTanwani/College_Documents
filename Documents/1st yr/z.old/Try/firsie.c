#include<stdio.h>
int main()
{
	char a[1000],b[1000]={'*'};
	int test,key;
	int k,i,j;
	char temp=' ';
	scanf("%d",&test);
	for(k=0;k<test;k++)
	{
		int counter=0;
		scanf("%s",&a);
		scanf("%d",&key);
		for(i=0;i<n;i++)
		{
			if(a[i]!='a'||a[i]!='e'||a[i]!='i'||a[i]!='o'||a[i]!='u')
			{
				if(a[i+2]!='a'||a[i+2]!='e'||a[i+2]!='i'||a[i+2]!='o'||a[i+2]!='u')
				{
					b[i+2]=a[i];
				}
				else
					counter++;
					


					

				


