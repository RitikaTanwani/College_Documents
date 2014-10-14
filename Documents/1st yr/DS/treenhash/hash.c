#include<stdio.h>
int k1=0,k2=0;
int a[100],b[100],c[100];
	int insertb(int k,int i);
	int insertc(int k,int i);
int main()
{
	int i=0;
	for(i=0;i<100;i++)
	{
		a[i]=rand()%100;
	}
	for(i=0;i<100;i++)
	{
		b[i]=-1;
		c[i]=-1;
	}

	for(i=0;i<100;i++)
	{ 
    b[insertb(0,i)]=a[i];
	
	}
	
    	for(i=0;i<100;i++)
	{ 
    c[insertc(0,i)]=a[i];	
	
	}
	printf("linear:%d\n",k1);

	printf("quadratic:%d\n",k2);
	printf("ratio:%d\n",k1/k2);
	return 0;
}
	int insertb(int k,int i)
	{
	//	printf("%d ",(a[i]%100+k)%100);
		if(b[(a[i]%100+k) %100]==-1)
		{
			return (a[i]%100+k)%100;
		}
		else
		{ 
			k++;
			k1++;
			return insertb(k,i);
		}
	}
	int insertc(int k,int i)
	{
	//	printf("i:%d ",i);
			printf(" %d ",(a[i]%100+k*k)%100);
	if(c[(a[i]%100+k*k) %100]==-1)
		{
			//printf("%d ",(a[i]%100+k*k));
			return ((a[i]%100+k*k)%100);
		}
		else
		{
			if(k==100)
			{return;}	
			k++;
			k2++;
			return insertc(k,i);
		}
	}
