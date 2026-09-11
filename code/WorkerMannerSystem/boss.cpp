#include <boss.h>

Boss::Boss(int id, string name, int careerid) {
    this->m_id = id;
    this->m_name = name;
    this->m_careerid = careerid;
}

void Boss::showinfo() {
    cout << "id:" << this->m_id << "\tname:" << this->m_name << "\tcareerid:" << this->getcareer() << "开公司" << endl;
}

string Boss::getcareer() {
    return string("Boss");
}