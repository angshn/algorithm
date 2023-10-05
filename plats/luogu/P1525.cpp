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
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
struct Node{
    int x,y,v;
    bool operator < (const Node& b)const {
        return v>b.v;
    }
}a[N];
int s[N];
int d[N];
void Init(){
    for(int i=0;i<=n;i++) s[i] = i;
}

int Find(int x){
    return x==s[x]?x:s[x]=Find(s[x]);
}

inline bool same(int x,int y){
    return Find(x)==Find(y);
}

void Merge(int x,int y){
    int fx=Find(x),fy=Find(y);
    if(fx!=fy){
        s[fx]=fy;
    }
}


void solve(){
    cin>>n>>m;
    //贪心方法，将仇恨值大的优先分配在不同的集合
    for(int i=1;i<=m;i++){
        cin>>a[i].x>>a[i].y>>a[i].v;
    }
    Init();
    sort(a+1,a+1+m);

    for(int i=1;i<=m;i++){
        int x=a[i].x,y=a[i].y;
        if (same(x,y)){
            cout<<a[i].v<<endl;
            return;
        }
        if(!d[x]) d[x] = y;
        else Merge(y,d[x]);

        if(!d[y]) d[y] = x;
        else Merge(x,d[y]);
    }
    cout<<0<<endl;
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