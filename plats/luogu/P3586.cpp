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
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
class FenwickTree{
    public:
        ll tree[N];
        int lowbit(int x){ return x&(-x); }
        void update(int x,int d){ while(x<=N){ tree[x] += d; x+=lowbit(x); } }
        ll query(int x){ ll ans = 0; while(x){ ans+=tree[x]; x-=lowbit(x); } return ans; }
};
FenwickTree t1,t2;
int ops[N],a[N],b[N],c[N];
int rnk[N];
int vis[N];
int nums[N];
void solve(){
    n=read(),m=read();
    char s[5];
    for(int i=1;i<=m;i++){
        scanf("%s",s);a[i]=read(),b[i]=read();
        c[i] = b[i];
        if(s[0]=='U')ops[i]=1;
        else ops[i]=0;
    }

    sort(c+1,c+1+m);
    int cnt = unique(c+1,c+1+m)-(c+1);
    for(int i=1;i<=cnt;i++){
        rnk[i]=c[i];
    }
    //每个值的新序号
    for(int i=1;i<=m;i++){
        nums[i] = lower_bound(rnk + 1, rnk + 1 + cnt, b[i]) - rnk;
    }
    for(int i=1;i<=m;i++){
        if(ops[i]==1){
            if(vis[a[i]]){
                int j = vis[a[i]];
                t1.update(j,-1);
                t2.update(j,-rnk[j]);
            }
            vis[a[i]] = nums[i];
            t1.update(nums[i],1);
            t2.update(nums[i],rnk[nums[i]]);
        }
        else {
            int r = rnk[nums[i]];//对应的值
            int rnks = nums[i];
            ll n1 = t1.query(rnks-1);//不大于s的值有多少个
            ll n2 = t1.query(cnt);
            ll n3 = n2-n1;
            ll sum = t2.query(nums[i]-1);

            if(sum>=(a[i]-n3)*rnk[nums[i]]){
                printf("TAK\n");
            }
            else {
                printf("NIE\n");
            }

        }
    }


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