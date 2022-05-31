#include <bits/stdc++.h>
using namespace std;
vector<vector<long long>> vec;
vector<vector<long long>>vec2;
vector<long long>top_sort;
long long vis[100000]={0};
int flag=0;
long long count1=0,count2;
vector<long long >dist;

 void dfs(long long p ,long long u){
              vis[p]=1;//currently visiting

     int l;
     for (l=0;l<vec2[p].size();l++ ){
count1=count1+1;
        if (vec2[p][l]==u ){
            dist.push_back(count1);}
            
            if (vis[vec2[p][l]]==0){
             dfs(vec2[p][l],u);

            }
           
            
           
         
     }
    top_sort.push_back(p);
    count1=0;
 }
void dfs2(long long p ,long long u,long long h){
              vis[p]=1;//currently visiting

     int l;
     sort(vec2[p].begin(),vec2[p].end());
      top_sort.push_back(p);
     for (l=0;l<vec2[p].size();l++ ){
         count2=count2+1;

        if (vec2[p][l]==u && count2==h){
            
            return;
            }
            
            if (vis[vec2[p][l]]==0){
                
                
             dfs2(vec2[p][l],u,h); 
            }
            
           
         
     }
    
     count2=0;
 }
 int main(){
     long long j,i,n,k,a,b,c,d,r,t;
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
         cout<<"Enter the two vertices : ";
         cin>>r>>t;
     
     
     dfs(r-1,t-1);
 if (dist.size()==0){
     cout<<"IMPOSSIBLE";
 }else{
    sort(dist.begin(),dist.end());
    cout<<"Min Distance : "<<dist[0]<<endl;
    cout<<"Max Distance : "<<dist[dist.size()-1]<<endl;
    cout<<"No of Paths  : "<<dist.size()<<endl;
    
    dfs2(r-1,t-1,dist[dist.size()-1]);
    for(i=0;i<top_sort.size();i++){
        if (top_sort[top_sort.size()-i-1]+1==t){
            cout<<t;
            break;
            }
        cout<<top_sort[top_sort.size()-i-1]+1<<" ";
    }
 }

     return 0;

 }