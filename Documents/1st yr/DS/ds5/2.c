#include<stdio.h>
int k=0,w=0;
void push(int q[],int j,int known[]);
int main()
{
	int z,n;
	scanf("%d",&n);
	int i,j,a[n][n],b[n][n],q[n+1],known[n+1];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			b[i][j]=-1;
		}
	}
	for(i=0;i<=n;i++)
	{
		q[i]=-1;
		known[i]=-1;
	}
	q[0]=0;
	int v=q[0],f=0,lev=0,count=0;
	while(v!=-1)
	{
		//		printf("pp\n");
		for(j=0;j<n;j++)
		{
			if(a[v][j]==1 && known[j]==-1)
			{
				push(q,j,known);
			}
		}

		b[lev][f]=v;
		f++;
		if(w==count)
		{
			count=k;
			f=0;
			lev++;
		}
		w++;
		v=q[w];
		//printf("%d ",v);
	}
	printf("%d\n",lev);
	int min,x,y;
	for(i=0;i<n;i++)
	{
		j=0;
		while(b[i][j]!=-1)
		{
			//printf("%d ",b[i][j]);
			j++;
		}
		for(x=0;x<j;x++)
		{
			min=x;
			for(y=x+1;y<j;y++)
			{
				if(b[i][y]<b[i][min])
				{
					min=y;
				}
			}
			int t=b[i][x];
			b[i][x]=b[i][min];
			b[i][min]=t;
		}
		if(b[i][0]!=-1)
		{
			for(z=0;z<j-1;z++)
			{
				printf("%d ",b[i][z]);
			}
			printf("%d\n",b[i][j-1]);
		}


	}

	for(i=0;i<w;i++)
	{
		//		printf("%d ",q[i]);
	}
	return 0;
}
void push(int q[],int j,int known[])
{
	k++;
	q[k]=j;
	known[j]=1;
}

