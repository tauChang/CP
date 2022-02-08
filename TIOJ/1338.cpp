
/*
 tag: sparse table
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <numeric>
#include "lib1338.h"
#define AC ios::sync_with_stdio(0),cin.tie(0);
#define MAXN 1000007
#define MAXJ 21
using namespace std;
typedef long long ll;
ll st1[MAXN][MAXJ], st2[MAXN][MAXJ];

void init(int N, ll* C){
    for(int i = 0; i < N; ++i) {
        st1[i][0] = st2[i][0] = C[i];
    }
    
    for(int j = 1; j < MAXJ; ++j){
        for(int i = 0; i+(1<<j)-1 < N; ++i){
            st1[i][j] = min(st1[i][j-1], st1[i+(1<<(j-1))][j-1]);
            st2[i][j] = gcd(st2[i][j-1], st2[i+(1<<(j-1))][j-1]);
        }
    }
}

int query(int L, int R){
    int j = 31-__builtin_clz(R-L); // fast way to compute floor(log2(x))
    return gcd(st2[L][j], st2[R-(1<<j)][j]) == min(st1[L][j], st1[R-(1<<j)][j]);
}