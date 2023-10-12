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
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N],b[N];
int q[N];
int cnt[N];
void solve(){
    memset(cnt,0,sizeof(cnt));
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for(int i=1;i<=k;i++) {
        cin>>a[i];a[i]--;
    }
    for(int i=1;i<=k;i++) {
        cin>>b[i];b[i]--;
    }
    int qs;cin>>qs;
    for(int i=1;i<=qs;i++){
        cin>>q[i];
        cnt[q[i]-1]++;//每个位置-1
    }
    string ans = "";
    for(int i=1;i<=k;i++){
        string subs = s.substr(a[i],b[i]-a[i]+1);
        int sum = 0;
        int l = a[i];
        int r = b[i];
        for(int j=l;j<=(r+l)/2;j++){
            sum+=cnt[j]+cnt[r+l-j];
            if(sum&1) swap(subs[j-l],subs[r-j]);
        }
        ans+=subs;
    }
    cout<<ans<<endl;


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}
