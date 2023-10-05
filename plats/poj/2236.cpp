    #include <iostream>
    #include <cstdio>
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
    int n;
    ll d;
    struct {
        int x,y, s;
    }a[N];

    int s[N];
    void Init(){for(int i=0;i<N;i++) s[i]=i;}
    int Find(int x){return x==s[x]?x:s[x]=Find(s[x]);}
    void Merge(int x,int y){int fx = Find(x),fy=Find(y);if(fx!=fy) s[fx] = fy;}
    bool check(int x,int y){
        ll dis= (a[x].x-a[y].x)*(a[x].x-a[y].x)+(a[x].y-a[y].y)*(a[x].y-a[y].y);
        return dis<=d*d;
    }
    void solve(){
        cin>>n>>d;
        char op;int p,q;
        for(int i=1;i<=n;i++){
            cin>>a[i].x>>a[i].y;
            a[i].s = 0;
        }
        Init();
        while(cin>>op){
            cin>>p;
            if(op=='O'){
                a[p].s = 1;
                for(int i=1;i<=n;i++){
                    if(p!=i&&a[i].s==1&&check(p,i)){
                        Merge(p,i);
                    }
                }

            }else {
                cin>>q;
                if (a[p].s&&a[q].s&&Find(p)==Find(q)){
                    cout<<"SUCCESS\n";
                }
                else {
                    cout<<"FAIL\n";
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