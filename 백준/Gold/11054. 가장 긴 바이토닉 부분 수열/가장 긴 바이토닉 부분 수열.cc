#include <iostream>
#include <vector>

using namespace std;

void makeB(vector<int> &seq, vector<int> &big,int now, int n);
void makeS(vector<int> &seq, vector<int> &big,int now, int n);

int main(){
    int n;

    cin >> n;

    vector<int> seq(n);
    vector<int> big(n,1);
    vector<int> small(n,1);

    for(int i = 0; i < n; i++){
        cin >> seq[i];
    }

    for(int i = n-1; i >= 0; i--){
        makeB(seq, big, i, n);
    }

    for(int i = 0; i < n; i++){
        makeS(seq, small, i, n);
    }

    int total = 0;

    for(int i = 0; i < n; i++){
        if(total < big[i] + small[i]){
            total = big[i] + small[i];
        }
    }
    cout << total - 1;
}

void makeB(vector<int> &seq, vector<int> &big,int now, int n){
    for(int i = now+1; i < n; i++){
        if(seq[now] > seq[i]){
            big[now] = max(big[now], big[i] + 1);
        }
    }
}

void makeS(vector<int> &seq, vector<int> &small,int now, int n){
    for(int i = 0; i < now; i++){
        if(seq[now] > seq[i]){
            small[now] = max(small[now], small[i] + 1);
        }
    }
}