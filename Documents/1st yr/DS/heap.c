#include<stdio.h>
int a[50],t=1;

void insert(int n);
int main()
{
	int n,i,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		insert(num);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	int z;
	for(z=1;z<=n;z++)
	{
		//printf("del:%d \n",a[z]);
		t=t-1;
		printf("del:%d\n",a[1]);
//		printf("%d t:%d\n",a[t],t);
		a[1]=a[t];
		int r,y,k=1;
		while(k<t/2)
		{
			printf(":%d \n",a[k]);
			if(a[k]>a[2*k]||a[k]>a[2*k+1])
			{
				if(a[2*k]<a[2*k+1])
					r=2*k;
				else
					r=2*k+1;
				//printf("swap with:%d\n",a[r]);
				y=a[r];
				a[r]=a[k];
				a[k]=y;
				k=r;
			}

			else
				break;
		} 
		for(i=1;i<t;i++)
		{
			printf("%d ",a[i]);
		}
		printf("\n");
	}
}


void insert(int n)
{
	a[t]=n;
	//printf("%d t:%d\n",a[t],t);
	int i=t;
	while(i!=0)
	{
		if(a[i/2]>a[i])
		{
			int temp=a[i/2];
			a[i/2]=a[i];
			a[i]=temp;
			i=i/2;
		}
		else
			break;
	}
	//printf("%d %d\n",a[t],t);
	t++;
}

