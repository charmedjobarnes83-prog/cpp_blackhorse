#include <queue>
#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>

struct Accumulator{
  int sum;
  Accumulator(){
    sum = 0;
  }  
  void operator()(int x){
    sum += x;
  }
};
int main(){
    Accumulator a1;
    a1(10);
    a1(20);
    a1(30);
    cout << a1.sum;
}

  