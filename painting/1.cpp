/***************************************************************
	File name: 1.cpp
	Author: ljfcnyali
	Create time: 2021年01月02日 星期六 11时10分15秒
***************************************************************/
#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) ) 
#define str(a) strlen ( a ) 
#define pii pair<int, int>
typedef long long LL;

const int maxn = 1e5 + 10;

struct node
{
    int a, b, c; 
    node ( int x = 0, int y = 0, int z = 0) { a = x; b = y; c = z; }
    bool operator < (const node&a) const { return c > a.c; }
} a[maxn];

int main()
{
    freopen("todo", "r", stdin);
    freopen("todo.list", "w", stdout);
    /*
    int x, y, z, n = 0;
    while ( ~scanf("%d%d%d, ", &x, &y, &z) ) a[++ n] = node(x, y, z);
    sort(a + 1, a + n + 1);
    REP(i, 1, n) printf("%d %d %d\n", a[i].a, a[i].b, a[i].c);
    */
    REP(i, 1, 50) REP(j, 1, 50) printf("%d %d 12\n", i, j);
    return 0;
}
