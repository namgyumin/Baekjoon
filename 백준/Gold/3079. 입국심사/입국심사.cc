#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, k, min = 0, max =  1e18, res =  1e18;
    cin >> n >> k;

    vector<int> arr (n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    while(min <= max){
        long long mid = (min + max) / 2;
        long long total = 0;
        for(int i = 0; i < n; i++){
            total += mid / arr[i];
            if(total > k){
                break;
            }
        }

        if(total >= k){
            res = mid;
            max = mid - 1;
        }
        else{
            min = mid + 1;
        }
    }
    cout << res;
}