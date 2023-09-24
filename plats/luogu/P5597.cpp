#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 3e3 + 5;
const int INF = 0x3f3f3f3f;
int pos1,pos2;
struct Node{
    int val;
    int size;
    int l,r;
}tree[N],mtree[N];//旧树和新树

int ans = INF;
int size1=0;
int size2=0;
int build(){
    int op = getchar()-'0';
    int u = ++size1;
    if(op&1){
        tree[u].l = build();
    }
    if(op&2){
        tree[u].r = build();
    }
    return u;
}

//从当前节点出发归并树
//递归并树
void merge(int rt, int fn){
    // 当前节点到达了枚举的终点，
    if(rt == pos1 || fn == pos2){
        pos2 = fn;
        fn = 1;//从根节点重新开始merge
    }
    if(tree[rt].l){
        if(!mtree[fn].l){
            mtree[fn].l=++size2;
        }
        merge(tree[rt].l, mtree[fn].l);
    }
    if(tree[rt].r){
        if(!mtree[fn].r){
            mtree[fn].r=++size2;
        }
        merge(tree[rt].r, mtree[fn].r);
    }
}
void dfs1(int rt,int dep){
    pos1 = rt;
    memset(mtree,0,sizeof(mtree)); // 清空新树
    pos2=0;
    merge(1,size2 = 1);
    ans = min(ans, 2*(size2-1) - dep);
    // 枚举终点
    if(tree[rt].l) dfs1(tree[rt].l,dep+1);
    if(tree[rt].r) dfs1(tree[rt].r,dep+1);
}
void solve(){
    int rt = build();
    dfs1(rt,0);
    cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}