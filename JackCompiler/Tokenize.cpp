#include<set>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

map<string,string> symbol;
set<string> keyword;

string type;
string s;
string tmp;

char iname[10086];
char oname[10086];
char cs[10086];

inline void _get_string(char *src,char *obj)
{
	for(int i=0;src[i]!='\0';++i) obj[i]=src[i];
}
inline string _T(char t)
{
	string rtn;
	rtn=t;
	return rtn;
}
inline void _init()
{
	freopen("keyword.tbl","r",stdin);

	while(scanf("%s",cs)!=EOF)
	{
		s=cs;
		keyword.insert(s);
	}
	freopen("symbol.tbl","r",stdin);
	while(scanf("%s",cs)!=EOF)
	{
		s=cs;
		cin>>tmp;
		symbol[s]=tmp;	
	}
}

inline char _proc(char t)
{
	s.clear();
	if(symbol.find(_T(t))!=symbol.end())
	{
		cout<<"<symbol> "<<symbol[_T(t)]<<" </symbol>"<<endl;
		t=getchar();
	}
	else if(t=='\"')
	{
		for(t=getchar();t!='\"';t=getchar()) s+=t;
		cout<<"<stringConstant> "<<s<<" </stringConstant>"<<endl;
		t=getchar();
	}
	else
	{
		for(;t!=' '&&t!='\n'&&t!=EOF&&symbol.find(_T(t))==symbol.end();t=getchar()) s+=t;
		if(keyword.find(s)!=keyword.end()) type="keyword";
		else if('0'<=s[0]&&s[0]<='9') type="integerConstant";
		else type="identifier";
		cout<<'<'<<type<<"> "<<s<<" </"<<type<<'>'<<endl;
	}
	while(t==' '||t=='\n'||t=='\t') t=getchar();
	return t;
}
inline void _work()
{
	freopen(iname,"r",stdin);
	freopen(oname,"w",stdout);
	printf("<tokens>\n");
	char tt=getchar();
	while(tt==' '||tt=='\n'||tt=='\t') tt=getchar();
	while(tt!=EOF)
	{
		tt=_proc(tt);
	}
	printf("</tokens>\n");
}
int main(int argc,char *argv[])
{
	_get_string(argv[1],iname);
	_get_string(argv[2],oname);
	_init();
	_work();
}
