#include<stdio.h>
int k=0,a[1000][1000];
void push(int q[],int i,int j);
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);

	int i,j,q[n+1],z,l;
	int x,y,c=0,gcd[m],e=0;
	for(l=0;l<m;l++)
	{
		scanf("%d%d",&x,&y);
		//printf("x:%d y:%d\n",x,y);
		while(y!=0)
		{
			c=x%y;
			x=y;
			y=c;
		}
		gcd[e]=x;
		e++;
	}



	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
	for(i=2;i<=n;i++)
	{
		for(z=0;z<=n;z++)//but fill frm q[1]
		{
			q[z]=-1;
		}
		k=0;
		for(j=i-1;j>=1;j--)
		{
			if(i%j==0)
			{
				push(q,i,j);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-1;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("%d\n",a[i][n]);
	}
	for(i=0;i<e;i++)
	{
		printf("%d\n",gcd[i]);
	}
	return 0;
}

void push(int q[],int i,int j)
{
	k++;
	q[k]=j;
	int h,flag=0;
	for(h=k-1;h>=1;h--)
	{
		if(q[h]%q[k]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		a[i][j]=1;
	}
}
