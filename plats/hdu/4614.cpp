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
const int N = 5e4+ 5;

const int INF = 0x3f3f3f3f;
int n,m;
int tree[N<<2];
int tag[N<<2];
int ls(int p){ return p<<1; } 
int rs(int p){ return p<<1|1; }

void push_up(int p){ tree[p] = tree[ls(p)]+tree[rs(p)]; }
void build(int p,int pl,int pr){
    tag[p]=-1;
    if(pl==pr){ tree[pl]=0; return; }
    int mid = pl+pr>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
}

void addtag(int p,int pl,int pr,int d){
    tag[p]=d;
    tree[p]=d*(pr-pl+1);
}
void push_down(int p,int pl,int pr){
    if(tag[p]!=-1){
        int mid = (pr+pl)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=-1;
    }
}

void update(int L,int R,int p,int pl,int pr,int d){
    if(L<=pl && pr <=R ){
        addtag(p,pl,pr,d);
        return ;
    }
    int mid = (pr+pl)>>1;
    if(tag[p]!=-1) push_down(p,pl,pr);
    if(L<=mid) update(L,R,ls(p),pl,mid,d);
    if(R>mid) update(L,R,rs(p),mid+1,pr,d);
    push_up(p);
}


int query(int L,int R,int p,int pl,int pr){
    if(L<=pl && pr <=R ){
        return tree[p];
    }
    int mid = pr+pl>>1;
    int res = 0;
    if(tag[p]!=-1)  push_down(p,pl,pr);
    if(L<=mid) res+=query(L,R,ls(p),pl,mid);
    if(R>mid) res+=query(L,R,rs(p),mid+1,pr);
    return res;
}
int kzero(int l,int r,int cnt){
    int start = l;
    int ans = 0;
    while(l<=r){
        int mid = l+r>>1;
        int num = (mid - start + 1) - query(start, mid, 1, 0, n-1);
        if(num>=cnt){
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }
    return ans;
}
inline int Min(int x,int y){return x<y?x:y;}
void solve(){
    memset(tree,0,sizeof(tree));
    memset(tag,0,sizeof(tag));

    cin>>n>>m;
    build(1,0,n-1);
    while(m--){
        int op,a,f;cin>>op>>a>>f;

        if(op==1){
            int has = query(a,n-1,1,0,n-1);
            if(has==(n-1-a+1)){//没有可以放置的位置
                cout<<"Can not put any one.\n";
                continue;
            }
            int pos1 = kzero(a,n-1,1);
            int zero_num = n-1-a+1-has;
            int pos2 = kzero(pos1,n-1,Min(zero_num,f));
            cout<<pos1<<" "<<pos2<<"\n";
            update(pos1,pos2,1,0,n-1,1);
        }
        else if(op==2){
            cout<<query(a,f,1,0,n-1)<<"\n";
            update(a,f,1,0,n-1,0);
        }
    }
    cout<<"\n";
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