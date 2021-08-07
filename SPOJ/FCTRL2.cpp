#include <iostream>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int qry[103], len[104], fac[104][200];

void calc(int maxn){
    len[0] = fac[0][0] = 1;
    for(int i = 1; i <= maxn; ++i){
        int car = 0;
        int& j = len[i];
        for(; j < len[i-1]; ++j){
            fac[i][j] = (fac[i-1][j]*i + car) % 10;
            car = (fac[i-1][j]*i + car) / 10;
        }
        while(car){
            fac[i][j] = car % 10;
            car /= 10;
            ++j;
        }
    }
}

int main(){
    AC
    int t, n, maxn = -1;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> qry[i];
        maxn = max(maxn, qry[i]);
    }
    calc(maxn);
    for(int i = 0; i < t; ++i){
        for(int j = len[qry[i]]-1; j >= 0; --j) cout << fac[qry[i]][j];
        cout << endl;
    }

    return 0;
}
