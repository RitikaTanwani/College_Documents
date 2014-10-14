#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *right;
	int data;
	struct node *left;
}node;
node* insert(node *tree,int,int);
void pre(node *tree);
void post(node *tree);
//void del(node *tree,int num);
int a[1000];
int main()
{
int test,c=0;
scanf("%d",&test);
for(c=0;c<test;c++)
{
	int n,i=0,p;
	node *tree;
	tree=NULL;

//	int m=100000;
	scanf("%d",&n);
	//k=n-1;
	//k1=n-1;
	while(i<n)
	{
		scanf("%d",&a[i]);
	/*	if(a[i]<m)
		{m=a[i];
			p=i;
		}*/
		i++;
	}
	//tree=(node *)malloc(sizeof(node));
	//tree->data=a[p];
	//tree->left=tree->right=NULL;
	tree=insert(tree,0,n-1);
	pre(tree); 
        printf("\n");
        post(tree);
        printf("\n");
}
return 0;
	//printf("delete:\n");
	//scanf("%d",&num);
	//del(tree,num);
	//print(tree);
}
//int low=0,high;

node* insert(node *tree,int i,int j)
{
        int m;
	m=min(a,i,j);
//        printf("i:%d j:%d m:%d\n",i,j,m);
	if(j<i)
	{
		return tree;
	}
        //if(tree==NULL)
         //{
	tree=(node *)malloc(sizeof(node));
	tree->data=a[m];
         //tree->left=tree->right=NULL;
         //}
	tree->left=insert(tree->left,i,m-1);
	tree->right=insert(tree->right,m+1,j);
	return tree;
}




int min(int a[],int l, int h)
{
	int t=l+1;
	int min1=a[l];
	int p=l;
	while(t<=h)
	{
		if(a[t]<min1)
		{
			min1=a[t];
			p=t;
		}
		t++;
	}

	return p;
}

void pre(node *tree)
{
	if(tree!=NULL)
	{
		printf("%d ",tree->data);
		pre(tree->left);
		pre(tree->right);
	}
return;
	
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
