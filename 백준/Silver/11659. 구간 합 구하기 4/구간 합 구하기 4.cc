#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<int> arr(n);
    vector<int> dp(n+1);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[0];
    for(int i= 2; i <= n; i++){
        dp[i] = dp[i-1] + arr[i-1]; 
    }
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << dp[e] - dp[s-1] << '\n';
    }
}