#include<bits/stdc++.h>
using namespace std;

int n,m,k,cnt = 0;
int arr[10000];
int result[10000];
int start = 1, stop = 0;
void print_sol(){
    for(int i = 1; i<=m; i++){
        cout<<result[i]<<" ";
    }
}
void Try(int a){
    if(cnt<k){
        if(a>1) start = result[a-1]+1;
        stop = n-m+a;
        for(int i = start; i<=stop; i++){
            result[a] = arr[i];
            if(a==m){
                cnt++;
                if(cnt==k){
                    print_sol();
                    return;
                }
            } else Try(a+1);
        }
    }
}

int main(){
    cin>>n>>m>>k;
    for(int i=1; i<=n;i++){
        arr[i]= i;
    }
    Try(1);
    if(cnt<k) cout<<-1;
}
