#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#define MAX 1000

struct Person{
  string name;
  string sex;
  int age;
  int tele;
  string address;  
};

struct AddressBook{//通讯录结构体
  //通讯录中保存的联系人数组
  struct Person personArray[MAX];
  //通讯录在当前记录联系人个数
  int size;
};

void showmenu();
void addPerson(AddressBook * abs);
void del(AddressBook * abs);
int isExist(AddressBook * abs, string name);
void viewPerson(AddressBook * abs);
void searchPerson(AddressBook * abs);
void modifyPerson(AddressBook * abs);
void clearPerson(AddressBook * abs);

void showmenu() {
    cout << "**************************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "**************************" << endl;
}

void addPerson(AddressBook * abs){  
    if(abs->size == MAX){
        cout<<"通讯录已满"<<endl;
        return;
    }
    else{
        string name;
        int sex;
        int age;
        int tele;
        string address;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[abs->size].name = name;
        
        cout << "请输入性别 1为男 2为女"<< endl;
        FLAG:
        cin >> sex;
        if(sex==1){
            abs->personArray[abs->size].sex = "男";
        }
        else if (sex==2){
            abs->personArray[abs->size].sex = "女";
        }
        else{
            cout<<"输入性别信息错误，请重新输入"<<endl;
            goto FLAG;
        }

        cout<<"请输入年龄"<<endl;
        cin >> age;
        abs->personArray[abs->size].age = age;

        cout<<"请输入电话"<<endl;
        cin>>tele;
        abs->personArray[abs->size].tele = tele;
        
        cout<<"请输入住址"<<endl;
        cin >> address;
        abs->personArray[abs->size].address = address;
        
        system("pause");
        system("cls");

        abs->size++;
    }
 
}

void del(AddressBook * abs){//覆盖操作实现删除
    cout << "请输入要删除的人的姓名" << endl;
    string name;
    cin >> name;
    int index;
    index = isExist(abs,name);
    if(index == -1){
        cout << "联系人不存在" << endl;
    }
    else{
        for(int i = index;i<abs->size;i++){
            abs->personArray[i] = abs->personArray[i+1];
            cout << "删除成功" << endl;
        }
        abs->size--;
    }

    system("pause");
    system("cls");
}

int isExist(AddressBook * abs, string name){//检测联系人是否存在，且查找其具体位置
    for(int i = 0;i<abs->size;i++){
        if(abs->personArray[i].name == name){
            return i;
        }
    }
        return -1;
}

void viewPerson(AddressBook * abs){
    for(int i=0;i<abs->size;i++){
            cout << abs->personArray[i].name << "\t";
            cout << abs->personArray[i].sex << "\t";
            cout << abs->personArray[i].age << "\t";
            cout << abs->personArray[i].tele << "\t";
            cout << abs->personArray[i].address << "\t";
            cout << endl;
    }
    system("pause");
    system("cls");
}

void searchPerson(AddressBook * abs){
    cout << "请输入需要查找的联系人姓名"<<endl;
    string name;
    cin >> name;
    bool found = false;
    for(int i=0;i<abs->size;i++){
        if(name == abs->personArray[i].name){
            cout << "你要寻找的人信息如下" << endl;
            cout << abs->personArray[i].name << "\t";
            cout << abs->personArray[i].sex << "\t";
            cout << abs->personArray[i].age << "\t";
            cout << abs->personArray[i].tele << "\t";
            cout << abs->personArray[i].address << "\t";
            cout << endl;
            found = true;
        }
    }
    if(!found){
        cout << "查无此人" << endl;
    }
    system("pause");
    system("cls");
}

void modifyPerson(AddressBook * abs){
    cout << "请输入需要修改的联系人姓名"<<endl;
    string name;
    int sex;
    int age;
    int tele;
    string address;
    cin >> name;
    int index = isExist(abs,name);
    if(index == -1){
        cout << "联系人不存在"<< endl;
    }
    else{
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personArray[index].name = name;
        
        cout << "请输入性别 1为男 2为女"<< endl;
        FLAG:
        cin >> sex;
        if(sex==1){
            abs->personArray[index].sex = "男";
        }
        else if (sex==2){
            abs->personArray[index].sex = "女";
        }
        else{
            cout<<"输入性别信息错误，请重新输入"<<endl;
            goto FLAG;
        }

        cout<<"请输入年龄"<<endl;
        cin >> age;
        abs->personArray[index].age = age;

        cout<<"请输入电话"<<endl;
        cin>>tele;
        abs->personArray[index].tele = tele;
        
        cout<<"请输入住址"<<endl;
        cin >> address;
        abs->personArray[index].address = address;
        
        system("pause");
        system("cls");
    }
}

void clearPerson(AddressBook * abs){
    for(int i=0;i<abs->size;i++){
        abs->personArray[i] = {};//重置联系人数据，但不会释放内存
    }
    abs->size = 0;
    cout << "通讯录已清空" << endl;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif


    AddressBook abs;
    abs.size = 0;

    int num;
    while (true) {
        showmenu();
        if (!(cin >> num)) {
            return 0;
        }

        switch (num) {
        case 1:
            cout << "添加联系人" << endl;
            addPerson(&abs);//地址传递修改实参
            break;
        case 2:
            cout << "显示联系人" << endl;
            viewPerson(&abs);
            break;
        case 3:
            cout << "删除联系人" << endl;
            del(&abs);
            break;
        case 4:
            cout << "查找联系人" << endl;
            searchPerson(&abs);
            break;
        case 5:
            cout << "修改联系人" << endl;
            modifyPerson(&abs);
            break;
        case 6:
            cout << "清空联系人" << endl;
            clearPerson(&abs);
            break;
        case 0:
            cout << "退出通讯录" << endl;
            return 0;
        default:
            cout << "无效选项，请重新输入" << endl;
            break;
        }
    }
}
