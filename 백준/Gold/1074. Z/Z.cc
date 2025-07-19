#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct coor{
    int i, j;
    coor(int a, int b) : i(a) , j(b) {}
};

int ans;

void rescurive(coor start, int size, int &number, coor goal);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n >> i >> j;

    int initial_size = static_cast<int>(pow(2, n));
    int number = 0;

    rescurive(coor(0,0), initial_size, number, coor(i,j));

    cout << ans << endl;

    return 0;
}

void rescurive(coor start, int size, int &number, coor goal){
    if(size == 1){
        if(start.i == goal.i && start.j == goal.j){
            ans = number;
            return;
        }
        return;
    }

    int temp = size/2;
    int quad_area = temp * temp;

    if((goal.i >= start.i && goal.i < start.i + temp) && (goal.j >= start.j && goal.j < start.j + temp)){
        rescurive(coor(start.i, start.j), temp, number, goal);
    }
    else if ((goal.i >= start.i && goal.i < start.i + temp) && (goal.j >= start.j + temp)){
        number += quad_area;
        rescurive(coor(start.i, start.j + temp), temp, number, goal);
    }
    else if ((goal.i >= start.i + temp) && (goal.j >= start.j && goal.j < start.j + temp)){
        number += 2 * quad_area;
        rescurive(coor(start.i + temp, start.j), temp, number, goal);
    }
    else {
        number += 3 * quad_area;
        rescurive(coor(start.i + temp, start.j + temp), temp, number, goal);
    }
}