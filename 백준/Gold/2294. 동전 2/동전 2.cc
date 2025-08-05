#include <iostream>
#include <vector>

using namespace std;

int fuc(vector<int> &dp, vector<int> &arr, int n, int step);

int main(){
    int n, goal;
    cin >> n >> goal;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> dp(goal+1, -1);

    fuc(dp, arr,n, goal);

    if(dp[goal] > 10000){
        cout << -1;
    }
    else{
        cout << dp[goal];
    }
}

int fuc(vector<int> &dp, vector<int> &arr, int n, int step){
    int m = 10001;
    if(step < 0){
        return m;
    }
    if(step == 0){
        return 0;
    }
    if(dp[step] != -1){
        return dp[step];
    }
    for(int i = 0; i < n; i++){
        m = min(m, fuc(dp, arr, n, step - arr[i]) + 1);
    }
    return dp[step] = m;

}
