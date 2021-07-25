#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main(){
    AC
    bool mp[1000] = {0}; 
    int n, tmp, cnt=0, x;
    cin >> n;
    while(n != 1){
        tmp = 0;
        while(n){
            x = n % 10;
            n /= 10;
            tmp += x*x;
        }
        n = tmp;
        if(!mp[n]) {
            mp[n] = 1;
            ++cnt;
        }else{
            cnt = -1;
            break;
        }
    }
    cout << cnt;
    return 0;
}