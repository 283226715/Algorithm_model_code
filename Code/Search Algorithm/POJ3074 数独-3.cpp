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

const int maxn2 = 105;
const int n = 9;
const int maxn = 15;

char s[maxn2];
int maze[maxn][maxn];

struct blank{
	int x, y, sum;
	int c[maxn];
}bks[maxn2];
int cnt;
int row[maxn][maxn], col[maxn][maxn], block[maxn][maxn]; 
int oprow[maxn][maxn], opcol[maxn][maxn], opblock[maxn][maxn];

void init(){
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(block, 0, sizeof(block));
	cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(s[i*n+j] == '.'){
				maze[i][j] = 0;
				bks[cnt].x = i;
				bks[cnt].y = j;
				cnt++;
			}
			else{
				maze[i][j] = s[i*n+j]-'0';
				row[i][maze[i][j]] = 1;
				col[j][maze[i][j]] = 1;
				block[i/3*3+j/3][maze[i][j]] = 1;
			}
		}
	}
}

void update(){
	memset(oprow, 0, sizeof(oprow));
	memset(opcol, 0, sizeof(opcol));
	memset(opblock, 0, sizeof(opblock));
	for(int i=0; i<cnt; i++){
		int x = bks[i].x;
		int y = bks[i].y;
		if(maze[x][y] == 0){
			bks[i].sum = 0;
			memset(bks[i].c, 0, sizeof(bks[i].c));
			for(int k=1; k<=n; k++){
				if(row[x][k] == 0 && col[y][k] == 0 && block[x/3*3+y/3][k] == 0){
					oprow[x][k]++;
					opcol[y][k]++;
					opblock[x/3*3+y/3][k]++;
					bks[i].c[k] = 1;
					bks[i].sum++;
				}
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int k=1; k<=n; k++){
			if(oprow[i][k] == 1){
				for(int j=0; j<cnt; j++){
					if(bks[j].x == i && maze[bks[j].x][bks[j].y] == 0 && bks[j].c[k] == 1){
						bks[j].sum = 1;
						memset(bks[j].c, 0, sizeof(bks[j].c));
						bks[j].c[k] = 1;
						break;
					}
				}
			}
			if(opcol[i][k] == 1){
				for(int j=0; j<cnt; j++){
					if(bks[j].y == i && maze[bks[j].x][bks[j].y] == 0 && bks[j].c[k] == 1){
						bks[j].sum = 1;
						memset(bks[j].c, 0, sizeof(bks[j].c));
						bks[j].c[k] = 1;
						break;
					}
				}
			}
			if(opblock[i][k] == 1){
				for(int j=0; j<cnt; j++){
					if(bks[j].x/3*3+bks[j].y/3 == i && maze[bks[j].x][bks[j].y] == 0 && bks[j].c[k] == 1){
						bks[j].sum = 1;
						memset(bks[j].c, 0, sizeof(bks[j].c));
						bks[j].c[k] = 1;
						break;
					}
				}
			}
		} 
	}
}

int getnow(){
	int mmax = maxn;
	int id = -1;
	for(int i=0; i<cnt; i++){
		int x = bks[i].x;
		int y = bks[i].y;
		if(maze[x][y] == 0 && bks[i].sum<mmax){
			mmax = bks[i].sum;
			id = i;
		}
	}
	return id;
}

int dfs(int id){
	if(id>=cnt)	return 1;	
	int now = getnow();
	if(now == -1) return 0;
	for(int k=1; k<=n; k++){
		if(bks[now].c[k]){
			int x = bks[now].x;
			int y = bks[now].y;
			
			maze[x][y] = k;
			row[x][k] = 1;
			col[y][k] = 1;
			block[x/3*3+y/3][k] = 1;
			update();
			
			if(dfs(id+1)) return 1;
			
			maze[x][y] = 0;
			row[x][k] = 0;
			col[y][k] = 0;
			block[x/3*3+y/3][k] = 0;
			update();
		}
	} 
	return 0;
}

int main(){
	while(scanf("%s", s)){
		if(strcmp(s, "end") == 0){
			break;
		}
		init();
		update();
		dfs(0);
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				printf("%d", maze[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
