//#include <fstream>
//#include<iostream>
//using namespace std;
//void test01()
//{
//	ofstream ofs;
//	ofs.open("test.txt", ios::out);
//
//	ofs << "����������" << endl;
//	ofs << "�Ա���" << endl;
//	ofs << "���䣺18" << endl;
//
//	ofs.close();
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}


#include <fstream>
#include <string>
#include<iostream>
using namespace std;
void test01()
{
	ifstream ifs;
	ifs.open("test.txt", ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}

	//��һ�ַ�ʽ
	/*char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
	}*/

	//�ڶ���
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	//������
	string buf;
	while (getline(ifs, buf))
	{
		cout << buf << endl;
	}
	//�����ַ�ʽ
	char c;
	/*while ((c = ifs.get()) != EOF)
	{
		cout << c;
	}

	ifs.close();*/


}

int main() {

	test01();

	system("pause");

	return 0;
}
