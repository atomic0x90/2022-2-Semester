#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>


using namespace std;

ifstream fin("grid.inp");
ofstream fout("grid.out");

int T,N,M,K;

int main(){
	fin>>T;
	while(T--){
		fin>>N>>M>>K;
		vector<int> a(K);
		vector<int> b(K);

		int N1,N2,M1,M2;
		N1 = N2 = N;
		M1 = M2 = M;
		

		for(int i = 0;i < K;i++)
			fin>>a[i];

		sort(a.begin(),a.end(),greater<int>());
		b = a;


		bool flag = true;
		int checkNo = K;
		int checkIndex = K;
		for(int i = 0;i < K;i++){
			if(M1 >= 2){
				if(a[i]/N1 >= 2){
					M1 -= 2;
					a[i] -= 2*N1;
				}
				else{
					checkNo = i;
					break;
				}
			}
			else if(M1 == 1){
				checkIndex = i;
				break;
			}
			else if(M1 == 0){
				break;
			}
		}
		if(M1 == 1){
			for(int i = 0;i < checkIndex;i++){
				if(a[i]/N1 > 0){
					M1 = 0;
					break;
				}
			}
		}
		else if(M1 == 0){}
		else{
			for(int i = 0;i < checkNo;i++){
				if(M1 <= 0) break;
				if(a[i]/N1 > 0){
					M1 -= a[i]/N1;
				}
			}
		}

		if(M1 > 0) flag = false;
		

		checkNo = checkIndex = K;
		if(flag) fout<<"Yes"<<endl;
		else{
			flag = true;
			for(int i = 0;i < K;i++){
				if(N2 >= 2){
					if(b[i]/M2 >= 2){
						N2 -= 2;
						b[i] -= 2*M2;
					}
					else{
						checkNo = i;
						break;
					}
				}
				else if(N2 == 1){
					checkIndex = i;
					break;
				}
				else if(N2 == 0){
					break;
				}
			}
			if(N2 == 1){
				for(int i = 0;i < checkIndex;i++){
					if(b[i]/M2 > 0){
						N2 = 0;
						break;
					}
				}
			}
			else if(N2 == 0){}
			else{
				for(int i = 0;i < checkNo;i++){
					if(N2 <= 0) break;
					if(b[i]/M2 > 0){
						N2 -= b[i]/M2;
					}
				}
			}

			if(N2 > 0) flag = false;

			if(flag) fout<<"Yes"<<endl;
			else fout<<"No"<<endl;
		}
	}

	fin.close();
	fout.close();
	return 0;
}
