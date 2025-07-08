#include <iostream>
#include <vector>
using namespace std;


long long fuc(vector<long long>&arr, long long max, long long goal);

int main(){
    long long n, total, max = 0, min = 1;
    cin >> n >> total;

    vector<long long> arr(n);

    for(long long i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > max){
            max = arr[i];
        }
    }

    cout << fuc(arr, max, total) << endl;
}

long long fuc(vector<long long>& arr, long long max, long long goal){
    long long min = 1;
    long long res = 0;
    while(max >= min){
        long long total = 0;
        long long mid = (max+min)/2;
        if(mid == 0){
            return -1;
        }
        for(long long entry : arr){
            total += entry/mid;
        }
        if(total >= goal){
            min = mid+1;
            res = mid;
        }
        else{
            max = mid - 1;

        }
    }
    return res;
}