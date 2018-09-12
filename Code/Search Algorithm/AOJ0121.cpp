//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 305;
const int inf = 1e7;
map<string, int> mp;
int dir[4] = {-4, 1, 4, -1};

void bfs(){
	queue<string> q;
	q.push("01234567");
	mp["01234567"] = 1;
	while(!q.empty()){
		string u = q.front();
		q.pop();
		int st = u.find('0');
		for(int i=0; i<4; i++){
			int ed = st+dir[i];
			if(ed<0 || ed>7 || st == 3 && ed == 4 || st == 4 && ed == 3){
				continue;
			}
			string v = u;
			swap(v[st], v[ed]);
			if(mp[v] == 0){
				q.push(v);
				mp[v] = mp[u]+1;
			}
		}
	}
}

int main(){
	bfs();
	int num;
	while(scanf("%d", &num) == 1){
		string final = "";
		final += '0'+num;
		for(int i=0; i<7; i++){
			scanf("%d", &num);
			final += '0'+num;
		}
		printf("%d\n", mp[final]-1); 
	}
	return 0;
}
