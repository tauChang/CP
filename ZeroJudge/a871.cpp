/*
 tag: convex hull, geometry
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define F first
#define S second
using namespace std;
typedef pair<double, double> pd;

pd operator-(pd p1, pd p2){
    return {p1.F-p2.F, p1.S-p2.S};
}

double cross(pd p1, pd p2){
    return p1.F*p2.S - p1.S*p2.F;
}

double dist(pd p1, pd p2){
    return sqrt(pow(p1.F-p2.F, 2)+pow(p1.S-p2.S, 2));
}

double triArea(pd p1, pd p2, pd p3){
    double a = dist(p1, p2), b = dist(p2, p3), c = dist(p3, p1);
    return sqrt((a+b+c)/2 * (b+c-a)/2 * (a+c-b)/2 * (a+b-c)/2);
}

double solve(vector<pd>& pts){
    sort(pts.begin(), pts.end());
    vector<pd> hull;
    for(int i = 0; i < 2; i++){
        int t = hull.size();
        for(auto& pt:pts){
            while(hull.size() - t >= 2 && cross(hull.back()-hull[hull.size()-2], pt-hull[hull.size()-2]) <= 0){
                hull.pop_back();
            }
            hull.push_back(pt);
        }
        hull.pop_back();

        reverse(pts.begin(), pts.end());
    }

    double ans = 0.0;
    for(int i = 1; i+1 < hull.size(); ++i){
        ans += triArea(hull[0], hull[i], hull[i+1]);
    }
    return ans;
}

int main(){
    AC
    int n;
    while(cin >> n){
        vector<pd> pts(n);
        for(int i = 0; i < n; ++i) cin >> pts[i].F >> pts[i].S;
        cout << fixed << showpoint << setprecision(2) << solve(pts) << endl;
    }
}