#include <fstream>

using namespace std;

ifstream fin("addingways.inp");
ofstream fout("addingways.out");

int n,k;
int dp[301][21];
void algo(){
	dp[1][1] = dp[2][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for(int i = 4;i < 301;i++){
		for(int j = 1;j < 21;j++){
			if(i < j) break;
			if(j == 1 || i == j || i-1 == j){
				dp[i][j] = 1;
				continue;
			}
		
			int count = 1;
			for(int k = j;k > 1;k--){
				count = (count + dp[i-j][k])%1000000007;
			}
			dp[i][j] = count;
		}
	}

}
int main(){
	algo();
	while(true){
		fin>>n>>k;
		if(n == 0 && k == 0) break;
		fout<<dp[n][k]<<endl;
	}

	return 0;
}
