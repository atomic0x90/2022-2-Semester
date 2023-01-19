#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>


using namespace std;

ifstream fin("snail.inp");
ofstream fout("snail.out");

int T;
long long N,A,B;



int main(){
	fin>>T;
	while(T--){
		fin>>N>>A>>B;

		int ax,ay,bx,by;
		ax = bx = -1;
		ay = by = 0;

		long long nextNa = N;
		long long nextA = 0;

		long long nextNb = N;
		long long nextB = 0;
		bool checkA,checkB;
		checkA = checkB = false;
		while(true){

			if(checkA && checkB) break;

			if(!checkA){
				if(nextNa == 1){
					ax++;
					checkA = true;
				}
				else if(nextA + (nextNa*4) - 4 < A){//해당N*N 테두리에 A 없음
					nextA += (nextNa*4)-4;
					nextNa -= 2;
					ax++;
					ay++;
				}
				else{
					int tmp = A-nextA;

					if(tmp <= nextNa){
						ax += tmp;
					}
					else{
						ax += nextNa;
						tmp -= nextNa;
						if(tmp <= nextNa-1){
							ay += tmp;
						}
						else{
							ay += nextNa-1;
							tmp -= nextNa-1;

							if(tmp <= nextNa-1){
								ax -= tmp;
							}
							else{
								ax -= nextNa-1;
								tmp -= nextNa-1;
								ay -= tmp;
							}
						}

					}

					checkA = true;
				}
			}
			if(!checkB){
				if(nextNb == 1){
					bx++;
					checkB = true;
				}
				else if(nextB + (nextNb*4) - 4 < B){//해당N*N 테두리에 B 없음
					nextB += (nextNb*4)-4;
					nextNb -= 2;
					bx++;
					by++;
				}
				else{
					int tmp = B-nextB;

					if(tmp <= nextNb){
						bx += tmp;
					}
					else{
						bx += nextNb;
						tmp -= nextNb;
						if(tmp <= nextNb-1){
							by += tmp;
						}
						else{
							by += nextNb-1;
							tmp -= nextNb-1;

							if(tmp <= nextNb-1){
								bx -= tmp;
							}
							else{
								bx -= nextNb-1;
								tmp -= nextNb-1;
								by -= tmp;
							}
						}

					}

					checkB = true;
				}
			}
		}

		if(abs(ax-bx) == abs(ay-by)) fout<<"YES"<<endl;
		else fout<<"NO"<<endl;
	}


	fin.close();
	fout.close();
	return 0;
}
