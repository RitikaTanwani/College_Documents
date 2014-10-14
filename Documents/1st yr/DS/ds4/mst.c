#include<stdio.h>
/*typedef struct node
{
int val;
int rep;
struct node *next;
};*/
int main()
{
int n,i,j,e,n1,n2,k,ans;
scanf("%d",&n);
scanf("%d",&e);
int we,w[n+1][n+1],a[n+1][n+1],rep[n+1],vis[n+1][n+1];
for(i=1;i<n+1;i++)
{for(j=1;j<n+1;j++)
{w[i][j]=0;
a[i][j]=0;
vis[i][j]=0;
}
}
for(i=0;i<e;i++)
{scanf("%d %d %d",&n1,&n2,&we);
w[n1][n2]=we;
w[n2][n1]=we;
}
for(i=1;i<n+1;i++)
{rep[i]=i;}
int min=100,e1,e2;
int count=0;
while(count!=n)
{min=100;
for(i=1;i<n+1;i++)
{for(j=1;j<n+1;j++)
{if(w[i][j]!=0 && vis[i][j]==0)
{if(w[i][j]<min)
{min=w[i][j];
e1=i;
e2=j;
}
}
}
}
if(rep[e1]!=rep[e2])
{a[e1][e2]=1;
a[e2][e1]=1;
int count1=0,count2=0;
for(k=1;k<n+1;k++)
{if(rep[k]==rep[e1])
{count1++;}
if(rep[k]==rep[e2])
{count2++;}
}
if(count1<count2)
{for(k=1;k<n+1;k++)
{if(rep[k]==rep[e1] && k!=e1)
{rep[k]=rep[e2];}
}
rep[e1]=rep[e2];}
else
{
for(k=1;k<n+1;k++)
{if(rep[k]==rep[e2] && k!=e2)
{rep[k]=rep[e1];}
}
rep[e2]=rep[e1];}
vis[e1][e2]=1;
vis[e2][e1]=1;
}
else
{a[e1][e2]=0;
vis[e1][e2]=1;
vis[e2][e1]=1;}
count=0;
for(k=1;k<n+1;k++)
{if(rep[k]==rep[1])
{//printf("k:%d\n",k);
count++;}
}
//for(k=1;k<n+1;k++)
//{printf("%d ",rep[k]);}
//printf("\n");
//printf("%d\n",count);
}
int sum=0;
for(i=1;i<n+1;i++)
{for(j=1;j<n+1;j++)
{if(a[i][j]==1)
{sum=sum+w[i][j];
//printf("%d %d %d \n",i,j,sum);
}
}
}
ans=sum/2;
printf("%d\n",ans);
return 0;
}
