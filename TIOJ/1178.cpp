/*
 tag: convex hull
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

pll operator-(pll p1, pll p2){
    return {p1.F-p2.F, p1.S-p2.S};
}

ll cross(pll p1, pll p2){
    return p1.F * p2.S - p1.S * p2.F;
}

vector<pll> convexHull(vector<pll> pts){
    sort(pts.begin(), pts.end());
    vector<pll> hull;
    for(int i = 0; i < 2; ++i){
        int init = hull.size();
        for(pll& pt:pts){
            while(hull.size() - init >= 2 && cross(hull.back()-hull[hull.size()-2], pt-hull[hull.size()-2]) <= 0){
                hull.pop_back();
            }
            hull.push_back(pt);
        }
        hull.pop_back();

        reverse(pts.begin(), pts.end());
    }
    return hull;
}

int main(){
    AC
    int n;
    cin >> n;
    vector<pll> pts(n);
    for(int i = 0; i < n; ++i) cin >> pts[i].F >> pts[i].S;
    vector<pll> ans = convexHull(pts);
    cout << ans.size();
    return 0;
}
