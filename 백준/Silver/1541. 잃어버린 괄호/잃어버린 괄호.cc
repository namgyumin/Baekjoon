#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    string str;

    getline(cin, str);

    vector<int> arr;

    int data = 0, flag = 0;
    string temp = "0";
    for(char entry : str){
        if(entry == '-'){
            if(flag == 0){
                data += stoi(temp);
            }
            else{
                data -= stoi(temp);
            }
            flag = 1;
            temp = "0";
        }
        else if(entry == '+'){
            if(flag == 0){
                data += stoi(temp);
            }
            else{
                data -= stoi(temp);
            }
            temp = "0";
        }
        else{
            temp += entry;
        }
    }

    if(flag == 0){
        data += stoi(temp);
    }
    else{
        data -= stoi(temp);
    }
    
    cout << data << endl;
}