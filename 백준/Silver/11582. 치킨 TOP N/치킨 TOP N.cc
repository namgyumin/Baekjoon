#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int goal;
int n;
vector<int> divideV(vector<int> v);
vector<int> merge(vector<int> &v1, vector<int> &v2);
bool compare(int a, int b);
int main(){
    cin >>n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    cin >> goal;
    vector<int> ans = divideV(v);

    for(int entry : ans){
        cout << entry << " ";
    }
}

vector<int> divideV(vector<int> v){
    int size = v.size();
    if(size <=  1){
        return v;
    }
    else{
        vector<int> v1(v.begin(), v.begin() + size/2);
        vector<int> v2(v.begin()+ size/2, v.end());
        v1 = divideV(v1);
        v2 = divideV(v2);
        return merge(v1, v2);
    }
}

vector<int> merge(vector<int> &v1, vector<int> &v2){
    v1.insert(v1.end(), v2.begin(), v2.end());
    if(v1.size() > n / goal){
        return v1;
    }
    else{
        sort(v1.begin(), v1.end(), compare);
        return v1;
    }
}

bool compare(int a, int b){
    return a < b;
}