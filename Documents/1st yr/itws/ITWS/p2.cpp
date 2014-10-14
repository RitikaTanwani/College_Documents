#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
class Mfile
{
	private:
	FILE *fp;
	protected:
	char *word;
	public:
	Mfile(char *name,char ch)
	{
		char mode[2];
		sprintf(mode, "%c", ch);
		fp=fopen(name,mode);
		word=new char[100];
	}
	char *read_word()
	{
		int status = fscanf(fp,"%s",word);
		if(status == EOF)
			strcpy(word,"");
		return word;
	}
	void write_string(char *s)
	{
		fprintf(fp,s);
	}
	~Mfile()
	{
		delete []word;
		fclose(fp);
	}
};
int main(int argc,char* argv[])
{
	Mfile m(argv[1],argv[2][0]);
	if(argv[2][0]=='r')
	{
		printf("%s\n",m.read_word());
		printf("%s\n",m.read_word());
		printf("%s\n",m.read_word());
		printf("%s\n",m.read_word());
	}
	else if(argv[2][0]=='w' || argv[2][0]=='a')
	{
		char string[100];
		scanf("%s",string);
		m.write_string(string);
	}
	return 0;
}
