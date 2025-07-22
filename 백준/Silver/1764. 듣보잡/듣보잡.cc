#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n >> m;

    unordered_set<string> temp;
    vector<string> res;

    for(int i = 0; i < n; i++){
        string t;
        cin >> t;
        temp.insert(t);
    }
    for(int i = 0; i < m; i++){
        string t;
        cin >> t;
        if (temp.find(t) != temp.end()){
            res.push_back(t);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(string entry : res){
        cout << entry << endl;
    }
}


