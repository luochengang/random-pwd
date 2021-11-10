#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

/*
编译: g++ main.cpp -o main
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
    char ch;    //保存随机生成的字符
    int num;    //决定随机生成字符的类型
    int npwd;   //输出密码的个数
    cout << "请输入要生成的密码数量: ";
    cin >> npwd;
    for(int j=0; j<npwd; j++)
    {
        vector<char> str; //保存随机生成的字符串
        for(int i=0; i<10; i++) //默认生成十位字符串密码
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
    cout << "完成生成密码" << endl;

    return 0;
}
