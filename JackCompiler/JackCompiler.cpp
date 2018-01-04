#define _CRT_SECURE_NO_WARNINGS
#include<map>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

#define gets(s) gets_s(s,400)

const bool SGL = true;
const bool LNE = false;
const int NOT_FIND = -1;



struct VARINFO
{
	string storeT;
	string dataT;
	int id;
	VARINFO(string TstoreT="", string TdataT="", int Tid=0)
	{
		storeT = TstoreT;
		dataT = TdataT;
		id = Tid;
	}
};

struct FUNINFO
{
//	string classT;
	string callT;
	string returnT;
	FUNINFO(string TcallT = "", string TreturnT = "")
	{
//		classT = TclassT;
		callT = TcallT;
		returnT = TreturnT;
	}
};

struct COMD
{
	string label;
	string word;
	int depth;
	bool type;
}comd[100086];


map<string, VARINFO> cvars;
map<string, VARINFO> svars;
map<string, VARINFO> sargs;
map<string, VARINFO> tvars;
map<string, FUNINFO> funcs;
map<string, string> op_map;

string className;

int cvar_num;
int lvar_num;
int cnt_while;
int cnt_if;

void term(int, int);
void expression(int, int);
inline void subroutineCall(int, int);
inline void deal_with_statements(int, int);

inline void get_all_function()
{
}

inline int catch_depth(int l, int r, int k)
{
	for (int i = l; i <= r; ++i)
		if (comd[i].depth == comd[k].depth && i != k && ("/" + comd[k].label) == comd[i].label)
			return i;
	return NOT_FIND;
}

inline void case_classvarDec(int l, int r, int& staticN, int& fieldN)
{
	int p = l;
	string storeT = comd[++p].word;
	string dataT = comd[++p].word;
	string varName;
	for (++p; p<r; p += 2)
	{
		varName = comd[p].word;
		if (storeT == "static") cvars[varName] = VARINFO(storeT, dataT, staticN++);
		else cvars[varName] = VARINFO(storeT, dataT, fieldN++);
		++cvar_num;
	}
}

inline void case_subroutinevarDec(int l, int r, int& varN)
{
	int p = l;
	string storeT = comd[++p].word;
	string dataT = comd[++p].word;
	string varName;
	for (++p; p < r; p += 2)
	{
		varName = comd[p].word;
		svars[varName] = VARINFO(storeT, dataT, varN++);
	}
}

inline void deal_with_classvarDec(int l, int r)
{
	int staticN;
	int fieldN;
	int ll, rr;
	//	int sid=0;
	//	int fid=0;
	for (ll = l; ll <= r; ++ll)
		if (comd[ll].label == "varDec")
		{
			rr = catch_depth(ll, r, ll);
			case_classvarDec(ll, rr, staticN, fieldN);
			ll = rr;
		}
		else if (comd[ll].label == "subroutineDec")
			ll = catch_depth(ll, r, ll);
}

inline int deal_with_subroutinevarDec(int l, int r, int& varN)
{
	//int varN = 0;
	int ll, rr;
	//svars.clear();
	for (ll = l; ll <= r; ++ll)
		if (comd[ll].label == "varDec")
		{
			rr = catch_depth(ll, r, ll);
			case_subroutinevarDec(ll, rr, varN);
			ll = rr;
		}
	return varN;
}

inline void deal_with_parameterList(int l, int r,int& argumentN)
{
	for (int p = l + 1; p <= r; p += 3)
		sargs[comd[p + 1].word] = VARINFO("arg", comd[p].word, argumentN++);
}
/*
inline void expression(int l, int r)
{
}
*/

void expression(int l, int r)
{
	int termstart;
	int termend;
	int findop;
	int dep;
	for (termstart = l; comd[termstart].label != "term"; termstart++);
	dep = comd[termstart].depth;
	for (termend = termstart; !(comd[termend].label == "/term" && comd[termend].depth == dep); termend++);
	term(termstart, termend);
	for (findop = termend; findop<r && op_map.find(comd[findop].word) == op_map.end(); findop++);
	while (findop != r)
	{
		for (termstart = findop; comd[termstart].label != "term"; termstart++);
		for (termend = termstart; !(comd[termend].label == "/term" && comd[termend].depth == dep); termend++);
		term(termstart, termend);
		cout << op_map[comd[findop].word] << endl;
		for (findop = termend; findop<r && op_map.find(comd[findop].word) == op_map.end(); findop++);
	}
}
void term(int l, int r)
{
	int ll, rr;
	string varName;
	VARINFO varInfo;
	if (comd[l + 1].label == "integerConstant") {
		printf("push constant ");
		cout << comd[l + 1].word << endl;
	}
	else if (comd[l + 1].label == "stringConstant") {
		int strcount;
		int temp;
		strcount = comd[l + 1].word.length();
		string stringconst = comd[l + 1].word;
		printf("push constant %d\n", strcount);
		printf("call String.new 1\n");
		for (int i = 0; i<strcount; i++) {
			temp = stringconst[i];
			printf("push constant %d\n", temp);
			printf("call String.appendChar 2\n");
		}
	}
//	else if (comd[l + 1].label == "keywordConstant") {
	else if (comd[l + 1].label == "keyword") {
		int temp = -1;
		string word = comd[l + 1].word;
		if (word == "true") temp = 1;
		else if (word == "false") temp = 0;
		else if (word == "null") temp = 0;
		else if (word == "this") printf("push pointer 0\n");
		if (temp != -1) printf("push constant %d\n", temp);
	}
	else if (comd[l + 1].label == "identifier")
	{
		//varName(l + 1, l + 1);
		varName = comd[l + 1].word;
		varInfo = tvars[varName];

		if (varInfo.storeT == "static") cout << "push static " << varInfo.id << endl;
		if (varInfo.storeT == "field") cout << "push this " << varInfo.id << endl;
		if (varInfo.storeT == "var") cout << "push local " << varInfo.id << endl;
		if (varInfo.storeT == "arg") cout << "push argument " << varInfo.id << endl;
	
		if(comd[l+2].word=="[")
		{
			ll = l + 3;
			rr = catch_depth(ll, r, ll);
			expression(ll, rr);
			cout << "add" << endl;
			cout << "pop pointer 1" << endl;
			cout << "push that 0" << endl;
		}
	}
	else if (comd[l + 1].label == "subroutineCall")
	{
		int substart;
		int subend;
		int dep;
		for (substart = l; comd[substart].label != "subroutineCall"; substart++);
		dep = comd[substart].depth;
		for (subend = substart; !(comd[subend].label == "/subroutineCall" && comd[subend].depth == dep); subend++);
		subroutineCall(substart, subend);
	}
	else if (comd[l + 1].word == "-" || comd[l + 1].word == "~") {
		int termstart = l + 2;
		int termend;
		int dep;
		dep = comd[termstart].depth;
		for (termend = termstart; !(comd[termend].label == "/term" &&comd[termend].depth == dep); termend++);
		term(termstart, termend);
		if (comd[l + 1].word == "-") printf("neg\n");
		else if (comd[l + 1].word == "~") printf("not\n");
	}
	else if (comd[l + 1].word == "(") {
		int expressionstart;
		int expressionend;
		int dep;
		for (expressionstart = l; comd[expressionstart].label != "expression"; expressionstart++);
		dep = comd[expressionstart].depth;
		for (expressionend = expressionstart; !(comd[expressionend].label == "/expression" && comd[expressionend].depth == dep); expressionend++);
		expression(expressionstart, expressionend);
	}
}
inline int expressionList(int l, int r)
{
	int ll = l + 1, rr, rtn = 0;
	for (; ll <= r; ++ll)
	{
		rr = catch_depth(ll, r, ll);
		if (rr == NOT_FIND) break;
		expression(ll, rr);
		ll = rr;
		++rtn;
	}
	return rtn;
}

inline void subroutineCall(int l, int r)
{
	int p = l;
	int ll, rr;
	bool varNameExist = false;
	string varName = "";
	VARINFO varInfo;
	FUNINFO funInfo;
	string subroutineName;
	int argumentN=0;

	if (comd[p + 2].word != ".")
	{
		subroutineName = className + "." + comd[p + 1].word;
		funInfo = funcs[subroutineName];
		if (funInfo.callT == "method")
		{
			cout << "push pointer 0" << endl;
			++argumentN;
		}
		p = p + 2;
	}
	else
	{
		varName = comd[p + 1].word;
		if (tvars.find(varName) != tvars.end())
		{
			varInfo = tvars[varName];
			subroutineName = varInfo.dataT + "." + comd[p + 3].word;
			funInfo = funcs[subroutineName];
			if (funInfo.callT == "method")
			{
				if (varInfo.storeT == "static") cout << "push static " << varInfo.id << endl;
				if (varInfo.storeT == "field") cout << "push this " << varInfo.id << endl;
				if (varInfo.storeT == "var") cout << "push local " << varInfo.id << endl;
				if (varInfo.storeT == "arg") cout << "push argument " << varInfo.id << endl;
				++argumentN;
			}
		}
		else subroutineName = varName + "." + comd[p + 3].word;
		p = p + 4;
	}

	ll = p + 1;
	rr = catch_depth(ll, r, ll);
	argumentN += expressionList(ll, rr);
	cout << "call " << subroutineName << " " << argumentN << endl;
}

inline void letStatement(int l, int r)
{
	int p = l;
	int ll, rr;
	string varName = comd[p + 2].word;
	VARINFO varInfo = tvars[varName];
	if (comd[p + 3].word == "[")
	{
		if (varInfo.storeT == "static") cout << "push static " << varInfo.id << endl;
		if(varInfo.storeT=="field") cout << "push this " << varInfo.id << endl;
		if (varInfo.storeT == "var") cout << "push local " << varInfo.id << endl;
		if (varInfo.storeT == "arg") cout << "push argument " << varInfo.id << endl;

		ll = p + 4;
		rr = catch_depth(ll, r, ll);
		expression(ll, rr);
		cout << "add" << endl;
		ll = rr + 3;
		rr = catch_depth(ll, r, ll);
		expression(ll, rr);
		cout << "pop temp 0" << endl;
		cout << "pop pointer 1" << endl;
		cout << "push temp 0" << endl;
		cout << "pop that 0" << endl;
	}
	else
	{
		ll = p + 4;
		rr = catch_depth(ll, r, ll);
		expression(ll, rr);
		if (varInfo.storeT == "static") cout << "pop static " << varInfo.id << endl;
		if (varInfo.storeT == "field") cout << "pop this " << varInfo.id << endl;
		if (varInfo.storeT == "var") cout << "pop local " << varInfo.id << endl;
		if (varInfo.storeT == "arg") cout << "pop argument " << varInfo.id << endl;
	}
}
/*
inline void ifStatement(int l, int r)
{
}
inline void whileStatement(int l, int r)
{
}
*/
void whileStatement(int l, int r)
{
	++cnt_while;
	cout << "label L1_" << className << "_while_" << cnt_while << endl;
	//printf("label L1\n");
	int expressionstart;
	int expressionend;
	int dep;
	for (expressionstart = l; comd[expressionstart].label != "expression"; expressionstart++);
	dep = comd[expressionstart].depth;
	for (expressionend = expressionstart; !(comd[expressionend].label == "/expression" && comd[expressionend].depth == dep); expressionend++);
	expression(expressionstart,expressionend);
	printf("not\n");
//	printf("if-goto L2\n");
	cout << "if-goto L2_" << className << "_while_" << cnt_while << endl;

	int statementstart;
	int statementend;
	for (statementstart = expressionend; comd[statementstart].label != "statements"; statementstart++);
	dep = comd[statementstart].depth;
	for (statementend = statementstart; !(comd[statementend].label == "/statements" && comd[statementend].depth == dep); statementend++);
	deal_with_statements(statementstart, statementend);
//	printf("goto L1\n");
//	printf("label L2\n");
	cout << "goto L1_" << className << "_while_" << cnt_while << endl;
	cout << "label L2_" << className << "_while_" << cnt_while << endl;

}


void ifStatement(int l, int r)
{
	++cnt_if;
	int expressionstart;
	int expressionend;
	int dep;
	for (expressionstart = l; comd[expressionstart].label != "expression"; expressionstart++);
	dep = comd[expressionstart].depth;
	for (expressionend = expressionstart; !(comd[expressionend].label == "/expression" && comd[expressionend].depth == dep); expressionend++);
	expression(expressionstart,expressionend);
	printf("not\n");
	//printf("if-goto L1\n");
	cout << "if-goto L1_" << className << "_if_" << cnt_if << endl;
/*
	if(expression)
	{
	}
	else
	{
	}


	expression
	not
	if-goto L1

	goto L2
	L1

	L2
	
*/
	int statementstart;
	int statementend;
	for (statementstart = expressionend; comd[statementstart].label != "statements"; statementstart++);
	dep = comd[statementstart].depth;
	for (statementend = statementstart; !(comd[statementend].label == "/statements" && comd[statementend].depth == dep); statementend++);
	deal_with_statements(statementstart, statementend);
//	printf("goto L2\n");
//	printf("label L1\n");
	cout << "goto L2_" << className << "_if_" << cnt_if << endl;
	cout << "label L1_" << className << "_if_" << cnt_if << endl;

	for (statementstart = statementend; comd[statementstart].label != "statements"; statementstart++);
	statementend = catch_depth(statementstart, r, statementstart);
	if(statementend!=NOT_FIND)
		deal_with_statements(statementstart, statementend);

	//dep = comd[statementstart].depth;
	//for (statementend = statementstart; !(comd[statementend].label == "/statement" && comd[statementend].depth == dep); statementend++);
	//printf("label L2\n");
	cout << "label L2_" << className << "_if_" << cnt_if << endl;

}

inline void doStatement(int l, int r)
{
	int ll = l + 2, rr;
	rr = catch_depth(ll, r, ll);
	subroutineCall(ll, rr);
}
inline void returnStatement(int l, int r)
{
	int p = l;
	int ll, rr;
	if (comd[p + 2].label == "expression")
	{
		ll = p + 2;
		rr = catch_depth(ll, r, ll);
		expression(ll, rr);
	}
	else
	{
		cout << "push constant 0" << endl;
	}
	cout << "return " << endl;
}

inline void deal_with_statements(int l, int r)
{
	int ll = l + 1 , rr;
	for (; ll <= r; ++ll)
	{
		rr = catch_depth(ll, r, ll);
		if (rr == NOT_FIND) break;
		if (comd[ll].label == "letStatement") letStatement(ll, rr);
		if (comd[ll].label == "ifStatement") ifStatement(ll, rr);
		if (comd[ll].label == "whileStatement") whileStatement(ll, rr);
		if (comd[ll].label == "doStatement") doStatement(ll, rr);
		if (comd[ll].label == "returnStatement") returnStatement(ll, rr);
		ll = rr;
	}
}

inline void deal_with_subroutineDec(int l, int r)
{
	int varN = 0;
	int p = l + 3;
	string subroutineName = className + "." + comd[p].word;
	FUNINFO finfo = funcs[subroutineName];
	sargs.clear();
	int ll, rr,argumentN=0;
	for (ll = p; ll <= r; ++ll)
		if (comd[ll].label == "parameterList")
		{
			p = rr = catch_depth(ll, r, ll);
			break;
		}
	sargs.clear();
	if (finfo.callT == "method") ++argumentN;
	deal_with_parameterList(ll,rr,argumentN);
	for (; p <= r; ++p) if (comd[p].label == "subroutineBody") break;
	ll = p;
	rr = catch_depth(ll, r, ll);
	svars.clear();
	deal_with_subroutinevarDec(ll, rr, varN);

	tvars.clear();
	for (map<string, VARINFO>::iterator it = cvars.begin(); it != cvars.end(); ++it) tvars.insert(*it);
	for (map<string, VARINFO>::iterator it = svars.begin(); it != svars.end(); ++it) tvars.insert(*it);
	for (map<string, VARINFO>::iterator it = sargs.begin(); it != sargs.end(); ++it) tvars.insert(*it);

	cout << "function " << subroutineName << " " << varN << endl;
	if (finfo.callT == "method")
	{
		cout << "push argment 0" << endl;
		cout << "pop point 0" << endl;
	}
	if (finfo.callT == "constructor")
	{
		cout << "push constant " << cvar_num << endl;
		cout << "call Memory.alloc 1" << endl;
		cout << "pop pointer 0" << endl;
	}
	for (ll = p; ll <= r; ++ll)
		if (comd[ll].label == "statements")
		{
			rr = catch_depth(ll, r, ll);
			deal_with_statements(ll, rr);
			ll = rr;
		}
}

inline void compile_class(int l, int r)
{
	int ll, rr;
	for (ll = 0; ll <= r; ++ll)
		if (comd[ll].label == "classVarDec")
		{
			rr = catch_depth(ll, r, ll);
			deal_with_classvarDec(ll, rr);
			ll = rr;
		}
	for (ll = 0; ll <= r; ++ll)
		if (comd[ll].label == "subroutineDec")
		{
			rr = catch_depth(ll, r, ll);
			deal_with_subroutineDec(ll, rr);
			ll = rr;
		}
}

int main()
{
	freopen("Main.xml", "r", stdin);
	freopen("Main.vm", "w", stdout);
	funcs["Mian.main"] = FUNINFO("function", "int");
	funcs["Main.fill"] = FUNINFO("function", "void");
	funcs["Main.double"] = FUNINFO("function", "int");
	className = "Main";
	int lineN=0;
	op_map["+"] = "add";
	op_map["-"] = "sub";
	op_map["*"] = "call Math.multiply 2";
	op_map["/"] = "call Math.divide 2";
	op_map["&amp;"] = "and";
	op_map["|"] = "or";
	op_map["&lt;"] = "lt";
	op_map["&gt;"] = "gt";
	op_map["="] = "eq";
	char temp[500] = { '\0' };
	int count = 0;
	gets(temp);
	for (int i = 0; temp[0] != '#'; i++) {
		comd[i].label.clear();
		comd[i].word.clear();
		for (count = 0; temp[count] != '<'; count++);
		comd[i].depth = (count + 1) / 2;
		for (count += 1; temp[count] != '>'; count++)
			comd[i].label += temp[count];
		if (temp[count + 1] != '\0') {
			comd[i].type = false;
			for (count += 2; temp[count] != '<'; count++) comd[i].word += temp[count];
			comd[i].word.pop_back();
		}
		else comd[i].type = true;
		for (int i = 0; i<500; i++) temp[i] = '\0';
		//scanf("%s",temp);
		gets(temp);
		lineN = i;
	}
//	expression(0, 20);
//	return 0;
	compile_class(0, lineN);
	return 0;
}