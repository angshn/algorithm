#include <bits/stdc++.h>
using namespace std;
int t;
#define ll long long
int cnt[4];
int main(){
	#ifndef ONLINE_JUDGE
	  freopen("/Users/syang/career/algorithm/in.txt","r",stdin);
	#endif
    cin>>t;
    while(t--){
        string passw;cin>>passw;
        ll ans = 0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<passw.length();i++){
            if(isdigit(passw[i])){
                cnt[0]++;
            }
            if(passw[i]<='z'&&passw[i]>='a'){
                cnt[1]++;
            }
            if(passw[i]<='Z'&&passw[i]>='A'){
                cnt[2]++;
            }
            if(passw[i]==','||passw[i]=='.'||passw[i]=='?'||passw[i]=='!'){
                cnt[3]++;
            }
        }
        for(int i=0;i<passw.length();i++){
            //数字多于1个时当前的数字位可以转换成其他任意字符315
            char cur = passw[i];
            if(isdigit(cur)){
                if(cnt[0]>1){
                    ans+=65;
                }
                else {
                    ans+=9;//只能换成其他数字了
                }
            }
            if(passw[i]<='z'&&passw[i]>='a'){
                if(cnt[1]>1){
                    ans+=65;
                }
                else {
                    ans+=25;
                }
            }
            if(passw[i]<='Z'&&passw[i]>='A'){
                if(cnt[2]>1){
                    ans+=65;
                }
                else {
                    ans+=25;
                }
            }
            if(passw[i]==','||passw[i]=='.'||passw[i]=='?'||passw[i]=='!'){
                if(cnt[3]>1){
                    ans+=65;
                }
                else {
                    ans+=3;
                }
            }
        }
        cout<<ans<<endl;
    }
}