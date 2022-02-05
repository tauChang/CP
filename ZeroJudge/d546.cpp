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
    return p1.F*p2.S-p1.S*p2.F;
}

double shoelace(vector<pd> pts){
    int n = pts.size();
    double area = 0.0;
    for(int i = 0; i < n; ++i) {
        area += cross(pts[i], pts[(i+1)%n]);
    }
    return area/2;
}

double polygonArea(vector<pd> pts){
    vector<pd> hull;
    sort(pts.begin(), pts.end());
    for(int i = 0; i < 2; ++i){
        int t = hull.size();
        for(auto& pt:pts){
            while(hull.size()-t >= 2 && cross(hull.back()-hull[hull.size()-2], pt-hull[hull.size()-2]) <= 0){
                hull.pop_back();
            }
            hull.push_back(pt);
        }
        hull.pop_back();
        reverse(pts.begin(), pts.end());
    }

    double area = 0.0;
    for(int i = 1; i+1 < hull.size(); ++i){
        area += shoelace({hull[0], hull[i], hull[i+1]});
    }
    return area;
}

int main(){
    AC
    int n;
    double a;
    cin >> n >> a;
    vector<pd> pts(n);
    for(int i = 0; i < n; ++i){
        cin >> pts[i].F >> pts[i].S;
    }
    cout << (int)ceil((polygonArea(pts) - shoelace(pts))/a);
}


