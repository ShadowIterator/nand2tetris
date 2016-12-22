#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

char t1,t2;
char iname[100];
char oname[100];
//char *iname="BasicTest.vm";
//char *oname="BasicTest.spf";
char s[1000];
inline void _get_string(char *src,char *obj)
{
	for(int i=0;src[i]!='\0';++i) obj[i]=src[i];
}

int main(int argc,char *argv[])
{
//	printf("%d\n",argc);
	_get_string(argv[1],iname);
	_get_string(argv[2],oname);
	freopen(iname,"r",stdin);
	freopen(oname,"w",stdout);
	t1='\0';t2=getchar();
	while(t2!=EOF)
	{
		if(t1=='/'&&t2=='/')
		{
			gets(s);
			t1='\n';t2=getchar(); 
			putchar('\n');
			continue;
		}
		else if(t1=='/'&&t2=='*')
		{
			t1=t2;
			t2=getchar();
			while(t1!='*'||t2!='/') 
			{
				t1=t2;
				t2=getchar();
			}
			t1=t2;
			t2=getchar();
			continue;
		}
		putchar(t2);
		t1=t2;
		t2=getchar();
	}
}
