#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct element
{
    int from, to, value;
    element(int a, int b, int c) : from(a), to(b), value(c) {}
};

bool compare(const element a, const element b);
void unio(vector<int>&arr, int a, int b);
int find(vector<int>&arr, int data);

int main(){
    int v,e;

    cin >> v >> e;

    vector<element>arr;

    vector<int>vis(v+1, -1);

    for(int i = 0 ; i < e; i++){
        int a,b,c;
        cin >> a >> b >> c;
        arr.push_back(element(a,b,c));
    }

    sort(arr.begin(), arr.end(), compare);

    int total = 0;

    for(element entry : arr){
        if(find(vis, entry.from) != find(vis, entry.to)){
            unio(vis, entry.from, entry.to);
            total += entry.value;
        }
    }
    
    cout << total;
}

bool compare(const element a, const element b){
    return a.value < b.value;
}

int find(vector<int>&arr, int data){
    if(arr[data] < 0) return data;
    else{
        return arr[data] = find(arr, arr[data]);
    }
}

void unio(vector<int>&arr, int a, int b){
    int v1 = find(arr, a);
    int v2 = find(arr, b);
    if(arr[v1] > arr[v2]){
        arr[v2] += arr[v1];
        arr[v1] = v2; 
    }
    else {
        arr[v1] += arr[v2];
        arr[v2] = v1; 
    }
}