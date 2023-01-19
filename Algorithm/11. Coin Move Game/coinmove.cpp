#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("coinmove.inp");
ofstream fout("coinmove.out");

int T;
int P,K,S;
int main(){
	fin>>T;
	while(T--){
		fin>>P>>K>>S;
		vector< vector<int> > v(S+1,vector<int>(K+1));
		//-1 : unable, 0 : initial, 1 : able
		for(int i = 1;i <= K;i++) v[0][i] = -1;

		for(int i = 1;i <= S;i++){//1 ~ S 까지 check
			for(int j = 1;j <= K;j++){//jump 해서 i 번째 도착
				for(int l = 1;l <= K;l++){
					if(j == l) continue;
					//i-j 위치에서 j만큼 점프 했을 때 [i-j][l] check
					if(j > i ||
						( (i-j) != 0 && (i-j)%P == 0 ) ||
						v[i-j][l] == 1
						/*
						 * i-j번째에서 상대가 이기는(죽지 않는) 수 가 있으므로
						 * j만큼 점프해서 i위치에 왔을 때 이길 수 없다
						*/
						){
						v[i][j] = -1;
						break;
					}
				}
				if(v[i][j] == 0) v[i][j] = 1;
			}
		}

		bool flag = true;
		for(int i = 1;i <= K;i++){
			if(v[S][i] == 1 && flag){
				flag = false;
				fout<<S-i<<endl;
			}
		}
		if(flag) fout<<"-1"<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
