#include<bits/stdc++.h>
using namespace std;

int n, k, m, cnt=0;
vector<int> result;
vector<int> e[1000];

bool checkOk(int a){
    if(result.size()==0) return true;
    for(int i = 0; i< result.size(); i++){
        if(a == result[i]) return false;
    }
    for(int i = 0; i< e[a].size(); i++){
        if(e[a][i] == result[result.size()-1]) return true;
    }
    return false;
}

void Try(int a){


    for(int i = 1; i<= n; i++){
        if(checkOk(i)){
            result.push_back(i);

            if(a==k){
                cnt++;
            } else if(e[a].size()> 0 || a == k-1){
                Try(a+1);
            }

            result.pop_back();
        }
    }
}


int main(){
    cin>>n>>k>>m;
    k++;
    for(int i= 0; i<m; i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    Try(1);
    cout<<cnt/2;
    return 0;
}
