#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
void insert(node *temp,int,int);
//void print(node *temp);
void del(int,node *temp,int);
int cycle(int i,node *temp,int n);
int prime(int);
int main()
{
	int n=1;
	int num,num1,n1;

	node *list,*temp;

	scanf("%d\n",&n1);
	list=(node *)malloc(sizeof(node));
	list->next=NULL;
	list->next=(node *)malloc(sizeof(node));
	list->next->data=n1;
	temp=list;
	while(scanf("%d %d\n",&num,&num1)!=EOF)
	{
		insert(temp,num,num1);
		n++;
	}
	//print(temp);
	int j=0,i,p=5,r;
	while(n>=p)
	{
		del(p,temp,n);
		n=n-n/p;
		p=p+1;
		r=prime(p);
		p=r;
	}
	int h=cycle(p,temp,n);
	n=n-1;
	//	print(temp);
	while(h!=1)
	{
		p=p+1;
		r=prime(p);
		p=r;
		h=cycle(p,temp,n);
		n=n-1;
	}
	//	printf("h:%d p:%d\n",h,p);
	printf("%d\n",temp->next->data);
//	printf("\n");
	return 0;
}
int prime(int p)
{
	int flag1=0;
	int y;
	while(flag1!=1)
	{
		flag1=1;
		for(y=p-1;y>1;y--)
		{
			if(p%y==0)
			{
				flag1=0;
				break;
			}
		}
		if(flag1==1)
		{return p;}
		else
			p++;
	}
}
int cycle(int i,node *temp,int n)
{
	int c=i%n;
	//printf("c:%d",c);
	int j=1;
	while(temp->next!=NULL)
	{
		if(j==c)
		{
			node *check;
			check=temp->next;
			{printf("%d : %d\n",i,temp->next->data);}
			temp->next=temp->next->next;
			free(check);
			break;
		}
		temp=temp->next;
		j++;
	}
	if(temp->next==NULL)
	{return 1;}
	else
		return 0;
}
void del(int i,node *temp,int n)
{
	int c=0;
	int t=0,u[50]={0};
	int k=i;
	printf("%d : ",k);
	while(temp->next!=NULL && temp->next->next!=NULL)
	{c++;

		temp=temp->next;
		if(c==i-1)
		{
			node *check;
			check=temp->next;
			u[t]=temp->next->data;
			//		{printf("%d ",u[t]);}
			t++;
			//		{printf("t:%d",t);}
			temp->next=temp->next->next;
			free(check);
			if(i<n)
			{i=i+k;
				c++;
			}
		}
	}
	for(i=0;i<t-1;i++)
	{printf("%d ",u[i]);}
	printf("%d\n",u[t-1]);
}
void insert(node *temp,int num,int num1)
{
	node *put;
	while(temp->next!=NULL)
	{
		if(temp->next->data==num1)
		{temp=temp->next;
			break;
		}
		temp=temp->next;

	}
	put=(node *)malloc(sizeof(node));
	put->data=num;
	put->next=temp->next;
	temp->next=put;
}
/*void print(node *temp)
{
	while(temp->next->next!=NULL)
	{
		printf("%d ",temp->next->data);
		temp=temp->next;
	}
	printf("%d",temp->next->data);
}*/



