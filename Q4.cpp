
#include <bits/stdc++.h>
#include<queue>
using namespace std;
long long ad_mat[10000][10000];
int main(){
    cout<<"Enter the number of nodes : ";
    int j,i,n,k;
    cin>>n;
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>ad_mat[i][j];
        }

    }
    queue <int> q;
    
    
    int flag=0;
   for (i=0;i<n;i++){
       int covered[n]={0};
       covered[i]=1;
       q.push(i);
       
       while (!q.empty()){
        int flag=0;
        j=q.front();
        q.pop();
    for (k=0;k<n;k++){
        if (ad_mat[j][k]==1 && covered[k]==0 ){
            flag=1;
            q.push(k);
             covered[k]=1;   
        }
        if ( ){
        flag=1;
        break;}

    }
    if (flag==1)break;}
    if (flag==1)break;

   }
   if (flag==1){
       cout<<"Yes";
   }
   else if (flag==0){
       cout<<"No";
   }



    return 0;
    }