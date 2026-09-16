#include <workerManner.h>

workerManner::workerManner() {
    //初始化属性
    this->m_peoplenum = 0;
    this->m_array = nullptr;
    this->m_fileIsEmpty = true;


    //1.文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
        ifs.close();
        return;//初始化完成，直接return，结束构造函数
    }


    //2.文件存在，数据为空
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        ifs.close();
        return;
    }


    //3.文件不为空
    int num = this->get_num();

    this->m_peoplenum = num;
    this->m_fileIsEmpty = false;
    this->m_array = new Worker * [m_peoplenum];//在堆区创建一个数组，其中有m_peoplenum个元素，每个元素都是一个Worker*指针，用于存放员工对象的地址

    ifs.close();
    ifs.open(FILENAME, ios::in);
    for (int i = 0;i < m_peoplenum;i++) {
        int id;
        string name;
        int careerid;
        ifs >> id >> name >> careerid;
        switch (careerid) {
        case 1:m_array[i] = new Employee(id, name, careerid);//多态，父类指针Worker*指向子类对象
            break;
        case 2:m_array[i] = new Manager(id, name, careerid);
            break;
        case 3:m_array[i] = new Boss(id, name, careerid);
            break;
        default:
            m_array[i] = nullptr;
            break;
        }
    }
    ifs.close();
    //运行程序，需要把原数据保留，于是我干脆直接把原数据加到新程序运行时的array中，这样也就导致了我必须对这些原数据对应的array进行初始化
}

workerManner::~workerManner() {
    if (this->m_array != nullptr) {
        for (int i = 0;i < this->m_peoplenum;i++) {
            delete m_array[i];
        }
    }
    delete[]this->m_array;
    this->m_array = nullptr;
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
        this->save();

        //设置标志位
        this->m_fileIsEmpty = false;

        cout << "添加" << addnum << "个员工成功" << endl;
    }
    else if (addnum <= 0) {
        cout << "输入有误" << endl;
    }

    //system("pause");
    //system("cls");
}

void workerManner::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0;i < this->m_peoplenum;i++) {
        ofs << this->m_array[i]->m_id << " " << this->m_array[i]->m_name << " " << this->m_array[i]->m_careerid << endl;
    }
}

int workerManner::get_num() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int careerid;

    int num = 0;
    while (ifs >> id && ifs >> name && ifs >> careerid) {
        num++;
    }
    ifs.close();
    return num;
}

void workerManner::show() {
    if (m_fileIsEmpty) {
        cout << "文件为空" << endl;
        return;
    }
    else {
        for (int i = 0;i < this->m_peoplenum;i++) {
            this->m_array[i]->showinfo();//多态，父类调用子类接口(showinfo位于各个员工类中)
        }
    }

}

void workerManner::dele() {
    int id;
    cout << "请输入删除的职工id:" << endl;
    cin >> id;
    int ret = this->isExist(id);
    if (ret == -1) {
        cout << "查无此人" << endl;
        return;
    }

    delete m_array[ret];

    for (int i = ret;i < m_peoplenum - 1;i++) {//注意范围，不要越界
        m_array[i] = m_array[i + 1];
    }

    m_peoplenum--;
    m_array[m_peoplenum] = nullptr;

    if (m_peoplenum == 0) {
        m_fileIsEmpty = true;
    }

    save();
}

int workerManner::isExist(int id) {
    for (int i = 0;i < m_peoplenum;i++) {
        if (this->m_array[i]->m_id == id) {
            return i;
        }
    }
    return -1;
}

void workerManner::modify() {
    int id;
    string name;
    int careerid;
    cout << "输入需要修改人的id:" << endl;
    cin >> id;
    for (int i = 0;i < m_peoplenum;i++) {
        if (m_array[i]->m_id == id) {
            cout << "请输入修改后的name:" << endl;
            cin >> name;
            cout << "请输入修改后的careerid:" << endl;
            cin >> careerid;
            Worker* newWorker = nullptr;
            switch (careerid) {
            case 1:newWorker = new Employee(id, name, careerid);
                break;
            case 2:newWorker = new Manager(id, name, careerid);
                break;
            case 3:newWorker = new Boss(id, name, careerid);
                break;
            default:
                cout << "输入有误" << endl;
                return;
            }
            delete m_array[i];
            m_array[i] = newWorker;
            save();
            return;
        }
    }
    cout << "查无此人" << endl;
}

void workerManner::search() {
    int id;
    cout << "请输入需要查找的id:" << endl;
    cin >> id;
    if (isExist(id) != -1) {
        m_array[isExist(id)]->showinfo();
        return;
    }
    cout << "查无此人" << endl;
}

void workerManner::sort() {
    //降序

    //选择排序法
    if (!m_fileIsEmpty) {
        for (int i = 0;i < m_peoplenum;i++) {
            int max = i;
            for (int j = i + 1;j < m_peoplenum;j++) {
                if (m_array[max]->m_id < m_array[j]->m_id) {
                    max = j;
                }
            }
            if (i != max) {
                Worker* temp = m_array[i];//关键一步
                m_array[i] = m_array[max];
                m_array[max] = temp;
            }
        }
        save();
    }
    else {
        cout << "文件为空" << endl;
    }

    //冒泡排序法

    /*for (int i = 0;i < m_peoplenum - 1;i++) {
        for (int j = 0;j < m_peoplenum - i - 1;j++) {
            if (m_array[j]->m_id < m_array[j + 1]->m_id) {
                Worker* temp = m_array[j + 1];
                m_array[j + 1] = m_array[j];
                m_array[j] = temp;
            }
        }
    }*/
}

void workerManner::clear() {
    cout << "确认清空？" << endl << "1.确认 2.返回" << endl;
    int a;
    cin >> a;
    if (a == 1) {
        //清空文件
        ofstream ofs(FILENAME, ios::trunc);//文件存在则清空内容保留文件。文件不存在则创建新文件
        ofs.close();
        if (this->m_array != nullptr) {
            //删除堆区的每个职工对象
            for (int i = 0;i < m_peoplenum;i++) {
                delete m_array[i];
                m_array[i] = nullptr;

            }
            //删除堆区的数组指针
            delete[] m_array;
            m_array = nullptr;
            m_peoplenum = 0;
            m_fileIsEmpty = true;
        }
    }
    else if (a == 2) {
        return;
    }

}