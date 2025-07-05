#include <iostream>
#include <vector>

using namespace std;

struct element{
    int i,j,day;
    element(int a, int b, int c) : i(a), j(b), day(c){}
};

int i_dir[4] = {-1, 0, 1, 0};
int j_dir[4] = {0, 1, 0, -1};

int rear = 0, front = 0;

int bfs(int arr[][1002], vector<element> q);
void check(int n, int m, int arr[][1002], int goal);
int main(){
    int n, m;
    cin >> n >> m;

    int arr[1002][1002];

    vector<element> q;

    for(int i = 0; i < m+2; i++){
        for(int j = 0; j < n+2; j++){
            if(i == 0 || i == m+1 || j == 0 || j == n+1){
                arr[i][j] = -1;
            }
            else{
                int temp;
                cin >> temp;
                if(temp == 1){
                    q.push_back(element(i,j,0));
                    rear++;
                }
                arr[i][j] = temp;
            }
        }
    }

    int tempday = bfs(arr,q);

    check(n,m,arr,tempday);
}

int bfs(int arr[][1002], vector<element> q){
    int day = 0;
    while(front != rear){
        element temp = q[front++];
        if(day < temp.day){
            day = temp.day;
        }
        for(int i = 0; i < 4; i++){
            int ti = temp.i + i_dir[i];
            int tj = temp.j + j_dir[i];
            if(arr[ti][tj] == 0){
                arr[ti][tj] = 1;
                q.push_back(element(ti,tj,temp.day+1));
                rear++;
            }
        }
    }
    return day;
}

void check(int n, int m, int arr[][1002], int goal){
    for(int i = 1; i < m+1; i++){
        for(int j = 1; j < n+1; j++){
            if(arr[i][j] == 0){
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << goal << endl;

}