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
void printLevelorder(node *tree,int);
int checkavl(node *tree);
void printavl(node *tree);
//int search(int a[],int num,int l, int h);

void printG(node *tree,int level);
//void print(node *tree);
int h(node *tree);
//void del(node *tree,int num);
int a[1000],b[1000],height=0;
int main()
{
	int test,c=0;
	scanf("%d",&test);
	for(c=0;c<test;c++)
	{
		int n,z=0;
		node *tree;
		tree=NULL;
		int bst=1;
		scanf("%d",&n);
		while(z<n)
		{
			scanf("%d",&a[z]);
			if(z!=0)
			{
				if(a[z]<a[z-1])
				{
					bst=0;
				}
			}
			z++;
		}
		z=0;
		while(z<n)
		{
			scanf("%d",&b[z]);

			z++;
		}
		x=n;
		tree=insert(tree,0,n-1,0,n-1);
		//print(tree);
	//	printf("\n");
		printf("%d\n",bst);
height=h(tree);
//printf("h:%d\n",height);
//printavl(tree);
int l;
if(bst==1)
{
l=checkavl(tree);
if(l==0)
{
printf("0\n");
printavl(tree);
printf("\n");
}
else if(l==1)
{
printf("1\n");
}


}
else
{
printf("0\n");
}

		/*for(i=0;i<j;i++)
}	  {
		  printf("%d\n",a[i]);
		  printf("%d\n",b[i]);
		  }*/
	}
	return 0;
}

int checkavl(node *tree)
{
int d,k;
for(d=1;d<=height+1;d++)
   {
k=printGivenLevel(tree, d);
if(k==0)
{
break;
}
}
if(k==0)
 return 0;
else
 return 1;
}
void printavl(node *tree)
{int d;
for(d=1;d<=height+1;d++)
{

printG(tree,d);

}
}
void printG(node *tree,int level)
{
if(tree== NULL ){return;}
if (level==1){
if((h(tree->left)-h(tree->right))>1 | (h(tree->right)-h(tree->left))>1 )
    printf("%d ",tree->data);}
else if (level > 1)
{
    printG(tree->left, level-1);
    printG(tree->right, level-1);
}
}





void printLevelorder(node *tree,int level)
{
printf("level:%d ",level);
if (tree==NULL)
 return;
if (level==1)
{
//printf("f1");
  //  printf("%d ",tree->data);
if((h(tree->left)-h(tree->right))>1 | (h(tree->right)-h(tree->left))>1 )
printf("%d ",tree->data);
}
else if (level>1) 
{
    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);
}
}


/*Function to print all nodes at a given level*/
int printGivenLevel(node *tree, int level)
{
if (tree==NULL)
 return;
if (level==1)
{
    //print(tree->data);
if((h(tree->left)-h(tree->right))>1 | (h(tree->right)-h(tree->left))>1)
   return 0;
else
  return 1;

}
else if (level>1) 
{
    printGivenLevel(tree->left, level-1);
    printGivenLevel(tree->right, level-1);
}
}








int h(node *tree)
{
if(tree==NULL)
{
return -1;
}
if(h(tree->left)>h(tree->right))
{
return 1+h(tree->left);
}
else
{
return 1+h(tree->right);
}
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
