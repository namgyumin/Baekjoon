#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int fuc(long long n , long long goal);

int main(){
    long long n, goal, flag = 0;
    cin >> n >> goal;

    flag = fuc(n, goal);
    
    if(flag == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

int fuc(long long n , long long goal){
    long long rear = 0, front = n , mid;


    while(rear <= front){
        mid = (rear+front)/2;
        long long res = (n-mid+1) * (mid+1);
        if(res > goal){
            rear = mid+1;
        }
        else if(res < goal){
            front = mid-1;
        }
        else{
            return 1;
        }
    }
    return 0;
}
