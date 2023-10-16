#include <cstdio>
#include <algorithm>
#include <cstring>
#define ll long long int
#define GETA(buf,size) for(int i=0;i<size;i++) cin>>buf[i];
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
inline int read(){int x=0,f=1;char ch=getchar();while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}return x*f;}

using namespace std;
const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
int n,a[25],dir[30][30];
int topo[25],vis[30],indegree[30];
void dfs(int z,int cnt){
    int i;
    topo[cnt]=z;
    if(cnt==n-1){
        for(int i=0;i<n;i++){
            printf("%c",topo[i]+'a');
           
        }
         printf("\n");
            return ;
        
    }
    vis[z]=1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[a[i]] && dir[z][a[i]])
            indegree[a[i]]--;
    }
    for(int i=0;i<n;i++){
        if(!indegree[a[i]] && !vis[a[i]]){
            dfs(a[i],cnt+1);
        }
    }

    for(int i=0;i<n;i++){
        if(!vis[a[i]]&&dir[z][a[i]]){
            indegree[a[i]]++;
        }
    }
    vis[z]=0;
}
void solve()
{
    char s[100];
    int len;
    while (gets(s) != NULL)
    {
        memset(dir, 0, sizeof(dir));
        memset(vis, 0, sizeof(vis));
        memset(indegree, 0, sizeof(indegree));
        len = strlen(s);
        n = 0;
        for (int i = 0; i < len; i++)
            if (s[i] <= 'z' && s[i] >= 'a')
            {
                a[n++] = s[i] - 'a';
            }
        sort(a, a + n);
        gets(s);
        len = strlen(s);
        int first = 1;
        for (int i = 0; i < len; i++)
        {
            int st, ed;
            if (first && s[i] <= 'z' && s[i] >= 'a')
            {
                first = 0;
                st = s[i] - 'a';
                continue;
            }
            if (!first && s[i] <= 'z' && s[i] >= 'a')
            {
                first = 1;
                ed = s[i] - 'a';
                dir[st][ed] = 1;
                indegree[ed]++;
                continue;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!indegree[a[i]])
            {
                dfs(a[i], 0);
            }
        }
        printf("\n");
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    solve();
    return 0;
}