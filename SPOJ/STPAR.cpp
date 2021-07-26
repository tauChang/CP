#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define AC ios::sync_with_stdio(0),cin.tie(0);

int main(){
    AC
    while(1){
        int n;
        queue<int> q;
        stack<int> s;
        cin >> n;
        if(!n) break;
        for(int i = 0, x; i < n; ++i){
            cin >> x;
            q.push(x);
        }

        int i = 1, q1, s1;
        while(i <= n && (q.size() || s.size())){
            q1 = q.size() ? q.front() : -1;
            s1 = s.size() ? s.top() : -1;

            if(q1 == i){
                q.pop();
                ++i;
            } else if(s1 == i){
                s.pop();
                ++i;
            } else{
                if(q1 != -1){
                    q.pop();
                    s.push(q1);
                } else break;
            }
        }
        if(i == n+1) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}