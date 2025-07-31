#include <iostream>
#include <vector>

using namespace std;

int fuc(vector<vector<int>> &dp, int nowi, int nowj, int si, int sj);

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n+1, vector<int> (m+1, -1));

    int k;
    cin >> k;

    int subn = (k-1)/m+1, subm = (k-1) % m + 1; 


    if(k == 0){
        cout << fuc(map, 1, 1, n, m);
    }
    else{
        int res = fuc(map, 1, 1, subn, subm);
        map[subn][subm] = -1;
        res *= fuc(map, subn, subm, n, m);
        cout << res;
    }
}

int fuc(vector<vector<int>> &dp, int nowi, int nowj, int si, int sj){
    if(nowi > si || nowj > sj){
        return 0;
    }
    if(dp[nowi][nowj] != -1){
        return dp[nowi][nowj];
    }
    if(nowi == si && nowj == sj){
        return dp[nowi][nowj] = 1;
    }
    else{
        return dp[nowi][nowj] = fuc(dp, nowi+1, nowj, si,sj) + fuc(dp, nowi, nowj+1, si,sj);
    }
}