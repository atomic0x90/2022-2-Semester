#include <fstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <climits>

#include <iostream>
using namespace std;

ifstream fin("freelancer.inp");
ofstream fout("freelancer.out");

int resultI,resultT;
int n,I;
vector<int> check;
vector<pair<pair<int,int>,int> >data;//(i,t),index

bool compare(const pair<pair<int,int>,int> &a, const pair<pair<int,int>,int> &b){
	if(a.first.first/(double)a.first.second > b.first.first/(double)b.first.second) return true;
	else if(a.first.first/(double)a.first.second < b.first.first/(double)b.first.second) return false;
	else{
		if(a.first.second > b.first.second) return true;
		else if(a.first.second < b.first.second) return false;
		else return a.second > b.second;
	}
}

bool checkNode(int now,int sumI,int sumT){
	if(now >= n) return false;
	if(sumT >= resultT) return false;
	if(sumI >= I) return false;

	int j;
	int tsumT;
	int tsumI;

	j = now+1;
       	tsumI = sumI;
	tsumT = sumT;
	while(j < n && tsumI < I && tsumT <= resultT){
		tsumI = tsumI + data[j].first.first;
		tsumT = tsumT + data[j].first.second;
		j++;
	}


	if(tsumI >= I && tsumT <= resultT) return true;
	else return false;
}

void algo(int now,int sumI,int sumT,vector<int> &a){
	if(sumI >= I){
		if(resultT > sumT){
			resultI = sumI;
			resultT = sumT;
			check = a;
		}
		else if(resultT == sumT){
			if(sumI < resultI){
				resultI = sumI;
				check = a;
			}
		}
		return;
	}

	for(int i = now;i < n;i++){
		if(checkNode(i,sumI,sumT)){
			a[i+1] = 1;
			algo(i+1,sumI+data[i+1].first.first,sumT+data[i+1].first.second,a);
			a[i+1] = 0;
			algo(i+1,sumI,sumT,a);
		}
	}
}

int main(){
	fin>>n>>I;
	check.resize(n,0);
	data.resize(n);
	resultI = resultT = INT_MAX;
	int a,b;
	for(int i = 0;i < n;i++){
		fin>>a>>b;
		data[i] = make_pair(make_pair(a,b),i);
	}

	sort(data.begin(),data.end(),compare);

	vector<int> visit(n,0);
	vector<int> check10(10,0);

	algo(-1,0,0,visit);

	for(int i = 0;i < n;i++){
		if(check[i] == 1){
			if(data[i].second < 10) check10[data[i].second] = 1;
		}
	}

	fout<<resultT<<" "<<resultI<<endl;
	for(int i = 0;i < 10;i++) fout<<check10[i]<<" ";
	
	fin.close();
	fout.close();
	return 0;
}
