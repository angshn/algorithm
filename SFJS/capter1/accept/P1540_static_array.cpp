#include <bits/stdc++.h>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int buffer[N];

struct mque{
    int data[N];
    int head, rear;
    bool init(){
        head = rear = 0;
        return true;
    }
    int size(){
        return (rear - head + N) % N;
    }
    bool empty(){
        return size()==0;
    }

    bool push(int x){
        if((rear + 1)%N == head)return false;
        data[rear] = x;
        rear = (rear + 1)%N;
        return true;
    }
    bool pop(int &e){
        if(head == rear)return false;
        e = data[head];
        head = (head + 1) % N;
        return true;
    }
    int front(){
        return data[head];
    }
};
void solve(){
    memset(buffer,0,sizeof(buffer));
    int n, m;cin >> m >> n;
    mque q;q.init();
    int cnt = 0;
    for(int i=0;i<n;i++){
        int k;cin>>k;

        bool exsit = buffer[k] > 0;
        if (!exsit)
        {
            cnt++;
            if (q.size() == m)
            {
                int p ;q.pop(p);
                buffer[p]--;
            }
            buffer[k]++;
            q.push(k);
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\workspace\\algorithm\\in.in","r",stdin);
#endif
#ifdef MULTI_CASE
    int t;cin>>t;
    while(t--) 
#endif
    solve();
    return 0;
}