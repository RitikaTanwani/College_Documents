#include<stdio.h>
#include<string.h>
void fun(int);
int check(int,int);
char q[1000];
int i,counter=0,sum1=-1000,l;
int  main(){
	scanf("%s",q);
	l=strlen(q);
	int a;
	fun(0);
	printf("%d\n",counter);
}
	void fun(int i){
	int	sum=0;int k=0;
		for(k=i;k<l;k++){
			printf("%d %d\n",k,i);
			printf("f\n");
			if(i==0)
				sum1=-1000; 
				printf("%d\n",sum1);
			sum=sum+q[k]-48;
			
			if(check(k,sum)==1){
				printf("y\n");
				 fun(k+1);
			}
			
		}
		return;
	}
	int check(int i,int sum){
			if(i==l-1){
				if(sum>=sum1){printf("x\n");
				counter++;
				return 0;
				}}
				else if(sum>=sum1){
					sum1=sum;
					return 1;
				}
			else return 0;
		}