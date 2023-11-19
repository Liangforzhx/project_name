#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("calendar.txt");

void Printtitle(int n);
int OrEndl(int year);
void Printmonth(int year, int month, int &week);

int main()
{
    int year, week = 0;
    cout << "请输入年份：";
    cin >> year;
    fout << year << "年日历" << endl;
    for (int i = 1; i <= 12; i++)
    {
        Printmonth(year, i, week);
    }
    fout.close();
    cout << "日历已生成，请查看calendar.txt文件！" << endl;
    return 0;
}

void Printtitle(int n)
{
    fout << n << "月" << endl;
    fout << "日 一 二 三 四 五 六" << endl;
}

int OrEndl(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    else
        return 0;
}

void Printmonth(int year, int month, int &week)
{
    int day, i, j;
    int monthday[13] = {0, 31, 28 + OrEndl(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    Printtitle(month);
    for (i = 1; i <= week; i++)
        fout << "   ";
    for (i = 1; i <= monthday[month]; i++)
    {
        fout << i;
        if ((i + week) % 7 == 0)
            fout << endl;
        else
            fout << " ";
    }
    week = (week + monthday[month]) % 7;
    fout << endl;
}
