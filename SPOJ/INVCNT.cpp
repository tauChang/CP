#include <iostream>
#include <vector>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;
typedef long long ll;
 
ll merge(vector<int>& a, int i, int j){
    if(i == j) return 0;
    int m = (i+j)/2;
    ll ic = merge(a, i, m);
    ic += merge(a, m+1, j);
 
    int p = 0, p1 = i, p2 = m+1;
    vector<int> b(j-i+1);
    while(p1 <= m || p2 <= j){
        if(p1 > m) b[p++] = a[p2++];
        else if(p2 > j) b[p++] = a[p1++];
        else if(a[p1] <= a[p2]) b[p++] = a[p1++];
        else{
            ic += (m-p1+1);
            b[p++] = a[p2++];
        }
    }
    p = 0;
    while(i <= j) a[i++] = b[p++];
    
    return ic;
}
 
 
int main(){
    AC
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        cout << merge(a, 0, n-1) << endl;
    }
    return 0;
} 
