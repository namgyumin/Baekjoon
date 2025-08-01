#include <iostream>
#include <vector>

using namespace std;

int bu(vector<int> &a, vector<int> &v, int now, int size);
int du(vector<int> &a, vector<int> &v, int now);

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        char temp;
        cin >> temp;
        if(temp == 'B'){
            v[i] = 0;
        }
        else{
            v[i] = 1;
        }
    }

    vector<int> b(n, -1);
    vector<int> d(n, -1);

    bu(b, v, 0, n);
    du(d, v, n-1);

    int min = 1000000;

    for(int i = 0; i < n; i++){
        if(min > b[i] + d[i] - 1){
            min = b[i] + d[i] - 1;
        }
    }

    cout << min;
}

int bu(vector<int> &a, vector<int> &v, int now, int size){
    if(now == size){
        return 0;
    }
    if(a[now] != -1){
        return a[now];
    }
    if(v[now] == 0){
        return a[now] = 1 + bu(a, v, now + 1, size);
    }
    else{
        return a[now] = bu(a, v, now + 1, size);
    }
}

int du(vector<int> &a, vector<int> &v, int now){ //뒤에서부터 기준이 되서 이제 돌리는건데
    if(now == -1){
        return 0;
    }
    if(a[now] != -1){
        return a[now];
    }
    if(v[now] == 1){
        return a[now] = 1 + du(a, v, now - 1);
    }
    else{
        return a[now] = du(a, v, now - 1);
    }
}