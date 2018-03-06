//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 105;

int n, m;
char maze[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, char c){
	maze[x][y] = '.';
	for(int i=0; i<4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<n && nx>=0 && ny<m && ny>=0 && maze[nx][ny] == c){
			dfs(nx, ny, c);
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &m) == 2 && n && m){
		for(int i=0; i<n; i++){
			scanf("%s", maze[i]);
		}
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(maze[i][j] != '.'){
					ans++;
					dfs(i, j, maze[i][j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
