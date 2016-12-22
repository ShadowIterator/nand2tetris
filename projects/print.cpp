#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

char str[10086];
char cmd[10086];

int main()
{
	freopen("out.out","w",stdout);
	for(int i=0;i!=16;++i)
	{
		printf("b[%d]=true,",i);
//		printf("    \n",i,i,i,i+1);
//		printf("    Mux(a=c[%d],b=d[%d],sel=sel[0],out=cd%d);\n",i,i,i);
//		printf("    Mux(a=ab%d,b=cd%d,sel=sel[1],out=out[%d]);\n",i,i,i);
//		putchar('\n');
	}
	return 0;
}
