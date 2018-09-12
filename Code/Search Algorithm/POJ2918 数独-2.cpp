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

const int maxn = 15;
const int inf = 1e7;

char s[maxn];
int a[maxn*maxn];
int n;
int mark[maxn];
int finish;

bool yes(){
	for(int i=1; i<=9; i++){
		if(!mark[i]){
			return false;
		}
	}
	return true;
}

bool ok(){
	for(int i=0; i<9; i++){
		memset(mark, 0, sizeof(mark));
		for(int j=0; j<9; j++){
			mark[a[i*9+j]] = 1;
		}
		if(!yes()){
			return false;
		}
	}
	
	for(int j=0; j<9; j++){
		memset(mark, 0, sizeof(mark));
		for(int i=0; i<9; i++){
			mark[a[j*9+i]] = 1;
		}
		if(!yes()){
			return false;
		}
	}
	
	for(int i=0; i<9; i+=3){
		for(int j=0; j<9; j+=3){
			memset(mark, 0, sizeof(mark));
			for(int di=0; di<3; di++){
				for(int dj=0; dj<3; dj++){
					int x = i+di;
					int y = j+dj;
					mark[a[x*9+y]] = 1;
				}
			}
			if(!yes()){
				return false;
			}
		}
	}
	return true;
}

bool check(int id, int num){
	int x = id/9;
	int y = id%9;
	for(int i=0; i<9; i++){
		if(a[x*9+i] == num){
			return false;
		}
		if(a[i*9+y] == num){
			return false;
		}
	}
	int sx = x/3*3;
	int sy = y/3*3;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int nx = sx+i;
			int ny = sy+j;
			if(a[nx*9+ny] == num){
				return false;
			}
		}
	}
	return true;
}

void dfs(int id){
	if(finish) return;
	if(id>=n){
		if(ok()){
			for(int i=0; i<9; i++){
				for(int j=0; j<9; j++){
					printf("%d", a[i*9+j]);
				}
				printf("\n");
			}
			finish = 1;
		}
		return;
	}
	if(a[id]){
		dfs(id+1);
	}
	else{
		for(int i=1; i<=9; i++){
			if(check(id, i)){
				a[id] = i;
				dfs(id+1);
				a[id] = 0;
			}
		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	for(int cas = 1; cas<=t; cas++){
		printf("Scenario #%d:\n", cas);
		n = 0;
		for(int i=0; i<9; i++){
			scanf("%s", s);
			for(int j=0; j<9; j++){
				a[n++] = s[j]-'0';
			}
		}
		finish = 0;
		dfs(0);
		printf("\n");
	}
	return 0;
} 

