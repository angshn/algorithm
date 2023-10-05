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
const int N = 3e4 + 5;
const int INF = 0x3f3f3f3f;
int t;
int d[N];
int s[N];
int l[N];
void Init(){
    for(int i=0;i<N;i++) s[i]=i,d[i]=0,l[i]=i;
    //队尾开始时是自己
}

int Find(int x){
    if(x!=s[x]){
        int t=s[x];
        s[x] = Find(s[x]);
        d[x]+=d[t];
    }
    return s[x];
}
void Merge(int x,int y){
    int rx = Find(x),ry = Find(y);
    if(rx!=ry){
        s[rx]=ry;//x的队列指向y的对头
        Find(l[ry]);
        d[rx]=d[l[ry]]+1;//x的队头到ry的距离为ry的队尾到ry的距离+1
        l[ry] = l[rx];//ry的队尾更新为rx的队尾
    }

}

void solve(){
    cin>>t;
    Init();
    char op;int x, y;
    while(t--){
        cin>>op>>x>>y;
        if(op=='M'){
            Merge(x,y);
        }
        else {
            if(x==y){
                cout<<"0\n";
            }
            else if(Find(x)==Find(y)){
                cout<<abs(d[x]-d[y])-1<<"\n";
            }
            else {
                cout<<"-1\n";
            }
        }
    }
}
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
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