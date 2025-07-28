#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int dya(vector<vector<long long>> &dp, vector<int> &arr, int now, int hes,int n);

int main(){
    string str;
    cin >> str;
    vector<int> arr ;
    for(char c : str){
        if(isdigit(c)){
            arr.push_back(c - '0');
        }
    }
    int n = arr.size();
    vector<vector<long long>> dp (3, vector<long long>(n+1, -1));
    cout << dya(dp, arr, 0, 0, n);
    return 0;
}

int dya(vector<vector<long long>> &dp, vector<int> &arr, int now, int hes,int n){
    if(now == n){
        if(hes == 0){
            return 1;
        }
        return 0;
    }
    if(dp[hes][now] != -1){
        return dp[hes][now];
    }
    if(hes == 0){
        if(arr[now] == 0){
            return dp[hes][now] = 0;
        }
        long long &ret = dp[hes][now];
        ret = 0;
        ret += dya(dp, arr, now+1, 0, n);
        if(now + 1 <= n && (arr[now] == 1 || arr[now] == 2)){
            ret  += dya(dp, arr, now+1, arr[now], n);
        }
        ret %= 1000000;
        return ret;
    }
    if(hes == 1){
        long long &ret = dp[hes][now];
        ret = 0;
        ret += dya(dp, arr, now+1, 0, n);
        ret %= 1000000;
        return ret;
    }
    if(hes == 2){
        if(arr[now] > 6){
            return 0;
        }
        long long &ret = dp[hes][now];
        ret = 0;
        ret += dya(dp, arr, now+1, 0, n);
        ret %= 1000000;
        return ret;
    }
}



