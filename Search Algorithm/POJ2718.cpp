//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;

const int maxn = 15;
const int inf = 1e7;

int a[maxn];

int main(){
	int t;
	scanf("%d", &t);
	getchar();
	char s[maxn];
	while(t--){
		int n = 0;
		char c;
		while((c=getchar())!='\n'){
			if(c>='0' && c<='9'){
				a[n++] = c-'0';
			}
		}
		int ans = inf;
		int mid = n/2;
		do{
			if(a[0] == 0 || a[mid] == 0 && (n-mid)>1){
				continue;
			}
			int a_ = 0, b_ = 0;
			for(int i=0; i<n; i++){
				if(i<mid){
					a_ *= 10;
					a_ += a[i];
				}
				else{
					b_ *= 10;
					b_ += a[i];
				}
			}
			ans = min(ans, abs(a_-b_));
		}while(next_permutation(a, a+n));
		printf("%d\n", ans);
	}
	return 0;
} 
