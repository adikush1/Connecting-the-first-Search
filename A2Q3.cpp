#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> vec;
vector<vector<long long>> rev_vec;
vector<vector<long long>>vec2;
vector<vector<long long>>vec4;
vector<long long>top_sort;
vector<long long>top_sort1;
long long vis[100000]={0};
long long vis1[100000]={0};

 void dfs(long long p ,long long q){
              vis[p]=1;

     int l;
     for (l=0;l<vec2[p].size();l++ ){
         
          if (vis[vec2[p][l]]==0 ){
            
           dfs(vec2[p][l],q);  
         
     }}
    top_sort.push_back(p);
 }


 void dfs2(long long p ,long long q){
              vis1[p]=1;

     int l;
     for (l=0;l<vec4[p].size();l++ ){
         
          if (vis1[vec4[p][l]]==0 ){
            
           dfs2(vec4[p][l],q);  
         
     }}
    top_sort1.push_back(p);
 }


 int main(){
     long long j,i,n,k,a,b,c,d,e,f;
     cin>>a>>b;
     for (i=0;i<b;i++){
         vector<long long> vec1;
          vector<long long> vec5;

         cin>>k>>n;
         vec1.push_back(k);
         vec1.push_back(n);
         vec5.push_back(n);
         vec5.push_back(k);
         vec.push_back(vec1);
         rev_vec.push_back(vec5);
        
     }
      for (j=0;j<a;j++){
         vector<long long >vec3;
         vec2.push_back(vec3);
         vec4.push_back(vec3);
     }
     for (j=0;j<b;j++){
         c=vec[j][0];
         d=vec[j][1];
         vec2[c-1].push_back(d-1);
         e=rev_vec[j][0];
         j=rev_vec[j][1];
         vec4[e-1].push_back(j-1);
             
         }
     
     
     for (j=0;j<a;j++){
         if (vis[j]==0){
             dfs(j,a);

         }
     }
     int count1=0;
     int arr[a];
    for (i=0;i<a;i++){
        if (vis1[top_sort[i]]==0){
            count1+=1;
        dfs2(top_sort[i],a);
        
        for (j=0;j<top_sort1.size();j++){
            arr[top_sort1[j]]=count1;
        }
        top_sort1.clear();
        
        }
        

    }
    cout<<count1<<endl;
    for (j=0;j<a;j++){
        cout<<arr[j]<<" ";
    }

     return 0;

 }