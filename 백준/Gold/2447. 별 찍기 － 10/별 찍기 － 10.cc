#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void star_maker(int n, vector<vector<int>> &arr, int i, int j);

int main(){
    int n;
    
    cin >> n;

    vector<vector<int>> arr (n+1, vector<int>(n+1, 0));

    star_maker(n, arr, 1, 1);

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < n+1; j++){
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

void star_maker(int n, vector<vector<int>> &arr, int i , int j){
    if(n == 1){
        arr[i][j] = 1;
    }
    else{
        int plus = n/3;
        star_maker(plus, arr, i, j);
        star_maker(plus, arr, i, j + plus);
        star_maker(plus, arr, i, j + (2*plus));

        star_maker(plus, arr, i + plus, j); 
        star_maker(plus, arr, i + plus, j + (2*plus));

        star_maker(plus, arr, i + (2*plus), j);
        star_maker(plus, arr, i + (2*plus), j + plus);
        star_maker(plus, arr, i + (2*plus), j + (2*plus));
    }
}