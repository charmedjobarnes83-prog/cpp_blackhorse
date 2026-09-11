#include <employee.h>

Employee::Employee(int id, string name, int careerid) {
    this->m_id = id;
    this->m_name = name;
    this->m_careerid = careerid;
}

void Employee::showinfo() {
    cout << "id:" << this->m_id << "\tname:" << this->m_name << "\tcareerid:" << this->getcareer() << "完成员工的工作" << endl;
}
string Employee::getcareer() {
    return string("employee");
}