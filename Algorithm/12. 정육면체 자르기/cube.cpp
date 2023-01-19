#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

ifstream fin("cube.inp");
ofstream fout("cube.out");

int T,W,L,H;
int dp[201][201][201];

int algo(int a,int b,int c){
	if(a == b && b == c) return dp[a][b][c] = 1;

	if(a > b) swap(a,b);
	if(b > c) swap(b,c);
	if(a > b) swap(a,b);

	if(dp[a][b][c] != INT_MAX) return dp[a][b][c];
	
	if(a == 1 && b == 1) return dp[a][b][c] = c;
	else if(a == 1 && b != 1) return dp[a][b][c] = b*c;
	else{
		for(int i = 1;i <= a/2;i++)
			dp[a][b][c] = min(dp[a][b][c] , algo(i,b,c) + algo(a-i,b,c));
		
		for(int i = 1;i <= b/2;i++)
			dp[a][b][c] = min(dp[a][b][c] , algo(a,i,c) + algo(a,b-i,c));
		
		for(int i = 1;i <= c/2;i++)
			dp[a][b][c] = min(dp[a][b][c] , algo(a,b,i) + algo(a,b,c-i));
	}

	return dp[a][b][c];
}

void init(){
	for(int i = 0;i < 201;i++){
		for(int j = 0;j < 201;j++){
			for(int k = 0;k < 201;k++)
				dp[i][j][k] = INT_MAX;
		}
	}
}

int main(){
	fin>>T;
	while(T--){
		fin>>W>>L>>H;
	
		init();

		if(W > L) swap(W,L);
		if(L > H) swap(L,H);
		if(W > L) swap(W,L);

		fout<<algo(W,L,H)<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
