//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1005;
const int inf = 1e7;

int n, m;
char maze[maxn][maxn];
int mark[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct node{
	int x, y, t;
};

int bfs(int &x, int &y, int now){
	queue<node> q;
	q.push({x, y, 0});
	mark[x][y] = 1;
	while(!q.empty()){
		node u = q.front();
		q.pop();
		if(maze[u.x][u.y] == '0'+now){
			x = u.x; y = u.y;
			return u.t;
		}
		for(int i=0; i<4; i++){
			int nx = u.x+dx[i];
			int ny = u.y+dy[i];
			if(nx<n && nx>=0 && ny<m && ny>=0 && maze[nx][ny] != 'X' && !mark[nx][ny]){
				mark[nx][ny] = 1;
				q.push({nx, ny, u.t+1});
			}
		}
	}
	return inf;
}

int main(){
	int e;
	while(scanf("%d%d%d", &n, &m, &e) == 3 && n && m){
		int sx, sy;
		for(int i=0; i<n; i++){
			scanf("%s", &maze[i]);
			for(int j=0; j<m; j++){
				if(maze[i][j] == 'S'){
					sx = i, sy = j;
				}
			}
		}
		int ans = 0;
		for(int i=1; i<=e; i++){
			memset(mark, 0, sizeof(mark));
			ans += bfs(sx, sy, i);
		}
		printf("%d\n", ans);
	}
	return 0;
} 
