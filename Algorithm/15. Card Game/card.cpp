#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("card.inp");
ofstream fout("card.out");

int card[1005];
int dp[1005][1005];
int T,n;

int algo(int front,int back,bool flag){
	if(dp[front][back] != 0) return dp[front][back];
	if(front == back){
		if(flag) return card[front];
		else return 0;
	}

	if(flag) dp[front][back] = max(algo(front+1,back,!flag)+card[front],algo(front,back-1,!flag)+card[back]);
	else if(!flag) dp[front][back] = min(algo(front+1,back,!flag),algo(front,back-1,!flag));

	return dp[front][back];
}
void init(){
	for(int i = 0;i < 1005;i++){
		card[i] = 0;
		for(int j = 0;j < 1005;j++)
			dp[i][j] = 0;
	}
}
int main(){
	fin>>T;
	while(T--){
		init();
		fin>>n;
		for(int i = 0;i < n;i++) fin>>card[i];
		fout<<algo(0,n-1,true)<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
