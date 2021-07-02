#include<cstdio>
#include<iostream>
#define MAX 100
using namespace std;

int W, N, t[MAX][MAX] = {0}, d[MAX][MAX] = {0}, it, v;
int wt[MAX] = {0}, val[MAX] = {0};

int main(){
    scanf("%d%d", &W, &N);
    for(int i = 1; i <= N; ++i){
        scanf("%d%d", &wt[i], &val[i]);
    }
    for(int i = 0; i <= N; ++i){
        for(int j = 0; j <= W; ++j){
            t[i][j] = d[i][j] = 0;
        }
    }
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= W; ++j){
            if(wt[i]<=j){
                if(val[i]+t[i-1][j-wt[i]] > t[i-1][j]){
                    t[i][j] = val[i] + t[i-1][j-wt[i]];
                    d[i][j] = j-wt[i];
                }else{
                    t[i][j] = t[i-1][j];
                    d[i][j] = j;
                }
            }else{
                t[i][j] = t[i-1][j];
                d[i][j] = j;
            }
        }
    }
    cout << "Max Value: " << t[N][W] << endl;
    for(int i = N, j = W; i > 0; --i){
        if(val[i]+t[i-1][j-wt[i]] > t[i-1][j]){
            cout << "Take item " << i << endl;
            j -= wt[i];
        }
    }
    return 0;
}
