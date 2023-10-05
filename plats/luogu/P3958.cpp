#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
inline int read();
using namespace std;
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
ll n,h,r;
struct Point{
    ll x,y,z;
}p[N];
int s[N];
ll dis(int i,int j){
    return (p[i].x - p[j].x) * (p[i].x - p[j].x) +
           (p[i].y - p[j].y) * (p[i].y - p[j].y) +
           (p[i].z - p[j].z) * (p[i].z - p[j].z);
}
bool is_connected(int i,int j){
    ll d = dis(i,j);

    return d<=4LL*r*r;
}
void Init(){
    for(int i=0;i<=n;i++) s[i] = i;
}

int Find(int x){
    return x==s[x]?x:s[x]=Find(s[x]);
}

void Merge(int x,int y){
    int rx=Find(x),ry=Find(y);
    if(rx!=ry){
        s[rx]=ry;
    };
}

void solve(){
    cin>>n>>h>>r;
    for(int i=1;i<=n;i++){
        cin >> p[i].x >> p[i].y>>p[i].z;
    }
    Init();
    //n^2的复杂度计算每两个洞之间的距离，

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i!=j){
                if(is_connected(i,j)){
                    Merge(i,j);
                }
            }
        }
    }

    //枚举每一个0以下的洞，查看他们的r-z是否小于等于0,如果存在一个i，他的r-z<=0且他的父亲的z+r>=h，那么就yes，
    //否则就是NO
    string ans = "No\n";
    bool finded = false;
    for(int i=1;i<=n;i++) Find(i);
    for(int i=1;i<=n;i++){
        if(p[i].z-r<=0){
            int fa = s[i];//查看从这个洞出发是否存在一个能上至顶端的球
            for(int j=1;j<=n;j++){
                if(s[j]==fa && p[j].z+r>=h){
                    ans = "Yes\n";
                    finded = 1;
                    break;
                }
            }
        }
        if(finded) break;
    }
    cout<<ans;

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
#endif
    FASTIO
    int t;cin>>t;
    while(t--) solve();
    return 0;
}