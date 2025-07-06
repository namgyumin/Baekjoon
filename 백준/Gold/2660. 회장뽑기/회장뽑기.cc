#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//방법 -> n을 받고 -1,-1 입력값이 들어올때까지 while문을 사용해서 입력을 받아서 
//저장을 한다 (link list 구조체를 사용해서 배열 저장한다) 첫번째 값은 최대 건너는 수를 체크한다
//for 문을 이용해서 각자의 최대 건너는 수를 확인한다 (각 각 bfs 사용 -> (bfs)nlogn * (for문)n ==> (n은 최대 50까지임) 10000 언저리)

struct link{
    int data;
    link *next;
    link(int a, link *b) : data(a), next(b) {}
};

void push(vector<link*> &arr, int v1, int v2);
void bfs(vector<link*> &arr, int v1, int n);

int main(){
    int n, v1, v2;

    cin >> n;

    vector<link*> arr;

    for(int i = 0; i <= n; i++){
        arr.push_back(new link(0,nullptr));
    }

    while(1){
        cin >> v1 >> v2;
        if(v1 == -1 && v2 == -1){
            break;
        }
        else{
            push(arr, v1, v2);
            push(arr, v2, v1);
        }
    }

    int min = 10000, total = 0;
    vector<int> res;
    for(int i = 1; i <= n; i++){
        bfs(arr, i , n);
        if(arr[i]->data < min){
            min = arr[i]->data;
        }
    }

    for(int i = 1; i <= n; i++){
        if(arr[i]->data == min){
            total++;
            res.push_back(i);
        }
    }

    cout << min << " " << total << endl;
    for(int entry : res){
        cout << entry << " ";
    }
}

void push(vector<link*> &arr, int v1, int v2){
    link* trail= arr[v1];

    while(trail->next != nullptr){
        trail = trail->next;
    }

    link* temp = new link(v2, nullptr);
    trail->next = temp;
}

void bfs(vector<link*> &arr, int v1, int n){
    vector<int>visited(n+1 , 0);
    queue<int> q;
    q.push(v1);
    visited[v1] = 1;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        link * trail = arr[temp];
        while(trail->next){
            trail = trail->next;
            if(visited[trail->data] == 0){
                q.push(trail->data);
                visited[trail->data] = visited[temp] + 1;
            }
        }
    }

    int max = 0;
    for(int i = 1; i <= n; i++){
        if (visited[i] > max){
            max = visited[i];
        }
    }
    arr[v1]->data = max-1;
}