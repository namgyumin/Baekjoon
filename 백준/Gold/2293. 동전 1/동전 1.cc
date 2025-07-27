#include <iostream>
#include <vector>
#include <string>

using namespace std;

int coin(vector<int> &arr, vector<vector<int>> &dp, int k, int aSize, int index);

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> base(n);
    for(int i = 0; i < n; i++){
        cin >> base[i];
    }

    vector<int> dp(k+1, 0);

    dp[0] = 1;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <= k - base[i]; j++){
            dp[j + base[i]] += dp[j];
        }
    }
    cout << dp[k];
}