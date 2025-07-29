#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n;
    cin >> n;
    
    vector<long long> dp(3);
    dp[0] = 1;
    dp[1] = 1;

    for(long long i = 0; i < n-2; i++){
        long long temp = (dp[0] + dp[1]) % 1000000007;
        dp[0] = dp[1];
        dp[1] = temp;
    }

    cout << dp[1] << " " << n-2 << endl;
}
