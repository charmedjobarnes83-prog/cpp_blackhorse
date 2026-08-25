#include <iostream>
using namespace std;

int main(){
    int sum[3] = {0};
    string name[3] = {"张三","李四","王五"};
    int arr[3][3] = {{100,100,100},{90,50,100},{60,70,80}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){  
            sum[i] += arr[i][j];
        }
    }
    for(int i=0;i<3;i++){
        cout << name[i]<< ":"<< sum[i] << endl;
    }
}
