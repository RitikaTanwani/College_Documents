#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
class Mfile
{
	public:
	FILE *fp,*fp1;
	Mfile(){
		fp=NULL;
	}
	public:
	char *name1;
	char *ch1;
	Mfile(char *name,char ch){
		//fp=fopen(name,"ch");
		ch1 = (char*) malloc(sizeof(char)*4);
		sprintf(ch1, "%c", ch);
		fp=fopen(name, ch1);
		fp1=fp;
		name1=name;
	}
	char *read_word(){
		//return fscanf(fp1,"%s","r");
		char *word;
		word = (char *)malloc(20*sizeof(char)); //memory allocation is necessary to store the scanned string
		fscanf(fp1, "%s", word);
		//return "abcd";
		//word=word1;
		return word;
	}
	void write_string(char *s){
		fprintf(fp , "%s" ,s);
	}
	~Mfile(){
		if(fp!=NULL){

		fclose(fp);
		}
	}
};
class logfile:public Mfile
{
	public:
		//char *ch1;
		//char *name1;
	logfile(char *name){
		fp=fopen(name,"a");
	}
	logfile(char *name,char ch):Mfile(name,ch){}
		//Mfile::Mfile(name,ch);
/*	//Mfile(char *name,char ch){
		//fp=fopen(name,"ch");
		ch1 = (char*) malloc(sizeof(char)*4);
		sprintf(ch1, "%c", ch);
		fp=fopen(name, ch1);
		//fp1=fp;
		name1=name;*/
	
	void clear_file(){
		fclose(fp);
		fp=fopen(name1,"w");
		fclose(fp);
		fp=fopen(name1,ch1);
	}
	int search_file(char *s){
	//	fclose(fp);
	//	fp=fopen(name1,"r");
		char *word;
		word = (char *)malloc(20*sizeof(char)); //memory allocation is necessary to store the scanned string
		int i=0;
		while(fscanf(fp, "%s" ,word)!=EOF){
			if(strcmp(word,s)==0){
				i=1;
			}
		}
	//	fclose(fp);
	//	fp=fopen(name1,ch1);
		return i;
	}
};
		



int main(){
		
	
	char c;
	scanf("%c",&c);
	char f[100];
	scanf("%s",f);
	printf("%s %c\n",f,c);
	/*Mfile f1(f,c);
	int i;
	for(i=0;i<4;i++){
		printf("%s\n",f1.read_word());
	}
	f1.write_string("hello");
	printf("%s\n",f1.read_word());*/
	logfile f1(f,c);
	
	printf("%d\n",f1.search_file("this"));
	f1.clear_file();





	return 0;
}






	




