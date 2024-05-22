#include<vector>
#include<iostream>
using namespace std;
void merge(vector<int>a,vector<int>b,vector<int>&arr){
     int i=0;
     int j=0;
     int k=0;
     while(i<a.size()&&j<b.size()){
        if(a[i]>b[j]) arr[k++]=a[i++];
        else arr[k++]=b[j++];
     }
     if(i==a.size()) while(j<b.size()) arr[k++]=b[j++]; 
     if(j==b.size())  while(i<a.size()) arr[k++]=a[i++];
    
     
}
void merge_sort(vector<int>&v){
    int n=v.size();
    if(n==1) return ;
    int n1=n/2,n2=n-n1;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[i+n1];
    }
    merge_sort(a);
    merge_sort(b);
    merge(a,b,v);

}
int main(){
    vector<int> v={4,5,3,8,1};
    int n=v.size();
    merge_sort(v);
    for(int i=0;i<n;i++){
        cout<<v[i];
    }

}
