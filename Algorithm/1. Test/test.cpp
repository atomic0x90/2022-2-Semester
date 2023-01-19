#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <utility>

#include <iostream>

using namespace std;

ifstream fin("test.inp");
ofstream fout("test.out");

int N;
int main(){
	fin>>N;

	vector<pair<int,pair<string,string> > > data;
	vector<pair<int,string> > nameCheck;
	vector<pair<string,int> > check;

	int maxLength = 0;
	string s1,s2,s3;
	for(int i = 0;i < N;i++){
		fin>>s1>>s2>>s3;
		data.push_back(make_pair(stoi(s1),make_pair(s2,s3)));
	}
	sort(data.begin(),data.end());
	for(int i = 0;i < N;i++){
		if(data[i].second.first.length() > maxLength)
			maxLength = data[i].second.first.length();

		bool flag = true;
		for(int j = 0;j < nameCheck.size();j++){
			if(nameCheck[j].second == data[i].second.second){
				flag = false;
				nameCheck[j].first++;
				break;
			}
		}
		if(flag)
			nameCheck.push_back(make_pair(1,data[i].second.second));
	}

	for(int i = 0;i < nameCheck.size();i++){
		if(nameCheck[i].first > 1)
			check.push_back(make_pair(nameCheck[i].second,nameCheck[i].first));
	}

	sort(check.begin(),check.end());

	for(int i = 0;i < N;i++){
		fout.width(5);
		fout.fill('0');
		fout<<data[i].first<<" ";
		
		fout.width(maxLength);
		fout.fill(' ');
		fout<<left<<data[i].second.first<<" ";
		
		
		fout<<right<<data[i].second.second<<endl;
	}
	if(check.size() > 0){
		fout<<endl;
		for(int i = 0;i < check.size();i++){
			fout<<check[i].first<<" "<<check[i].second<<endl;
		}
	}

	fin.close();
	fout.close();
	return 0;
}
