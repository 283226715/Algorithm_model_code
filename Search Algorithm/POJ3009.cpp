//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 105;

int n, m;
int maze[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void dfs(int x, int y, int step){
	if(step>10 || step>=ans){
		return;
	}
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<n && nx>=0 && ny<m && ny>=0 && maze[nx][ny]!=1){
			while(nx<n && nx>=0 && ny<m && ny>=0){
				if(maze[nx][ny] == 1){
					maze[nx][ny] = 0;
					dfs(nx-dx[i], ny-dy[i], step+1);
					maze[nx][ny] = 1;
					break;
				}
				if(maze[nx][ny] == 3){
					ans = min(step, ans);
					return;
				}
				nx += dx[i];
				ny += dy[i]; 
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &m, &n) == 2 && n && m){
		int sx, sy;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d", &maze[i][j]);
				if(maze[i][j] == 2){
					sx = i, sy = j;
				}
			}
		}
		ans = 15;
		dfs(sx, sy, 1);
		printf("%d\n", ans == 15?-1:ans);
	}
	return 0;
} 
