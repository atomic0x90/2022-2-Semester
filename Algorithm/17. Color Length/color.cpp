#include <fstream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

ifstream fin("color.inp");
ofstream fout("color.out");

int T;

int line1[5005][26],line2[5005][26];	//line[line num][alphabet] : num까지 나온 총 alphabet 개수
int mergeLine[5005][5005];	//mergeLine[line1 에서 다음으로 선택 할 위치][line2 에서 다음으로 선택 할 위치]

string s1,s2;

int checkFirstOrEnd(int l1now,int l2now,int alpha){//결국 (마지막에 나온 위치 - 처음 나온 위치) 를 합산하기 때문에 return이 아래와 같다
	int ret = 0;
	
	if(line1[l1now][alpha]+line2[l2now][alpha] == line1[s1.size()][alpha]+line2[s2.size()][alpha])//지금 나온 알파벳이 마지막일 때
		ret = l1now+l2now;
	
	if(line1[l1now][alpha]+line2[l2now][alpha] == 1)//지금 나온 알파벳이 처음일 때
		ret -= l1now+l2now;
	
	return ret;
	/*
	 * ret > 0 : 알파벳의 마지막 위치
	 * ret < 0 : 알파벳의 처음 위치
	 * ret == 0 : 알파벳이 처음 나오고 마지막으로 나올 때(merge 했을 때 알파벳이 한 번만 나올 경우)
	 * */
}

int main(){
	fin>>T;
	while(T--){
		fin>>s1>>s2;
		/* 
		 * s1는 0부터 s1.size()-1까지 : s1[0]~s1[s1.size()-1]
		 * s2는 0부터 s2.size()-1까지 : s2[0]~s2[s2.size()-1]
		 * */
		for(int i = 0;i < 5001;i++){
			for(int j = 0;j < 26;j++) line1[i][j] = line2[i][j] = 0;
			for(int j = 0;j < 5001;j++) mergeLine[i][j] = INT_MAX;
		}
		for(int i = 1;i <= s1.size();i++){
			//merge[0][0]을 대비해서 line1은 1부터 s1.size()까지 : line1[1]~line1[s1.size()]
			line1[i][s1[i-1]-'A']++;
			
			//line1[현재 위치 까지][알파벳] : 알파벳이 나온 횟수 총합 저장
			for(int j = 0;j < 26;j++) line1[i][j] += line1[i-1][j];
		}
		for(int i = 1;i <= s2.size();i++){
			//merge[0][0]을 대비해서 line2는 1부터 s2.size()까지 : line2[1]~line2[s2.size()]
			line2[i][s2[i-1]-'A']++;

			//line2[현재 위치 까지][알파벳] : 알파벳이 나온 횟수 총합 저장
			for(int j = 0;j < 26;j++) line2[i][j] += line2[i-1][j];
		}
	
		mergeLine[0][0] = 0;	//아직 아무것도 선택을 안한 경우

		/*
		 * line1 : (0)a(1)b(2)c(3)d(4)
		 * line2 : (0)e(1)f(2)g(3)
		 * 예를 들어, mergeLine[2][1] => line1 에서 ab, line2에서 e를 선택해서 merge 했을 때
		 * ab + e 경우와 ae + b 경우가 있다.
		 * ab + e => mergeLine[2][0] 에서 line2를 선택하는 경우
		 * ae + b => mergeLine[1][1] 에서 line1을 선택하는 경우 
		 * */
		for(int i = 0;i <= s1.size();i++){
			for(int j = 0;j <= s2.size();j++){
				if(i > 0) mergeLine[i][j] = min(mergeLine[i-1][j]+checkFirstOrEnd(i,j,s1[i-1]-'A'),mergeLine[i][j]);
				if(j > 0) mergeLine[i][j] = min(mergeLine[i][j-1]+checkFirstOrEnd(i,j,s2[j-1]-'A'),mergeLine[i][j]);
			}
		}

		fout<<mergeLine[s1.size()][s2.size()]<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
