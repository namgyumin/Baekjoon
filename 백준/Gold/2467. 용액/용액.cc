#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long n;

    cin >> n;

    vector<long long> v;

    for(long long i = 0; i < n; i++){
        long long temp;
        cin >> temp;
        v.push_back(temp);
    }

    long long res = 200000000000, rear = n-1, front = 0, res_samll, res_big;

    while(rear > front){
        long long handle = v[rear] + v[front];
        if(res >= abs(handle)){
            res = abs(handle);
            res_samll = v[front];
            res_big = v[rear];
        }
        if(handle > 0){
            rear--;
        }
        else{
            front++;
        }
    }

    cout << res_samll << " " << res_big;
}