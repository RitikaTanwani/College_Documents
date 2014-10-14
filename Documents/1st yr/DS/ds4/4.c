#include<stdio.h>
int main()
{
	int n,t,i=0,j=0;
	scanf("%d",&n);
	int dis[1000],mat[1000][1000],b[1000];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
		mat[i][i]=0;
	}/*
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
	for(i=1;i<=n;i++)
	{
	for(j=1;j<=n;j++)
	{
	printf("%d ",mat[i][j]);
	}
	printf("\n");
	}*/
	int z,max=0;
	for(z=1;z<=n;z++)
	{
		int ve=z,k=1;
		for(j=1;j<=n;j++)
		{
			dis[j]=100;
			b[j]=-1;
		}
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
		/*for(i=1;i<=n;i++)
		{printf("%d ",dis[i]);}
		printf("\n");*/
		for(j=1;j<=n;j++)
		{
			if(dis[j]!=100)
			{
				if(dis[j]>max)
				{
					max=dis[j];
				}
			}
		}

	}

	printf("%d\n",max);

	return 0;
}
