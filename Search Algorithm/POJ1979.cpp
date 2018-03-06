//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 105;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char maze[maxn][maxn];
int n, m;

int dfs(int x, int y){
	maze[x][y] = '#';
	int cnt = 0;
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<n && nx>=0 && ny<m && ny>=0 && maze[nx][ny] == '.'){
			cnt += dfs(nx, ny)+1;
		}
	}
	return cnt;
}

int main(){
	while(scanf("%d%d", &m, &n) == 2 && n && m){
		for(int i=0; i<n; i++){
			scanf("%s", maze[i]);
		}
		int ans = 1;
		int flag = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(maze[i][j] == '@'){
					ans += dfs(i, j);
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		printf("%d\n", ans);
	}
	return 0;
} 
