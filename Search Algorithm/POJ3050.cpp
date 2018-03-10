//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

const int maxn = 15;
const int inf = 1e7;

int a[maxn][maxn];
int cs[maxn];
map<int, int> mp;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int id, int x, int y){
	if(id>=6){
		int num = 0;
		for(int i=0; i<6; i++){
			num *= 10;
			num += cs[i];
		}
		mp[num] = 1;
	}
	else{
		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx<5 && nx>=0 && ny>=0 && ny<5){
				cs[id] = a[nx][ny];
				dfs(id+1, nx, ny);
			}
		}
	}
}

int main(){
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			cs[0] = a[i][j];
			dfs(1, i, j);
		}
	}
	int ans = mp.size();
	printf("%d\n", ans);
	return 0;
}

