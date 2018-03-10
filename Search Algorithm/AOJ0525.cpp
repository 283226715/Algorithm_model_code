//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
using namespace std;

const int maxn = 10005;
const int inf = 1e7;

int n, m;
int ans;

bitset<maxn> bs[15];

void dfs(int r){
	if(r>=n){
		int sum = 0;
		for(int j=0; j<m; j++){
			int tmp = 0;
			for(int i=0; i<n; i++){
				if(bs[i][j]){
					tmp++;
				}
			}
			sum += max(tmp, n-tmp);
		}
		ans = max(ans, sum);
		return;
	}
	dfs(r+1);
	bs[r].flip();
	dfs(r+1);
	bs[r].flip();
}

int main(){
	while(scanf("%d%d", &n, &m) == 2 && n && m){
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int num;
				scanf("%d", &num);
				bs[i][j] = num;
			}
		}
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
} 
