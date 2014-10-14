#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
int insert(int,node *temp3);
void create(node *temp,int );
void create1(node *temp,int );
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
		//list1=(node *)malloc(sizeof(node));
		//list1->next=NULL;

		//temp=list1;
		new1=(node *)malloc(sizeof(node));
		new1->next=NULL;
		temp4=new1;

		new=(node *)malloc(sizeof(node));
		new->next=NULL;
		temp3=new;
		scanf("%d ",&num);
		//new->next=(node *)malloc(sizeof(node));
		//new->next->data=num;
		//new->next->next=NULL;
		while(num!=-1)
		{
			p=insert(num,temp3);

			if(p==1)
			{create(temp3,num);}
                         else
                        {create1(temp4,num);}
			scanf("%d",&num);
			scanf("%c",&ch);
		}
				print(temp3);
		printf("\n");
		p=1;
		int u=1;
		scanf("%d ",&num);
	/*	while(temp3->next!=NULL)
		{
			if(temp3->next->data==num)
			{u=0;}
			temp3=temp3->next;
		}
		temp3=new;
		if(u==1)
		{create(temp3,num);}*/
		while(num!=-1)
		{
			p=insert(num,temp3);
			if(p==1 )
			{create(temp3,num);}			

else
{create1(temp4,num);}
			scanf("%d",&num);
			scanf("%c",&ch);

		}
		print(temp3);
		printf("\n");
//		print(temp4);
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
		temp=temp->next;
	}
	temp->next=(node *)malloc(sizeof(node));
	temp->next->data=num;
	temp->next->next=NULL;
}
void create1(node *temp,int num)
  {
          while(temp->next!=NULL)
          {
                  temp=temp->next;
          }
          temp->next=(node *)malloc(sizeof(node));
          temp->next->data=num;
          temp->next->next=NULL;
       }
void print(node *temp)
{
	while(temp->next!=NULL)
	{
		printf("%d",temp->next->data);
		temp=temp->next;
	}
}

