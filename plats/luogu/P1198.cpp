#include <bits/stdc++.h>
using namespace std;
#define FASTIO ios ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

#define ll long long int
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}
ll tree[N<<2];
ll mod;
ll m;
void pushup(int p){
    tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
ll pre;
void build(int p,int pl,int pr){
    if(pl==pr){
        tree[p]=0;
        return ;
    }
    int mid=(pr+pl)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
}

void update(int L,int R,int p,int pl,int pr,ll d){
    if(L<=pl and pr <= R){
        tree[p]=(d+pre)%mod;
        return ;
    }
    int mid = (pl+pr)>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);
    pushup(p);
}

int query(int L,int R,int p,int pl,int pr){
    if(L<=pl and pr <= R){
        return tree[p];
    }
    int mid = (pr+pl)>>1;
    int res = -INF;
    if(L<=mid) res = max(res,query(L,R,ls(p),pl,mid));
    if(R>mid)  res = max(res,query(L,R,rs(p),mid+1,pr));
    return res;
}

void solve(){
    cin>>m>>mod;
    pre=0;
    int cnt = 0;
    ll right = 2e5;
    build(1,1,right);
    for(int i=1;i<=m;i++){
        string op;int n;cin>>op>>n;
        if(op=="A"){
            update(right-cnt,right-cnt,1,1,right,n);
            cnt++;
        }
        else {
            int ans = query(right-cnt,right-cnt+n,1,1,right);
            cout<<ans<<"\n";
            pre=ans;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO;solve();return 0;
}