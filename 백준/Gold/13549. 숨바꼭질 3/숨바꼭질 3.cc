#include <iostream>
#include <vector>
using namespace std;

int n, k;

void fuc(vector<int> &arr, int now);

int main(){
    cin >> n >> k;
    vector<int>a(200001 , -1);
    a[n] = 0;
    fuc(a, n);
    cout << a[k] << endl;
}

void fuc(vector<int> &arr, int now){
    vector<int>q;
    int front = 0, rear = 0;
    q.push_back(now);
    rear++;
    while(front < rear){
        int temp = q[front++];
        if (arr[temp] == -1) continue;
        if(temp + 1 < arr.size()){
            if(arr[temp+1] == -1 || arr[temp] + 1 < arr[temp + 1]){
                arr[temp+1] = arr[temp] +1;
                q.push_back(temp+1);
                rear++; 
            }
        }
        if(temp > 0){
            if(arr[temp-1] == -1 || arr[temp] + 1 < arr[temp-1]){
                arr[temp-1] = arr[temp] +1;
                q.push_back(temp-1);
                rear++; 
            }
        }
        if(temp * 2 < arr.size()){
            if(arr[temp*2] == -1 || arr[temp] < arr[temp*2]){
                arr[temp*2] = arr[temp];
                q.push_back(temp*2);
                rear++; 
            }
        }
    }
}