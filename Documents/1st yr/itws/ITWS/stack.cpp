#include<cstdio>
#include<cstdlib>
#include<iostream>

class stack
{
	private:
	//pointer to array containing data
	int a[100];
	int i;
	public:
	stack()
	{
		i=-1;
	}
	~stack()
	{
//		free(a);
	}
	void push(int data)
	{
		i++;
		a[i]=data;
	}
	int is_empty()
	{
		if(i==-1)
		{
			return 1;
		}
		else return 0;
	}
	int pop()
	{
		int k;
		if(is_empty()==1)
		{
			return -1;
		}
		else 
		{
			k=a[i];
			i--;
			return k;
		}
	}
	int size()
	{
		return i+1;
	}
	int find(int data)
	{
		int j;
		for(j=0;j<=i;j++)
		{
			if(a[j]==data)
			{
				return 1;
			}
		}
		return 0;
	}
};
int main(int argc,char *argv[])
{
	stack s;
	printf("%d\n",s.is_empty());
	s.push(40);
	s.push(50);
	printf("%d\n",s.find(50));
	printf("%d\n",s.find(30));
	printf("%d\n",s.pop());
	s.push(70);
	printf("%d\n",s.is_empty());
	s.push(80);
	return 0;
}

