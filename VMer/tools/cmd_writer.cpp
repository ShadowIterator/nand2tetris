#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char cmd[10000];

int main()
{
	for(printf("------------------------------------------------\n>>>"),gets(cmd);strcmp(cmd,"exit")!=0;printf("------------------------------------------------\n>>>"),gets(cmd))
		if(strcmp(cmd,"exit")!=0) system(cmd);
	return 0;
}
