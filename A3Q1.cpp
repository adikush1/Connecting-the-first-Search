#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
int parent[100000];
int rank1[100000]={0};
void make(int n){
    for (int i=1;i<=n;i++){
        parent[i]=i;
    }}
int find_par(int n){
    if(n==parent[n]){
    return n;}
    return parent[n]=find_par(parent[n]);
}
void union_1(int a,int b)
{
    a=find_par(a);
    b=find_par(b);
    if (a!=b){
        if (rank1[a]>rank1[b]){
             parent[b]=a;
        }
        else if (rank1[a]<rank1[b]){
            parent[a]=b;
        }
        else{
            parent[a]=b;
            rank1[b]++;
        }
    } 
}
int main(){
    int l,k,j,o,p,g,h;
    string s1;
    cin>>l>>k;
    make(l);
    for (j=0;j<k;j++){
        cin>>s1;
        cin>>g>>h;
        if (s1[0]=='u'){
        union_1(g,h);}
        
        else{ 

        if (find_par(g)==find_par(h)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
return 0;
}