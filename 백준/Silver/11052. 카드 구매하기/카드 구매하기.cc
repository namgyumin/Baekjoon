#include <iostream>
#include <vector>

using namespace std;

long long fuc(vector<long long> &dp, vector<long long> &v, long long step);

int main(){
    int n;
    cin >> n;

    vector<long long> v(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    
    vector<long long> dp(n+1, -1);
    cout << fuc(dp, v, n) << endl;
}

long long fuc(vector<long long> &dp, vector<long long> &v, long long step){
    if(dp[step] != -1){
        return dp[step];
    }
    if(step == 1){
        return dp[step] = v[step];
    }
    long long m = v[step];
    for(int i = 1; i <= step/2; i++){
        m = max(fuc(dp, v, step-i)+fuc(dp, v, i), m);
    }
    return dp[step] = m;
}