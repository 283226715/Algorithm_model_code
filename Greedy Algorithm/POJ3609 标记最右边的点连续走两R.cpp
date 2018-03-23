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

typedef long long ll;
const int maxn = 1e3+5;

int x[maxn];

int main(){
	int r, n;
	while(scanf("%d%d", &r, &n) == 2){
		if(n == -1 && r == -1){
			break;
		}
		for(int i=0; i<n; i++){
			scanf("%d", &x[i]);
		}
		sort(x, x+n);
		int now = 0;
		int ans = 0;
		while(now<n){
			int s = x[now++];
			while(now<n && x[now]<=s+r)	now++;
			s = x[now-1];
			while(now<n && x[now]<=s+r)	now++;
			ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}

