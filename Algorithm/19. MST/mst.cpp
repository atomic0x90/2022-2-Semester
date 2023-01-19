#include <fstream>
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

ifstream fin("mst.inp");
ofstream fout("mst.out");

int n,m;
vector<int> primResult;
vector<int> kruResult;

bool primCompare(const pair<pair<int,int>,pair<int,int> > &a, const pair<pair<int,int>,pair<int,int> > &b){
	if(a.second.first < b.second.first) return true;
	else if(a.second.first > b.second.first) return false;
	else{
		if(a.second.second < b.second.second) return true;
		else if(a.second.second > b.second.second) return false;
	}
}

bool kruCompare(const pair<pair<int,int>,pair<int,int> > &a, const pair<pair<int,int>,pair<int,int> > &b){
	if(a.second.first < b.second.first) return true;
	else if(a.second.first > b.second.first) return false;
	else return a.second.second < b.second.second;
}

int prim(int start, vector<pair<pair<int,int>,pair<int,int> > > v){
	vector<int> checkRoot(n);
	vector<int> visit(n,-1);
	visit[start] = 0;
	for(int i = 0;i < n;i++) checkRoot[i] = i;

	sort(v.begin(),v.end(),primCompare);
	
	int checkIndex = 0;
	int resultPrim = 0;
	while(*max_element(checkRoot.begin(),checkRoot.end()) != 0){
		for(int index = 0;index < v.size();index++){
			int checkRootF = v[index].first.first;
			int checkRootS = v[index].first.second;
			int rootF = checkRoot[checkRootF];
			int rootS = checkRoot[checkRootS];
			if(v[index].second.first == INT_MAX) continue;
			if(checkRoot[checkRootF] != checkRoot[checkRootS] && !(visit[checkRootF] == -1 && visit[checkRootS] == -1)){
				visit[checkRootF] = visit[checkRootS] = 0;
				resultPrim += v[index].second.first;
				checkRoot[checkRootF] = checkRoot[checkRootS] = rootF < rootS ? rootF : rootS;
				for(int i = 0;i < checkRoot.size();i++){
					if(checkRoot[i] == (rootF > rootS ? rootF : rootS))
						checkRoot[i] = (rootF < rootS ? rootF : rootS);
				}
				primResult.push_back(v[index].second.second);
				v[index].second.first = INT_MAX;
				break;
			}
		}
	}
	return resultPrim;
}

int kruskal(vector<pair<pair<int,int>,pair<int,int> > >v){
	vector<int> checkRoot(n);
	for(int i = 0;i < n;i++) checkRoot[i] = i;
	int resultKruskal = 0;

	sort(v.begin(),v.end(),kruCompare);

	for(int i = 0;i < v.size();i++){
		if(checkRoot[v[i].first.first] != checkRoot[v[i].first.second]){
			resultKruskal += v[i].second.first;

			int highValue,lowValue;
			if(checkRoot[v[i].first.first] < checkRoot[v[i].first.second]){
				highValue = checkRoot[v[i].first.second];
				lowValue = checkRoot[v[i].first.first];
			}
			else{
				highValue = checkRoot[v[i].first.first];
				lowValue = checkRoot[v[i].first.second];
			}

			for(int j = 0;j < checkRoot.size();j++){
				if(checkRoot[j] == highValue) checkRoot[j] = lowValue;
			}
			

			kruResult.push_back(v[i].second.second);
		}
	}

	return resultKruskal;
}

int main(){
	fin>>n>>m;
	vector<pair<pair<int,int>,pair<int,int> > > primData(m);//v1,v2,w,index
	vector<pair<pair<int,int>,pair<int,int> > > kruData(m);

	int v1,v2,w;
	for(int i = 0;i < m;i++){
		fin>>v1>>v2>>w;
		kruData[i] = make_pair(make_pair(v1,v2),make_pair(w,i));
		primData[i] = make_pair(make_pair(v1<v2?v1:v2,v1<v2?v2:v1),make_pair(w,i));
	}
	fout<<"Tree edges by Kruskal algorithm: "<<kruskal(kruData)<<endl;
	for(int i = 0;i < kruResult.size();i++) fout<<kruResult[i]<<endl;

	int index = 0;
	fout<<"Tree edges by Prim algorithm with starting vertex "<<index<<": "<<prim(index,primData)<<endl;
	for(int i = 0;i < primResult.size();i++) fout<<primResult[i]<<endl;
	primResult.clear();

	index = n/2;
	fout<<"Tree edges by Prim algorithm with starting vertex "<<index<<": "<<prim(index,primData)<<endl;
	for(int i = 0;i < primResult.size();i++) fout<<primResult[i]<<endl;
	primResult.clear();

	index = n-1;
	fout<<"Tree edges by Prim algorithm with starting vertex "<<index<<": "<<prim(index,primData)<<endl;
	for(int i = 0;i < primResult.size();i++) fout<<primResult[i]<<endl;
	primResult.clear();

	fin.close();
	fout.close();
	return 0;
}
