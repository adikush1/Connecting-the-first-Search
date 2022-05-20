//BFS

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

    }//taking adjacency matrix as input
    queue <int> q;

    int covered[n]={0};
    int distance[n]={0};// array for tracking distance from the node "s" . 
    int s; // starting node
    cout<<"Enter the node value s (vertex) to start with: ";
    cin>>s;
    covered[s]=1;
    cout<<"BFS Traversal : "<<s;
    q.push(s );
     int   count=1;
     
    while (!q.empty()){
        int flag=0;
        j=q.front();
        q.pop();
    for (k=0;k<n;k++){
        if (ad_mat[j][k]==1 && covered[k]==0 ){
            flag=1;
            q.push(k);
             distance[k]=distance[j]+1;
            cout<<k;
             covered[k]=1;   
        }

    }}
    for (j=0;j<n;j++){
        if (j!=s && distance[j]==0){
        cout<<endl<<"Distance of node valued "<< j<< " from s is : -1";

    }
    else {
         cout<<endl<<"Distance of node valued "<< j<< " from s is :"<<distance[j];

    }
    }

    return 0;
}







    
