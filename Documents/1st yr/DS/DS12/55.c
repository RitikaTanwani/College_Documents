#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
int p=0;
double sum2=0;

	int z,test,f1=0;
	scanf("%d\n",&test);
int count1[test+1];
	int age[test+1];
	//	scanf("%d %d\n",&r1,&r2);
long int num1[test+1],y;
	scanf("%ld",&y);
	/*if(r1>r2)
	  {
	  temp=r1;r1=r2;r2=temp;
	  }*/
	int f,num[test+1][10],s=1,x=0,j=1;
	char u[test+1][10];
	char a[test+1][100],ch;
	for(z=0;z<test;z++)
	{
		int t=0,i=0;
		scanf("%c",&ch);
		while(1)
		{
			a[z][i]=ch;
			i++;
			if(ch==',')
			{t++;
				if(t==2)
				{
					scanf("%c",&ch);
					scanf("%d",&age[z]);

				}
				if(t==4)
				{
					scanf("%c",&ch);
					scanf("%ld",&num1[z]);

					break;
				}
			}
			scanf("%c",&ch);
		}
		a[z][i]='\0';
		scanf("%c",&ch);
		//printf("%c %c",a[0][i-3],a[0][i-4]);
		if(z==0)
		{
			num[z][0]=a[0][i-3]+a[0][i-4];
			u[z][0]=a[0][i-4];
			u[z][1]=a[0][i-3];
			u[z][2]='\0';
			num[0][1]=num1[0];
			num[0][2]=-1;
if(num1[z]>y)
{
count1[0]=1;
sum2=sum2+age[z];
p++;}
else
count1[0]=0;
		}
		if(z>0)
		{
			for(x=s-1;x>=0;x--)
			{
				f=0;
				if(a[z][i-3]+a[z][i-4]==num[x][0] && a[z][i-3]==u[x][1])
				{
if(num1[z]>y)
{
count1[x]++;
sum2=sum2+age[z];
p++;
}

			/*	ddd	if(f1==1)
					{j=1;}
					while(num[x][j]!=-1)
					{j++;}
					num[x][j]=num1[z];
					num[x][j+1]=-1;*/
					f=1;
	//				f1=0;
					break;
				}
			}
			if(f!=1)
			{
	//			f1=1;
				num[s][0]=a[z][i-3]+a[z][i-4];
				num[s][1]=num1[z];
				num[s][2]=-1;
				u[s][0]=a[z][i-4];
				u[s][1]=a[z][i-3];
				u[s][2]='\0';
if(num1[z]>y)
{
count1[s]=1;
sum2=sum2+age[z];
p++;
}
else
count1[s]=0;
//printf("%d %d//\n",count1[s],s);
				s++;
			}
		}
		//printf("//%d %d %d \n ",num[0][1],num[1][1],num[2][1]);

	}
//printf("%d %d %d \n",count1[1],count1[2],count1[3]);
	//printf("out s:%d\n",s);
/*	double sum=0;
	int p=0;
	for(z=0;z<test;z++)
	{
		if(num1[z]>y)
		{
			sum=sum+age[z];
			p++;
		}
	}*/
double avg;
          if(p!=0)
{avg=sum2/(p);}
          else
{ avg=0;}
/*
	int i,count[s+1];
	for(i=0;i<s;i++)
	{count[i]=0;}
	for(i=0;i<s;i++)
	{
		j=1;
		//printf("//%d//",num[i][j]);
		while(num[i][j]!=-1)
		{
			if (num[i][j]>=y)
			{
				count[i]++;
				//printf("** i:%d j:%d\n",i,j);
			}
			j++;
		}
		//printf("%d\n",count[i]);
	}*/
	printf("%.4lf\n",avg);
int i;
	for(i=0;i<s;i++)
	{
		int min=i;
		for(j=i+1;j<s;j++)
		{
			if(num[j][0]<num[min][0])
				min=j;
			else if (num[j][0]==num[min][0])
			{
				if(count1[j]>count1[min])
				{min=j;}
			}
		}


	double temp=num[min][0];
		num[min][0]=num[i][0];
		num[i][0]=temp;

	double temp1=count1[min];
		count1[min]=count1[i];
		count1[i]=temp1;
		char temp4[5];
		strcpy(temp4,u[min]);
		strcpy(u[min],u[i]);
		strcpy(u[i],temp4);

		printf("%s , %d\n",u[i],count1[i]);
	}
	return 0;
}


























