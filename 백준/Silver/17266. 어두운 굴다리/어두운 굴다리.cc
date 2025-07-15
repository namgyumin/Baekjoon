#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b);

int main(){
    int n, m;

    cin >> n;
    cin >> m;

    vector<int>dist;

    int before = 0, temp;

    for(int i = 0; i < m; i++){
        cin >> temp;
        if(i == 0){
            dist.push_back(temp-before);
        }
        else{
            int entry = temp - before;
            if(entry % 2 == 0){
                dist.push_back(entry/2);
            }
            else{
                dist.push_back(entry/2+1);
            }
        }
        before = temp;
    }

    dist.push_back(n-before);

    sort(dist.begin(), dist.end(), compare);

    cout << dist[0];

}

bool compare(int a, int b){
    return a > b;
}
