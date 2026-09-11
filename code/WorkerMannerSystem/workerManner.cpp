#include <workerManner.h>

workerManner::workerManner() {
    //初始化属性
    this->m_peoplenum = 0;
    this->m_array = nullptr;
}

workerManner::~workerManner() {

}

void workerManner::showmenu() {
    cout << "**********************" << endl;
    cout << "******欢迎使用职工管理系统******" << endl;
    cout << "0退出" << endl;
    cout << "1添加" << endl;
    cout << "2显示" << endl;
    cout << "3删除" << endl;
    cout << "4修改" << endl;
    cout << "5查找" << endl;
    cout << "6排序" << endl;
    cout << "7清空" << endl;
    cout << "**********************" << endl;
}

void workerManner::exitSystem() {
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void workerManner::add() {
    cout << "请输入需要添加的人数" << endl;
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0) {
        //计算数组空间大小
        int new_num = this->m_peoplenum + addnum;//新空间人数=原人数+新人数
        Worker** newspace = new Worker * [new_num];//创建的是一个大小为 new_num 的指针数组
        //将原来空间的数据拷贝到新空间中
        if (this->m_array != NULL) {
            for (int i = 0;i < this->m_peoplenum;i++) {
                newspace[i] = this->m_array[i];
            }
        }
        //添加新数据
        for (int i = 0;i < addnum;i++) {
            int id;
            string name;
            int careerid;
            cout << "请输入第" << i + 1 << "个职工的id" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个职工的name" << endl;
            cin >> name;
            cout << "请输入此职工的类别" << endl;
            cout << "1:employee" << endl << "2:manager" << endl << "3:boss" << endl;
            cin >> careerid;
            Worker* worker = nullptr;
            switch (careerid) {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            default:break;
            }
            //将创建的职工指针保存到数组中
            newspace[this->m_peoplenum + i] = worker;
        }
        //释放原有空间
        delete[] this->m_array;
        //更改新空间的指向
        this->m_array = newspace;
        //更新新的职工人数
        this->m_peoplenum = new_num;
        //保存到文件中

        cout << "添加" << addnum << "个员工成功" << endl;
    }
    else if (addnum <= 0) {
        cout << "输入有误" << endl;
    }
    //system("pause");
    //system("cls");
}