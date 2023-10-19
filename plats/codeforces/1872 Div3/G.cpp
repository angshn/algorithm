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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n;ll a[N];
void solve(){
    cin>>n;
    //统计前缀和
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    int l=1,r=n;
    while (l + 1 <= n && a[l] == 1)
        l++;
    while (r - 1 >= 1 && a[r] == 1)
        r--;

    ll acc = 1;
    for(int i=l;i<=r;i++){
        if (1.0 * acc * a[i] > 2e14){

            cout<<l<<" "<<r<<"\n";
            return;
        }
        acc*=a[i];
    }


    vector <ll> sum(n + 1, 0); // 累加
	vector <ll> prod(n + 1, 0); // 累乘
    prod[0] = 1;
    vector<ll> noone;
    noone.push_back(0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        prod[i]=prod[i-1]*a[i];

        if(a[i]>1){
            noone.push_back(i);
        }
    }
    ll maxv = -1;
    int ansl=1,ansr=1;
    for (int i = 1; i < noone.size(); i++)
    {
        for (int j = i; j < noone.size(); j++)
        {
            int pi = noone[i], pj = noone[j];
            ll newval = prod[pj] / prod[pi - 1] + sum[n] - sum[pj] + sum[pi - 1];
            if (maxv < newval)
            {
                maxv = newval;
                ansl = pi;
                ansr = pj;
            }
        }
    }
    cout<<ansl<<" "<<ansr<<"\n";
    

}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}