#include <iostream>
#include <string>
// 1343 폴리오미노
// String


using namespace std;
int main() {
    string input;
    cin >> input;
    for(int i = 0; i < input.size();){
        if(input[i] == '.'){
            ++i;
            continue;
        }
        if(input.substr(i, 4) == "XXXX") {
            input.replace(i,4,"AAAA");
            i = i+4;
            continue;
        }

        if(input.substr(i, 2) == "XX"){
            input.replace(i,2,"BB");
            i = i+2;
            continue;
        }
        cout << "-1\n";
        return 0;
    }
    cout << input;

    return 0;
}