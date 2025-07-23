#include <iostream>
#include <vector>
using namespace std;

vector<long long> arr(50);

char solve(int k, long long n) {
    if(k == 0){
        if(n == 1) return 'm';
        else return 'o';
    }

    long long left_len = arr[k - 1];
    long long mid_len = k + 3;
    long long midd = left_len + 1;
    long long right = left_len + mid_len;

    if(n <= left_len) {
        return solve(k - 1, n);
    }
    else if(n == midd) {
        return 'm';
    }
    else if(n > midd && n <= right) {
        return 'o';
    }
    else {
        return solve(k - 1, n - right);
    }
}

int main() {
    long long n;
    cin >> n;

    arr[0] = 3;
    int max_k = 0;
    for(int i = 1; i < 50; i++) {
        arr[i] = 2 * arr[i - 1] + i + 3;
        if(arr[i] >= n) {
            max_k = i;
            break;
        }
    }

    cout << solve(max_k, n) << '\n';
    return 0;
}
