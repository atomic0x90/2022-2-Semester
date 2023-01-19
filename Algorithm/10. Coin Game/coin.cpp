#include <algorithm>
#include <fstream>

#include <iostream>

using namespace std;

ifstream fin("coin.inp");
ofstream fout("coin.out");

int n;
int a,b,c;
int checkZero;
int checkOne;

int main(){
	fin>>n;
	while(n--){
		fin>>a>>b>>c;
		fout<<"("<<a<<" "<<b<<" "<<c<<") : ";
		a %= 4;
		b %= 4;
		c %= 4;
		checkZero = 0;
		checkOne = 0;
		if(a == 0) checkZero++;
		if(b == 0) checkZero++;
		if(c == 0) checkZero++;

		if(a == 1) checkOne++;
		if(b == 1) checkOne++;
		if(c == 1) checkOne++;

		if(checkZero == 0){
			if(checkOne == 3) fout<<"-1"<<endl;
			else if(checkOne == 2) fout<<"1"<<endl;
			else if(checkOne == 1){
				if(a+b+c == 5 || a+b+c == 7) fout<<"1"<<endl;
				else fout<<"-1"<<endl;
			}
			else if(checkOne == 0) fout<<"1"<<endl;
		}
		else if(checkZero == 1){
			if(checkOne == 2) fout<<"1"<<endl;
			else if(checkOne == 1) fout<<"1"<<endl;
			else{
				if(a+b+c == 5) fout<<"1"<<endl;
				else fout<<"-1"<<endl;
			}
		}
		else if(checkZero == 2){
			if(checkOne == 1) fout<<"-1"<<endl;
			else fout<<"1"<<endl;
		}
		else if(checkZero == 3){
			fout<<"1"<<endl;
		}


	}

	fin.close();
	fout.close();
	return 0;
}
