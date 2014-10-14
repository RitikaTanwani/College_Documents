#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int i,j,g[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
int known[n],d[n],p[n];
for(i=0;i<n;i++){
	known[i]=0;
	d[i]=100000;
	p[i]=-1;
}
known[1]=1;
//d[1]=0;
int h=0,k,min=1;
for(i=0;i<n;i++){
	//for(j=1;j<n;j++){
	j = min;
			for(k=1;k<n;k++){
				if(g[j][k]!=0 && known[k]==0){
					if(d[k] > g[j][k]){
						d[k]=g[j][k];
						p[k]=j;
					}
				}
			}
			min=1;
			for(k=1;k<n;k++){
				if(d[k] < d[min] && known[k]==0){
					min=k;
				}
			}
			printf("%d\n",min);
	
			known[min]=1;
			
		}


for(i=1;i<n;i++){
	printf(" dis =%d parent = %d ",d[i],p[i]);
}
printf("\n");
int ansg[n][n];
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		ansg[i][j]=0;
	}
}
for(i=2;i<n;i++){
	ansg[p[i]][i]=g[p[i]][i];
	ansg[i][p[i]]=g[i][p[i]];
}
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
	printf("%d ",ansg[i][j]);
	}
	printf("\n");
}

return 0;
}


