#include <algorithm>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

ifstream fin("stairs.inp");
ofstream fout("stairs.out");

int T;	//testcase
int M;	//건물의 층
int F;	//배찌가 사는 층
int N;	//배찌가 오르고 싶은 계단의 총 층수

int main(){

	fin>>T;
	while(T--){
		int ev = 0;
		int n = 0;
		fin>>M>>F>>N;
		
		if(M - F >= N){//위로 올라갔다가 엘베타고 집으로
			fout<<++ev<<endl;
		}
		else if(M - F < N){
			ev += N/(M-1);
			if(N%(M-1) != 0) ev++;
			fout<<ev<<endl;
		}

	}

	fin.close();
	fout.close();
	return 0;
}
