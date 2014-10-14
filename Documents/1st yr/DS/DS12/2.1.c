#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *next;
}node;
int insert(node *temp,char);
//void del(node *temp);
int main()
{
int test,i=0;
scanf("%d\n",&test);
for(i=0;i<test;i++)
{
	char ch;
	int p=0;
	node *list,*temp;
	list=(node *)malloc(sizeof(node));
	list->next=(node *)malloc(sizeof(node));
	list->next->data='?';
	list->next->next=NULL;
	temp=list;
	scanf("%c",&ch);
	while(ch!='\n')
	{
		p=insert(temp,ch);
//		printf("p:%d",p);
		if(p==1)
			scanf("%c",&ch);
		else if(p==0)
		{
			while(ch!='\n')
			{
				scanf("%c",&ch);
			}
                        break;
		}
	}
	if(p==1)
	{
		printf("YES\n");
	}
	else
		printf("NO\n");
}
	return 0;
}

int insert(node *temp,char ch)
{
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	if(ch=='('||ch=='{'||ch=='[')
	{
		temp->next->next=(node *)malloc(sizeof(node));
		temp->next->next->data=ch;
		temp->next->next->next=NULL;
		return 1;
	}
	else if(ch=='}')
	{
		if(temp->next->data=='{')
		{
			temp->next=NULL;
                         return 1;
		}
		else
			return 0;
	}
	else if(ch==')')
	{
		if(temp->next->data=='(')
		{
			temp->next=NULL;
                         return 1;
		}
		else
			return 0;
	}
	else if(ch==']')
	{
		if(temp->next->data=='[')
		{
			temp->next=NULL;
                         return 1;
		}
		else
			return 0;
	}

}
