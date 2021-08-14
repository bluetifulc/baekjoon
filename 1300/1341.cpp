#include <iostream>
#include <string>
// 사이좋은 형제
// Math
using namespace std;
string binary;
int main(){
    long long a,b;
    cin >> a >> b;
    if(a == 0){
        cout << "-\n";
        return 0;
    }
    if(a == b){
        cout << "*\n";
        return 0;
    }
    long long oa = a;
    while(a != 0 && binary.size() < 120){
        a *= 2;
        if(a >= b){
            binary += "1";
            a -= b;
        }else{
            binary += "0";
        }
    }
    if(binary.length() < 120){
        cout << "-1\n";
        return 0;
    }
    for(int i = 1; i <= 60; ++i){
        string tmp = binary.substr(0, i);
        for(int j = i; j + i <= 120; j += i){
            if(binary.substr(j,i) != tmp){
                tmp = "#";
                break;
            }
        }
        if(tmp != "#"){
            for(int j = 0; j < tmp.length(); ++j){
                tmp[j] = (tmp[j] == '1') ? '*' : '-';
            }
            cout << tmp << endl;
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}