#include<stdio.h>
int main()
{
int n,i,t=0,j,k,count,vis,max=0,size,p;
scanf("%d",&n);
int a[n+1][n+1];
int visited[n+1];
for(i=1;i<n+1;i++)
{visited[i]=0;}
for(i=1;i<n+1;i++)
{for(j=1;j<n+1;j++)
{scanf("%d",&a[i][j]);}
}
int s[10000];
p=1;
s[t]=p;
t++;
while(vis!=n)
{size=0;
vis=0;
while(t!=0)
{count=0;
for(i=1;i<n+1;i++)
{if(a[p][i]==1)
{if(visited[i]==0)
{visited[i]=1;
s[t]=i;
t++;
count++;
size++;
}
}
}
if(count==0)
{t--;}
p=s[t];
}
if(size>max)
{max=size;}
for(k=1;k<n+1;k++)
{if(visited[k]==1)
{vis++;}
else
{break;}
}
p=k;
t=0;
s[t]=p;
t++;
}
printf("%d\n",max);
return 0;
}
