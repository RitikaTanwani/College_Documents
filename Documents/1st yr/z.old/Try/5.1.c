#include<stdio.h>
#include<string.h>
int main()
{
       int h=0,test;
scanf("%d\n",&test);
while(h<test)
{
	char s[1000],b[1000];
	int u,i,num=0,z=0,n,key;
	scanf("%s%d",s,&key);

	i=num+1;	
	n=strlen(s);
if(key==0)
{printf("%s",s);}
else
{	
	while(z<key && num!=n)
	{
	if(s[num]=='a'||s[num]=='e'||s[num]=='i'||s[num]=='o'||s[num]=='u')	
	{
		b[num]=s[num];
		num++;
		i=(num+1)%n;
//printf("%d*",i);
	}
	else{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')	
       {
        i=(i+1)%n;   	
       }	
       else
       {
       	z++;u=i;
       	i=(i+1)%n;
//printf("%d*",i);
       }
	if(z==key)
	{
		z=0;
		b[u]=s[num];

//printf("%c%d",b[u],u);
		num++;

i=(num+1)%n;
	}
    
	}
	}
	//if(num==n)
//printf("\n");

	for(z=0;z<n;z++)
	{printf("%c",b[z]);}
}


printf("\n");
h++;}
return 0;	
}
