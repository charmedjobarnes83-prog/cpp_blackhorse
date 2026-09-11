#include <manager.h>

Manager::Manager(int id, string name, int careerid) {
    this->m_id = id;
    this->m_name = name;
    this->m_careerid = careerid;
}

void Manager::showinfo() {
    cout << "id:" << this->m_id << "\tname:" << this->m_name << "\tcareerid:" << this->getcareer() << "指挥工作" << endl;
}

string Manager::getcareer() {
    return string("manager");
}