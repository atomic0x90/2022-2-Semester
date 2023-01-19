#include <algorithm>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin("bitmap.inp");
ofstream fout("bitmap.out");

char check;
int N,M;//N by M metrix

string s;
string resultBtoD;
string resultDtoB;
vector< vector<char> > vB;
vector< vector<char> > vD;

void algoBtoD(int x1,int y1,int x2,int y2){
	if(x1 >= N || x2 >= N || y1 >= M || y2 >= M ||
			x1 > x2 || y1 > y2) return;
	char checkValue = ' ';

	if(vB[x1][y1] == '0') checkValue = '0';
	else checkValue = '1';

	bool flag = true;

	for(int i = x1;i <= x2;i++){
		for(int j = y1;j <= y2;j++){
			if(checkValue != vB[i][j]){
				flag = false;
				break;
			}
		}
		if(!flag) break;
	}
	if(flag){
		resultBtoD += checkValue;
		return;
	}
	else{
		resultBtoD += 'D';

		if(x1 == x2 && y1 == y2) return;

		int xmid,ymid;
		
		xmid = ((x2-x1)/2)+x1;
		ymid = ((y2-y1)/2)+y1;

		algoBtoD(x1,y1,xmid,ymid);
		if(y1 != y2) algoBtoD(x1,ymid+1,xmid,y2);
		if(x1 != x2) algoBtoD(xmid+1,y1,x2,ymid);
		if(y1 != y2) algoBtoD(xmid+1,ymid+1,x2,y2);
	}
}

void algoDtoB(int x1,int y1,int x2,int y2){
	if(s.length() == 0) return;
	if(x1 >= N || x2 >= N || y1 >= M || y2 >= M ||
			x1 > x2 || y1 > y2) return;

	if(s[0] == '1' || s[0] == '0'){
		for(int i = x1;i <= x2;i++){
			for(int j = y1;j <= y2;j++)
				vD[i][j] = s[0];
		}
		s = s.substr(1);
	}
	else if(s[0] == 'D'){
		s = s.substr(1);

		int xmid,ymid;

		xmid = ((x2-x1)/2)+x1;
		ymid = ((y2-y1)/2)+y1;

		algoDtoB(x1,y1,xmid,ymid);
		if(y1 != y2) algoDtoB(x1,ymid+1,xmid,y2);
		if(x1 != x2) algoDtoB(xmid+1,y1,x2,ymid);
		if(y1 != y2) algoDtoB(xmid+1,ymid+1,x2,y2);
	}
}

int main(){
	string checkLine = "";
	while(true){
		if(checkLine == ""){
			fin>>check;
			if(check == '#') break;
	
			fin>>N>>M;
		}
		else{
			if(checkLine == "#") break;
			if(checkLine == "D" || checkLine == "B"){
				check = checkLine[0];
				fin>>N>>M;
			}
			checkLine = "";
		}

		resultBtoD = "";
		vB.clear();
		vB.resize(N,vector<char>(M));
		vD.clear();
		vD.resize(N,vector<char>(M));
		s = "";
		
		fin>>s;
		if(s.length() == 50){
			while(true){
				fin>>checkLine;
				if(checkLine.length() > 1){
					if(checkLine[1] == ' '){
						break;
					}
					else{
						s+= checkLine;
					
						if(checkLine.length() != 50){
							checkLine = "";
							break;
						}
					}
				}
				else{
					if(checkLine[0] != '#' && checkLine[0] != 'D' && checkLine[0] != 'B'){
						s += checkLine;
						checkLine = "";
					}

					break;
				}
			}
		}
		if(check == 'B'){
			int index = 0;
			for(int i = 0;i < N;i++){
				for(int j = 0;j < M;j++){
					vB[i][j] = s[index++];
				}
			}

			algoBtoD(0,0,N-1,M-1);
			
			fout<<"D";
			fout.width(4);
			fout<<N;
			fout.width(4);
			fout<<M<<endl;

			int check50Line = 0;
			while(true){
				check50Line++;
				fout<<resultBtoD[0];
				if(check50Line == 50){
					check50Line = 0;
					fout<<endl;
				}
				resultBtoD = resultBtoD.substr(1);
				if(resultBtoD == "") break;
			}
			fout<<endl;
		}
		else if(check == 'D'){
			algoDtoB(0,0,N-1,M-1);

			fout<<"B";
			fout.width(4);
			fout<<N;
			fout.width(4);
			fout<<M<<endl;

			int check50Line = 0;
			for(int i = 0;i < N;i++){
				for(int j = 0;j < M;j++){
					fout<<vD[i][j];
					check50Line++;
					if(check50Line == 50){
						check50Line = 0;
						if(i != N-1 || j != M-1)fout<<endl;
					}
				}
			}
			fout<<endl;
		}
		if(checkLine[0] == '#') break;
	}

	fin.close();
	fout.close();
	return 0;
}
