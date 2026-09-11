#include <iostream>
using namespace std;
#include <string>
#include <fstream>


class Person {
public:
    int id;
    string name;
    int career;
};

class PersonBook {//职工表类
public:
    class Person Personarray[100];
    int size;
};

void showmenu();
void add(PersonBook* pb1);
void show(PersonBook* pb1);
void dele(PersonBook* pb1);
int isexist(PersonBook* pb1, int id);

void txt(PersonBook* pb1);

void showmenu() {
    cout << "**********************" << endl;
    cout << "******欢迎使用职工管理系统******" << endl;
    cout << "0" << endl;
    cout << "1" << endl;
    cout << "2" << endl;
    cout << "3" << endl;
    cout << "4" << endl;
    cout << "5" << endl;
    cout << "6" << endl;
    cout << "7" << endl;
    cout << "**********************" << endl;
}

void add(PersonBook* pb1) {
    cout << "请输入需要增加的职工数量" << endl;
    int id;
    string name;
    int career;

    int num;
    cin >> num;
    for (int i = 0;i < num;i++) {
        cout << "请输入第" << i + 1 << "个新职工编号" << endl;
        cin >> id;
        pb1->Personarray[pb1->size].id = id;
        cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
        cin >> name;
        pb1->Personarray[pb1->size].name = name;
        cout << "请选择该职工职位" << endl;
        cout << "1.普通职工" << endl;
        cout << "2.经理" << endl;
        cout << "3.老板" << endl;
        cin >> career;
        pb1->Personarray[pb1->size].career = career;
        pb1->size++;
    }
}

void show(PersonBook* pb1) {
    for (int i = 0;i < pb1->size;i++) {
        cout << "id:" << pb1->Personarray[i].id << " ";
        cout << "name:" << pb1->Personarray[i].name << " ";
        cout << "career:" << pb1->Personarray[i].career << endl;
    }
}

void dele(PersonBook* pb1) {
    int id;
    cout << "输入离职员工id" << endl;
    cin >> id;
    int index = isexist(pb1, id);
    if (index != -1) {
        for (int i = index;i < pb1->size - 1;i++) {
            pb1->Personarray[i] = pb1->Personarray[i + 1];
        }
        pb1->size--;
    }
    else {
        cout << "查无此人" << endl;
    }

}
int isexist(PersonBook* pb1, int id) {
    for (int i = 0;i < pb1->size;i++) {
        if (pb1->Personarray[i].id == id) {
            return i;
        }
    }
    return -1;
}

void mod(PersonBook* pb1) {
    int id;
    string name;
    int career;
    cout << "请输入需要修改人的id" << endl;
    cin >> id;
    if (isexist(pb1, id) != -1) {
        cout << "修改name为:" << endl;
        cin >> pb1->Personarray[isexist(pb1, id)].name;
        cout << "修改career为:" << endl;
        cin >> pb1->Personarray[isexist(pb1, id)].career;
    }
    else {
        cout << "查无此人" << endl;
    }

}

void sear(PersonBook* pb1) {
    int id;
    cout << "请输入需要查找的id" << endl;
    cin >> id;
    for (int i = 0;i < pb1->size;i++) {
        if (pb1->Personarray[i].id == id) {
            cout << pb1->Personarray[i].id << " ";
            cout << pb1->Personarray[i].name << " ";
            cout << pb1->Personarray[i].career << endl;
            break;
        }
        else {
            cout << "查无此人" << endl;
        }
    }
}

void range(PersonBook* pb1) {

}

void clear(PersonBook* pb1) {
    for (int i = 0;i < pb1->size;i++) {
        pb1->Personarray[i] = {};
    }
}
void txt(PersonBook* pb1) {
    ofstream ofs;
    ofs.open("D:/94.txt", ios::out);
    for (int i = 0;i < pb1->size;i++) {
        ofs << pb1->Personarray[i].id << " ";
        ofs << pb1->Personarray[i].name << " ";
        ofs << pb1->Personarray[i].career << endl;
    }
    ofs.close();
}


int main() {
    PersonBook pb1;
    pb1.size = 0;
    showmenu();
    while (1) {
        cout << "输入你的选择" << endl;
        int a;
        cin >> a;
        switch (a) {
        case 0:return 0;
        case 1:add(&pb1);break;
        case 2:show(&pb1);break;
        case 3:dele(&pb1);break;
        case 4:mod(&pb1);break;
        case 5:sear(&pb1);break;
            // case 6:range();
            // case 7:clear();
        }
        txt(&pb1);
    }
}