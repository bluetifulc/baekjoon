#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        bool A[101] = {0, };
        int x,y,n, a = 1, b = 1;
        cin >> x >> y >> n;
        while(n--){
            int u;
            cin >> u;
            // 1.
            a = (a+u-1)%x;
            b = (b-u-1)%y;
            a++;
            b++;
            if(b <= 0) b += y;
            if(A[a] == false){
                A[a] = true;
                cout << a << " ";
                continue;
            }

            // 2.
            u = b;
            a = (a+u-1)%x;
            b = (b-u-1)%y;
            a++;
            b++;
            if(b <= 0) b += y;
            if(A[a] == false){
                A[a] = true;
                cout << a << " ";
                continue;
            }

            // 3.
            while(A[a] == true){
            a = (a-1-1)%x;
            b = (b+1-1)%y;
            a++;
            b++;
            if(a <= 0) a += x;
            }
            cout << a << " ";
            A[a] = true;
        }
        cout << endl;
    }
    return 0;
}