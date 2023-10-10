#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
inline int lowbit(int x){
    return x&-x;
}
const int N = 1e5 + 5;
const int MOD = 1e8-3;
const int INF = 0x3f3f3f3f;
int n;
int rnk[N];
struct Node{
    int val,num;
}a[N],b[N];
int c[N];
bool cmp(Node x,Node y){
    return x.val < y.val;
}
int tree[N];
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}

int query(int x){
    int ans = 0;
    while(x){
        ans=(ans+tree[x])%MOD;
        x-=lowbit(x);
    }
    return ans;
}
void solve(){
    n = read();
    for(int i=1;i<=n;i++) {
        a[i].val = read();
        a[i].num = i;
    }
    for(int i=1;i<=n;i++) {
        b[i].val = read();
        b[i].num = i;
    }
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+n,cmp);

    for(int i=1;i<=n;i++){
        c[a[i].num] = b[i].num;
    }    

    int ans = 0;
    for(int i=n;i;i--){
        update(c[i],1);
        ans = (ans+query(c[i]-1)) % MOD;
    }
    printf("%d\n",ans);
  
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}