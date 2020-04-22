#include<bits/stdc++.h>
#include<string>
using namespace std;

int m,n,minimum = 10000000, totalPrice=0, minWage = 100000000;
int t[100],T[100], D[100], a[100];
vector<int> listPatient[100],result[100];

bool isNotFull(int i, int k){
    if(a[i] + t[k] <= T[i]) return true;
    return false;
}

void Try(int k){
    for(int i = 1; i<=m; i++){
        if(isNotFull(i,k)){
            listPatient[i].push_back(k);

            a[i]+=t[k];
            totalPrice += t[k]*D[i];
            if(k==n){
                if(totalPrice<minimum){
                    minimum = totalPrice;
                    for(int j = 0;j<7; j++){
                        result[j] = listPatient[j];
                    }
                }
            }else if(totalPrice + (n-k)*minWage < minimum){
                Try(k+1);
            }

            listPatient[i].pop_back();
            a[i]-=t[k];
            totalPrice -= t[k]*D[i];
        }
    }
}

int main(){
    cin>>m;
    for(int i = 1; i<=m; i++){
        cin>>T[i];
    }
    for(int i = 1; i<=m; i++){
        cin>>D[i];
        if(D[i]<minWage) minWage = D[i];
    }
    cin>>n;
    for(int i = 1; i<=n; i++){
        cin>>t[i];
    }
    Try(1);
    if(minimum == 10000000){
        cout<<-1;
    } else {
        cout<<minimum<<endl;
        for(int i = 1; i<=m ; i++){
            cout<<result[i].size()<<" ";
            for(int j = 0; j< result[i].size(); j++) cout<<result[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
