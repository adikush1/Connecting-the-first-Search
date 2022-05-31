#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> vec;
vector<vector<long long>>vec2;
vector<long long>top_sort;
long long vis[100000]={0};
int flag=0;

 void dfs(long long p ,long long q){
              vis[p]=2;//currently visiting ,for checking cycle

     int l;
     for (l=0;l<vec2[p].size();l++ ){
          if (vis[vec2[p][l]]==2 ){
                 flag=1;
                 return;
             }
         else if (vis[vec2[p][l]]==0 ){
            
           dfs(vec2[p][l],q);  
         
     }}
     vis[p]=1;//fully visited
    top_sort.push_back(p);
 }

 int main(){
     long long j,i,n,k,a,b,c,d;
     cin>>a>>b;
     for (i=0;i<b;i++){
         vector<long long> vec1;
         cin>>k>>n;
         vec1.push_back(k);
         vec1.push_back(n);
         vec.push_back(vec1);
     }
      for (j=0;j<a;j++){
         vector<long long >vec3;
         vec2.push_back(vec3);
     }
     for (j=0;j<b;j++){
         c=vec[j][0];
         d=vec[j][1];
         vec2[c-1].push_back(d-1);

             
         }
     
     
     for (j=0;j<a;j++){
         if (vis[j]==0){
             dfs(j,a);

         }
     }
 if (flag==1){
     cout<<"IMPOSSIBLE";
 }else{
    for (j=0;j<a;j++){
        cout<<top_sort[a-j-1]+1<<" ";
    }}

     return 0;

 }