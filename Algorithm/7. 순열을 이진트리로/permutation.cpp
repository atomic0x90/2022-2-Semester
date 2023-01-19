#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>

using namespace std;

ifstream fin("permutation.inp");
ofstream fout("permutation.out");

int T,n;

vector<int> v;
vector<int> depth;

void algo(int left,int right){
	for(int i = left;i <= right;i++) depth[i]++;

	int root = max_element(v.begin()+left,v.begin()+right+1)-v.begin();

	depth[root]--;

	if(left < root-1) algo(left,root-1);
	if(root+1 < right)algo(root+1,right);
}

int main(){
	fin>>T;
	while(T--){
		fin>>n;
		v.clear();
		v.resize(n);
		depth.clear();
		depth.resize(n);
		
		for(int i = 0;i < n;i++) fin>>v[i];

		algo(0,n-1);

		for(int i = 0;i < n;i++){
			fout<<depth[i]<<" ";
		}
		fout<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
