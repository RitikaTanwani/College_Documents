//insert,print,delete,level order printing,height
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
}node;
node *insert(node *,int);
void print(node *);
int search(node *tree,int s);
node *del(node *tree,int);
int c=0,min;
node *findmin(node *tree);
int h(node *tree);//height of a tree
int main()
{
	int z=0,num,n;
	node *tree;
	tree=NULL;
	scanf("%d",&num);
	
	for(z=0;z<num;z++)
	{
		scanf("%d",&n);
		tree=insert(tree,n);
	}
	print(tree);
	int s,d;
	printf("\nsearch:");
    scanf("%d",&s);
	printf("depth of %d is %d",s,search(tree,s));
	printf("\ndelete:");
    scanf("%d",&d);
min=1000;
//  tree=findmin(tree);
//printf("\n%d\n",min);
tree=del(tree,d);
print(tree);
printf("\n");
// level order printing
int x,i=0,j=0;
node *arr[num];
for(x=0;x<=num;x++)
{
arr[x]=NULL;
}
arr[j]=tree;

while(arr[j]!=NULL)
{
printf("%d\n",arr[j]->data);
if(arr[j]->left)
{
i++;
arr[i]=arr[j]->left;
}
if(arr[j]->right)
{
i++;
arr[i]=arr[j]->right;
}
j++;


}
return 0;
}

int h(node *tree)
{
if( tree == NULL)
{return -1;}
int max=h(tree->left);
if(max<h(tree->right))
{
return 1+h(tree->right);
}
else
{
return 1+max;
}
}




node *findmin(node *tree)
         {

if(tree==NULL)
{
	return;
}
tree->left=findmin(tree->left);
tree->right=findmin(tree->right);

 int a=tree->data;
 if(a<min)
{
	min=a;
}

return tree;

}
node *del(node *tree,int s)
{
	if (tree==NULL)
{
return NULL;
}
	if(s==tree->data)
	{

		if(tree->left && tree->right==NULL)
		{
			tree=tree->left;
		}
		else if(tree->right && tree->left==NULL)
		{
			tree=tree->right;
		}
		else if(tree->left && tree->right)
		{
			node *temp;
		temp=findmin(tree->right);
		//tree=temp;
		tree=del(tree,min);
		tree->data=min;
		}

            

		
		else
		{
			tree=NULL;
		}
	}

	else if(s<tree->data)
	{
		//	c++;
		tree->left=del(tree->left,s);
	}
	else if(s>tree->data)
	{
		//	c++;
		tree->right=del(tree->right,s);
	}
	return tree;
}



node *insert(node *tree,int num)
{
	if(tree==NULL)
	{
		tree=(node *)malloc(sizeof(node));
		tree->data=num;
		tree->left=tree->right=NULL;
	}
	else if(num<tree->data)
	{
		tree->left=insert(tree->left,num);
	}
	else if(num>tree->data)
	{
		tree->right=insert(tree->right,num);
	}
	return tree;
}
int search(node *tree,int s)
{
	if(tree==NULL)
	{c=-1;}

	else{	
	if(s==tree->data)
	{
		c++;
	}
	else if(s<tree->data)
{
	c++;
	search(tree->left,s);
}
else if(s>tree->data)
{
	c++;
	search(tree->right,s);
}
}
return c;
}




void print(node *tree)
{
	if(tree==NULL)
		return;
	print(tree->left);
	printf("%d ",tree->data);
	printf("h:%d\n",h(tree));
	print(tree->right);
}
