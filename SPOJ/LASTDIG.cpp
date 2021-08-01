#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main(){
    AC
    int n;
    cin >> n;
    while(n--){
        bool map[10] = {0};
        int r[12];
        int a, b, x=1;
        cin >> a >> b;
        if(!b) {
            cout << 1 << endl;
            continue;
        }
        for(int i = 1; i <= b; ++i){
            r[i] = x = (x*a)%10;
            if(map[x]){
                r[0] = r[i-1];
                cout << r[b % (i-1)] << endl;
                break;
            } else if(i == b){
                cout << x << endl;
                break;
            } else map[x] = 1;
        }

    }
    return 0;
}