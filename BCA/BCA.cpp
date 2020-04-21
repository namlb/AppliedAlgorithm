#include<bits/stdc++.h>
using namespace std;

int m,n;
vector<int> spec[11];
int conflict[31][31] = {};
int timeTable[31];
int load[11] = {};
int minMaxLoad = 1e9;


bool checkOk(int a, int k){
    if(load[a]>= minMaxLoad) return false;
    for(int i=0; i<spec[a].size(); i++){
        if(spec[a][i] == k){
            for(int j= 1; j<k; j++){
                if(timeTable[j] == a){
                    if(conflict[j][k] ==1) return false;
                }
            }
            return true;
        }
    }
    return false;
}

void Try(int k){
    for(int i = 1; i<=m; i++){
        if(checkOk(i, k)){
            load[i]++;
            timeTable[k] = i;

            if(k==n){
                int maxLoad = 0;
                for(int j = 1; j<=10; j++){
                    if(load[j]>maxLoad) maxLoad = load[j];
                }
                minMaxLoad = min(minMaxLoad, maxLoad);
            } else {
                Try(k+1);
            }

            load[i]--;
        }
    }
}

int main(){
    int tmp;
    cin>>m>>n;
    for(int i=1; i<=m ; i++){
        cin>>tmp;
        for(int j = 1; j<= tmp; j++){
            int x;
            cin>>x;
            spec[i].push_back(x);
        }
    }
    cin>>tmp;
    int c1, c2;
    for(int i = 1; i<=tmp; i++){
        cin>>c1>>c2;
        conflict[c1][c2] = 1;
        conflict[c2][c1] = 1;
    }
    Try(1);
    cout<<minMaxLoad;
    return 0;
}
