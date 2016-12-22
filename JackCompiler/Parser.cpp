//#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<map>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;

int N, ST=1;
int dep = 0;
char iname[10086];
char oname[10086];
char s[10086];
char s2[10086];
char s3[10086];

struct comd
{
	string type, word;

	comd(string a = "", string b = "")
	{
		type = a;
		word = b;
	}
}temp,pretemp, comd_set[100000];

inline bool isop(string ss)
{
	return 	ss == "+" || ss == "-" || ss == "*" ||
		ss == "/" || ss == "&amp;" || ss == "|" ||
		ss == "&lt;" || ss == "&gt;" || ss == "=";
}
inline bool isstatement(string ss)
{
	return	ss == "let" || ss == "if" || ss == "while" ||
		ss == "do" || ss == "return";
}
inline bool isclassVarDec(string ss)
{
	return ss == "var" || ss == "static" || ss == "field";
}
inline bool isvarDec(string ss)
{
	return ss == "var";
}
inline bool isunaryOP(string ss)
{
	return ss=="-"||ss=="~";
}

inline void prtb()
{
	for (int i = 0; i != dep; ++i) putchar(' '), putchar(' ');
}
inline void _readcomd(comd &d)
{
	d = comd_set[ST++];
}
inline void _putbackcomd()
{
	--ST;
}
inline void _printcomd(comd d)
{
	cout << '<' << d.type << "> " << d.word << " </" << d.type << '>' << endl;
}

void statements();
void letStatement();
void ifStatement();
void whileStatement();
void doStatement();
void returnStatement();
void term();
void expression();
void expressionList();
void paramenterList();
void subroutineDec();
void subroutineBody();
void subroutineCall();
void varDec();
void classVarDec();
void compile_class();

void statements()
{
	prtb(); puts("<statements>");
	++dep;
	_readcomd(temp);
	_putbackcomd();
	while (isstatement(temp.word))
	{
		if (temp.word == "let") { letStatement(); }
		else if (temp.word == "if") { ifStatement(); }
		else if (temp.word == "do") { doStatement(); }
		else if (temp.word == "while") { whileStatement(); }
		else if (temp.word == "return") { returnStatement(); }
		_readcomd(temp);
		_putbackcomd();
	}
	--dep;
	prtb(); puts("</statements>");
}
void letStatement()
{
	prtb(); puts("<letStatement>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp);
	if (temp.word == "[")
	{
		prtb(); _printcomd(temp);
		expression();
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp);
	}
	prtb(); _printcomd(temp);
	expression();
	_readcomd(temp); prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</letStatement>");
}
void ifStatement()
{
	prtb(); puts("<ifStatement>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	expression();
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	statements();
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp);
	if (temp.word == "else")
	{
		prtb(); _printcomd(temp);
		_readcomd(temp); prtb(); _printcomd(temp);
		statements();
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp);
	}
	_putbackcomd();
	--dep;
	prtb(); puts("</ifStatement>");
}
void whileStatement()
{
	prtb(); puts("<whileStatement>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	expression();
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	statements();
	_readcomd(temp); prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</whileStatement>");
}
void doStatement()
{
	prtb(); puts("<doStatement>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	subroutineCall();
	_readcomd(temp); prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</doStatement>");
}
void returnStatement()
{
	prtb(); puts("<returnStatement>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp);
	if (temp.word != ";")
	{
		_putbackcomd();
		expression();
		_readcomd(temp);
	}
	prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</returnStatement>");
}
void term()
{

	prtb(); puts("<term>");
	++dep;
	_readcomd(temp);
	_putbackcomd();
	if (isunaryOP(temp.word))
	{
		_readcomd(temp); prtb(); _printcomd(temp);
		term();
	}
	else if (temp.word == "(")
	{
		_readcomd(temp); prtb(); _printcomd(temp);
		expression();
		_readcomd(temp); prtb(); _printcomd(temp);
	}
	else
	{
		_readcomd(pretemp);
		_readcomd(temp);
		_putbackcomd();
		_putbackcomd();
		if (temp.word == "[")
		{
			_readcomd(temp); prtb(); _printcomd(temp);
			_readcomd(temp); prtb(); _printcomd(temp);
			expression();
			_readcomd(temp); prtb(); _printcomd(temp);
		}
		else if (temp.word == "." || temp.word == "(")
		{
			subroutineCall();
		}
		else {_readcomd(temp); prtb(); _printcomd(temp);}
	}
	--dep;
	prtb(); puts("</term>");
}
void expression()
{
	prtb(); puts("<expression>");
	++dep;
	term();
	_readcomd(temp);
	while (isop(temp.word))
	{
		prtb(); _printcomd(temp);
		term();
		_readcomd(temp);
	}
	_putbackcomd();
	--dep;
	prtb(); puts("</expression>");
}
void expressionList()
{
	prtb(); puts("<expressionList>");
	++dep;
	_readcomd(temp);
	_putbackcomd();
	if (temp.word != ")")
	{
		expression();
		_readcomd(temp);
		while (temp.word == ",")
		{
			prtb(); _printcomd(temp);
			expression();
			_readcomd(temp);
		}
		_putbackcomd();
	}
	--dep;
	prtb(); puts("</expressionList>");
}
void subroutineCall()
{
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	if (temp.word == "(")
	{
		expressionList();
		_readcomd(temp); prtb(); _printcomd(temp);
	}
	else
	{
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp); prtb(); _printcomd(temp);
		expressionList();
		_readcomd(temp); prtb(); _printcomd(temp);
	}
}
void parameterList()
{
	prtb(); puts("<parameterList>");
	++dep;
	_readcomd(temp);
	_putbackcomd();
	if (temp.word != ")")
	{
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp);
		while (temp.word == ",")
		{
			prtb(); _printcomd(temp);
			_readcomd(temp); prtb(); _printcomd(temp);
			_readcomd(temp); prtb(); _printcomd(temp);
			_readcomd(temp);
		}
		_putbackcomd();
	}
	--dep;
	prtb(); puts("</parameterList>");
}
void subroutineDec()
{
	prtb(); puts("<subroutineDec>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	parameterList();
	_readcomd(temp); prtb(); _printcomd(temp);
	subroutineBody();
	--dep;
	prtb(); puts("</subroutineDec>");
}
void subroutineBody()
{
	prtb(); puts("<subroutineBody>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);

	_readcomd(temp);
	_putbackcomd();
	while (temp.word != "}")
	{
		if (isvarDec(temp.word)) varDec();
		else statements();
		_readcomd(temp);
		_putbackcomd();
	}

	_readcomd(temp); prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</subroutineBody>");
}
void varDec()
{
	prtb(); puts("<varDec>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp);
	while (temp.word == ",")
	{
		prtb(); _printcomd(temp);
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp);
	}
	prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</varDec>");
}
void classVarDec()
{
	prtb(); puts("<classVarDec>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp);
	while (temp.word == ",")
	{
		prtb(); _printcomd(temp);
		_readcomd(temp); prtb(); _printcomd(temp);
		_readcomd(temp);
	}
	prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</classVarDec>");
}
inline void compile_class()
{
	prtb(); puts("<class>");
	++dep;
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp); prtb(); _printcomd(temp);
	_readcomd(temp);
	_putbackcomd();
	while (temp.word != "}")
	{
		if (isclassVarDec(temp.word)) classVarDec();
		else subroutineDec();
		_readcomd(temp);
		_putbackcomd();
	}
	_readcomd(temp); prtb(); _printcomd(temp);
	--dep;
	prtb(); puts("</class>");
}

inline void _init()
{
	int i;
	while (scanf("%s", s) != EOF)
	{
		if (strcmp(s, "</tokens>") == 0) break;
		gets(s2);
		for (i = 0; s2[i] != '<'; ++i);
		s2[i - 1] = '\0';
		comd_set[++N].type = s;
		comd_set[N].type=comd_set[N].type.substr(1,comd_set[N].type.length()-2);
		comd_set[N].word = &s2[1];
	}
}

inline void _get_string(char *src, char *obj)
{
	for (int i = 0; src[i] != '\0'; ++i) obj[i] = src[i];
}

int main(int argc, char *argv[])
{
	_get_string(argv[1],iname);
	_get_string(argv[2],oname);
	freopen(iname, "r", stdin);
	freopen(oname, "w", stdout);
	scanf("%s", s);
	_init();
	compile_class();
	scanf("%s", s);
	return 0;
}
