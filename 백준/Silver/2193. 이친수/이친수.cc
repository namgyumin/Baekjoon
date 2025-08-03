#include <iostream>
#include <vector>

using namespace std; 

long long fuc(vector<vector<long long>> &dp, long long step, long long j, long long size);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<vector<long long>> dp(n, vector<long long>(2, -1));

    cout << fuc(dp, 0, 1, n) << endl;
}

long long fuc(vector<vector<long long>> &dp, long long step, long long j, long long size){
    if(size - 1 == step){
        return 1;
    }
    if(dp[step][j] != -1){
        return dp[step][j];
    }
    if(j == 0){
        return dp[step][j] = fuc(dp, step+1, 0, size) + fuc(dp, step + 1, 1, size);
    }
    if(j == 1){
        return dp[step][j] = fuc(dp, step + 1, 0, size);
    }

}