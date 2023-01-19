#include <fstream>
#include <climits>
#include <algorithm>

using namespace std;

ifstream fin("card.inp");
ofstream fout("card.out");

int T;
int n;
int card[1005];
int dp[1005];
int check2[1005];

void algo(int now){
	if(now > n) return;
	if(now == 4){
		if(dp[1] > dp[2]){
			dp[4] = dp[1] + card[4];
		}
		else{
			dp[4] = dp[2] + card[4];
			check2[4] = dp[1] + card[4];
		}
		algo(now + 1);
	}
	else{
		int num2,num3,num4;
		if(check2[now-2] != INT_MIN) num2 = check2[now-2];
		else num2 = dp[now-2];

		num3 = dp[now-3];
		num4 = dp[now-4];

		if(num2 >= num3 && num2 >= num4){
			dp[now] = num2 + card[now];
			check2[now] = max(num3,num4) + card[now];
		}
		else if(num3 >= num2 && num3 >= num4) dp[now] = num3 + card[now];
		else dp[now] = num4 + card[now];

		algo(now+1);
	}

}

int main(){
	fin>>T;
	while(T--){
		fin>>n;
		for(int i = 1;i < n+1;i++){
			fin>>card[i];

			dp[i] = check2[i] = INT_MIN;
		}
		dp[1] = card[1];
		dp[2] = card[2];
		dp[3] = card[3];
	
		algo(4);
		fout<<dp[n]<<endl;
	}	

	fin.close();
	fout.close();
	return 0;
}
