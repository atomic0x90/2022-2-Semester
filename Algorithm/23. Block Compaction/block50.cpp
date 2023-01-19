#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

#include <iostream>

using namespace std;

ifstream fin("block.inp");
ofstream fout("block.out");

int T,x,y,p,q,N;

bool compareY(const pair<pair<int,int>,pair<int,int> > &a,const pair<pair<int,int>,pair<int,int> > &b){
	//x 축으로 부터 얼마나 떨어져 있는지로 정렬
	//y 위치가 같으면 영점과 가까운 block 우선
	if(a.first.second != b.first.second) return a.first.second < b.first.second;
	else return a.first.first < b.first.first;
}

bool compareX(const pair<pair<int,int>,pair<int,int> > &a,const pair<pair<int,int>,pair<int,int> > &b){
	//y 축으로 부터 얼마나 떨어져 있는지로 정렬
	//x 위치가 같으면 영점과 가까운 block 우선
	if(a.first.first != b.first.first) return a.first.first < b.first.first;
	else return a.first.second < b.first.second;
}

int main(){
	fin>>T;
	while(T--){
		fin>>N;
		vector<pair<pair<int,int>,pair<int,int> > > v(N);
		for(int i = 0;i < N;i++){
			fin>>x>>y>>p>>q;
			v[i] = make_pair(make_pair(x,y),make_pair(p,q));
		}
		


		while(true){
			bool flag = true;
			//down
			sort(v.begin(),v.end(),compareY);

			for(int i = 0;i < N;i++){
				if(v[i].first.second == 0) continue;
				int check = 0;
				for(int j = 0;j < i;j++){
					if(v[j].second.first > v[i].first.first && v[j].first.first < v[i].second.first){
						//내리면 겹치는 경우
						if(check < v[j].second.second){
							check = v[j].second.second;
						}
					}
				}
				int tmp = v[i].first.second - check;
				v[i].first.second -= tmp;
				v[i].second.second -= tmp;
				if(tmp != 0) flag = false;
			}

		
	
			sort(v.begin(),v.end(),compareX);

			for(int i = 0;i < N;i++){
				if(v[i].first.first == 0) continue;
				int check = 0;
				for(int j = 0;j < i;j++){
					if(v[j].second.second > v[i].first.second && v[j].first.second < v[i].second.second){
						//왼쪽으로 밀면 겹치는 경우
						if(check < v[j].second.first){
							check = v[j].second.first;
						}
					}
				}
				int tmp = v[i].first.first - check;
				v[i].first.first -= tmp;
				v[i].second.first -= tmp;
				if(tmp != 0) flag = false;
			}

			if(flag) break;
		}
		int X = 0,Y = 0;
		for(int i = 0;i < N;i++){
			if(v[i].second.first > X) X = v[i].second.first;
			if(v[i].second.second > Y) Y = v[i].second.second;
		}
		fout<<X<<" "<<Y<<endl;
	}

	fin.close();
	fout.close();
	return 0;
}
