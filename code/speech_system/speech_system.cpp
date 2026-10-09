#include <iostream>
using namespace std;
#include "speech_Manager.h"
#include <string>

int main()
{
    srand((unsigned int)time(NULL));
    SpeechManager s1;
    /*for (map<int, Speecher>::iterator it1 = s1.m1.begin(); it1 != s1.m1.end(); it1++)
    {
        cout << "编号：" << it1->first << " 姓名:" << it1->second.m_name << " 分数：" << it1->second.m_score[0] << endl;
    }*/
    int choice = 0;
    while (1)
    {
        s1.show_menu();
        cout << "请输入您的选择: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "开始演讲比赛" << endl;
            s1.startspeech();
            break;
        case 2:
            cout << "查看往届记录" << endl;
            s1.showrecord();
            break;
        case 3:
            cout << "清空比赛记录" << endl;
            s1.clearRecord();
            break;
        case 0:
            cout << "退出比赛程序" << endl;
            s1.exitSystem();
            break;
        default:
            cout << "输入有误，请重新输入！" << endl;
            break;
        }
    }
    return 0;
}