#include<stdio.h>
int main()
{
	char a[5];
	scanf("%s",a);
	char temp;
	temp=a[4];
	int x;
	for(x=4;x>0;x--)
	{
		a[x]=a[x-1];
		printf("%c hello\n",a[x]);

	}
	a[0]=temp;
	printf("%s\n",a);
	return 0;
}
	
