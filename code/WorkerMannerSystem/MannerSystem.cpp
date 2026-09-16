#include <iostream>
using namespace std;
#include <string>
#include <worker.h>
#include <employee.h>
#include <manager.h>
#include <boss.h>

#include <workerManner.h>

int main() {
    workerManner wm1;

    while (1) {
        wm1.showmenu();
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 0:return 0;
        case 1:wm1.add();
            break;
        case 2:wm1.show();
            break;
        case 3:wm1.dele();
            break;
        case 4:wm1.modify();
            break;
        case 5:wm1.search();
            break;
        case 6:wm1.sort();
            break;
        case 7:wm1.clear();
            break;
        }
    }

    system("pause");
    return 0;
}
