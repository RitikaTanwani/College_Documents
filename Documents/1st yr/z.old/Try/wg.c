#include<stdio.h>
#include<math.h>
long long int f(char);
char s,p[1000];
int r=0;
int main()
{
	char ch;
	long long int res;
	while(scanf("%c",&ch)!=EOF)
	{
		int l,b[100000]={0};
		res=f(ch);
		scanf("%c",&ch);
		if(ch==' ')
		{scanf("%c",&ch);}
		if(s=='+'){
			res=res+f(ch);}
		else if(s=='-')
		{res=res-f(ch);}
		else if(s=='*')
		{res=res*f(ch);}
		else if(s=='/')
		{res=res/f(ch);}
		if(res==0 )
		{printf(" = 10");
		}
		else if(res!=0)
		{int h=0,c[100],u=0;
			while(res!=0)
			{ l=res%10;
				res=res/10;
				b[u]=l;
				u++;
		//		printf("%d>>>>",u);
			}
			printf(" = ");
				int count1=1;
				for(h=u-1;h>0;h--)
				{if(b[h-1]==b[h])
					{count1++;
                                        //    printf("%d\n",h);
						if(count1==9)
						{printf("%d%d",count1,b[h]);
							count1=1;
							h--;
							//continue;
						}
						}
						else
						{printf("%d%d",count1,b[h]);
						count1=1;}	
				}
				printf("%d%d",count1,b[0]);
			
		}
			printf("\n");
	}
			return 0;
}
	int a[1000],t[2],y[1000];
long long int f(char ch)
{
	int j,i=0,n=0,k;
	while(ch!='/'&& ch!='*'&& ch!='+'&& ch!='-'&&ch!='\n')
	{
		a[i]=ch-'0';
		printf("%d",a[i]);
		i++;
		scanf("%c",&ch);
		if(ch==' ')
		{scanf("%c",&ch);}
	}
	s=ch;
	n=i;

//printf("%d %d",a[0],a[1]);
	if(s!='\n'){
	printf(" %c ",s);}
	long long int rv=0;
int z=0;
int d=0;
while(z<=n-2)
{for(d=0;d<a[z];d++)
{rv=rv*10+a[z+1];}
d=0;
z=z+2;
}
//printf("* %lld ",rv);
	return rv;
}



