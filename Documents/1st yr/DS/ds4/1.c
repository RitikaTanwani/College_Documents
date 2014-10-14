#include<stdio.h>
int main()
{
	int n,t,i=0,j=0;
	scanf("%d%d",&n,&t);
	int dis[n+1],mat[n+1][n+1],b[n+1];
	for(i=1;i<=n;i++)
	{dis[i]=100;b[i]=-1;
		for(j=1;j<=n;j++)
		{
			mat[i][j]=0;
		}
	}
	int num,u,v,a[n+1][n+1];
	for(i=0;i<t;i++)
	{
		j=-1;
		scanf("%d",&num);
		while(num!=-1)
		{
			j++;
			a[i][j]=num;
			scanf("%d",&num);
		}
		//k=a[i][0];
		for(u=0;u<=j;u++)
		{
			for(v=0;v<=j;v++)
			{
				if(u==v)
				{
					mat[a[i][u]][a[i][u]]=0;
				}
				else
				{
					mat[a[i][u]][a[i][v]]=1;
					//mat[a[i][v]][a[i][u]]=1;
				}
			}
		}
}
/*		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				printf("%d ",mat[i][j]);
			}
printf("\n");
		}*/
//int d[n+1];

int ve=1,k=1;
	//scanf("%d",&v);
	dis[ve]=0;
	while(k!=n-1)
	{
        for(j=1;j<=n;j++)
	{
		if(mat[ve][j]!=0)
		{
			
			if(dis[j]>dis[ve]+mat[ve][j])
			{
				dis[j]=dis[ve]+mat[ve][j];
			}/*if(v==4)
			{
				printf("4: %d\n",dis[j]);
			}*/
		}
	}
	b[ve]=1;//known vertex
	int min=100;
	for(j=1;j<=n;j++)
	{
		if(dis[j]<min && b[j]!=1)
		{min=dis[j];
			ve=j;
		}
	}
        k++;
	}
	
for(j=1;j<n;j++)
{
printf("%d ",dis[j]);
}
printf("%d\n",dis[n]);
	return 0;
}
