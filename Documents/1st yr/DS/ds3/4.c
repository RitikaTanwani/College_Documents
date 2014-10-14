#include<stdio.h>
#include<stdlib.h>
int x;
typedef struct node
{
	struct node *right;
	int data;
	struct node *left;
}node;
node* insert(node *tree,int m,int n,int i,int j);
int search(int a[],int num,int l, int h);
void print(node *tree);
//void del(node *tree,int num);
int a[1000],b[1000];
int main()
{
int test,c=0;
scanf("%d",&test);
for(c=0;c<test;c++)
{
	int n,z=0;
	node *tree;
	tree=NULL;

	scanf("%d",&n);
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
	tree=insert(tree,0,n-1,0,n-1);
	print(tree);
printf("\n");
	/*for(i=0;i<j;i++)
	  {
	  printf("%d\n",a[i]);
	  printf("%d\n",b[i]);
	  }*/
}
	return 0;
}

//printf("delete:\n");
//scanf("%d",&num);
//del(tree,num);
//print(tree);

//int low=0,high;

node* insert(node *tree,int m,int n,int i,int j)
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
	tree->left=insert(tree->left,m,p-1,i+1,i+p);
	tree->right=insert(tree->right,p+1,n,i+p-m+1,j);
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
void print(node *tree)
{
	if(tree!=NULL)
	{
		print(tree->left);
		print(tree->right);
		printf("%d ",tree->data);
	}
	return;
}
