#include <iostream>
#include <vector>

using namespace std;

long long n;

vector<vector<long long>> recurMat(vector<vector<long long>> &mat, long long n, vector<vector<long long>> &base);
vector<vector<long long>> powMat(vector<vector<long long>> &mat);
long long calMat(vector<vector<long long>> &mat, long long i , long long j);
long long calMatVer2(vector<vector<long long>> &v1, vector<vector<long long>> &v2, long long i , long long j);
vector<vector<long long>> mutiMat(vector<vector<long long>> &v1, vector<vector<long long>> &v2);

int main(){
    long long b;

    cin >> n >> b;

    vector<vector<long long>> mat(n, vector<long long>(n));

    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    vector<vector<long long>> base(n, vector<long long>(n));
    
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            base[i][j] = mat[i][j];
        }
    }

    vector<vector<long long>> temp = recurMat(mat, b, base);

    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            cout << (temp[i][j]) % 1000 << " ";
        }
        cout << endl;
    }

}

vector<vector<long long>> recurMat(vector<vector<long long>> &mat, long long n, vector<vector<long long>> &base){
    if(n == 1){
        vector<vector<long long>> ret(n, vector<long long>(n));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < n; j++){
                ret[i][j] = mat[i][j] % 1000;
            }
        }
        return mat;
    }
    vector<vector<long long>> temp = recurMat(mat, n/2, base) ;
    vector<vector<long long>> ret = powMat(temp);
    if(n % 2 == 0){
        return ret;
    }
    else{
        ret = mutiMat(ret, base);
        return ret;
    }
}

vector<vector<long long>> powMat(vector<vector<long long>> &mat){
    vector<vector<long long>> ret(n, vector<long long>(n));
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            ret[i][j] = calMat(mat, i, j);
        }
    }
    return ret;
}

long long calMat(vector<vector<long long>> &mat, long long i , long long j){
    long long total = 0;
    for(long long m = 0; m < n; m++){
        total += (mat[i][m] * mat[m][j]) % 1000;
    }
    return total % 1000;
}

long long calMatVer2(vector<vector<long long>> &v1, vector<vector<long long>> &v2, long long i , long long j){
    long long total = 0;
    for(long long m = 0; m < n; m++){
        total += (v1[i][m] * v2[m][j]) % 1000;
    }
    return total % 1000;
}

vector<vector<long long>> mutiMat(vector<vector<long long>> &v1, vector<vector<long long>> &v2){
    vector<vector<long long>> ret(n, vector<long long>(n));
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            ret[i][j] = calMatVer2(v1, v2, i, j);
        }
    }
    return ret;
}