#include<stdio.h>
#include<string.h>
int count=0;
void ans(int b[],int i,int l){
	int j;
	if(i==l-1){
		return;
	}
	for(j=i+1;j<l+1;j++){
		if((b[l]-b[j])>=(b[j]-b[i])){
			count++;
			ans(b,i+1,l);
		}
	}
	return;
}	
int main(){
	int i,l;
	char a[10000];
	scanf("%s",a);
	l=strlen(a);
	int b[l+1];
	b[0]=0;
	for(i=0;i<l;i++){
		b[i+1]=b[i]+a[i]-48;
	}
	ans(b,1,l);
	printf("%d\n",count);
	return 0;
}	
