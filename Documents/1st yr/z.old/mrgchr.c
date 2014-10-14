//1.insert,2.delete,3.insert in sorted list,4.reverse
#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
char  marks;
struct student *next;
}std;
void del(std *list,char);
void insert(std *temp,char);
void print(std *list);
void sort(std *list,std *temp);
//void rev(std *list);
void con(std *list,std * list1);
void sum(std *list);
int main()
{
std *temp,*temp1;
std *list,*list1;
list=(std *)malloc(sizeof(std));
list->next=NULL;
temp=list;
list1=(std *)malloc(sizeof(std));
list1->next=NULL;
temp1=list1;
int i;
char h;
for(i=1;i<6;i++)
{
scanf("%c",&h);
insert(temp,h);
}

for(i=1;i<4;i++)
{
scanf("%c",&h);
insert(temp1,h);
}
print(list);
printf("\n");

print(list1);
}

void insert(std *temp,char i)
{
while(temp->next!=NULL)
{temp=temp->next;}
temp->next=(std *)malloc(sizeof(std));
temp->next->marks=i;
//temp=temp->next;
}
void print(std *list)
{
while(list->next!=NULL)
{
printf("%c",list->next->marks);
list=list->next;
}


//printf("%c",list->next->marks);
}

