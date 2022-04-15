/*
 tag: segment tree, greedy, medium
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
#include <deque>
using namespace std;
#define MAXN 1000005
int n, k;
int arr[MAXN];

void solve(bool ismin){
    deque<int> dq;
    for(int i = 0; i < n; ++i){
        if(!dq.empty() && dq.front() < (i-k+1)) dq.pop_front();
        while(!dq.empty() && (ismin ? arr[dq.back()] > arr[i] : arr[dq.back()] < arr[i])) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1) {
            printf("%d", arr[dq.front()]);
            if(i != n-1) printf(" ");
        }
    }
    printf("\n");
}

int main(){
    while(scanf("%d %d", &n, &k) != EOF){
        k = min(n, k);
        for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
        solve(1);
        solve(0);
    }
}
