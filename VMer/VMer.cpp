#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

char iname[100];
char oname[100];
char cmd[1000];
int main()
{
	printf("enter the source file name:");
	scanf("%s",iname);
	printf("enter the object file name:");
	scanf("%s",oname);
	
	if(iname[0]=='$')
	{
		strcpy(cmd,&iname[1]);
		strcpy(iname,cmd);
		sprintf(cmd,"Python tools\\get_file_list.py %s tools\\flt.tmp",iname);
		system(cmd);
		sprintf(cmd,"tools\\Linker.exe %s tools\\flt.tmp %s.tmp",iname,iname);
		system(cmd);
		strcat(iname,".tmp");
	}
	
	sprintf(cmd,"tools\\Simplifier.exe %s tools\\spf.tmp",iname);
	system(cmd);
	
	system("tools\\Parser.exe tools\\spf.tmp tools\\par.tmp tools\\arg_num.txt");

	sprintf(cmd,"tools\\Coder.exe tools\\par.tmp %s tools\\explain.txt",oname);
	system(cmd);

	sprintf(cmd,"del %s",iname);
	system(cmd);
	system("del tools\\flt.tmp");
	system("del tools\\spf.tmp");
	system("del tools\\par.tmp");

	return 0;
}
