#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
int tree[N],rnk[N];
struct Point{
    int num,val;
}a[N];
#define lowbit(x) (x&-x)
bool cmp(Point x,Point y){
    if(x.val==y.val) return x.num<y.num;
    return x.val<y.val;
}
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
ll sum(int x){
    ll ans = 0;
    while(x){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}


void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) { cin>>a[i].val;a[i].num = i; }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        rnk[a[i].num] = i;
    }
    ll ans = 0;
    for(int i=n;i;i--){
        update(rnk[i],1);
        ans+=sum(rnk[i]-1);
    }
    cout<<ans<<endl;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}