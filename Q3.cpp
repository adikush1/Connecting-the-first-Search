
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
    
    int covered[n]={0};
    int s; // starting node
    cout<<"Enter the node value (vertex) to start with: ";
    cin>>s;
    covered[s]=1;
    cout<<"BFS Component 1 : "<<s;
    q.push(s );
     
     while (!q.empty()){
        int flag=0;
        j=q.front();
        q.pop();
    for (k=0;k<n;k++){
        if (ad_mat[j][k]==1 && covered[k]==0 ){
            flag=1;
            q.push(k);
            cout<<k;
             covered[k]=1;   
        }

    }}
    int   count=1;
    cout<<endl;
    for (i=0;i<n;i++){
        if (covered[i]==0){
            count+=1;
            covered[i]=1;
            cout<<"BFS Component "<<count<<" : "<<i<<endl;
            q.push(i);
            while (!q.empty()){
        int flag=0;
        j=q.front();
        q.pop();
    for (k=0;k<n;k++){
        if (ad_mat[j][k]==1 && covered[k]==0 ){
            flag=1;
            q.push(k);
            cout<<k;
             covered[k]=1;   
        }

    }}



        }
    }
    

return 0;
}