#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct coor{
    int i, j;

    coor(int a, int b) : i(a) , j(b) {}
};

int ans, bigSize, n;

void rescurive(coor start, int size, int &number, coor goal);

int main(){
    int i, j;
    
    cin >> n >> i >> j;

    bigSize = pow(2,n);
    int number = 0;

    rescurive(coor(0,0), pow(2,n), number, coor(i,j));

    cout << ans;

}

void rescurive(coor start, int size, int &number, coor goal){
    if(size == 1){
        if(start.i == goal.i && start.j == goal.j){
            ans = number;
            return;
        }
        number++;
    }

    else{
        int temp = size/2;

        if((goal.i >= start.i && goal.i < start.i + temp) && (goal.j >= start.j && goal.j < start.j + temp)){
            rescurive(coor(start.i, start.j), temp, number, goal);
        }
        else if ((goal.i >= start.i && goal.i < start.i + temp) && (goal.j >= start.j + temp)){
            number += temp * temp;
            rescurive(coor(start.i, start.j+temp), temp, number, goal);
        }
        else if ((goal.i >= start.i + temp) && (goal.j >= start.j && goal.j < start.j + temp)){
            number += temp * temp * 2;
            rescurive(coor(start.i+temp, start.j), temp, number, goal);
        }
        else {
            number += temp * temp * 3;
            rescurive(coor(start.i+temp, start.j+temp), temp, number, goal);
        }
        
    }
}