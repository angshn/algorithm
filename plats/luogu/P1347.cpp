#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}
#define FASTIO                \
    ios ::sync_with_stdio(0); \
    cin.tie(0);               \
    cout.tie(0);
using namespace std;
const int N = 30 + 5;
const int INF = 0x3f3f3f3f;
int n,m;
char line[5];
int w[N][N];
int ind[N];
int indt[N];
int ans[N];
int cnt;
int check(){

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indt[i]){
            indt[i]--;
            q.push(i);
        }
    }
    cnt = 0;
    int f = 0;
    while(!q.empty()){
        //同一时刻有多于一个状态就表示无法确定了
        if(q.size()>1) f = -1;
        int u = q.front();q.pop();
        ans[cnt++] = u;
        for(int i=1;i<=n;i++){
            if(w[u][i]) indt[i]--;
            if(!indt[i]){
                q.push(i);
                indt[i]--;//刚好变为-1
            }
        }

    }
    for(int i=1;i<=n;i++){//有环
        if(indt[i]!=-1) return -1;
    }
    if(f==-1) return 0;
    return 1;
    //无法确定
}

void solve(){
    scanf("%d %d",&n,&m);
    memset(ind,0,sizeof(ind));
    memset(w,0,sizeof(w));
    int flag =0;
    int i=0;
    for(i=1;i<=m;i++){
        scanf("%s",line);
        int a = line[0]-'A'+1, b = line[2]-'A'+1;
        if(!w[b][a])
            ind[a]++;
        w[b][a]=1;
        memcpy(indt,ind,sizeof(ind));
        int t = check();
        if(t == 1){
            printf("Sorted sequence determined after %d relations: ",i);
            for(int i=cnt-1;i>=0;i--){
                printf("%c",ans[i]+'A'-1);
            }
            printf(".\n");
            flag = 1;
            i++;
            break;
        }
        if(t==-1){
            printf("Inconsistency found after %d relations.\n",i);
            flag =1;
            i++;
            break;

        }
    }

    if(!flag) printf("Sorted sequence cannot be determined.\n");

    
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    solve();
    return 0;
}