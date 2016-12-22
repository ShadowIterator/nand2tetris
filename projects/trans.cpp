#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

char cmd[10086];
char name[10011];
string str;


inline void getname()
{
	scanf("%s",name);
//	printf("%s\n",name);
	scanf("%s",name);
	scanf("%s",name);	
	scanf("%s",name);
	int i=0;
	while(name[i]!='.') ++i;
	name[i]='\0';
}

int main()
{
//	sprintf(cmd,"dir > temp.txt");
//	system(cmd);
//	for(int i=1;i<=7;++i) getline(cin,str);
	freopen("temp.txt","r",stdin);
	for(int i=1;i<=14;++i)
	{
		printf("Running case%2d\n",i);
		getname();
		sprintf(cmd,"rename %s.hdl %s.txt",name,name);
		system(cmd);
	}
	return 0;
}
