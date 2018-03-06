//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 15;

int a[maxn];
int x[maxn];
int y[maxn];
int mark[maxn];
int ans;

void dfs(int id){
	if(id >= 10){
		int lena = 0, lenb = 0;
		for(int i=0; i<10; i++){
			if(mark[i]){
				x[lena++] = a[i];
			}
			else{
				y[lenb++] = a[i];
			}
		}
		int flag = 1;
		for(int i=1; i<lena; i++){
			if(x[i]<=x[i-1]){
				flag = 0;
				break;
			}
		} 
		for(int i=1; i<lenb; i++){
			if(y[i]<=y[i-1]){
				flag = 0;
				break;
			}
		} 
		if(flag){
			ans = 1;
			return;
		}
	}
	else{
		mark[id] = 1;
		dfs(id+1);
		mark[id] = 0;
		dfs(id+1); 
	} 
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		for(int i=0; i<10; i++){
			scanf("%d", &a[i]);
		}
		ans = 0;
		dfs(0);
		printf("%s\n", ans?"YES":"NO");
	}
	return 0;
} 
