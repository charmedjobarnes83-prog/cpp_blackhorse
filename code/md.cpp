#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> v1 = { 1,2,11,34,66,55,3,4,5 };
    /*for (auto it1 = v1.begin();it1 != v1.end(); ) {
        if ((*it1) % 2 != 0) {

            it1 = v1.erase(it1);
            continue;
        }
        ++it1;
    }*/
    v1.erase(std::remove_if(v1.begin(), v1.end(), [](int n) {return n % 2 != 0; }), v1.end());
    for (auto it1 = v1.begin();it1 != v1.end(); ++it1) {
        std::cout << *it1 << " ";
    }
    return 0;
}

/*int main() {
    std::vector<int> v1 = { 1,2,11,34,66,55,3,4,5 };
    for (auto it1 = v1.begin();it1 != v1.end(); ++it1) {
        if ((*it1) % 2 != 0) {
            v1.erase(it1);
        }
    }
    for (auto it1 = v1.begin();it1 != v1.end(); ++it1) {
        std::cout << *it1 << " ";
    }
    return 0;
}*/