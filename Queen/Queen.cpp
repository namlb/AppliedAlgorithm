#include<bits/stdc++.h>
using namespace std;

int n,m;
int holes[200][2];
int result[100];
int cnt;

bool checkOk(int row, int col){
    for(int i = 1; i<row; i++){
        if(result[i] == col || abs(row-i) == abs(col-result[i])) return false;
    }
    for(int i = 1; i<=m; i++){
        if(row==holes[i][0] && col == holes[i][1]) return false;
    }
    return true;
}
Try(int k){
    for(int i = 1; i<=n; i++){
        if(checkOk(k, i)){
            result[k] = i;
            if(k == n){
                cnt++;
            } else {
                Try(k+1);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    while(n!=0 || m!=0){
        cnt = 0;
        for(int i = 1; i<=m; i++){
            cin>>holes[i][0]>>holes[i][1];
        }
        Try(1);
        cout<<cnt<<endl;
        cin>>n>>m;
    };
    return 0;
}
