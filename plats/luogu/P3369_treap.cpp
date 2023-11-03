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
const int M = 1e5 + 10;
const int INF = 0x3f3f3f3f;
int cnt = 0;

struct Node{
    int ls,rs;
    int key,pri;
    int size;
}t[M];

void newNode(int x){
    cnt++;
    t[cnt].size = 1;
    t[cnt].ls = t[cnt].rs = 0;
    t[cnt].key = x;
    t[cnt].pri = rand(); //优先级随机
}

//更新以u为根的子树的size
void Update(int u){
    t[u].size = t[t[u].ls].size + t[t[u].rs].size + 1;
}
//d=0右旋，d=1左旋
void rotate(int &o,int d){
    int k;
    if(d==1){
        k = t[o].rs;
        t[o].rs = t[k].ls;
        t[k].ls = o;
    }
    else {
        k = t[o].ls;
        t[o].ls = t[k].rs;
        t[k].rs = o;
    }
    t[k].size = t[o].size;
    Update(o);
    o = k; //新的根是k
}

void Insert(int &u,int x){
    if(u==0){
        newNode(x);u = cnt;return;//叶节点，新建节点，且新节点的下标是cnt
    }
    t[u].size++;//子树节点要+1
    if(x>=t[u].key) Insert(t[u].rs,x);
    else            Insert(t[u].ls,x);

    if(t[u].ls !=0 && t[u].pri > t[t[u].ls].pri) rotate(u,0);
    if(t[u].rs !=0 && t[u].pri > t[t[u].rs].pri) rotate(u,1);
    Update(u);
}

void Del(int &u,int x){

    t[u].size --;

    if(t[u].key == x){
        if(t[u].ls == 0 && t[u].rs == 0) { u=0;return; }
        if(t[u].ls == 0 || t[u].rs == 0){ u=t[u].ls + t[u].rs;return; }
        if(t[t[u].ls].pri < t[t[u].rs].pri){ rotate(u,0); Del(t[u].rs,x); return; }
        else { rotate(u,1); Del(t[u].ls,x); return; }
    }
    if(t[u].key >=x) Del(t[u].ls,x);
    else Del(t[u].rs,x);

    Update(u);
}
//求x的排名
int Rank(int u,int x){
    if(u==0) return 0;
    //左子树大小+当前节点和在右子树中的排名
    if(x>t[u].key) return t[t[u].ls].size + 1 +Rank(t[u].rs,x);
    return Rank(t[u].ls,x);
}

int kth(int u,int k){
    if(k==t[t[u].ls].size+1) return t[u].key;//刚好是当前节点
    //在右子树中，并且在右子树中的排名是减去左子树个数+当前节点1
    if(k>t[t[u].ls].size+1)  return kth(t[u].rs,k-t[t[u].ls].size - 1);
    //on the left of tree
    if(k<=t[t[u].ls].size) return kth(t[u].ls,k);
}

int Precursor(int u,int x){
    if(u == 0) return 0;
    //在左子树中
    if(t[u].key >=x) return Precursor(t[u].ls,x);
    //右子树中的前驱不是0的时候才是真正的前驱，如果是0表示找不到x的前驱，那么根节点就做前驱
    int tmp = Precursor(t[u].rs,x);
    if(tmp==0) return t[u].key;
    return tmp;
}

int Successor(int u,int x){
    if(u==0) return 0;
    if(t[u].key <= x) return Successor(t[u].rs,x);
    int tmp = Successor(t[u].ls,x);
    if(tmp == 0) return t[u].key;
    return tmp;
}

void solve(){
    srand(time(NULL));
    int q;cin>>q;
    int root = 0;
    while(q--){
        int opt,x;cin>>opt>>x;
        switch(opt){
            case 1: Insert(root,x); break;
            case 2: Del(root,x);break;
            case 3: cout<<Rank(root,x)+1<<'\n';break;
            case 4: cout<<kth(root,x)<<"\n";break;
            case 5: cout<<Precursor(root,x)<<"\n";break;
            case 6: cout<<Successor(root,x)<<'\n';break;
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