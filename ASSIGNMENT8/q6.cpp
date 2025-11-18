#include <iostream>
using namespace std;

class MaxHeap{
public:
    int a[100];
    int size=0;

    void insert(int x){
        a[size]=x;
        int i=size;
        size++;
        while(i>0 && a[(i-1)/2] < a[i]){
            swap(a[(i-1)/2], a[i]);
            i=(i-1)/2;
        }
    }

    int extractMax(){
        if(size==0) return -1;
        int mx=a[0];
        a[0]=a[size-1];
        size--;
        heapify(0);
        return mx;
    }

    void heapify(int i){
        int mx=i,l=2*i+1,r=2*i+2;
        if(l<size && a[l]>a[mx]) mx=l;
        if(r<size && a[r]>a[mx]) mx=r;
        if(mx!=i){ swap(a[i],a[mx]); heapify(mx); }
    }
};

int main(){
    MaxHeap pq;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        pq.insert(x);
    }
    cout<<pq.extractMax()<<endl;
    cout<<pq.extractMax()<<endl;
}
