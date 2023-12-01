#include <bits/stdc++.h>

using namespace std;
const int N = 1e3+5;
int Next[N];

void getNext(string p){
	Next[0]=Next[1] = 0;
	int plen = p.length();
	for(int i = 1;i<plen;i++){
		int j = Next[i];
		while(j&&p[i]!=p[j]){
			j = Next[j];
		}
		if(p[i]==p[j]){
			Next[i+1] = Next[i]+1;
		}
		else {
			Next[i+1] = 0;
		}
	}
}

int kmp(string s,string p){
	int slen = s.length(),plen = p.length();
	getNext(p);
	int j = 0;
	for(int i =0;i<slen;i++){
		while(j&&p[j]!=s[i]){
			j = Next[j];
		}
		if(s[i]==p[j]){
			j++;
		}
		if(j == plen){
			return i-plen+1;
		}
	}
	return -1;
}

int main(){
    string s = "qabcdabc";
    string p = "dab";
    cout<<kmp(s,p);


}