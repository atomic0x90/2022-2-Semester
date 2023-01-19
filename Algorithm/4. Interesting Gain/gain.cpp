#include <algorithm>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

ifstream fin("gain.inp");
ofstream fout("gain.out");

int T;
int n;
int l;
int r;
int main(){
	fin>>T;
	while(T--){
		fin>>n;
		vector<int> v(n);
		for(int i = 0;i < n;i++) fin>>v[i];

		sort(v.begin(),v.end());
		fout<<v[n-1]+v[n-2]-v[0]-v[1]<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
