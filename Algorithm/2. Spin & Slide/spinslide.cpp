#include <algorithm>
#include <fstream>
#include <vector>
#include <utility>
#include <string>

using namespace std;

ifstream fin("spinslide.inp");
ofstream fout("spinslide.out");

int T,N,M;

int main(){
	fin>>T;
	int tc = 1;
	while(T--){
		fin>>N>>M;
		vector<vector<char> > v(N,vector<char>(N));
		for(int i = 0;i < N;i++){
			for(int j = 0;j < N;j++){
				fin>>v[i][j];
			}
		}

		while(M--){
			vector<vector<char> > spin(N,vector<char>(N,'.'));
			for(int i = 0;i < N;i++){
				string s = "";
				for(int j = 0;j < N;j++){
					if(v[i][j] != '.') s += v[i][j];
				}

				int check = s.length()-1;
				for(int j = N-1;j > -1;j--){
					if(s == "") break;
					spin[i][j] = s[check--];
					if(check < 0) break;
				}
			}

			for(int i = 0;i < N;i++){
				for(int j = 0;j < N;j++){
					v[i][j] = spin[N-1-j][i];
				}
			}
		}

		if(tc > 1) fout<<endl;

		fout<<"Case #"<<tc++<<":"<<endl;
		for(int i = 0;i < N;i++){
			for(int j = 0;j < N;j++){
				fout<<v[i][j];
			}
			fout<<endl;
		}
	}

	return 0;
}
