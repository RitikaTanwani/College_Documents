#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,e,i,j,z=0;
	scanf("%d%d",&n,&e);
	int a[n+1][n+1],b[n+1],dis[n+1],d;
	for(i=0;i<=n;i++)
	{
		b[i]=-1;
		dis[i]=100;
		for(j=0;j<n;j++)
		{
			a[i][j]=-1;
		}
	}
        while(z!=e)
	{
		scanf("%d%d%d",&i,&j,&d);
                a[i][j]=d;
		z++;
        }
	int v,k=1,l=0,count=0,flag;
	scanf("%d",&v);
	dis[v]=0;
	while(k!=n)
	{
        for(j=0;j<n;j++)
	{
		if(a[v][j]!=-1)
		{
			
			if(dis[j]>dis[v]+a[v][j])
			{
				dis[j]=dis[v]+a[v][j];
			}/*if(v==4)
			{
				printf("4: %d\n",dis[j]);
			}*/
		}
	}
	b[v]=1;//known vertex
	int min=100;
	for(j=0;j<=n;j++)
	{
		if(dis[j]<min && b[j]!=1)
		{min=dis[j];
			v=j;
		}
	}
        k++;
	}



	for(i=0;i<=n;i++)
	{
		if(dis[i]!=100)
		{
			printf("%d %d\n",i,dis[i]);
		}
	}

/*	while(b[s]!=-1)
	{
		printf("%d ",b[s]);
		s++;
	}*/
	return 0;
}

	

