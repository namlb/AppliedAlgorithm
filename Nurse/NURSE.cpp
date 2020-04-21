#include<bits/stdc++.h>
using namespace std;

int result[1000];
int N, K1, K2, series = 0;
int cnt = 0;
bool check(int i, int k){
    if(k==1) return true;
    if(i==1 && series<K2 || i==0 && series>=K1 && ((N-k)>=K1 || k == N)) return true;
    return false;
}

void Try(int k){
    for(int i = 0; i<=1; i++){
        if(check(i, k)){

            result[k] = i;
            int tmp = series;
            if(i==1){
                series++;
            } else series =0;

            if(k==N){
                cnt++;

            } else {
                Try(k+1);
            }

            series = tmp;
        }
    }
}
int main(){
    cin>>N>>K1>>K2;
    Try(1);
    int a = cnt% (int)(pow(10,9)+7);
    cout<<a;
    return 0;
}
