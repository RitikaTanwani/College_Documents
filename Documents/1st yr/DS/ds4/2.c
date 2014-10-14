#include<stdio.h>
int k=0;
//int stack[1000],known[1000],parent[1000],v1[1000],v2[1000];
int part=1,n;
int e=1,f=0;
void push(int stack[],int known[],int vertex,int);
void pop();
void pushin(int a[][n+1],int v1[],int v2[],int val,int parent[]);
void sort(int a1[],int n);
int main()
{
	int i,j,enter=0;
	scanf("%d",&n);
int a[n+1][n+1];
int stack[n+1],known[n+1],parent[n+1],v1[n+1],v2[n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		stack[i]=-1;
		known[i]=-1;
		parent[i]=-1;
		v1[i]=-1;
		v2[i]=-1;
	}

	int u;
	for(j=1;j<=n;j++)
	{
		if(k==0)
		{
			for(i=1;i<=n;i++)
			{
				enter=0;
				if(known[i]==-1)
				{
					enter=1;
					parent[i]=0;
					pushin(a,v1,v2,i,parent);
					push(stack,known,i,n);
					break;
				}
			}
		}
		if(enter!=1)
		{
			break;
		}

		int flag=0;
		if(a[stack[k]][j]==1 && known[j]==-1)
		{
			parent[j]=stack[k];
			pushin(a,v1,v2,j,parent);
			//			printf("parent of %d is %d\n",j,stack[k]);
			flag=1;
			push(stack,known,j,n);
			j=1;
		}
		if(j==n && flag==0)
		{
			pop();
			j=1;
		}
	}
	i=1;
	j=1;
	//printf("out\n");
	if(part==1)
	{
		printf("YES\n");
		sort(v1,e);
		sort(v2,f);
		for(i=1;i<=e;i++)
{
printf("%d ",v1[i]);
}
printf("\n");

		for(i=1;i<=f;i++)
{
printf("%d ",v2[i]);
}
printf("\n");
/*while(v1[i]!=-1)
		{printf("%d ",v1[i]);
			i++;
		};
		printf("\n");
		while(v2[j]!=-1)
		{printf("%d ",v2[j]);

			j++;}
			printf("\n");*/
	}
	else 
	{
		printf("NO\n");
	}
return 0;
}
void sort(int a1[],int n)
{
	int i,j,min;
	for(i=1;i<=n;i++)
	{
		min=i;
		for(j=i+1;j<=n;j++)
		{
			if(a1[min]>a1[j])
			{min=j;}
		}
		int t=a1[min];
		a1[min]=a1[i];
		a1[i]=t;
	}
}
void pop()
{
	k--;
}
void pushin(int a[][n+1],int v1[],int v2[],int val,int parent[])
{
	//printf("val :%d\n",val);
	int u,d=0;
	if(v1[1]==-1)
	{
		v1[1]=val;
	}
	else
	{
		for(u=1;u<=e;u++)
		{
	//			printf("v1[e]:%d P[val]:%d e:%d\n",v1[e],parent[val],e);
			if(v1[u]==parent[val])
			{
				d=1;
				f++;
				v2[f]=val;
				int y=f-1;
				while(y!=0)
				{
					if(a[val][v2[y]]==1)
					{
						//	printf("        %d %d    \n",val,v2[y]);
						part=0;
						break;
					}
					y--;
				}			//	printf("v2:%d f:%d\n",val,f);
				break;
			}
		}
		if(d!=1)
		{
			for(u=1;u<=f;u++)
			{
	//			printf("v2[f]:%d P[val]:%d f:%d\n",v2[f],parent[val],f);
				if (v2[u]==parent[val])
				{
					e++;
					v1[e]=val;
					int x=e-1;
					while(x!=0)
					{
						if(a[val][v1[x]]==1)
						{
							//			printf("        %d %d    ",val,x);
					//		printf("        %d %d    \n",val,v1[x]);
							part=0;
							break;
						}
						x--;
					}		//		printf("v1:%d e:%d\n",val,e);
					break;
				}
			}
		}
	}
}
void push(int stack[],int known[],int vertex,int n)
{
	int u;
	/*	for(u=1;u<=n;u++)
		{
		printf("%d ", stack[u]);
		}
		printf("\n");*/
	k++;
	stack[k]=vertex;
	known[vertex]=1;
}





