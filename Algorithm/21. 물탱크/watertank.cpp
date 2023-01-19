#include <fstream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

ifstream fin("watertank.inp");
ofstream fout("watertank.out");

int T,N,M,H;
int main(){
	fin>>T;
	while(T--){
		fin>>N>>M>>H;
		int result = 0;
		vector<vector<int> > data1(N+1,vector<int>(M));
		vector<vector<int> > data2(N,vector<int>(M+1));
		vector<vector<int> > nowH(N,vector<int>(M));
		vector<vector<bool> > visit(N,vector<bool>(M,false));
		priority_queue<pair<pair<int,int>,pair<int,int> > > pq;
		//높이, 상하좌우,0:위,1:오,2:아,3:왼, 세로N, 가로M
		for(int i = 0;i < N+1;i++){
			for(int j = 0;j < M;j++) fin>>data1[i][j];
		}
		for(int i = 0;i < N;i++){
			for(int j = 0;j < M+1;j++) fin>>data2[i][j];
		}

		for(int i = 0;i < N;i++){
			for(int j = 0;j < M;j++) nowH[i][j] = H;
		}



		for(int i = 0;i < M;i++){//맨 위 구멍
			if(data1[0][i] == -1) continue;
			pq.push(make_pair(make_pair(-data1[0][i],0),make_pair(0,i)));
		}
		for(int i = 0;i < M;i++){//맨 아래 구멍
			if(data1[N][i] == -1) continue;
			pq.push(make_pair(make_pair(-data1[N][i],2),make_pair(N-1,i)));
		}
		for(int i = 0;i < N;i++){//맨 오른쪽 구멍
			if(data2[i][M] == -1) continue;
			pq.push(make_pair(make_pair(-data2[i][M],1),make_pair(i,M-1)));
		}
		for(int i = 0;i < N;i++){//맨 왼쪽 구멍
			if(data2[i][0] == -1) continue;
			pq.push(make_pair(make_pair(-data2[i][0],3),make_pair(i,0)));
		}


		while(!pq.empty()){
			pair<pair<int,int>,pair<int,int> > a = pq.top();
			pq.pop();
			if(visit[a.second.first][a.second.second]) continue;

			a.first.first = a.first.first*(-1);
			if(a.first.second == 0){//위쪽
				if(a.second.first == 0){
					nowH[a.second.first][a.second.second] = a.first.first;
				}
				else{
					if(nowH[a.second.first-1][a.second.second] <= a.first.first)
						//구멍 보다 다른 공간이 더 낮을 때
						nowH[a.second.first][a.second.second] = a.first.first;
					else//구멍 보다 다른 공간이 더 높을 때	
						nowH[a.second.first][a.second.second] = nowH[a.second.first-1][a.second.second];
				}
			}
			else if(a.first.second == 1){//오른쪽
				if(a.second.second == M-1){
					nowH[a.second.first][a.second.second] = a.first.first;
				}
				else{
					if(nowH[a.second.first][a.second.second+1] <= a.first.first)
						nowH[a.second.first][a.second.second] = a.first.first;
					else
						nowH[a.second.first][a.second.second] = nowH[a.second.first][a.second.second+1];
				}
			}
			else if(a.first.second == 2){//아래
				if(a.second.first == N-1){
					nowH[a.second.first][a.second.second] = a.first.first;
				}
				else{
					if(nowH[a.second.first+1][a.second.second] <= a.first.first)
						nowH[a.second.first][a.second.second] = a.first.first;
					else
						nowH[a.second.first][a.second.second] = nowH[a.second.first+1][a.second.second];
				}
			}
			else if(a.first.second == 3){//왼쪽
				if(a.second.second == 0){
					nowH[a.second.first][a.second.second] = a.first.first;
				}
				else{
					if(nowH[a.second.first][a.second.second-1] <= a.first.first)
						nowH[a.second.first][a.second.second] = a.first.first;
					else
						nowH[a.second.first][a.second.second] = nowH[a.second.first][a.second.second-1];
				}
			}

			if(a.second.first != 0 && data1[a.second.first][a.second.second] != -1){//위가 있을 때
				pq.push(make_pair(make_pair(-data1[a.second.first][a.second.second],2),make_pair(a.second.first-1,a.second.second)));
			}
			if(a.second.second != M-1 && data2[a.second.first][a.second.second+1] != -1){//오른쪽이 있을 때
				pq.push(make_pair(make_pair(-data2[a.second.first][a.second.second+1],3),make_pair(a.second.first,a.second.second+1)));
			}
			if(a.second.first != N-1 && data1[a.second.first+1][a.second.second] != -1){//아래가 있을 때
				pq.push(make_pair(make_pair(-data1[a.second.first+1][a.second.second],0),make_pair(a.second.first+1,a.second.second)));
			}
			if(a.second.second != 0 && data2[a.second.first][a.second.second] != -1){//왼쪽이 있을 때
				pq.push(make_pair(make_pair(-data2[a.second.first][a.second.second],1),make_pair(a.second.first,a.second.second-1)));
			}

			visit[a.second.first][a.second.second] = true;
		}

		for(int i = 0;i < N;i++){
                        for(int j = 0;j < M;j++) result += nowH[i][j];
                }
		fout<<result<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
