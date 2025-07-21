#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void kantowo(long long n);

int main(){
    int n;
    while(cin >> n){
        long long value = pow(3, n);
        kantowo(value);
        cout << endl;
    }
}

void kantowo(long long n){
    if(n == 1){
        cout << "-";
    }
    else{
        long long size = n/3;
        kantowo(size);
        for(int i = 0; i < size; i++){
            cout << " ";
        }
        kantowo(size);
    }
}