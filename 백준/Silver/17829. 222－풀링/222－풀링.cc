#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int divideFuc(int n, vector<vector<int>> &map, int l, int m);
bool compare(int a, int b);
int main(){
    int n;
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j] ;
        }
    }

    cout << divideFuc(n, map, 0, 0);
}

int divideFuc(int n, vector<vector<int>>& map, int l, int m){
    if(n == 2){
        vector<int> arr;
        for(int i = l; i < l+2; i++){
            for(int j = m; j < m+2; j++){
                arr.push_back(map[i][j]);
            }
        }
        sort(arr.begin(), arr.end(), compare);
        return arr[1];
    }
    else{
        int size = n/2;
        vector<int> arr;
        arr.push_back(divideFuc(size, map, l, m));
        arr.push_back(divideFuc(size, map, l, m+size));
        arr.push_back(divideFuc(size, map, l+size, m));
        arr.push_back(divideFuc(size, map, l+size, m+size));
        sort(arr.begin(), arr.end(), compare);
        return arr[1];
    }
}

bool compare(int a, int b){
    return a > b;
}