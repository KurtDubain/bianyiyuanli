#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//对单词进行编码
enum TokenCode
{
	/*未识别*/
	UN_DEFINE = 0,//编码code值为0

	/* 基本保留字 */
	KEY_VOID,	//void关键字，编码为1
	KEY_MAIN,	//main关键字，编码为2
	KEY_INT,		//int关键字，编码为3
	KEY_DOUBLE,	//double关键字，编码为4
	KEY_FOR,		//for关键字，编码为5
	KEY_WHILE,	//while关键字，编码为6
	KEY_SWITCH,	//switch关键字，编码为7
	KEY_CASE,	//case关键字，编码为8
	KEY_IF,		//if关键字，编码为9
	KEY_ELSE,	//else关键字，编码为10
	KEY_RETURN,	//return关键字，编码为11

	/* 运算符 */
	COMPUTED_PLUS,	//+加号，编码为12
	COMPUTED_MINUS,	//-减号，编码为13
	COMPUTED_STAR,	//*乘号，编码为14
	COMPUTED_DIVIDE,	///除号，编码为15
	COMPUTED_FUZHI,	//=赋值运算符，编码为16
	COMPUTED_EQUAL,		//==等于号，编码为17
	COMPUTED_XIAOYU,		//<小于号，编码为18
	COMPUTED_XIAOYUDENGYU,		//<=小于等于号，编码为19
	COMPUTED_DAYU,		//>大于号，编码为20
	COMPUTED_DAYUDENGYU,		//>=大于等于号，编码为21

	/* 界符 */
	SP_LEFT_YUAN,	//(左圆括号，编码为22
	SP_RIGHT_YUAN,	//)右圆括号，编码为23
	SP_LEFT_ZHONG,	//[左中括号，编码为24
	SP_RIGHT_ZHONG,	//]右中括号，编码为25
	SP_LEFT_BIG,	//{左大括号，编码为26
	SP_RIGHT_BIG,		//}右大括号，编码为27
	SP_DOUHAO,	//,逗号，编码为28
	SP_FENHAO,	//;分号，编码为29

	/* 常数 */
	CHANG_INT,		//整型常量，编码为30
	CHANG_DOUBLE,	//浮点型常量，编码为31

	/* 定义标识符 */
	BIAOSHI//编码为32
};

TokenCode code = UN_DEFINE;		//记录单词的种别码
const int MAX = 11;				//关键字数量
int row = 1;					//记录字符所在的行数
string token = "";				//用于存储单词
char  keyWord[][10] = { "void","main","int","double","for","while","switch","case","if","else","return" };	//关键词类型存入数组中



void print(TokenCode code)
{

	switch (code)
	{
		/*未识别的符号*/
	case UN_DEFINE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);	//未识别的符号为红色
		cout << "( 编码为：" << code << "，无法正确识别的符号：  " << token << "   ，所在行数为：" << row << ")" << endl;
		return;
		break;
		/*基本保留字*/
	case KEY_VOID:		//void关键字
	case KEY_MAIN:	//main关键字
	case KEY_INT:		//int关键字
	case KEY_DOUBLE:	//double关键字
	case KEY_FOR:		//for关键字
	case KEY_WHILE:	//while关键字
	case KEY_SWITCH:	//switch关键字
	case KEY_CASE:	//case关键字
	case KEY_IF:		//if关键字
	case KEY_ELSE:	//else关键字
	case KEY_RETURN:	//return关键字
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	//关键字为蓝色
		break;

		/* 运算符 */
	case COMPUTED_PLUS:	//+加号
	case COMPUTED_MINUS:	//-减号
	case COMPUTED_STAR:	//*乘号
	case COMPUTED_DIVIDE:	///除号
	case COMPUTED_FUZHI:	//=赋值运算符
	case COMPUTED_EQUAL:		//==等于号
	case COMPUTED_XIAOYU:		//<小于号
	case COMPUTED_XIAOYUDENGYU:	//<=小于等于号
	case COMPUTED_DAYU:		//>大于号
	case COMPUTED_DAYUDENGYU:		//>=大于等于号
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);	//运算符为青色
		break;

	/* 界符 */
	case SP_LEFT_YUAN:	//(左圆括号
	case SP_RIGHT_YUAN:	//)右圆括号
	case SP_LEFT_ZHONG:	//[左中括号
	case SP_RIGHT_ZHONG:	//]右中括号
	case SP_LEFT_BIG:	//{左大括号
	case SP_RIGHT_BIG:	//}右大括号
	case SP_DOUHAO:	//,逗号
	case SP_FENHAO:	//;分号
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);	//分隔符为绿色
		break;

		/* 常数 */
	case CHANG_INT:	//整型常量
	case CHANG_DOUBLE:	//浮点型常量
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);	//常量为黄色
		if (token.find('.') == token.npos)
			cout << "( 编码为：" << code << ",内容为：  " << atoi(token.c_str()) << "  ,所在行数为：" << row << ")" << endl;						//单词为整型
		else
			cout << "( 编码为：" << code << ", 内容为：  " << atof(token.c_str()) << "  , 所在行数为：" << row << ")" << endl;							//单词为浮点型
		return;
		break;
		/* 定义标识符 */
	case BIAOSHI:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//关键字为灰色
		break;
	default:
		break;
	}
	cout << "( 编码为：" << code << ", 内容为：  " << token << "  ,所在行数位于：" << row << ")" << endl;
}
//判断是否为关键字类型

bool isKey(string token)
{
	for (int i = 0; i < MAX; i++)
	{
		if (token.compare(keyWord[i]) == 0)
			return true;
	}
	return false;
}

//返回基本保留字的编码

int  getKeyID(string token)
{
	for (int i = 0; i < MAX; i++)
	{	
		if (token.compare(keyWord[i]) == 0)
			return i + 1;//由于码值为0时，对应的是未定义的字符，所以在返回关键字的编码时，需要+1
	}
	return -1;
}


//判断一个字符是否是字母

bool isLetter(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return true;
	return false;

}

//判断一个字符是否是数字

bool isNum(char Num)
{
	if (Num >= '0' && Num <= '9')
		return true;
	return false;
}

//进行词法分析
void CiFa_analysis(FILE* fp)
{
	char ch;			
	while ((ch = fgetc(fp)) != EOF)	//读取文件内的全部字符
	{
		token = ch;									//将获取的字符存入token中
		if (ch == ' ' || ch == '\t' || ch == '\n')	//空格、Tab和回车忽略不进行读取
		{
			if (ch == '\n')							//遇到换行符，记录行数的row加1
				row++;
			continue;								//继续执行循环
		}
		else if (isLetter(ch))			//获取到以字母为开头的字符，判断是关键字还是标识符
		{
			token = "";					
			while (isLetter(ch) || isNum(ch))	//当读取到字符
			{
				token.push_back(ch);	//将读取的字符ch存入token中
				ch = fgetc(fp);			//获取下一个字符
			}
			//文件指针后退一个字节，即重新读取上述单词后的第一个字符
			fseek(fp, -1L, SEEK_CUR);
			if (isKey(token))	//关键字
				code = TokenCode(getKeyID(token));
			else	//标识符
				code = BIAOSHI;	//单词为标识符
		}
		else if (isNum(ch))	//无符号常数以数字开头
		{
			int isdouble = 0;	//判断是否为浮点数
			token = "";			
			while (isNum(ch))	
			{
				token.push_back(ch);		
				ch = fgetc(fp);				//从文件中获取下一个字符
				//该单词中第一次出现小数点
				if (ch == '.' && isdouble == 0)
				{
					//小数点下一位是数字
					if (isNum(fgetc(fp)))
					{
						isdouble = 1;		//标记该常数中已经出现过小数点
						fseek(fp, -1L, SEEK_CUR);		//将超前读取的小数点后一位重新读取	
						token.push_back(ch);			
						ch = fgetc(fp);				//读取小数点后的下一位数字
					}
				}
			}
			if (isdouble == 1)
				code = CHANG_DOUBLE;	//单词为浮点型
			else
				code = CHANG_INT;				//单词为整型
			//文件指针后退一个字节，即重新读取常数后的第一个字符
			fseek(fp, -1L, SEEK_CUR);
		}
		else switch (ch)
		{
			/*运算符*/
		case '+': code = COMPUTED_PLUS;		//+加号			
			break;
		case '-': code = COMPUTED_MINUS;		//-减号
			break;
		case '*': code = COMPUTED_STAR;		//*乘号		
			break;
		case '/': code = COMPUTED_DIVIDE;		//除号
			break;
		case '=':
		{
			ch = fgetc(fp);				//超前读取'='后面的字符
			if (ch == '=')				//==等于号
			{
				token.push_back(ch);	//将'='后面的'='存入token中
				code = COMPUTED_EQUAL;			//单词为"=="
			}
			else {						//=赋值运算符
				code = COMPUTED_FUZHI;		//单词为"="
				fseek(fp, -1L, SEEK_CUR);	//将超前读取的字符重新读取
			}
		}
		break;
		case '<':
		{
			ch = fgetc(fp);				//超前读取'<'后面的字符
			if (ch == '=')				//<=小于等于号
			{
				token.push_back(ch);	//将'<'后面的'='存入token中
				code = COMPUTED_XIAOYUDENGYU;			//单词为"<="
			}
			else {						//<小于号
				code = COMPUTED_XIAOYU;			//单词为"<"
				fseek(fp, -1L, SEEK_CUR);	//将超前读取的字符重新读取
			}
		}
		break;
		case '>':
		{
			ch = fgetc(fp);				//超前读取'>'后面的字符
			if (ch == '=')				//>=大于等于号
			{
				token.push_back(ch);	//将'>'后面的'='存入token中
				code = COMPUTED_DAYUDENGYU;			//单词为">="
			}
			else {						//>大于号
				code = COMPUTED_DAYU;			//单词为">"
				fseek(fp, -1L, SEEK_CUR);	//将超前读取的字符重新读取
			}
		}
		break;
		/*界符*/
		case '(': code = SP_LEFT_YUAN;		//(左圆括号
			break;
		case ')': code = SP_RIGHT_YUAN;	//)右圆括号
			break;
		case '[': code = SP_LEFT_ZHONG;		//[左中括号
			break;
		case ']': code = SP_RIGHT_ZHONG;	//]右中括号
			break;
		case '{': code = SP_LEFT_BIG;		//{左大括号
			break;
		case '}': code = SP_RIGHT_BIG;		//}右大括号
			break;
		case ',': code = SP_DOUHAO;		//,逗号
			break;
		case ';': code = SP_FENHAO;	//;分号
			break;
			//未识别内容
		default: code = UN_DEFINE;
		}
		print(code);				//打印词法分析结果
	}
}

int main()
{
	string filename;		//文件路径
	FILE* fp;				//文件指针
	cout << "请输入所要进行词法分析的txt文件的路径：" << endl;
	while (true) {
		cin >> filename;		//读取文件路径
		if ((fopen_s(&fp, filename.c_str(), "r")) == 0)		//打开文件
			break;
		else
			cout << "路径有误，请重新输入：" << endl;	//读取失败
	}
	cout << "词法分析正在加载中…………--------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------词法分析结果如下：" << endl;
	cout << "未识别的符号是红色；" << endl;
	cout << "基本保留字字类型是蓝色；" << endl;
	cout << "运算符类型是青色；" << endl;
	cout << "界符类型是绿色；" << endl;
	cout << "常数类型是黄色；" << endl;
	cout << "定义的标识符是灰色；" << endl << endl;
	CiFa_analysis(fp);		//词法分析
	fclose(fp);					//关闭文件
	cout << endl<<endl<<endl<<endl;
	cout << "----------阅览说明----------" << endl;
	cout << "编码为0时，字符是未定义的" << endl;
	cout << "编码为1时，字符是  void" << endl;
	cout << "编码为2时，字符是  main" << endl;
	cout << "编码为3时，字符是  int" << endl;
	cout << "编码为4时，字符是  double" << endl;
	cout << "编码为5时，字符是  for" << endl;
	cout << "编码为6时，字符是  while" << endl;
	cout << "编码为7时，字符是  switch" << endl;
	cout << "编码为8时，字符是  case" << endl;
	cout << "编码为9时，字符是  if" << endl;
	cout << "编码为10时，字符是  else" << endl;
	cout << "编码为11时，字符是  return" << endl;
	cout << "编码为12时，字符是  +" << endl;
	cout << "编码为13时，字符是  -" << endl;
	cout << "编码为14时，字符是  *" << endl;
	cout << "编码为15时，字符是  /" << endl;
	cout << "编码为16时，字符是  =" << endl;
	cout << "编码为17时，字符是  ==" << endl;
	cout << "编码为18时，字符是  <" << endl;
	cout << "编码为19时，字符是  <=" << endl;
	cout << "编码为20时，字符是  >" << endl;
	cout << "编码为21时，字符是  >=" << endl;
	cout << "编码为22时，字符是  (" << endl;
	cout << "编码为23时，字符是  )" << endl;
	cout << "编码为24时，字符是  [" << endl;
	cout << "编码为25时，字符是  ]" << endl;
	cout << "编码为26时，字符是  {" << endl;
	cout << "编码为27时，字符是  }" << endl;
	cout << "编码为28时，字符是  ," << endl;
	cout << "编码为29时，字符是  ;" << endl;
	cout << "编码为30时，字符是  int" << endl;
	cout << "编码为31时，字符是  double" << endl;
	cout << "编码为32时，字符是自定义标识符" << endl<<endl<<endl;
	cout << "请根据以上说明继续阅览词法分析结果" << endl;
	system("pause");
	return 0;
}
