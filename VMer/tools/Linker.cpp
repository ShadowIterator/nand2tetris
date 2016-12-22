#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

char oname[100];
char lname[100];
char temp[100];
char fname[100];
char fpath[100];
char t;
FILE *fp;

inline void _get_string(char *src,char *obj)
{
	for(int i=0;src[i]!='\0';++i) obj[i]=src[i];
}

int main(int argc,char *argv[])
{
	_get_string(argv[1],fpath);
	_get_string(argv[2],lname);
	_get_string(argv[3],oname);
//	strcpy(fpath,"Co_Compile");
//	strcpy(lname,"list.txt");
//	strcpy(oname,"lnk.tmp");
	freopen(oname,"w",stdout);
	strcat(fpath,"\\");
	strcpy(temp,fpath);
	strcat(temp,"Sys.vm");
	fp=fopen(temp,"r");
	while(fscanf(fp,"%c",&t)!=EOF) putchar(t);
	freopen(lname,"r",stdin);
	while(scanf("%s",fname)!=EOF)
	{
		if(strcmp(fname,"Sys.vm")==0) continue;
		strcpy(temp,fpath);
		strcat(temp,fname);
		fp=fopen(temp,"r");
		while(fscanf(fp,"%c",&t)!=EOF) putchar(t);
	}
	return 0;
}
