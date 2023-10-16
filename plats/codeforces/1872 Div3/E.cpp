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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int a[N];
int pre[N];
string s;
void solve(){
    int n;cin>>n;
    int s1=0,s2=0;
    for(int i=1;i<=n;i++) {
        cin>>a[i];pre[i]=pre[i-1]^a[i];
    }
    cin>>s;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'){
            s1^=a[i+1];
        }
        else {
            s2^=a[i+1];
        }
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++){
        int op;cin>>op;
        if(op==1){
            int l,r;cin>>l>>r;
            s1^=pre[r]^pre[l-1];
            s2^=pre[r]^pre[l-1];
            
        }
        else if(op==2){
            int d;cin>>d;
            if(d==0){
                cout<<s1<<" \n"[i==q];
            }
            else {
                cout<<s2<<" \n"[i==q];
            }
        }
    }


}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;while(t--) solve();
    return 0;
}