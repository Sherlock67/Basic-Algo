#include<iostream>
#include<cstdio>
#include<map>
#include<climits>
#define Max 100
using namespace std;

int adj[Max][Max] = {0};
int d[Max] = {0};
bool finished[Max] = {0};
multimap<int, int> min_heap;

void relax(int n1, int n2){
    if(d[n2] > d[n1] + adj[n1][n2])
        d[n2] = d[n1] + adj[n1][n2];
}

void dijs(int s, int n){
    for(int i = 1; i <= n; ++i){
        d[i] = INT_MAX;
    }
    d[s] = 0;
    //build min
    multimap<int, int>::iterator it;
    for(int j = 0; j < n; j++){
        if(finished[j] == 0)
            min_heap.insert(make_pair(d[j], j));
    }
    while(min_heap.size()){
        it = min_heap.begin();
        int u = it->second;
        finished[u] = 1;
        for(int j = 1; j <= n; ++j){
            if(adj[u][j] > 0){
                relax(u,j);
            }
        }
        min_heap.clear();
        for(int k = 0; k < n; k++){
            if(finished[k] == 0)
                min_heap.insert(make_pair(d[k], k));
        }
    }
}

int main(){
    int n, n1, n2, w, nodes = 0;
    FILE *in = fopen("input.txt", "r");
    fscanf(in, "%d", &n);
    for(int i = 0; i < n; ++i){
        fscanf(in, "%d%d%d", &n1, &n2, &w);
        adj[n1][n2] = w;
        if(n1 > n2 && n1 > nodes){
            nodes = n1;
        }else if(n1 < n2 && n2 > nodes){
            nodes = n2;
        }
    }
    dijs(1, nodes);
    for(int i = 1; i <= n; ++i){
        printf("%d ", d[i]);
    }
    cout << endl;
    return 0;
}
