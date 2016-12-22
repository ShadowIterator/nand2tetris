#include<map>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

char iname[100];
char oname[100];
char refer[100];
//char *iname="BasicTest.spf";
//char *oname="BasicTest.src";
char s[1000];
string ins_name,arg1,arg2;
string arg_null="null";
int case_arg_num;
map<string,int> arg_num_set;
inline void _get_string(char *src,char *obj)
{
	for(int i=0;src[i]!='\0';++i) obj[i]=src[i];
}

int main(int argc,char *argv[])
{
	_get_string(argv[3],refer);
//	strcpy(refer,"arg_num.txt");
	freopen(refer,"r",stdin);	
	for(;scanf("%s",s)!=EOF;) 
	{
		ins_name.clear();
		for(int i=0;s[i]!='\0';++i) ins_name+=s[i];
		scanf("%d",&case_arg_num);
		arg_num_set[ins_name]=case_arg_num;
	}

	_get_string(argv[1],iname);
	_get_string(argv[2],oname);		
//	strcpy(iname,"Sys.vm");
//	strcpy(oname,"par.tmp");
	freopen(iname,"r",stdin);
	freopen(oname,"w",stdout);
	
	for(;scanf("%s",s)!=EOF;)
	{
		ins_name.clear();
		for(int i=0;s[i]!='\0';++i) ins_name+=s[i];
		case_arg_num=arg_num_set[ins_name];
		arg1=arg2=arg_null;
		switch(case_arg_num)
		{
			case 0:	break;
			case 1: cin>>arg1; break;
			case 2: ins_name+='_';cin>>arg1;ins_name+=arg1;cin>>arg1; break;
			case 3: cin>>arg2; cin>>arg1; break;
		}
		cout<<ins_name<<' '<<arg1<<' '<<arg2<<endl;
	}
	return 0;
}
