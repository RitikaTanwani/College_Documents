#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
class Mfile
{
	protected:
	FILE *fp;
	char *word;
	char naam[100];
	char c[2];
	public:
	Mfile(char *name,char ch)
	{
		strcpy(naam,name);
		char mode[2];
		sprintf(mode, "%c", ch);
		strcpy(c,mode);
		fp=fopen(name,mode);
		word=new char[100];
	}
	char *read_word()
	{
		fscanf(fp,"%s",word);
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
class Logfile:public Mfile
{
	public:
	Logfile(char *name):Mfile(name,'a'){
	}
	Logfile(char *name,char ch):Mfile(name,ch){
	}
	void clear_file()
	{
		fclose(fp);
		fp=fopen(naam,"w");
		fclose(fp);
		fp=fopen(naam,c);
	}
	int search_file(char *s)
	{
		char w[100];
		fclose(fp);
		fp=fopen(naam,"r");
		while(fscanf(fp,"%s",w)==1)
		{
			if(strcmp(w,s)==0)
			{
				fclose(fp);
				fp=fopen(naam,c);
				return 1;
			}
		}
		fclose(fp);
		fp=fopen(naam,c);
		return 0;
	}
};
int main(int argc,char* argv[])
{
	Logfile m(argv[1],argv[2][0]);
	char temp[100];
	sprintf(temp,"hello");
	printf("%d\n",m.search_file(temp));
	m.clear_file();
	printf("%d\n",m.search_file(temp));
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
