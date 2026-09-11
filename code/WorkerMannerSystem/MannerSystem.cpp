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
        case 0:wm1.exitSystem();
            break;
        case 1:wm1.add();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        }
    }

    system("pause");
    return 0;
}
