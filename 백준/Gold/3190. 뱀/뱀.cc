#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int diri[4] = {0, -1, 0, 1}; // 오른쪽 위로 왼쪽 아래로 순서
int dirj[4] = {1, 0, -1, 0};

struct element{
    int time;
    int go;
    element(int a, int b) : time(a), go(b) {}
};

struct dat{
    int i,j;
    dat(int a, int b) : i(a), j(b) {}
};

int main(){
    int n, k, a, b, l;

    cin >> n;

    vector<vector<int>> arr(n+2, vector<int>(n+2, 0));

    for(int i = 0; i < n+2; i++){
        arr[0][i] = -1;
        arr[i][0] = -1;
        arr[n+1][i] = -1;
        arr[i][n+1] = -1;
    }
    cin >> k;

    for(int i = 0; i < k; i++){
        cin >> a >> b;
        arr[a][b] = 1;
    }

    cin >> l;

    queue<element> dir;

    for(int i = 0; i < l; i++){
        int temp_i;
        char temp_c;
        cin >> temp_i >> temp_c;
        if(temp_c == 'L'){
            dir.push(element(temp_i, 1));
        }
        else if(temp_c == 'D'){
            dir.push(element(temp_i, -1));
        }
    }

    int count = 0, go = 0;
    queue<dat> snack;
    snack.push(dat(1,1));
    dat head = dat(1,1);
    arr[1][1] = -1;
    while(1){
        count++;
        
        int di = head.i + diri[go];
        int dj = head.j + dirj[go];
        if(arr[di][dj] == -1){
            break;
        }
        else if (arr[di][dj] == 1){
            snack.push(dat(di, dj));
            head = dat(di, dj);
            arr[di][dj] = -1;
        }
        else{
            snack.push(dat(di, dj));
            head = dat(di, dj);
            arr[di][dj] = -1;
            dat temp = snack.front();
            snack.pop();
            arr[temp.i][temp.j] = 0;
        }

        if(!dir.empty()){
            if(count == dir.front().time){
                go += dir.front().go;
                dir.pop();
                if(go < 0){
                    go = 3;
                }
                if(go >= 4){
                    go = 0;
                }
            }
        }

    }

    cout << count;
}