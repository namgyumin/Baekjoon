#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    string str;
    string output;
    vector<int> v(20);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if(str.compare("add") == 0){
            cin >> num;
            v[num-1] = 1;
        }
        else if(str.compare("remove") == 0){
            cin >> num;
            v[num-1] = 0;
        }
        else if(str.compare("check") == 0){
            cin >> num;
            cout << v[num-1] << "\n";
        }
        else if(str.compare("toggle") == 0){
            cin >> num;
            if(v[num-1] == 1){
                v[num-1] = 0;
            }
            else{
                v[num-1] = 1;
            }
        }
        else if(str.compare("all") == 0){
            for(int i = 0; i < 20; i++){
                v[i] = 1;
            }
        }
        else if(str.compare("empty") == 0){
            for(int i = 0; i < 20; i++){
                v[i] = 0;
            }
        }
    }
}
