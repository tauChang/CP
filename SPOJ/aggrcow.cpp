#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define AC ios::sync_with_stdio(0),cin.tie(0);

vector<int> v;

bool able(int c, int val){
    int count = 0, pre = -1e9;
    for(int i = 0; i < v.size(); ++i){
        if(v[i] - pre >= val) {
            if(++count == c) return true;
            pre = v[i];
        }
    }
    return false;
}

int sol(int c){
    int l = 1, r = v[v.size()-1], m;
    while(l+1 < r){
        m = (l+r)/2;
        if(able(c, m)) l = m;
        else r = m;
    }
    return l;
}

int main(){
    AC
    int t, n, c;
    cin >> t;
    while(t){
        cin >> n >> c;
        for(int i = 0, x; i < n; ++i) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        cout << sol(c) << endl;
        v.clear();
        --t;
    }
}