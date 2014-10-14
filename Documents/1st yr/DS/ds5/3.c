#include<stdio.h>
#include<stdlib.h>
int x,hh=0;
typedef struct node
{
	struct node *right;
	int data;
	struct node *left;
}node;
node* insert(node *tree,int m,int n,int i,int j,int b[],int a[]);
int search(int a[],int num,int l, int h);
node *singleleft(node *k1);
node *singleright(node *k1);
node *rotate(node *tree,int num);
void inprint(node *tree,int print[]);
void preprint(node *tree,int print[]);
void postprint(node *tree,int print[]);
//void del(node *tree,int num);
int main()
{
	int test,c=0;
	//scanf("%d",&test);
	int n,z=0,numb;
	node *tree;
	tree=NULL;

	scanf("%d",&n);
int print[n];
int a[n+1],b[n+1];
	while(z<n)
	{

		scanf("%d",&b[z]);
		z++;
	}
	z=0;
	while(z<n)
	{
		scanf("%d",&a[z]);

		z++;
	}
	x=n;
	tree=insert(tree,0,n-1,0,n-1,b,a);
	scanf("%d",&numb);
	while(tree->data!=numb)
	{
		tree=rotate(tree,numb);
	}
	inprint(tree,print);
	for(z=0;z<hh-1;z++)
	{printf("%d ",print[z]);
	}
	printf("%d\n",print[hh-1]);
	hh=0;
	preprint(tree,print);
	for(z=0;z<hh-1;z++)
	{printf("%d ",print[z]);
	}
	printf("%d\n",print[hh-1]);
	hh=0;

	postprint(tree,print);
	for(z=0;z<hh-1;z++)
	{printf("%d ",print[z]);
	}
	printf("%d\n",print[hh-1]);
	hh=0;

	/*for(i=0;i<j;i++)
	  {
	  printf("%d\n",a[i]);
	  printf("%d\n",b[i]);
	  }*/
	return 0;
}
node *rotate(node *tree,int num)
{
	if(num<tree->data)
	{
		if(tree->left !=NULL)
		{
//printf("%d\n",tree->data);
			if(tree->left->data==num)
			{
				tree=singleleft(tree);
			}
					else
			{tree->left=rotate(tree->left,num);
			}
		}
		return tree;
	}
	else if(num>tree->data)
	{
		if(tree->right!=NULL)
		{
//printf("i%d\n",tree->data);
			if(tree->right->data==num)
			{
				tree=singleright(tree);
			}
						else
			{tree->right=rotate(tree->right,num);
			}
		}
		return tree;
	}
}

node *singleleft(node *k1)
{
	node *k2;
	k2=k1->left;
	k1->left=k2->right;
	k2->right=k1;
	return k2;
}
node *singleright(node *k1)
{
	node *k2;
	k2=k1->right;
	k1->right=k2->left;
	k2->left=k1;
	return k2;
}















node* insert(node *tree,int m,int n,int i,int j,int b[],int a[])
{
	//int p;
	//	printf("m:%d n:%d i:%d j:%d \n",m,n,i,j);
	if(m>n)
	{
		return tree;
	}
	if(i>j)
	{
		return tree;
	}
	tree=(node *)malloc(sizeof(node));
	tree->data=b[i];
	tree->left=tree->right=NULL;
	int p=search(a,b[i],0,x-1);
	//	printf("p:%d\n",search(a,b[i],0,x));
	tree->left=insert(tree->left,m,p-1,i+1,i+p,b,a);
	tree->right=insert(tree->right,p+1,n,i+p-m+1,j,b,a);
	return tree;
}


int search(int a[],int num,int l, int h)
{
	int k=l,p;
	while(k<=h)
	{
		if(a[k]==num)
		{
			p=k;
			break;
		}
		k++;
	}
	return p;
}
void inprint(node *tree,int print[])
{
	if(tree!=NULL)
	{
		inprint(tree->left,print);
		print[hh]=tree->data;
		hh++;
		//		printf("%d ",tree->data);
		inprint(tree->right,print);
	}
	return;
}
void preprint(node *tree,int print[])
{
	if(tree!=NULL)
	{
		//printf("%d ",tree->data);
		print[hh]=tree->data;
		hh++;
		preprint(tree->left,print);
		preprint(tree->right,print);
	}
	return;
}
void postprint(node *tree,int print[])
{
	if(tree!=NULL)
	{
		postprint(tree->left,print);
		postprint(tree->right,print);
		//printf("%d ",tree->data);
		print[hh]=tree->data;
		hh++;
	}
	return;
}
