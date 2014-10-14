#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
int insert(node *temp,int);
void create(node *temp);
void print(node *temp);
int main()
{
	int test,i=0,num;
	scanf("%d\n",&test);
	for(i=0;i<test;i++)
	{
		node *list1,list2,*temp1,*temp2,*new,*temp3;
		list1=(node *)malloc(sizeof(node));
		list1->next=NULL;

		temp1=list1;
		list2=(node *)malloc(sizeof(node));
		list2->next=NULL;

		temp2=list2;

		new=(node *)malloc(sizeof(node));
		new->next=NULL;
		temp3=new;
		scanf("%d",&num);
		//new->next=(node *)malloc(sizeof(node));
		//new->next->data=num;
		//new->next->next=NULL;
		while(num!=-1)
		{
			p=insert(temp1,num,temp3);
			if(p==1)
			{create(temp3,num);}
			scanf("%d",&num);
		}
		p=1;
		int u=1;
		scanf("%d",&num);
		while(temp3->next!=NULL)
		{
			if(temp3->next->data==num)
			{u=0;}
			temp3=temp3->next;
		}
		temp3=new;
		while(num!=-1)
		{
			p=insert(temp2,num,temp3);
			if(p==1 && u!=0)
			{create(temp3,num);}			

			scanf("%d",&num);

		}
		print(temp3);
		return 0;
	}
	int insert(node *temp,int num,node *temp3)
	{
		int p=1;
		while(temp->next!=NULL)
		{
			while(temp3->next!=NULL){
				if(temp3->next->data==num)
				{p=0;}
				temp3=temp3->next;}
				temp=temp->next;
		}
		temp->next=(node *)malloc(sizeof(node));
		temp->next->data=num;
		temp->next->next=NULL;
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

	void print(node *temp)
	{
		while(temp->next!=NULL)
		{
			printf("%d",temp->next->data);
			temp=temp->next;
		}

