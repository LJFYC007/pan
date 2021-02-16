#include <bits/stdc++.h>
using namespace std;
inline void read(register int &x){
    x = 0; register int f = 1;
    register char ch = getchar();
    while (!(ch >= '0' && ch <= '9')){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
const int N = 5e6 + 10;
int len;
bool endpos[N];
string stot = "\\n";
char s[N];
struct SAM{
    int ch[N][27], pre[N], mxl[N], sz[N], last, cnt;
    SAM(){last = cnt = 1;}
    inline void Insert(register int c){
        register int p = last, np = ++cnt; last = np;
        mxl[np] = mxl[p] + 1; sz[np] = 1;
        for (; p && !ch[p][c]; p = pre[p]) ch[p][c] = np;
        if (!p) pre[np] = 1;
        else{
            register int q = ch[p][c];
            if (mxl[q] == mxl[p] + 1) pre[np] = q;
            else{
                register int nq = ++cnt; mxl[nq] = mxl[p] + 1;
                memcpy(ch[nq], ch[q], sizeof(ch[q]));
                pre[nq] = pre[q]; pre[q] = pre[np] = nq;
                for (; ch[p][c] == q; p = pre[p]) ch[p][c] = nq;
            }
        }
    }
    inline void Insert1(register int c){
        register int p = last, np = ++cnt; last = np;
        mxl[np] = mxl[p] + 1; sz[np] = 1;
        for (; p && !ch[p][c]; p = pre[p]) ch[p][c] = np;
        if (!p){ pre[np] = 1; return; }
        register int q = ch[p][c], nq = ++cnt;
        if (mxl[q] == mxl[p] + 1) { pre[np] = q; --cnt; return; }
        memcpy(ch[nq], ch[q], sizeof(ch[q]));
        mxl[nq] = mxl[p] + 1; pre[nq] = pre[q]; pre[q] = pre[np] = nq;
        for (; ch[p][c] == q; p = pre[p]) ch[p][c] = nq;
    }
    int t[N], c[N];
    inline void tsort(){
        for (register int i = 1; i <= cnt; i++) t[mxl[i]]++;
        for (register int i = 1; i <= cnt; i++) t[i] += t[i - 1];
        for (register int i = 1; i <= cnt; i++) c[t[mxl[i]]--] = i;
    }
    inline void Dfs(register int u){
        for (register int c = 0; c < 26; c++) if (ch[u][c]){
            printf("    %d->%d[label=%c];\n", u, ch[u][c], c + 'a');
            Dfs(ch[u][c]);
        }
    }
    inline void Print(){
        tsort();
        printf("digraph test{\n");
        printf("    node[shape=\"circle\"];\n");
        printf("    subgraph cluster_sub{\n");
        printf("      1");
        for (register int i = 1; i <= cnt; i++) if (sz[i]) printf(",%d", i);
        printf(";\n    }\n");
        printf("    rankdir=LR;\n");
        for (register int i = 1; i <= cnt; i++)
        for (register int c = 0; c < 27; c++) if (ch[i][c])
            printf("    %d->%d[color=blue,label=\"%c\";];\n", i, ch[i][c], c + 'a');
        for (register int i = 2; i <= cnt; i++)
            printf("    %d->%d[color=green,style=dashed];\n", i, pre[i]);
        printf("    1");
        for (register int i = 1; i <= cnt; i++) if (sz[i] && !endpos[i]) printf(",%d", i);
        printf("[color=red];\n");
        register bool f = false;
        printf("    ");
        for (register int i = 1; i <= cnt; i++) if (endpos[i]){
            if (!f) {printf("%d", i); f = true;}
            else printf(",%d", i);
        }
        printf("[style=\"filled\",fillcolor=\"chartreuse\"];\n");
        printf("    ");
        printf("\"Suffix Automaton: "); cout << stot;
        for (register int i = cnt; i >= 1; i--) printf("%d ", c[i]);
        printf("\"");
        printf("[shape=plaintext];\n");
        printf("}");
    }
}sam;
int main(){
    freopen("test.dot", "w", stdout);
    register int n;
    scanf("%d", &n);
    while (n--){
        scanf("%s", s + 1); len = strlen(s + 1); sam.last = 1;
        string ss = s + 1;
        stot += ss + "\\n";
        register int mem;
        for (register int i = 1; i <= len; i++){
            mem = sam.cnt + 1;
            sam.Insert1(s[i] - 'a');
        }
        endpos[mem] = true;
    }
    sam.Print();
    return 0;
}
