#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("gridpath.inp");
ofstream fout("gridpath.out");

int main(){
	int n,m;
	fin>>n>>m;
	vector< vector<int> > v(n,vector<int>(m));
	vector< vector<string> > path(n,vector<string>(m));

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++)
			fin>>v[i][j];
	}

	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(v[i][j] == -1){}
			else{
				if(i-1 < 0){//맨 위
					if(j == 0){
						path[i][j] ="("+ to_string(i)+" "+to_string(j)+")\n";
					}
					else{
						if(v[i][j-1] == -1){
							v[i][j] = -1;
						}
						else{
							v[i][j] += v[i][j-1];
							path[i][j] = path[i][j-1] + "("+ to_string(i)+" "+to_string(j)+")\n";
						}
					}
				}
				else{
					if(j == 0){
						if(v[i-1][j] == -1){
							v[i][j] = -1;
						}
						else{
							v[i][j] += v[i-1][j];
							path[i][j] = path[i-1][j] + "("+ to_string(i)+" "+to_string(j)+")\n";
						}
					}
					else{
						if(v[i-1][j] == -1 && v[i][j-1] == -1){
							v[i][j] = -1;
						}
						else if(v[i-1][j] == -1 && v[i][j-1] != -1){
							v[i][j] += v[i][j-1];
							path[i][j] = path[i][j-1] + "("+ to_string(i)+" "+to_string(j)+")\n";
						}
						else if(v[i-1][j] != -1 && v[i][j-1] == -1){
							v[i][j] += v[i-1][j];
							path[i][j] = path[i-1][j] + "("+ to_string(i)+" "+to_string(j)+")\n";
						}
						else{
							if(v[i-1][j] == v[i][j-1]){
								v[i][j] += v[i-1][j];
								path[i][j] = path[i-1][j] + "("+ to_string(i)+" "+to_string(j)+")\n";
							}
							else if(v[i-1][j] < v[i][j-1]){
								v[i][j] += v[i-1][j];
								path[i][j] = path[i-1][j] + "("+ to_string(i)+" "+to_string(j)+")\n";
							}
							else if(v[i-1][j] > v[i][j-1]){
								v[i][j] += v[i][j-1];
								path[i][j] = path[i][j-1] + "("+ to_string(i)+" "+to_string(j)+")\n";
							}
						}
					}
				}
			}
		}
	}


	if(v[n-1][m-1] != -1){
		fout<<v[n-1][m-1]<<endl;
		fout<<path[n-1][m-1];
	}
	else fout<<"No path."<<endl;
	fin.close();
	fout.close();
	return 0;
}
