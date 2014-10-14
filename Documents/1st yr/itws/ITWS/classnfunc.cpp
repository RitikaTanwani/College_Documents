#include<stdio.h>
#include<stdlib.h>
#include<string.h>
class Mfile
{
	private:
	char *filename;
	char mode;
	FILE *f;
	public:
	Mfile(char *name,char ch)
	{
		filename=(char *)malloc(sizeof(char));
		strcpy(filename,name);
		mode=ch;
		if(ch=='r')
		{f=fopen(filename,"r");
		printf("%s\n",read_word());}
		if(ch=='w')
		{f=fopen(filename,"w");}
		if(ch=='a')
		{f=fopen(filename,"a");}
	}
	char* read_word()
	{char *s;
		s=(char *)malloc(sizeof(char));
	if(fscanf(f,"%s",s)!=EOF)
	{return s;}
	}
	void write_string(char *s)
	{
		fprintf(f,"%s",s);
	}
	~ Mfile()
	{fclose(f);}


};
int main()
{
	char *name;
	char ch;
	char *s;
	s=(char *)malloc(sizeof(char));
	name=(char *)malloc(sizeof(char));
	scanf("%s %c",name,&ch);
	Mfile myclass(name,ch);
	//if(ch=='r')
	//{printf("%s\n",myclass.read_word());}
	if(ch=='w')
	{
		scanf("%s",s);
		myclass.write_string(s);
	}
	return 0;
}










