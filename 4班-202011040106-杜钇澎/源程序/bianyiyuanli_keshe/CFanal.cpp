#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

//�Ե��ʽ��б���
enum TokenCode
{
	/*δʶ��*/
	UN_DEFINE = 0,//����codeֵΪ0

	/* ���������� */
	KEY_VOID,	//void�ؼ��֣�����Ϊ1
	KEY_MAIN,	//main�ؼ��֣�����Ϊ2
	KEY_INT,		//int�ؼ��֣�����Ϊ3
	KEY_DOUBLE,	//double�ؼ��֣�����Ϊ4
	KEY_FOR,		//for�ؼ��֣�����Ϊ5
	KEY_WHILE,	//while�ؼ��֣�����Ϊ6
	KEY_SWITCH,	//switch�ؼ��֣�����Ϊ7
	KEY_CASE,	//case�ؼ��֣�����Ϊ8
	KEY_IF,		//if�ؼ��֣�����Ϊ9
	KEY_ELSE,	//else�ؼ��֣�����Ϊ10
	KEY_RETURN,	//return�ؼ��֣�����Ϊ11

	/* ����� */
	COMPUTED_PLUS,	//+�Ӻţ�����Ϊ12
	COMPUTED_MINUS,	//-���ţ�����Ϊ13
	COMPUTED_STAR,	//*�˺ţ�����Ϊ14
	COMPUTED_DIVIDE,	///���ţ�����Ϊ15
	COMPUTED_FUZHI,	//=��ֵ�����������Ϊ16
	COMPUTED_EQUAL,		//==���ںţ�����Ϊ17
	COMPUTED_XIAOYU,		//<С�ںţ�����Ϊ18
	COMPUTED_XIAOYUDENGYU,		//<=С�ڵ��ںţ�����Ϊ19
	COMPUTED_DAYU,		//>���ںţ�����Ϊ20
	COMPUTED_DAYUDENGYU,		//>=���ڵ��ںţ�����Ϊ21

	/* ��� */
	SP_LEFT_YUAN,	//(��Բ���ţ�����Ϊ22
	SP_RIGHT_YUAN,	//)��Բ���ţ�����Ϊ23
	SP_LEFT_ZHONG,	//[�������ţ�����Ϊ24
	SP_RIGHT_ZHONG,	//]�������ţ�����Ϊ25
	SP_LEFT_BIG,	//{������ţ�����Ϊ26
	SP_RIGHT_BIG,		//}�Ҵ����ţ�����Ϊ27
	SP_DOUHAO,	//,���ţ�����Ϊ28
	SP_FENHAO,	//;�ֺţ�����Ϊ29

	/* ���� */
	CHANG_INT,		//���ͳ���������Ϊ30
	CHANG_DOUBLE,	//�����ͳ���������Ϊ31

	/* �����ʶ�� */
	BIAOSHI//����Ϊ32
};

TokenCode code = UN_DEFINE;		//��¼���ʵ��ֱ���
const int MAX = 11;				//�ؼ�������
int row = 1;					//��¼�ַ����ڵ�����
string token = "";				//���ڴ洢����
char  keyWord[][10] = { "void","main","int","double","for","while","switch","case","if","else","return" };	//�ؼ������ʹ���������



void print(TokenCode code)
{

	switch (code)
	{
		/*δʶ��ķ���*/
	case UN_DEFINE:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);	//δʶ��ķ���Ϊ��ɫ
		cout << "( ����Ϊ��" << code << "���޷���ȷʶ��ķ��ţ�  " << token << "   ����������Ϊ��" << row << ")" << endl;
		return;
		break;
		/*����������*/
	case KEY_VOID:		//void�ؼ���
	case KEY_MAIN:	//main�ؼ���
	case KEY_INT:		//int�ؼ���
	case KEY_DOUBLE:	//double�ؼ���
	case KEY_FOR:		//for�ؼ���
	case KEY_WHILE:	//while�ؼ���
	case KEY_SWITCH:	//switch�ؼ���
	case KEY_CASE:	//case�ؼ���
	case KEY_IF:		//if�ؼ���
	case KEY_ELSE:	//else�ؼ���
	case KEY_RETURN:	//return�ؼ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);	//�ؼ���Ϊ��ɫ
		break;

		/* ����� */
	case COMPUTED_PLUS:	//+�Ӻ�
	case COMPUTED_MINUS:	//-����
	case COMPUTED_STAR:	//*�˺�
	case COMPUTED_DIVIDE:	///����
	case COMPUTED_FUZHI:	//=��ֵ�����
	case COMPUTED_EQUAL:		//==���ں�
	case COMPUTED_XIAOYU:		//<С�ں�
	case COMPUTED_XIAOYUDENGYU:	//<=С�ڵ��ں�
	case COMPUTED_DAYU:		//>���ں�
	case COMPUTED_DAYUDENGYU:		//>=���ڵ��ں�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);	//�����Ϊ��ɫ
		break;

	/* ��� */
	case SP_LEFT_YUAN:	//(��Բ����
	case SP_RIGHT_YUAN:	//)��Բ����
	case SP_LEFT_ZHONG:	//[��������
	case SP_RIGHT_ZHONG:	//]��������
	case SP_LEFT_BIG:	//{�������
	case SP_RIGHT_BIG:	//}�Ҵ�����
	case SP_DOUHAO:	//,����
	case SP_FENHAO:	//;�ֺ�
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);	//�ָ���Ϊ��ɫ
		break;

		/* ���� */
	case CHANG_INT:	//���ͳ���
	case CHANG_DOUBLE:	//�����ͳ���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);	//����Ϊ��ɫ
		if (token.find('.') == token.npos)
			cout << "( ����Ϊ��" << code << ",����Ϊ��  " << atoi(token.c_str()) << "  ,��������Ϊ��" << row << ")" << endl;						//����Ϊ����
		else
			cout << "( ����Ϊ��" << code << ", ����Ϊ��  " << atof(token.c_str()) << "  , ��������Ϊ��" << row << ")" << endl;							//����Ϊ������
		return;
		break;
		/* �����ʶ�� */
	case BIAOSHI:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);	//�ؼ���Ϊ��ɫ
		break;
	default:
		break;
	}
	cout << "( ����Ϊ��" << code << ", ����Ϊ��  " << token << "  ,��������λ�ڣ�" << row << ")" << endl;
}
//�ж��Ƿ�Ϊ�ؼ�������

bool isKey(string token)
{
	for (int i = 0; i < MAX; i++)
	{
		if (token.compare(keyWord[i]) == 0)
			return true;
	}
	return false;
}

//���ػ��������ֵı���

int  getKeyID(string token)
{
	for (int i = 0; i < MAX; i++)
	{	
		if (token.compare(keyWord[i]) == 0)
			return i + 1;//������ֵΪ0ʱ����Ӧ����δ������ַ��������ڷ��عؼ��ֵı���ʱ����Ҫ+1
	}
	return -1;
}


//�ж�һ���ַ��Ƿ�����ĸ

bool isLetter(char letter)
{
	if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z'))
		return true;
	return false;

}

//�ж�һ���ַ��Ƿ�������

bool isNum(char Num)
{
	if (Num >= '0' && Num <= '9')
		return true;
	return false;
}

//���дʷ�����
void CiFa_analysis(FILE* fp)
{
	char ch;			
	while ((ch = fgetc(fp)) != EOF)	//��ȡ�ļ��ڵ�ȫ���ַ�
	{
		token = ch;									//����ȡ���ַ�����token��
		if (ch == ' ' || ch == '\t' || ch == '\n')	//�ո�Tab�ͻس����Բ����ж�ȡ
		{
			if (ch == '\n')							//�������з�����¼������row��1
				row++;
			continue;								//����ִ��ѭ��
		}
		else if (isLetter(ch))			//��ȡ������ĸΪ��ͷ���ַ����ж��ǹؼ��ֻ��Ǳ�ʶ��
		{
			token = "";					
			while (isLetter(ch) || isNum(ch))	//����ȡ���ַ�
			{
				token.push_back(ch);	//����ȡ���ַ�ch����token��
				ch = fgetc(fp);			//��ȡ��һ���ַ�
			}
			//�ļ�ָ�����һ���ֽڣ������¶�ȡ�������ʺ�ĵ�һ���ַ�
			fseek(fp, -1L, SEEK_CUR);
			if (isKey(token))	//�ؼ���
				code = TokenCode(getKeyID(token));
			else	//��ʶ��
				code = BIAOSHI;	//����Ϊ��ʶ��
		}
		else if (isNum(ch))	//�޷��ų��������ֿ�ͷ
		{
			int isdouble = 0;	//�ж��Ƿ�Ϊ������
			token = "";			
			while (isNum(ch))	
			{
				token.push_back(ch);		
				ch = fgetc(fp);				//���ļ��л�ȡ��һ���ַ�
				//�õ����е�һ�γ���С����
				if (ch == '.' && isdouble == 0)
				{
					//С������һλ������
					if (isNum(fgetc(fp)))
					{
						isdouble = 1;		//��Ǹó������Ѿ����ֹ�С����
						fseek(fp, -1L, SEEK_CUR);		//����ǰ��ȡ��С�����һλ���¶�ȡ	
						token.push_back(ch);			
						ch = fgetc(fp);				//��ȡС��������һλ����
					}
				}
			}
			if (isdouble == 1)
				code = CHANG_DOUBLE;	//����Ϊ������
			else
				code = CHANG_INT;				//����Ϊ����
			//�ļ�ָ�����һ���ֽڣ������¶�ȡ������ĵ�һ���ַ�
			fseek(fp, -1L, SEEK_CUR);
		}
		else switch (ch)
		{
			/*�����*/
		case '+': code = COMPUTED_PLUS;		//+�Ӻ�			
			break;
		case '-': code = COMPUTED_MINUS;		//-����
			break;
		case '*': code = COMPUTED_STAR;		//*�˺�		
			break;
		case '/': code = COMPUTED_DIVIDE;		//����
			break;
		case '=':
		{
			ch = fgetc(fp);				//��ǰ��ȡ'='������ַ�
			if (ch == '=')				//==���ں�
			{
				token.push_back(ch);	//��'='�����'='����token��
				code = COMPUTED_EQUAL;			//����Ϊ"=="
			}
			else {						//=��ֵ�����
				code = COMPUTED_FUZHI;		//����Ϊ"="
				fseek(fp, -1L, SEEK_CUR);	//����ǰ��ȡ���ַ����¶�ȡ
			}
		}
		break;
		case '<':
		{
			ch = fgetc(fp);				//��ǰ��ȡ'<'������ַ�
			if (ch == '=')				//<=С�ڵ��ں�
			{
				token.push_back(ch);	//��'<'�����'='����token��
				code = COMPUTED_XIAOYUDENGYU;			//����Ϊ"<="
			}
			else {						//<С�ں�
				code = COMPUTED_XIAOYU;			//����Ϊ"<"
				fseek(fp, -1L, SEEK_CUR);	//����ǰ��ȡ���ַ����¶�ȡ
			}
		}
		break;
		case '>':
		{
			ch = fgetc(fp);				//��ǰ��ȡ'>'������ַ�
			if (ch == '=')				//>=���ڵ��ں�
			{
				token.push_back(ch);	//��'>'�����'='����token��
				code = COMPUTED_DAYUDENGYU;			//����Ϊ">="
			}
			else {						//>���ں�
				code = COMPUTED_DAYU;			//����Ϊ">"
				fseek(fp, -1L, SEEK_CUR);	//����ǰ��ȡ���ַ����¶�ȡ
			}
		}
		break;
		/*���*/
		case '(': code = SP_LEFT_YUAN;		//(��Բ����
			break;
		case ')': code = SP_RIGHT_YUAN;	//)��Բ����
			break;
		case '[': code = SP_LEFT_ZHONG;		//[��������
			break;
		case ']': code = SP_RIGHT_ZHONG;	//]��������
			break;
		case '{': code = SP_LEFT_BIG;		//{�������
			break;
		case '}': code = SP_RIGHT_BIG;		//}�Ҵ�����
			break;
		case ',': code = SP_DOUHAO;		//,����
			break;
		case ';': code = SP_FENHAO;	//;�ֺ�
			break;
			//δʶ������
		default: code = UN_DEFINE;
		}
		print(code);				//��ӡ�ʷ��������
	}
}

int main()
{
	string filename;		//�ļ�·��
	FILE* fp;				//�ļ�ָ��
	cout << "��������Ҫ���дʷ�������txt�ļ���·����" << endl;
	while (true) {
		cin >> filename;		//��ȡ�ļ�·��
		if ((fopen_s(&fp, filename.c_str(), "r")) == 0)		//���ļ�
			break;
		else
			cout << "·���������������룺" << endl;	//��ȡʧ��
	}
	cout << "�ʷ��������ڼ����С�������--------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "----------------------------------------------------�ʷ�����������£�" << endl;
	cout << "δʶ��ķ����Ǻ�ɫ��" << endl;
	cout << "��������������������ɫ��" << endl;
	cout << "�������������ɫ��" << endl;
	cout << "�����������ɫ��" << endl;
	cout << "���������ǻ�ɫ��" << endl;
	cout << "����ı�ʶ���ǻ�ɫ��" << endl << endl;
	CiFa_analysis(fp);		//�ʷ�����
	fclose(fp);					//�ر��ļ�
	cout << endl<<endl<<endl<<endl;
	cout << "----------����˵��----------" << endl;
	cout << "����Ϊ0ʱ���ַ���δ�����" << endl;
	cout << "����Ϊ1ʱ���ַ���  void" << endl;
	cout << "����Ϊ2ʱ���ַ���  main" << endl;
	cout << "����Ϊ3ʱ���ַ���  int" << endl;
	cout << "����Ϊ4ʱ���ַ���  double" << endl;
	cout << "����Ϊ5ʱ���ַ���  for" << endl;
	cout << "����Ϊ6ʱ���ַ���  while" << endl;
	cout << "����Ϊ7ʱ���ַ���  switch" << endl;
	cout << "����Ϊ8ʱ���ַ���  case" << endl;
	cout << "����Ϊ9ʱ���ַ���  if" << endl;
	cout << "����Ϊ10ʱ���ַ���  else" << endl;
	cout << "����Ϊ11ʱ���ַ���  return" << endl;
	cout << "����Ϊ12ʱ���ַ���  +" << endl;
	cout << "����Ϊ13ʱ���ַ���  -" << endl;
	cout << "����Ϊ14ʱ���ַ���  *" << endl;
	cout << "����Ϊ15ʱ���ַ���  /" << endl;
	cout << "����Ϊ16ʱ���ַ���  =" << endl;
	cout << "����Ϊ17ʱ���ַ���  ==" << endl;
	cout << "����Ϊ18ʱ���ַ���  <" << endl;
	cout << "����Ϊ19ʱ���ַ���  <=" << endl;
	cout << "����Ϊ20ʱ���ַ���  >" << endl;
	cout << "����Ϊ21ʱ���ַ���  >=" << endl;
	cout << "����Ϊ22ʱ���ַ���  (" << endl;
	cout << "����Ϊ23ʱ���ַ���  )" << endl;
	cout << "����Ϊ24ʱ���ַ���  [" << endl;
	cout << "����Ϊ25ʱ���ַ���  ]" << endl;
	cout << "����Ϊ26ʱ���ַ���  {" << endl;
	cout << "����Ϊ27ʱ���ַ���  }" << endl;
	cout << "����Ϊ28ʱ���ַ���  ," << endl;
	cout << "����Ϊ29ʱ���ַ���  ;" << endl;
	cout << "����Ϊ30ʱ���ַ���  int" << endl;
	cout << "����Ϊ31ʱ���ַ���  double" << endl;
	cout << "����Ϊ32ʱ���ַ����Զ����ʶ��" << endl<<endl<<endl;
	cout << "���������˵�����������ʷ��������" << endl;
	system("pause");
	return 0;
}
