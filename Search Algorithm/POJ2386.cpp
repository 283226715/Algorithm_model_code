//#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;

const int maxn = 105;

char maze[maxn][maxn];
int n, m;

void dfs(int x, int y){
	maze[x][y] = '.';
	for(int i=-1; i<=1; i++){
		for(int j=-1; j<=1; j++){
			int nx = x+i;
			int ny = y+j;
			if(nx<n && nx>=0 && ny<m && ny>=0 && maze[nx][ny] == 'W'){
				dfs(nx, ny);
			}
		}
	}
}

int main(){
	while(scanf("%d%d", &n, &m) == 2){
		for(int i=0; i<n; i++){
			scanf("%s", maze[i]);
		}
		int ans = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(maze[i][j] == 'W'){
					ans++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
