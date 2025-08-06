#include <iostream>
#include <vector>

using namespace std;

void test();

int main(){
    int t;
    cin >> t;
    for(int i =0; i < t; i++){
        test();
    }
}

void test(){
    int n, m;
    cin >> n >> m;
    vector<int> vis(10, 0);
    vector<int> arr(n);
    int  front = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        vis[arr[i]]++;
    }
    while(1){
        int temp = arr[front];
        if(temp == -1){
            front = (front + 1) % n;
            continue;
        }
        bool flag = true;
        for(int i = 9; i > temp; i--){
            if(vis[i] != 0){
                front = (front+1) %n;
                flag = false;
                break;
            }
        }
        if(flag == false){
            continue;
        }
        else{
            if(front == m){
                int total = 0;
                for(int i = 0; i < n; i++){
                    if(arr[i] == -1){
                        total++;
                    }
                }
                cout << total + 1 << endl;
                return;
            }
            arr[front] = -1;
            vis[temp]--;
            front = (front+1) % n;
        }

    }
}