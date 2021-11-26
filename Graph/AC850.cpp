//
// Created by Pygmalion on 2021/11/19.
//
/**
 * Dijkstra 堆优化版本
 */
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int N=150010;
int h[N],w[N],ne[N],e[N],idx;
int dist[N];
bool st[N];
int n,m;
typedef pair<int,int> PII;
void add(int a,int b,int c){
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}
int dijkstra(){
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII> > heap;
    heap.push({0,1});
    while(!heap.empty()){
        auto t=heap.top();
        heap.pop();
        int ver=t.second,distance=t.first;
        if(st[ver]) continue;
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];


}
int main(){
    cin>>n>>m;
    memset(h,-1,sizeof h);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    cout<<dijkstra();
}
