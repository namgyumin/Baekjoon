#include <iostream>
#include <vector>

using namespace std;

// R, G , B 에 관한 함수를 각각 3개 dp 로 저장시키면서 리턴을 받아서 그 중 가장 작은거를 리턴하면서 저장하자. <<-- 기본 이론

int fuc(vector<vector<int>> &dp, vector<vector<int>> &map, int now, int rgb, int n);

int main(){
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(3));
    vector<vector<int>> dp(n, vector<int>(3, -1));

    for(int i = 0; i < n; i++){
        int r, g, b;
        cin >> r >> g >> b;
        map[i][0] = r;
        map[i][1] = g;
        map[i][2] = b;
    }

    int r = fuc(dp, map, 0, 0, n-1);
    int g = fuc(dp, map, 0, 1, n-1);
    int b = fuc(dp, map, 0, 2, n-1);
    int ret = min(r, b);
    ret = min(ret, g);
    cout << ret << endl;
}

int fuc(vector<vector<int>> &dp, vector<vector<int>> &map, int now, int rgb, int n){
    if(dp[now][rgb] != -1){
        return dp[now][rgb];
    }
    if(now == n){
        if(rgb == 0){
            return dp[now][rgb] = min(map[now][1], map[now][2]);
        }
        if(rgb == 1){
            return dp[now][rgb] = min(map[now][0], map[now][2]);
        }
        if(rgb == 2){
            return dp[now][rgb] = min(map[now][1], map[now][0]);
        }
    }

    if(rgb == 0){
        return dp[now][rgb] = min(fuc(dp, map, now+1, 1, n)+ map[now][1],fuc(dp, map, now+1, 2, n) + map[now][2]);
    }
    if(rgb == 1){
        return dp[now][rgb] = min(fuc(dp, map, now+1, 0, n) + map[now][0], fuc(dp, map, now+1, 2, n) + map[now][2]);
    }
    if(rgb == 2){
        return dp[now][rgb] = min(fuc(dp, map, now+1, 1, n) + map[now][1], fuc(dp, map, now+1, 0, n) + map[now][0]);
    }
    
}
