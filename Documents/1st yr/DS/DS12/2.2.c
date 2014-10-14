#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
int insert(int,node *temp3);
void create(node *temp,int );
int create1(node *temp,int,int []);
void print(node *temp);
int main()
{
	int test,i=0;
	scanf("%d\n",&test);
	for(i=0;i<test;i++)
	{
		int num,p=1;
		char ch;
		node *new,*temp3,*new1,*temp4;
		new1=(node *)malloc(sizeof(node));
		new1->next=NULL;
		temp4=new1;

		new=(node *)malloc(sizeof(node));
		new->next=NULL;
		temp3=new;
		scanf("%d ",&num);
		int a[1000],y=0;
		while(num!=-1)
		{
			p=insert(num,temp3);

			if(p==1)
			{create(temp3,num);
				a[y]=num;
				y++;
			}
			scanf("%d",&num);
			scanf("%c",&ch);
		}
		a[y]=-50;
		//print(temp3);
		//printf("\n");
		p=1;
		scanf("%d ",&num);
		while(num!=-1)
		{
			p=insert(num,temp3);
			if(p==1 )
			{create(temp3,num);}			


			int u=create1(temp4,num,a);
//			printf("u:%d\n",u);
			scanf("%d",&num);
			scanf("%c",&ch);

		}
		print(temp3);
		printf("\n");
		print(temp4);
		printf("\n");

	}
	return 0;
}
int insert(int num,node *temp3)
{
	int p=1;
	while(temp3->next!=NULL){
		if(temp3->next->data==num)
		{p=0;}
		temp3=temp3->next;}
		if(p==1)
			return 1;
		else 
			return 0;
}
void create(node *temp,int num)
{
	while(temp->next!=NULL)
	{
 if(num<=temp->next->data)
 {break;}  
		temp=temp->next;
	}
node *link;
link=(node *)malloc(sizeof(node));
link->data=num;
link->next=temp->next;
temp->next=link;

//	temp->next=(node *)malloc(sizeof(node));
//	temp->next->data=num;
//	temp->next->next=NULL;
}
int create1(node *temp,int num,int a[])
{
	int k=1,i=0;
	while(a[i]!=-50)
	{
		if(a[i]==num)
		{k=0;}
		i++;
	}

	//printf("k:%d ",k);
	if(k==0 && temp->next==NULL)
	{
		temp->next=(node *)malloc(sizeof(node));
		temp->next->data=num;
		temp->next->next=NULL;
		return 1;
	}


	else if(k==0 && temp->next!=NULL)
	{

		while(temp->next!=NULL)
		{
			if(temp->next->data==num)
			{return 0;}
if(num<temp->next->data)
{break;}
			temp=temp->next;
		}
node *link;
  link=(node *)malloc(sizeof(node));
  link->data=num;
  link->next=temp->next;
  temp->next=link;
	//	temp->next=(node *)malloc(sizeof(node));
	//	temp->next->data=num;
	//	temp->next->next=NULL;
		return 1;
	}
	else
		return 0;
}
void print(node *temp)
{
	while(temp->next->next!=NULL)
	{
		printf("%d ",temp->next->data);
		temp=temp->next;
	}
printf("%d",temp->next->data);
}

