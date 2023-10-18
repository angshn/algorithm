#include<bits/stdc++.h>
using namespace std;
const int maxn = 20005;
int n, m;
int in[maxn], f[maxn], name1[maxn], name2[maxn];
vector<int> e[10005];
int x, y, t;
char ch[maxn];
bool uncertain = false;

int Find(int x){
    if(f[x] == x){return x;}
    else return f[x] = Find(f[x]);
}
int Union(int a, int b){
    int fa = Find(a);
    int fb = Find(b);
    if(fa!=fb){f[fa] = fb; return 1;}
    else return 0;
}

void topsort(){
    queue<int> s;
    uncertain = false;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(in[i] == 0 && f[i] == i){
            s.push(i);
        }
    }
    while(!s.empty()){
        if(s.size() > 1){uncertain = true;}
        int x = s.front();
        s.pop();
        cnt++;
        for(int i = 0; i < e[x].size(); i++){
            int y = e[x][i];
            in[y]--;
            if(in[y] == 0){
                s.push(y);
            }
        }
    }
    if(cnt < n-t)cout << "CONFLICT" << endl;    //conflict;
    else if(uncertain)cout << "UNCERTAIN" << endl; //uncertain
    else cout << "OK" << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("D:\\devel\\algorithm\\in.txt","r",stdin);
#endif
    while(cin >> n >> m){
        for(int i = 0; i <= n; i++) f[i] = i, e[i].clear(), in[i] = 0;
        t = 0;
        for(int i = 0; i < m; i++){
            cin >> name1[i] >> ch[i] >> name2[i];
            x = name1[i], y = name2[i];
            if(ch[i] == '='){
                if(Union(x, y)) t++;
            }
        }
        for(int i = 0; i < m; i++){
            x = Find(name1[i]);
            y = Find(name2[i]);
            if(ch[i] == '>'){
                e[x].push_back(y);
                in[y]++;
            }
            else if(ch[i] == '<'){
                e[y].push_back(x);
                in[x]++;
            }
        }
        topsort();
    }
}

