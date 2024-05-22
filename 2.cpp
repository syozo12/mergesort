//count the inversions
#include<vector>
#include<iostream>
using namespace std;
int inversion(vector<int>a,vector<int>b){
    int c=0;
    int i=0;
    int j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]>(2*b[j])){
             c+=(a.size()-i);
             j++;
        }
        else i++;
    }
    return c;
}
void merge(vector<int>a,vector<int>b,vector<int>&arr){
     
     int i=0;
     int j=0;
     int k=0;
     while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]) arr[k++]=a[i++];
        else arr[k++]=b[j++];
     }
     if(i==a.size()) while(j<b.size()) arr[k++]=b[j++]; 
     if(j==b.size())  while(i<a.size()) arr[k++]=a[i++];
    
     
}
int merge_sort(vector<int>&v){
    int c=0;
    int n=v.size();
    if(n==1) return 0 ;
    int n1=n/2,n2=n-n1;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[i+n1];
    }
    c+=merge_sort(a);
    c+=merge_sort(b);
    c+=inversion(a,b);
    merge(a,b,v);
    a.clear();
    b.clear();
    return c;

}
int main(){
    vector<int> v={5,3,1,2};
    int n=v.size();
    cout<<merge_sort(v)<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i];
    }

}
