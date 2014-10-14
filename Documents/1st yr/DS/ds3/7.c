#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *right;
	int data;
	struct node *left;
}node;
node* insert(node *tree,int m,int n,int i,int j);
int search(int a[],int num,int l, int h);
void post(node *tree);
void in(node *tree);
void swap(node *tree);
//void del(node *tree,int num);
int a[1000],b[1000];
int main()
{
int test,c;
scanf("%d",&test);
for(c=0;c<test;c++)
{

	int n,z=0;
	node *tree;
	tree=NULL;

	scanf("%d",&n);
	while(z<n)
	{
		scanf("%d",&a[z]);
		
		z++;
	}
z=0;
	while(z<n)
	{
		scanf("%d",&b[z]);
		
		z++;
	}
	tree=insert(tree,0,n-1,0,n-1);
//	print(tree);
        swap(tree);
	post(tree);
printf("\n");
in(tree);
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

void swap(node *tree)
{
	//if(tree->left!=NULL && tree->right!=NULL)
	if(tree==NULL)
	{
		return;
	}
	
		node *k;
		k=tree->left;
		tree->left=tree->right;
		tree->right=k;
	//	free(k);
		swap(tree->left);
		swap(tree->right);
         return;
	
/*	if(tree->left==NULL && tree->right!=NULL)
	{
		//tree->left=(node *)malloc(sizeof(node));
		tree->left=tree->right;

		free(tree->right);
		swap(tree->left);
	}
	if(tree->right==NULL && tree->left!=NULL)
	{
		tree->right=tree->left;
		free(tree->left);
		swap(tree->right);
	}*/
}


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
	int p=search(a,b[i],m,n);
	//printf("p:%d\n",search(a,b[i],m,n));
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
void post(node *tree)
{
	if(tree!=NULL)
	{
		post(tree->left);
		post(tree->right);
		printf("%d ",tree->data);
	}
	return;
}
void in(node *tree)
{
	if(tree!=NULL)
	{
		in(tree->left);
		printf("%d ",tree->data);
		in(tree->right);
	}
	return;
}
