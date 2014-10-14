#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int validvar=0;
int errnum=0;
typedef struct node
{
	struct node *next;
	int scope;
	char var[9];
	int error;
}node;
void insert(node *list,int v,char s[]);
void print(node *arr);
void p(node *tab,int y);
void e(node *tab,int y);
int t[100],pp=-1,count1=-1;
void push(int x);
void pop();
int main()
{
	char a[9];
while(scanf("%s",a)!=EOF)
{
	node *tab[37];
	int h;
	for(h=0;h<37;h++)
	{
		tab[h]=(node *)malloc(sizeof(node));
		tab[h]->next=NULL;
	}



	int k1;
//	scanf("%s",a);
	//printf("p\n");
	while(1)
	{
		if(strcmp(a,"DONE")==0)
		{
break;}
		if(a[0]=='{')
		{
count1++;
                push(count1);
		}
		if(a[0]=='}')
		{
                  pop();
//			printf("in:%d\n",k1);
                        //if(k1==-1) {k2++;}
//			if(k3==0)
//			{
//				k1=k2;
//			}
		} 


//		printf("sentscope:%d\n",k1);
		if(a[0]!='{' && a[0]!='}')
		{
//			printf(" p1\n");
			int hashvalue;
			hashvalue=ascii(a);
//printf("hashv:%d\n",hashvalue);

			insert(tab[hashvalue],t[pp],a);
		}
		scanf("%s",a);
	}
printf("%d\n%d\n",validvar,errnum);
//printf("k2:%d",k2);
//	print(tab[33]);
//	print(tab[2]);

int z,y;
for(y=0;y<=count1;y++)
{
for(z=0;z<37;z++)
{
p(tab[z],y);
}
}
//printf("O//");
for(y=0;y<=count1;y++)
{
for(z=0;z<37;z++)
{
e(tab[z],y);
}
}
count1=-1;
validvar=0;
errnum=0;
}

return 0;
}

void push(int x)
{
pp++;
t[pp]=x;
}
void pop()
{
pp--;
}


void e(node *tab,int y)
{
int g;
while(tab->next!=NULL)
{
tab=tab->next;
for(g=0;g<tab->error;g++)
{
if(tab->scope==y && tab->error)
{
printf("%s,%d\n",tab->var,tab->scope);
}
}
/*if(tab->error==1)
{
printf("widerror : %s,%d\n",tab->var,tab->scope);
}*/
}
}




void p(node *tab,int y)
{
while(tab->next!=NULL)
{
tab=tab->next;
if(tab->scope==y)
{
printf("%s,%d\n",tab->var,tab->scope);
}
/*if(tab->error==1)
{
printf("widerror : %s,%d\n",tab->var,tab->scope);
}*/
}
}
int ascii(char s[])
{
	int j=0,k=0,name[8],val;
	for(j=0;j<8;j++)
	{
		name[j]=s[j];
		if(name[j]==0)
		{
			for(k=j+1;k<8;k++)
			{
				name[k]=0;
			}
			break;
		}
	}
	val=(name[0]*27 + name[1]*53 + name[2]*11 + name[3]*23 + name[4]*31 + name[5]*7 + name[6]*29 + name[7]*13)%37 ;

	return val;
}

void insert(node *list,int v,char s[])
{int flag=0;
	while(list->next!=NULL)
	{
		flag=0;
		list=list->next;
//               printf("O:%s\n",list->var);
		if(list->scope==v)
		{
//printf("in:%s %d\n",s,v);
                 errnum++;
			list->error++;
//printf("::%d\n",list->error);
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
                validvar++;
		list->next=(node *)malloc(sizeof(node));
		list->next->scope=v;
		strcpy(list->next->var,s);
		list->next->error=0;
                list->next->next=NULL;
	}

		/*printf("%s\n",list->var);
		printf("scp:%d",list->scope);
		printf("err:%d",list->error);*/
}

void print(node *arr)
{
	while(arr!=NULL)
	{
		arr=arr->next;
		printf("var:%s\n",arr->var);
		printf("scp:%d",arr->scope);
		printf("err:%d",arr->error);

	}
}

