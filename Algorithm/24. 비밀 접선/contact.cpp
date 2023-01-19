#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <string>

#include <iostream>

using namespace std;

ifstream fin("contact.inp");
ofstream fout("contact.out");

int T,N,M,K,a,b,w;


int main(){
	fin>>T;
	while(T--){
		fin>>N>>M>>K;
		vector<vector<int> > v(N+1,vector<int>(N+1,12345));
		for(int i = 0;i < M;i++){
			fin>>a>>b>>w;
			v[a][b] = v[b][a] = w;
		}

		for(int i = 0;i < K;i++){
			fin>>a>>b;
			
			vector<int> dist(N+1,12345);
			dist[a] = 0;
			
			priority_queue<pair<int,int> > pq;
			vector<int> path(N+1,-1);
		
			pq.push(make_pair(0,a));
			while(!pq.empty()){
				int cost = -pq.top().first;
				int here = pq.top().second;
				pq.pop();
				if(dist[here] < cost) continue;
				for(int j = 1;j <= N;j++){
					if(v[here][j] == 12345) continue;
					int there = j;
					int nextDist = cost+v[here][j];
					if(dist[there] > nextDist){
						dist[there] = nextDist;
						pq.push(make_pair(-nextDist,there));
						path[there] = here;
					}
					else if(dist[there] == nextDist){
						double pathW = (double)dist[j]/2.0;

						int rootW = 0;
						int root = j;
						int root2W = v[j][here];
						int root2 = here;
						int tmpRoot = a;
						while(true){
							while(true){
								if(rootW >= pathW) break;
								rootW += v[root][path[root]];
								if(rootW >= pathW) break;
								root = path[root];
								if(path[root] == tmpRoot) break;
							}
							bool flag = true;
							while(true){
								if(root2W >= pathW) break;
								if(flag){
									flag = false;
									continue;
								}
								root2W += v[root2][path[root2]];
								if(root2W >= pathW) break;
								root2 = path[root2];
								if(path[root2] == tmpRoot) break;
							}
						
							int r1,r2,r3,r4;
							r1 = root;
							r2 = path[root];
							if(flag){
								r3 = here;
								r4 = j;
							}
							else{
								r3 = root2;
								r4 = path[root2];
							}
							if(min(r1,r2) == min(r3,r4)){
								if(max(r1,r2) > max(r3,r4)){
									path[there] = here;
								}
								tmpRoot = root;
								root = j;
								root2 = here;
								break;
							}
							else if(min(r1,r2) > min(r3,r4)){
								path[there] = here;
								break;
							}
							else break;
						}
					}
				}
			}

			double mid = (double)dist[b]/2.0;
			int now = b;
			double sum = 0;
			while(path[now] != -1){
				sum += v[now][path[now]];
				if(sum == mid){
					fout<<path[now]<<" "<<path[now]<<endl;
					break;
				}
				else if(sum > mid){
					if(path[now] < now) fout<<path[now]<<" "<<now<<endl;
					else fout<<now<<" "<<path[now]<<endl;
					break;
				}

				now = path[now];
			}

		}
	}

	fin.close();
	fout.close();
	return 0;
}
