#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#define AC ios::sync_with_stdio(0),cin.tie(0);
using namespace std;

int mod(string y, int x){
    int ans = 0;
    for(int i = 0; i < y.size(); ++i) ans = (ans*10 + y[i]-'0') % x;
    return ans;
}

int main(){
    AC
    int t;
    cin >> t;
    while(t--){
        int x; 
        string y;
        cin >> x;
        queue<string> q; q.push("1");
        unordered_set<int> set;
        while(1){
            y = q.front(); q.pop();
            int m = mod(y, x);
            if(!m) break;
            else if(set.find(m) == set.end()){
                set.insert(m);
                q.push(y+"0");
                q.push(y+"1");
            }
        }
        cout << y << endl;
    }
    return 0;
}