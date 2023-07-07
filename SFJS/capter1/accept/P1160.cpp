#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf, size)            \
    for (int i = 0; i < size; i++) \
        cin >> buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int _hash[N];
struct node
{
    int id;
    int preid, nextid;

} nodes[N];
#define nxt(x) nodes[x].nextid;
#define pre(x) nodes[x].preid;
void solve()
{
    int n;
    cin >> n ;
    nodes[1].id = 1;
    nodes[1].preid = 0;
    nodes[1].nextid = 0;
    nodes[0].id = 0;
    nodes[0].preid = 1;
    nodes[0].nextid = 1;
    
    for (int i = 2; i <= n; i++)
    {
        int k, p;cin >> k >> p;
        if (p == 0)
        {
            nodes[i].id = i;
            nodes[i].nextid = k;
            nodes[nodes[k].preid].nextid = i;
            nodes[i].preid = nodes[k].preid;
            nodes[k].preid = i;
        }
        else {
            nodes[i].id = i;
            nodes[i].preid = k;
            nodes[i].nextid = nodes[k].nextid;
            nodes[nodes[k].nextid].preid = i;
            nodes[k].nextid = i;
        }
    }
    int m;cin>>m;
    for(int i=0;i<m;i++){   
        int k;cin>>k;
        if(nodes[k].id != -1){
            nodes[nodes[k].nextid].preid = nodes[k].preid;
            nodes[nodes[k].preid].nextid = nodes[k].nextid;
            nodes[k].id = -1;
        }
    }
    int head = nodes[0].nextid;
    while(nodes[head].id != 0){
        cout<<head<<" \n"[nodes[head].nextid==0];
        head = nodes[head].nextid;
    }
    cout<<"\n";

}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\workspace\\algorithm\\in.in","r",stdin); 
#endif
    FASTIO
    int t;
    // cin >> t;
    // while (t--)
    solve();
    return 0;
}