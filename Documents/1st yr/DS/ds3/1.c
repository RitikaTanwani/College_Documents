#include<stdio.h>
#include<stdlib.h>
int dd;
typedef struct node
{
	int l;
	struct node *right;
	int data;
	struct node *left;
}node;
node* insert(node *tree,int num);
void print(node *tree,int);
void del(node *tree,int num);
void printLevelorder(node *tree,int max);
void printGivenLevel(node *tree, int level);
int c=0;
int main()
{
int test,z;
scanf("%d",&test);

for(z=0;z<test;z++)
{c=0;
	int n,i=0,num;
	node *tree;
	tree=NULL;

int max=0;
	scanf("%d",&n);
	while(i<n)
	{
		scanf("%d",&num);
		tree=insert(tree,num);
                 if(c>max)
                  {
                  max=c;}
                 c=0;
		i++;
	}
	scanf("%d",&dd);
//	printf("count:%d\n",max);
//	printLevelorder(tree,max);
//        printLevelorder(tree,1);o
int g=1;
while(g<=max)
{
printGivenLevel(tree,g);
g=g+dd;
}
printf("\n");
}

return 0;
}




node* insert(node *tree,int num)
{
	if(tree==NULL)
	{c++;
		tree=(node *)malloc(sizeof(node));
		tree->data=num;
		tree->left=NULL;
		tree->right=NULL;
	}
	else
	{
		if(num<tree->data)
		{c++;
			tree->left=insert(tree->left,num);
		}
		else if(num>tree->data)
		{c++;
			tree->right=insert(tree->right,num);
		}
	}
	return tree;
}

void printGivenLevel(node *tree, int level)
{
if (tree ==NULL)
{ return;}
if (level == 1)
   {// printf("<:%d \n",tree->data);
   print(tree,1);
    //h=0;
 //p=0;
   // flag=1;
    }
else if (level > 1)
{    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);
}
}

void print(node *tree,int m)
{
	if(tree==NULL || m==dd+1)
		return;
	printf("%d ",tree->data);
	print(tree->left,m+1);
	print(tree->right,m+1);
}





