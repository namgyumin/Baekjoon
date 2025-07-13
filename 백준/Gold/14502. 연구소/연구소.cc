#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coor
{
    int i,j;

    coor(int a, int b) : i(a), j(b) {}
};

int n, m;

int diri[4] = {-1, 0, 1, 0};
int dirj[4] = {0, 1, 0, -1};

int fuc(coor a, coor b, coor c, vector<vector<int>> arr, queue<coor> vir);

int main(){
    cin >> n >> m;

    vector<vector<int>> arr(n+2, vector<int>(m+2, -1));

    vector<coor> sta;

    queue<coor> vir; 

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            int temp;
            cin >> temp;
            if(temp == 0){
                sta.push_back(coor(i,j));
            }
            if(temp == 2){
                vir.push(coor(i,j));
            }
            arr[i][j] = temp;
        }
    }
    
    int top = 0;

    for(int i = 0; i < sta.size(); i++){
        for(int j = i+1; j < sta.size(); j++){
            for(int k = j + 1; k < sta.size(); k++){
                coor f = sta[i], s = sta[j], t = sta[k];
                int temp = fuc(f, s, t, arr, vir);
                if (top < temp){
                    top = temp;
                }
            }
        }
    }

    cout << top;

}


int fuc(coor a, coor b, coor c, vector<vector<int>> arr, queue<coor> vir){
    vector<vector<int>> vis(n+2, vector<int>(m+2, 0));
    arr[a.i][a.j] = 1;
    arr[b.i][b.j] = 1;
    arr[c.i][c.j] = 1;

    while(!vir.empty()){
        coor temp = vir.front();
        vir.pop();
        vis[temp.i][temp.j] = 1;
        for(int i = 0; i < 4; i++){
            int di = temp.i+diri[i], dj = temp.j + dirj[i];
            if(vis[di][dj] == 0 && arr[di][dj] == 0){
                vis[di][dj] = 1;
                vir.push(coor(di, dj));
            }
        }
    }

    int res = 0;

    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(arr[i][j] == 0  && vis[i][j] == 0){
                res++;
            }
        }
    }

    return res;
}