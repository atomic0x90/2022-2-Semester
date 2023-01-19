#include <fstream>
#include <algorithm>
#include <vector>

#include <iostream>
using namespace std;

ifstream fin("bin.inp");
ofstream fout("bin.out");

int T,n,m;

vector<vector<int> > sum(501,vector<int>(501));
vector<vector<int> > gap(501,vector<int>(501));

int algo(int start,int bin){//start ~ () 까지 위치, bin 남은 통 개수
	if(start > n) return (bin == 0 ? 0 : 9999999);
//start>n -> 집 개수 초과, 쓰레기통 남아있으면 최댓값, 없으면 마지막 위치까지 해서 쓰레기통 배치
	
	if(bin == 0) return 9999999;
	//집 개수 남아있는데 앞의 위치까지 쓰레기통 배치를 다 했으므로 최대값
	
	if(sum[start][bin] != -1) return sum[start][bin];
	
	for(int i = start;i <= n;i++){
		/*
		 * sum[start][bin] start 위치 부터 이후에 bin 만큼 배치가 가능함 =
		 * gap[start][i] start~i 까지 쓰레기통 하나 배치 +
		 * i+1 ~ algo 호출 후 쓰레기통 갯수-1 why?:start~i 까지 하나 배치했으므로
		 * sum[start][bin]과 비교 -> min값 저장
		 */
		if(sum[start][bin] == -1) sum[start][bin] = gap[start][i] + algo(i+1,bin-1);
		else sum[start][bin] = min(gap[start][i] + algo(i+1,bin-1),sum[start][bin]);
	}

	return sum[start][bin];
}

int main(){
	fin>>T;
	while(T--){
		fin>>n>>m;
		vector<int> v(n+1);//집 위치
		//gap[a][b] a~b 거리, a,b 중간 위치에 쓰레기통이 있을 때 거리 총 합
		//sum[a][b] a~()거리, b 남은 쓰레기 통
		for(int i = 1;i <= n;i++) fin>>v[i];
		sort(v.begin()+1,v.end());
		
		for(int i = 1;i <= n;i++){
			for(int j = i;j <= n;j++) gap[i][j] = gap[i][j-1]+ v[j]-v[i+((j-i)/2)];
			for(int j = 1;j <= m;j++) sum[i][j] = -1;
		}
		fout<<algo(1,m)<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
