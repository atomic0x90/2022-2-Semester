#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

ifstream fin("path.inp");
ofstream fout("path.out");

int C,M,N,K;

int path[201][201][201];	//해당 위치에 k번 지나간게 몇 번
int pathWeight[201][201][201];	//해당 위치에 k번 지나가면서 생긴 비용
int pathWhere[201][201][201];	//0: 왼쪽->오른쪽, 1: 위->아래

//input
int checkX[201][201];
int weightWidth[201][201];
int weightLength[201][201];

void init(){
	for(int i = 0;i < 201;i++){
		for(int j = 0;j < 201;j++){
			checkX[i][j] = 
				weightWidth[i][j] = 
				weightLength[i][j] = 0;
			for(int k = 0;k < 201;k++){
				pathWhere[i][j][k] = -1;
				pathWeight[i][j][k] = path[i][j][k] = 0;
			}
		}
	}
	path[0][0][0] = 1;
	for(int i = 0;i < 201;i++) pathWhere[0][0][i] = 0;
}

int main(){
	fin>>C;
	int checkTC = 1;
	while(C--){
		init();
		fin>>M>>N>>K;
		int a,b;
		int tmp = K;
		while(tmp--){
			fin>>a>>b;
			checkX[a][b] = 1;
		}
		for(int i = 0;i < M;i++){
			for(int j = 0;j < N-1;j++){
				fin>>weightWidth[i][j];
			}
		}

		for(int i = 0;i < M-1;i++){
			for(int j = 0;j < N;j++){
				fin>>weightLength[i][j];
			}
		}

		int checkCount = 0;
		for(int i = 1;i < N;i++){//맨 윗 줄
			bool flag = false;
			if(checkX[0][i] == 1){
				checkCount++;
				flag = true;
			}
			pathWhere[0][i][checkCount] = 0;
			path[0][i][checkCount] = 1;
			pathWeight[0][i][checkCount] = pathWeight[0][i-1][checkCount-(flag ? 1 : 0)] + weightWidth[0][i-1];
			//flag가 true 일 경우 다음 checkCount 필드로 이동 후 이전 필드에 있는 가중치를 가져옴
		}
		checkCount = 0;
		for(int i = 1;i < M;i++){//맨 왼쪽 줄
			bool flag = false;
			if(checkX[i][0] == 1){
				checkCount++;
				flag = true;
			}
			
			pathWhere[i][0][checkCount] = 1;
			path[i][0][checkCount] = 1;
			pathWeight[i][0][checkCount] = pathWeight[i-1][0][checkCount-(flag ? 1 : 0)] + weightLength[i-1][0];
		}
		
		for(int i = 1;i < M;i++){
			for(int j = 1;j < N;j++){
				if(checkX[i][j] != 1){
					for(int k = 0;k <= K;k++){
						if(pathWhere[i-1][j][k] == -1 && pathWhere[i][j-1][k] == -1) continue;
						else if(pathWhere[i-1][j][k] == -1 && pathWhere[i][j-1][k] != -1){
							path[i][j][k] = path[i][j-1][k];
							pathWhere[i][j][k] = 0;
							pathWeight[i][j][k] = pathWeight[i][j-1][k] + weightWidth[i][j-1];
						}
						else if(pathWhere[i-1][j][k] != -1 && pathWhere[i][j-1][k] == -1){
							path[i][j][k] = path[i-1][j][k];
							pathWhere[i][j][k] = 1;
							pathWeight[i][j][k] = pathWeight[i-1][j][k] + weightLength[i-1][j];
						}
						else{
							path[i][j][k] = (path[i-1][j][k] + path[i][j-1][k])%100000;
							if(pathWeight[i-1][j][k] + weightLength[i-1][j] 
									< 
									pathWeight[i][j-1][k] + weightWidth[i][j-1]){
								pathWhere[i][j][k] = 1;
								pathWeight[i][j][k] = pathWeight[i-1][j][k] + weightLength[i-1][j];
							}
							else{
								pathWhere[i][j][k] = 0;
								pathWeight[i][j][k] = pathWeight[i][j-1][k] + weightWidth[i][j-1];
							}
						}
					}
				}
				else{//표시 o
					for(int k = K;k > 0;k--){
						//이전 필드에서 k번 째 필드로 넘어 올 수 있는지 확인 후 계산
						if(pathWhere[i-1][j][k-1] == -1 && pathWhere[i][j-1][k-1] == -1) continue;

						if(pathWhere[i-1][j][k-1] == -1 && pathWhere[i][j-1][k-1] != -1){
							path[i][j][k] = path[i][j-1][k-1];
							pathWhere[i][j][k] = 0;
							pathWeight[i][j][k] = pathWeight[i][j-1][k-1] + weightWidth[i][j-1];
						}
						else if(pathWhere[i-1][j][k-1] != -1 && pathWhere[i][j-1][k-1] == -1){
							path[i][j][k] = path[i-1][j][k-1];
							pathWhere[i][j][k] = 1;
							pathWeight[i][j][k] = pathWeight[i-1][j][k-1] + weightLength[i-1][j];
						}
						else{
							path[i][j][k] = (path[i-1][j][k-1] + path[i][j-1][k-1])%100000;
							if(pathWeight[i-1][j][k-1] + weightLength[i-1][j] 
									< 
									pathWeight[i][j-1][k-1] + weightWidth[i][j-1]){
								pathWhere[i][j][k] = 1;
								pathWeight[i][j][k] = pathWeight[i-1][j][k-1] + weightLength[i-1][j];
							}
							else{
								pathWhere[i][j][k] = 0;
								pathWeight[i][j][k] = pathWeight[i][j-1][k-1] + weightWidth[i][j-1];
							}
						}
					}
				}
			}
		}

		fout<<"Test Case No:"<<checkTC++<<endl;
		for(int i = 0;i <= K;i++){
			if(path[M-1][N-1][i] != 0){
				fout<<"k:"<<i<<" count:"<<path[M-1][N-1][i]<<" cost:"<<pathWeight[M-1][N-1][i]<<endl;


				int check = i;
				int m = M-1,n = N-1;
				string resultString = "";
				while(true){//경로 찾기
					/*
					 * 해당 위치가 checkX == 1 일 때 pathWhere[m][n][check] 따라 이동 후 check-1 번째 필드로 이동
					 * */
					resultString = "("+to_string(m)+","+to_string(n)+
						((m == M-1 && n == N-1) ? ")":")->") + resultString;
					
					if(pathWhere[m][n][check] == 0){
						if(checkX[m][n] == 1) check--;
						n--;
					}
					else if(pathWhere[m][n][check] == 1){
						if(checkX[m][n] == 1) check--;
						m--;
					}
					

					if(m == 0 && n == 0){
						resultString = "(0,0)->"+resultString;
						break;
					}
				}
				fout<<resultString<<endl;
			}
		}
		fout<<endl;


	}

	fin.close();
	fout.close();
	return 0;
}
