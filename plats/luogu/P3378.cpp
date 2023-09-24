#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
int heap[N],len;

void push(int x){
    heap[++len]=x;
    int i=len;
    while(i>1 && heap[i]<heap[i/2]){
        swap(heap[i],heap[i/2]);
        i/=2;
    }
}

void pop(){
    heap[1]=heap[len--];
    int i=1;
    while((i<<1) <=len){
        int son = i<<1;
        if(son<len && heap[son+1]<heap[son])
            son++;
        if(heap[son]<heap[i]){
            swap(heap[son],heap[i]);
            i = son;
        }
        else break;
    }
}

void solve(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int op;cin>>op;
        if(op==1){
            int x;cin>>x;
            push(x);
        }
        else if(op==2){
            cout<<heap[1]<<"\n";
        }
        else if(op==3){
            pop();
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/syang/career/algo/in.in","r",stdin);
#endif
    FASTIO
    solve();
    return 0;
}
