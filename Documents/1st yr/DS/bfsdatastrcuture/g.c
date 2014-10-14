#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,e,i,j,z=0;
	scanf("%d%d",&n,&e);
	int a[n+1][n+1],b[n+1],dis[n+1];
	for(i=0;i<n;i++)
	{
		b[i]=-1;
		dis[i]=-1;
		for(j=0;j<n;j++)
		{
			a[i][j]=-1;
		}
	}
        while(z!=e)
	{
		scanf("%d%d",&i,&j);
                a[i][j]=1;
		z++;
        }
	int v,k=1,l=0,count=0,flag;
	scanf("%d",&v);
	b[0]=v;
	dis[v]=0;
	while(b[count]!=-1)
	{
	
	//p[l]=v;
        //k--;
	for(j=0;j<n;j++)
	{
		if(a[v][j]==1)
		{
			flag=1;
			int s=0;
			while(b[s]!=-1)
			{
				if(b[s]==j)
				{flag=0;
				break;}
				s++;
			}
			if(flag==1)
			{
			b[k]=j;
			dis[j]=dis[v]+1;
			k++;
			}
		}
	}
        count++;
        v=b[count];
	}

	int s=0;
	for(i=0;i<n;i++)
	{
		if(dis[i]!=-1)
		{
			printf("%d %d\n",i,dis[i]);
		}
	}
	while(b[s]!=-1)
	{
		printf("%d ",b[s]);
		s++;
	}
	return 0;
}

	

