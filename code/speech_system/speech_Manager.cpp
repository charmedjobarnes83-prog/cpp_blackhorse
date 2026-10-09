#include "speech_Manager.h"
SpeechManager::SpeechManager()
{

    loadrecord();
}
void SpeechManager::show_menu()
{
    cout << "********************************" << endl;
    cout << "******** 欢迎参加演讲比赛 ********" << endl;
    cout << "******** 1.开始演讲比赛 ********" << endl;
    cout << "******** 2.查看往届记录 ********" << endl;
    cout << "******** 3.清空比赛记录 ********" << endl;
    cout << "******** 0.退出比赛程序 ********" << endl;
    cout << "********************************" << endl;
}
void SpeechManager::exitSystem()
{
    exit(0);
}
void SpeechManager::initspeech()
{
    // 保证容器为空
    v1.clear();
    v2.clear();
    v3.clear();
    m1.clear();
    // 初始化比赛轮数
    index = 1;
}
void SpeechManager::creatspeecher()
{
    for (int i = 0; i < 12; i++)
    {
        string name = "选手";
        name += to_string(i); // 类型转换
        Speecher s1;
        s1.m_name = name;
        s1.m_score[0] = 0;
        s1.m_score[1] = 0;
        // 12名选手编号
        v1.push_back(i + 10001);
        // 将选手编号及对应的选手信息存入map中
        m1.insert(pair<int, Speecher>(i + 10001, s1));
    }
}
void SpeechManager::startspeech()
{
    // 初始化数据并重新生成选手
    initspeech();
    creatspeecher();

    // 第一轮比赛
    // 抽签
    speechdraw();
    // 比赛
    contest();
    // 显示晋级结果
    showscore();

    // 第二轮比赛
    index = 2;
    // 抽签
    cout << "1" << endl;
    speechdraw();
    // 比赛
    cout << "2" << endl;
    contest();
    // 显示最终结果
    cout << "3" << endl;
    showscore();

    // 保存结果
    saverecord();
}
void SpeechManager::speechdraw()
{
    cout << "第" << index << "轮选手正在抽签" << endl;
    if (index == 1)
    {
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it1 = v1.begin(); it1 < v1.end(); it1++)
        {
            cout << *it1 << endl;
        }
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it2 = v2.begin(); it2 < v2.end(); it2++)
        {
            cout << *it2 << endl;
        }
    }
}
void SpeechManager::contest()
{
    vector<int> v;
    multimap<double, int, greater<double>> group1; // 临时容器，保存key:分数 value:选手编号
    int num = 0;
    if (index == 1)
    {
        v = v1;
    }
    else
    {
        v = v2;
    }
    for (vector<int>::iterator it = v.begin(); it < v.end(); it++)
    {
        num++;
        // 打分
        deque<double> d;
        for (int i = 0; i < 10; i++)
        {
            double score = (rand() % 401 + 600) / 10.f;
            // cout << score << endl;
            d.push_back(score);
        }
        sort(d.begin(), d.end(), greater<double>()); // greater<double>() 是内置的降序谓词
        d.pop_front();
        d.pop_back();
        double ave = (accumulate(d.begin(), d.end(), 0.0f)) / (double)d.size();
        m1[*it].m_score[index - 1] = ave;
        // 6个人一组，用临时容器保存
        group1.insert(pair<double, int>(ave, *it));
        if (num % 6 == 0)
        {
            cout << "第 " << num / 6 << "组小组名次" << endl;
            for (multimap<double, int, greater<int>>::iterator it1 = group1.begin(); it1 != group1.end(); it1++)
            {
                cout << "编号: " << it1->second << " 姓名：" << m1[it1->second].m_name << " 分数：" << it1->first
                     << endl; // it1->first 等价于m1[it1->second].m_score[index-1]
            }

            // 取走前三名
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it2 = group1.begin();
                 it2 != group1.end() && count < 3; it2++, count++)
            {
                if (index == 1)
                {
                    v2.push_back((*it2).second);
                }
                else
                {
                    v3.push_back((*it2).second);
                }
            }
            group1.clear(); // 每6个人清空一次临时小组容器
        }
    }
    cout << "第" << index << "轮比赛结束" << endl;
}

void SpeechManager::showscore()
{
    cout << "第" << index << "轮比赛晋级成绩如下" << endl;
    vector<int> v4;
    if (index == 1)
    {
        v4 = v2;
    }
    else
    {
        v4 = v3;
    }
    for (vector<int>::iterator it = v4.begin(); it < v4.end(); it++)
    {
        cout << "选手编号:" << *it << " 姓名:" << m1[*it].m_name << " 分数:" << m1[*it].m_score[index - 1] << endl;
    }
}

void SpeechManager::saverecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件
    for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
    {
        ofs << *it << "," << m1[*it].m_score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "已保存" << endl;
    fileIsEmpty = false;
}
void SpeechManager::loadrecord()
{
    ifstream ifs("speech.csv", ios::in); // 输入流对象 读取文件
    if (!ifs.is_open())
    {
        fileIsEmpty = true;
        cout << "不存在" << endl;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch; // 读一个字符
    if (ifs.eof())
    { // 读一个字符就是文件尾，意味着文件为空
        cout << "空 " << endl;
        fileIsEmpty = true;
        ifs.close();
        return;
    }

    fileIsEmpty = false;
    ifs.putback(ch); // 把上面读取的那个字符取回来，不然少一个

    string data;
    int index = 0;
    while (ifs >> data)
    {
        vector<string> v;
        int pos = -1;
        int start = 0;
        while (1)
        {
            pos = data.find(",", start);
            if (pos == -1)
            {
                break;
            }
            string tmp = data.substr(start, pos - start);
            v.push_back(tmp);
            start = pos + 1;
        }
        m_record.insert(make_pair(index, v));
        index++;
    }
    ifs.close();
}
void SpeechManager::showrecord()
{
    if (fileIsEmpty)
    {
        cout << "文件为空或不存在" << endl;
    }
    else
    {
        for (int i = 0; i < m_record.size(); i++)
        {
            cout << "第" << i + 1 << "届 " << "冠军编号：" << this->m_record[i][0] << " 得分：" << this->m_record[i][1]
                 << " "
                    "亚军编号："
                 << this->m_record[i][2] << " 得分：" << this->m_record[i][3]
                 << " "
                    "季军编号："
                 << this->m_record[i][4] << " 得分：" << this->m_record[i][5] << endl;
        }
    }
}
void SpeechManager::clearRecord()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        // 初始化属性
        initspeech();
        // 创建选手
        creatspeecher();
        // 获取往届记录
        loadrecord();

        cout << "清空成功！" << endl;
    }
}
SpeechManager::~SpeechManager()
{
}