#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int j=1,z,test,s=1,x=0,i=0,f1=0;
	scanf("%d\n",&test);
//printf("a");
	char ch,a[test][100];
char u[100][3];
		int f;
	int num[test][50],num1[test];
	for(z=0;z<test;z++)
	{
//printf(" j:%d z:%d\n",j,z);
		int t=0,i=0;
		scanf("%c",&ch);
		while(1)
		{
//printf("r\n");
			a[z][i]=ch;
			i++;
			if(ch==',')
			{t++;
				if(t==4)
				{
					scanf("%c",&ch);
					break;}
			}
			scanf("%c",&ch);
		}
		a[z][i]='\0';
		t=0;
		scanf("%d",&num1[z]);
	scanf("%c",&ch);
if(z==0)
{
		num[z][0]=a[0][i-3]+a[0][i-4];
u[z][0]=a[0][i-4];
 u[z][1]=a[0][i-3];
u[z][2]='\0';
 
//       printf("@%s@",u[0]);         
//		printf("%d-%d",a[0][i-3]+a[0][i-4],z);
		num[0][1]=num1[0];
		num[0][2]=-1;
}
		if(z>0)
		{
			for(x=s-1;x>=0;x--)
			{
				f=0;
//printf("%c %c",a[z][i-3],u[x][1]);
				if(a[z][i-3]+a[z][i-4]==num[x][0] && a[z][i-3]==u[x][1])
				{
//printf("%d",f1);
					if(f1==1)
                                       {j=1;}
//printf("%d,j:%d,z:%d ",num[x][j],j,z);
//                                      printf("%d %d %d %d\n",num[0][0],num[0][1],num[0][2],num[0][3]);
					while(num[x][j]!=-1)
					{j++;}
  //                                    printf("%d %d %d %d\n",num[0][0],num[0][1],num[0][2],num[0][3]);
                          //          printf("//%dj ",j);
					num[x][j]=num1[z];
					num[x][j+1]=-1;
//printf("%d %d %d %d //\n ",j,num[x][j-1],num[x][j],num[x][j+1]);
					f=1;
                                         f1=0;
//printf("/%d/",num[0][1]);
					break;
					//num[x][j]=a[z][i-3]+a[z][i-4];
					//scanf("%d",&num1);
					//j++;
				}
			}
			if(f!=1)
			{
f1=1;
				num[s][0]=a[z][i-3]+a[z][i-4];
				num[s][1]=num1[z];
				num[s][2]=-1;
u[s][0]=a[z][i-4];
 u[s][1]=a[z][i-3];
u[s][2]='\0';
				s++;
//				j=1;
//printf("/%d/",num[0][1]);
//				break;
			}
		}
//	printf("j at end:%d\n",j);
      }
//printf("%d\n%d\n",z,s);
printf("%d %d %d %d",num[0][1],num[0][2],num[0][3],num[0][4]);
int sum[50]={0},max[s],mini[s];
for(i=0;i<s;i++)
{
mini[i]=1000000;
max[i]=0;
}
for(i=0;i<s;i++)
{
	j=1;
	while(num[i][j]!=-1)
	{
//printf("%d ",num[i][j]);
if(num[i][j]>max[i])
{
max[i]=num[i][j];
}
if(num[i][j]<mini[i])
{
mini[i]=num[i][j];
}
		sum[i]=sum[i]+num[i][j];
		j++;
	}
	sum[i]=sum[i]/(j-1);
//	printf(" *%d %d %d \n",max[i],mini[i],sum[i]);
}
for(i=0;i<s;i++)
{
int min=i;
for(j=i+1;j<s;j++)
{
if(num[j][0]<num[min][0])
min=j;
else if(num[j][0]==num[min][0])
{
if(max[j]>max[min])
{
min=j;
}
}
}
int temp=num[min][0];
num[min][0]=num[i][0];
num[i][0]=temp;

int temp1=max[min];
max[min]=max[i];
max[i]=temp1;

int temp2=mini[min];
mini[min]=mini[i];
mini[i]=temp2;
int temp3=sum[min];
sum[min]=sum[i];
sum[i]=temp3;

char temp4[5];
strcpy(temp4,u[min]);
strcpy(u[min],u[i]);
strcpy(u[i],temp4);
printf("%s , %d , %d , %d\n",u[i],max[i],mini[i],sum[i]);
}

return 0;
}


























