#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("drive.inp");
ofstream fout("drive.out");

int T,M,N,L,G;
int data1[103][103];
int data2[103][103];

int dp[101][101][202][2];//x,y,꺾은 횟수,0:오른쪽에서 왔을 경우 1:위쪽에서 왔을 경우

int main(){
	fin>>T;
	while(T--){
		fin>>M>>N>>L>>G;
		for(int i = 0;i < M;i++){
			for(int j = 0;j < N-1;j++) fin>>data1[i][j];
		}
		for(int i = 0;i < M-1;i++){
			for(int j = 0;j < N;j++) fin>>data2[i][j];
		}
		for(int i = 0;i < 101;i++){
			for(int j = 0;j < 101;j++){
				for(int k = 0;k < 202;k++){
					dp[i][j][k][0] = dp[i][j][k][1] = 9999999;
				}
			}
		}

		dp[0][0][0][0] = dp[0][0][0][1] = 0;
		for(int i = 1;i < M;i++) dp[i][0][0][1] = dp[i-1][0][0][1] + data2[i-1][0];
		for(int i = 1;i < N;i++) dp[0][i][0][0] = dp[0][i-1][0][0] + data1[0][i-1];

		for(int i = 1;i < M;i++){
			for(int j = 1;j < N;j++){
				for(int k = 1;k < 202;k++){
					dp[i][j][k][0] = min(dp[i][j-1][k][0]+data1[i][j-1],dp[i][j-1][k-1][1]+data1[i][j-1]);
					dp[i][j][k][1] = min(dp[i-1][j][k][1]+data2[i-1][j],dp[i-1][j][k-1][0]+data2[i-1][j]);
				}
			}
		}

		int result = -1;
		for(int i = 1;i < 202;i++){
			/*
			 * 1번 꺾였을 때 부터 G 보다 작으면 출력하면 됨
			 * 어차피 최단 경로로 가는 경우 이동하는 행,열의 수는 정해져 있음
			 * 꺾이면 +1 이므로 result값은 (행+열)*거리+(꺾인 횟수) 가 됨
			 */
			if(dp[M-1][N-1][i][0] <= G || dp[M-1][N-1][i][1] <= G){
				result = (M+N-2)*L+i;
				break;
			}
		}
		fout<<result<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
