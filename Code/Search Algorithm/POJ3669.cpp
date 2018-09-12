//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 305;
const int inf = 1e7;

int mark[maxn][maxn];
int final[maxn][maxn];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int m;

struct node{
	int x, y, t;
	bool operator <(const node &rhs) const{
		return t<rhs.t; 
	} 
};
node boom[50005];
int cnt;

void addBoom(int now){
	while(cnt<m && boom[cnt].t<=now){
		mark[boom[cnt].x][boom[cnt].y] = 1;
		for(int i=0; i<4; i++){
			int nx = boom[cnt].x+dx[i];
			int ny = boom[cnt].y+dy[i];
			if(nx>=0 && ny>=0){
				mark[nx][ny] = 1;
			}
		}
		cnt++;
	}
}

int bfs(int x, int y){
	queue<node> q;
	q.push({0, 0, 0});
	cnt = 0;
	mark[0][0] = 1;
	while(!q.empty()){
		node u = q.front();
		q.pop();
		addBoom(u.t+1);
		if(final[u.x][u.y] == 0){
			return u.t;
		} 
		for(int i=0; i<4; i++){
			int nx = u.x+dx[i];
			int ny = u.y+dy[i];
			if(nx>=0 && ny>=0 && !mark[nx][ny]){
				mark[nx][ny] = 1;
				q.push({nx, ny, u.t+1});
			}
		}
	}
	return -1;
}

int main(){
	while(scanf("%d", &m) == 1){
		for(int i=0; i<m; i++){
			scanf("%d%d%d", &boom[i].x, &boom[i].y, &boom[i].t);
			final[boom[i].x][boom[i].y] = 1;
			for(int j=0; j<4; j++){
				int nx = boom[i].x+dx[j];
				int ny = boom[i].y+dy[j];
				if(nx>=0 && ny>=0){
					final[nx][ny] = 1;
				}
			}
		}
		sort(boom, boom+m);
		int ans = bfs(0, 0);
		printf("%d\n", ans);
	}
	return 0;
} 
