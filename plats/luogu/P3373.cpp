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
ll MOD = 571373;
ll sum[N<<2];
ll tag[N<<2];
ll tag2[N<<2];
inline int ls(int p){return p<<1;}
inline int rs(int p){return p<<1|1;}

void pushup(ll p,ll pl,ll pr){
    sum[p]=(sum[ls(p)]+sum[rs(p)])%MOD;
}

void addtag(ll p,ll pl,ll pr,ll d,int c){
    if(c==1){
        sum[p]= (sum[p]+(pr-pl+1)*d)%MOD;
        tag[p]=(tag[p]+d)%MOD;
    }
    else if(c==2){
        tag2[p] = tag2[p] * d % MOD;
        sum[p] = (sum[p] * d) % MOD;
        tag[p] = tag[p] * d % MOD;
    }
}

void pushdown(ll p,ll pl,ll pr){
    //下方子区间
    int mid=(pl+pr)>>1;
    sum[ls(p)] = (sum[ls(p)]*tag2[p]+tag[p]*(mid-pl+1))%MOD;
    sum[rs(p)] = (sum[rs(p)]*tag2[p]+tag[p]*(pr-mid))%MOD;
    tag2[ls(p)] = tag2[ls(p)]*tag2[p]%MOD;
    tag2[rs(p)] = tag2[rs(p)]*tag2[p]%MOD;

    tag[ls(p)] =( tag[ls(p)]*tag2[p]+tag[p])%MOD;
    tag[rs(p)] =( tag[rs(p)]*tag2[p]+tag[p])%MOD;
    tag[p]=0;
    tag2[p]=1;

}


void build(ll p,ll pl,ll pr){
    tag[p]==0;tag2[p]=1;
    if(pl==pr){
        cin>>sum[p];
        sum[p]=sum[p]%MOD;
        return ;
    }
    ll mid = (pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    pushup(p,pl,pr);
}

void update(ll L,ll R,ll p,ll pl,ll pr,ll d,ll c){
    if(L<=pl and pr<=R){
        if(c==1){//+
            tag[p]=(tag[p]+d)%MOD;
            sum[p]=(sum[p]+(pr-pl+1)*d)%MOD;
        }
        else {
            tag[p]=(tag[p]*d)%MOD;
            tag2[p]=tag2[p]*d%MOD;
            sum[p]=sum[p]*d%MOD;
        }
        return;
    }
    pushdown(p,pl,pr);
    ll mid = (pr+pl)>>1;
    if(L<=mid) update(L,R,ls(p),pl,mid,d,c);
    if(R>mid)  update(L,R,rs(p),mid+1,pr,d,c);
    pushup(p,pl,pr);
}


ll query(ll L,ll R,ll p,ll pl,ll pr){
    if(L<=pl and pr <= R){
        return sum[p]%MOD;
    }
    pushdown(p,pl,pr);
    ll mid=pl+pr>>1;
    ll res=0;
    if(L<=mid) res = (res+query(L,R,ls(p),pl,mid))%MOD; 
    if(R>mid)  res = (res+query(L,R,rs(p),mid+1,pr)) %MOD;
    return res%MOD;
}

void solve(){
    int n,m;cin>>n>>m>>MOD;
    build(1,1,n);
    while(m--){
        int op;cin>>op;
        ll x,y,k;
        if(op==1){
           cin>>x>>y>>k;
           update(x,y,1,1,n,k,2);
        }
        else if(op==2){
           cin>>x>>y>>k;
           update(x,y,1,1,n,k,1);

        }
        else{
            cin>>x>>y;
            cout<<query(x,y,1,1,n)%MOD<<"\n";

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