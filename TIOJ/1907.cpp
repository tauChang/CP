/*
 tag: LIS, DP, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
#define F first
#define S second
#define pii pair<int, int>

int main(){
    AC
    int t, m;
    cin >> t;
    while(t--){
        cin >> m;
        vector<pii> dolls(m);
        for(int i = 0; i < m; ++i) cin >> dolls[i].F >> dolls[i].S;
        sort(begin(dolls), end(dolls), [](pii& p1, pii&p2) { return p1.F < p2.F || p1.F == p2.F && p1.S > p2.S; });
        vector<int> lis;
        lis.push_back(dolls[0].S);
        for(int i = 1; i < m; ++i){
            if(dolls[i].S > *(lis.end()-1)) lis.push_back(dolls[i].S);
            else *(lower_bound(begin(lis), end(lis), dolls[i].S)) = dolls[i].S;
        }
        cout << lis.size() << endl;
    }
}