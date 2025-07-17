#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void star_maker(int n, vector<vector<int>> &arr, int i, int j);

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n*2 + 1, 0));

    star_maker(n*2, arr, 0, n);
    for(int i = 0; i < n; i++){
    for(int j = 1; j < n*2+1; j++){
            if(arr[i][j] == 1){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << endl;
    }

}

void star_maker(int n, vector<vector<int>> &arr, int i, int j){
    if(n % 4 == 0){
        int k = n/2, divideBy2 = n/4;
        star_maker(k, arr, i, j);
        star_maker(k, arr, i + divideBy2, j - divideBy2);
        star_maker(k, arr, i + divideBy2, j + divideBy2);
    }
    else if(n == 6){
        star_maker(1, arr, i, j);
        star_maker(1, arr, i + 1, j - 1);
        star_maker(1, arr, i + 1, j + 1);
        star_maker(1, arr, i + 2, j - 2);
        star_maker(1, arr, i + 2, j - 1);
        star_maker(1, arr, i + 2, j);
        star_maker(1, arr, i + 2, j + 1);
        star_maker(1, arr, i + 2, j + 2);
    }
    else if(n == 1){
        arr[i][j] = 1;
    }
    else{
        int k = n/3;
        star_maker(k, arr, i, j + k);
        star_maker(k, arr, i + k, j);
        star_maker(k, arr, i + k, j+ (2*k));
    }
}