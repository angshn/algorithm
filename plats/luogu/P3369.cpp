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
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const double alpha = .75;

struct Node{
    int ls,rs;
    int val;
    int tot;
    int size;
    int del;
}t[N];

int order[N],cnt;
int tree_stack[N],top=0;
int root = 0;
//中序遍历拍平
void inorder(int u){
    if(!u) return;
    inorder(t[u].ls);
    if(t[u].del) order[++cnt] = u;
    else tree_stack[++top] = u;
    inorder(t[u].rs);
}

void Initnode(int u){
    t[u].ls = t[u].rs = 0;
    t[u].size = t[u].tot = t[u].del = 1;
}

void Update(int u){
    t[u].size = t[t[u].ls].size + t[t[u].rs].size + 1;
    t[u].tot = t[t[u].ls].tot + t[t[u].rs].tot + 1;
}

void build(int l,int r,int &u){
    int mid = (l+r)>>1;
    u = order[mid];
    if(l==r){
        Initnode(u);return;
    }
    if(l<mid) build(l,mid-1,t[u].ls);
    if(l==mid) t[u].ls = 0;
    build(mid+1, r, t[u].rs);
    Update(u);
}

void rebuild(int &u){
    cnt = 0;
    inorder(u);
    if(cnt) build(1,cnt,u);
    else u = 0;
}

bool notbalance(int u){
    bool not_balanced = (double)t[u].size *alpha <= (double)max(t[t[u].ls].size,t[t[u].rs].size);
    return not_balanced;
}

void Insert(int &u,int x){
    if(!u){
        u = tree_stack[top--];
        t[u].val = x;
        Initnode(u);
        return ;
    }
    t[u].size++;
    t[u].tot++;
    if(t[u].val>=x) Insert(t[u].ls,x);
    else Insert(t[u].rs,x);

    if(notbalance(u)) rebuild(u);
}

int Rank(int u,int x){
    if(u==0) return 0;
    if(x>t[u].val) return t[t[u].ls].size + t[u].del + Rank(t[u].rs,x);
    return Rank(t[u].ls,x);
}

int kth(int k){
    int u = root;
    while(u){
        if(t[u].del && t[t[u].ls].size + 1 == k) return t[u].val;
        else if(t[t[u].ls].size >= k) u = t[u].ls;
        else {
            k-= t[t[u].ls].size + t[u].del;
            u = t[u].rs;
        }
    }
    return t[u].val;
}

void Del_k(int &u,int k){
    t[u].size--;
    if(t[u].del && t[t[u].ls].size + 1 == k){
        t[u].del = 0;
        return ;
    }
    if(t[t[u].ls].size + t[u].del >= k) Del_k(t[u].ls,k);
    else Del_k(t[u].rs,k-t[t[u].ls].size - t[u].del);
}

void Del(int x){
    Del_k(root,Rank(root,x)+1);
    if(t[root].tot * alpha >= t[root].size){
        rebuild(root);
    }
}

void solve(){
    for(int i=N-1;i>=1;i--) tree_stack[++top] = i;
    int q;cin>>q;
    while(q--){
        int opt,x;cin>>opt>>x;
        switch(opt){
            case 1: Insert(root,x); break;
            case 2: Del(x);break;
            case 3: cout<<Rank(root,x)+1<<'\n';break;
            case 4: cout<<kth(x)<<"\n";break;
            case 5: cout<<kth(Rank(root,x))<<"\n";break;
            case 6: cout<<kth(Rank(root,x+1)+1)<<'\n';break;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}