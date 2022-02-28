/*
 tag: trivial, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

int main(){
    AC
    int t, n, m, k;
    cin >> t;
    while(t--){
        int cnt = 0;
        char c;
        vector<int> gain;
        cin >> n >> m >> k;
        for(int i = 0; i < n; ++i){
            int g = 0;
            for(int j = 0; j < m; ++j){
                cin >> c;
                cnt += c == '*';
                g += (c == '.' ? 1 : -1);
            }
            gain.push_back(g);
        }
        sort(begin(gain), end(gain), std::greater<int>());
        int i = 0;
        for(; i < n && k; ++i){
            if(gain[i] > 0) {
                cnt += gain[i];
                k--;
            } else break;
        }
        if(k % 2) {
            if(i == n) cnt -= gain[i-1];
            else if(i == 0) cnt -= -gain[i];
            else cnt -= min(gain[i-1], -gain[i]);
        }
        cout << cnt << endl;
    }
}