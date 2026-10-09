#pragma once
#include <iostream>
using namespace std;
#include <algorithm>
#include <deque>
#include <fstream>
#include <map>
#include <numeric>
#include <speecher.h>
#include <vector>

class SpeechManager
{
  public:
    SpeechManager();
    void initspeech();

    void show_menu();
    void exitSystem();
    void creatspeecher();
    void startspeech();
    void speechdraw();
    void contest();
    void showscore();
    void saverecord();
    void loadrecord();
    void showrecord();
    void clearRecord();

    ~SpeechManager();

    // 比赛选手 容器  12人
    vector<int> v1;
    // 第一轮晋级容器  6人
    vector<int> v2;
    // 胜利前三名容器  3人
    vector<int> v3;
    // 存放编号 以及对应的 具体选手 容器
    map<int, Speecher> m1;
    // 记录比赛轮数
    int index = 0;

    // 文件为空的标志
    bool fileIsEmpty;
    // 往届记录
    map<int, vector<string>> m_record;
};
