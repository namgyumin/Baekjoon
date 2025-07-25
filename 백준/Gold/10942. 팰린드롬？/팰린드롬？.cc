#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<vector<int>> isPal(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        isPal[i][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (A[i] == A[i + 1]) isPal[i][i + 1] = 1;
    }

    for (int len = 3; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            if (A[i] == A[j] && isPal[i + 1][j - 1]) {
                isPal[i][j] = 1;
            }
        }
    }

    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        cout << isPal[s][e] << "\n";
    }
    return 0;
}