#include<map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

char iname[100];
char oname[100];
char expln[100];
//char *iname="BasicTest.src";
//char *oname="BasicTest.asm";
char fname[50][100];
char frepl[50][100];
char s[1000];
char arg1[1000],arg2[1000];
int item;
int counter=0;
map<string,int> indx;
string ins_name;

FILE *fp;

inline void _get_string(char *src,char *obj)
{
	for(int i=0;src[i]!='\0';++i) obj[i]=src[i];
}
inline int _get_int(char *s)
{
	int i=0,rtn=0;
	while(s[i]<'0'||s[i]>'9') ++i;
	for(;s[i]<='9'&&s[i]>='0';++i) rtn=rtn*10+s[i]-'0';
	return rtn;
}

int main(int argc,char *argv[])
{
	freopen("table\\explain.txt","r",stdin);
	_get_string(argv[3],expln);
//	strcpy(expln,"explain.txt");
	freopen(expln,"r",stdin);
	for(int k=0;scanf("%s%s%s",s,fname[k],frepl[k])!=EOF;++k)
	{
		ins_name.clear();
		for(int i=0;s[i]!='\0';++i)	ins_name+=s[i];
		indx[ins_name]=k;
	}
	
	_get_string(argv[1],iname);
	_get_string(argv[2],oname);		
//	strcpy(iname,"par.tmp");
//	strcpy(oname,"Sys.asm");
	freopen(iname,"r",stdin);
	freopen(oname,"w",stdout);

	for(;scanf("%s%s%s",s,arg1,arg2)!=EOF;++counter)
	{
		ins_name.clear();
		for(int i=0;s[i]!='\0';++i) ins_name+=s[i];
		item=indx[ins_name];
		fp=fopen(fname[item],"r");
		for(;fscanf(fp,"%s",s)!=EOF;)
		{
			if(s[0]=='~')
				for(int i=1;s[i]!='<'&&s[i]!='\0';++i)
					switch(s[i])
					{
						case '$': printf(frepl[item]); break;
						case '?': printf(arg1); break;
						case '#': printf("%d",counter); break;
						case '+': printf("%d",_get_int(arg1)+_get_int(frepl[item])); break;
						case '%': printf(arg2); break;
						default : putchar(s[i]); break;
					}
			else printf(s);
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}
