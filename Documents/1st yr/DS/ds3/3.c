#include<stdio.h>
int hash(int);
void sec(int i,int x,int size);
int i,j,a,b,p,m;
int c[25],d[25],size[31],z[31][625],count[31]={0};
int main()
{
//	while(scanf("%d",&c[0])!=EOF)
	//{
		for(i=0;i<25;i++)
		{
			scanf("%d",&c[i]);
		}
		scanf("%d %d %d %d",&a,&b,&p,&m);
		for(i=0;i<25;i++)
		{
			d[i]=hash(c[i]);
			count[d[i]]++;

			//printf("%d ",count[d[i]]);
		}
		for(i=0;i<31;i++)
		{
			for(j=0;j<625;j++)
			{
				z[i][j]=-1;
			}
		}
		for(i=0;i<31;i++)
		{

			if(count[i]>1)
			{
				for(j=0;j<25;j++)
				{
					if(d[j]==i)
					{
						 size[i]=count[i]*count[i];


						int k=(((a*c[j]+b)%p)%size[i]);
						z[i][k]=c[j];
                                                
					}
					//printf("s :%d ",s);
				}
			}
		}
		for(i=0;i<31;i++)
		{

				for(j=0;j<25;j++)
				{ 
if(count[i]==1){
					if(d[j]==i)
					{
						//y[d[i]]=c[j];
						printf("%d %d\n",i,c[j]);
					}}

				}
			
			if(count[i]>1)
			{
printf("%d %d\n",i,size[i]);

				int s=0;
				for(j=0;j<625;j++)
				{
//      					if(d[j]==i)
	//            printf("%d %d\n",i,c[j]);
					if(z[i][j]!=-1)
					{
						s++;
						printf("%d %d",j,z[i][j]);
						if(s==count[i])
						{
							printf("\n");}
						else if(s!=count[i]) 
							printf(" ");
						//printf("\n");

					}
				}
			}

		}
	
	return 0;
}
/*void sec(int i,int x,int size)
{
	int k=(((a*x+b)%p)%size);
	z[i][k]=x;
	printf("%d %d",k,z[i][k]);
}
*/



int hash(int x)
{
	int k=(((a*x+b)%p)%m);
	return k;
}
