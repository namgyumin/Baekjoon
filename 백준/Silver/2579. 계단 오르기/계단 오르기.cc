#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int main(){
    cin >> n;
    vector<int> arr(n);
    vector<vector<int>> dp (n, vector<int>(3, 0));
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    if(n > 1){
        dp[1][0] = arr[1];
        dp[1][1] = arr[0] + arr[1];
    }
    
    for(int i = 2; i < n; i++){
        dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + arr[i];
        dp[i][1] = dp[i-1][0] + arr[i];
    }

    int res = max(dp[n-1][0], dp[n-1][1]);

    cout << res << endl;
}
