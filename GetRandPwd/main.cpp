#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

/*
����: g++ main.cpp -o main
*/
char getDigit()
{
    return static_cast<char>('0' + rand()%('9'-'0'+1));
}
char getLower()
{
    return static_cast<char>('a' + rand()%('z'-'a'+1));
}
char getUpper()
{
    return static_cast<char>('A' + rand()%('Z'-'A'+1));
}

int main()
{
    ofstream output;
    output.open("pwd.txt");
    srand(time(0));
    char ch;    //����������ɵ��ַ�
    int num;    //������������ַ�������
    int npwd;   //�������ĸ���
    cout << "������Ҫ���ɵ���������: ";
    cin >> npwd;
    for(int j=0; j<npwd; j++)
    {
        vector<char> str; //����������ɵ��ַ���
        for(int i=0; i<10; i++) //Ĭ������ʮλ�ַ�������
        {
            num = rand()%3;
            if(num == 0)
            {
                ch = getDigit();
            }
            else if(num == 1)
            {
                while((ch = getLower()) == 'l');
            }
            else
            {
                while((ch = getUpper()) == 'I');
            }
            str.push_back(ch);
        }
        for (int i = 0; i < str.size(); i++)
        {
            output << str[i];
        }
		output << endl;
	}
    cout << "�����������" << endl;

    return 0;
}
