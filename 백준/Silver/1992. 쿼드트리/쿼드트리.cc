#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void recur(vector<vector<int>> &map, int i, int j, int size);

int main(){
    int n;

    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &map[i][j]);
        }
    }

    recur(map, 0, 0, n);
}

void recur(vector<vector<int>> &map, int i, int j, int size){
    if(size == 1){
        cout << map[i][j];
    }
    else{
        int first = map[i][j];
        bool flag = true;
        for(int l = i; l < i+size; l++){
            for(int m = j; m < j + size; m++){
                if(map[l][m] != first){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false){
            cout << "(";
            recur(map, i, j, size/2);
            recur(map, i, j+size/2, size/2);
            recur(map, i+size/2, j, size/2);
            recur(map, i+size/2, j+size/2, size/2);
            cout << ")";
        }
        else{
            cout << first;
        }
    }
}