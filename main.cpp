#include <iostream>
#include <cassert>
#include <vector>
#include <cstdlib>

using namespace std;

// s = start of range to sort
// e = end of range to sort

template<class T>
void msort(vector<T> &a,vector<T> &x, int s, int e) {
    int m=(s+e)/2;
    if(e-s<1)return;
    msort<T>(a,x,s,m);
    msort<T>(a,x,m+1,e);
    int i=s,j=m+1,k=0;
    while(i<=m && j<=e){
        if(a[i]<a[j]){
            x[k]=a[i];
            i++;
            k++;
        }
        else{
            x[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        x[k]=a[i];
        i++;
        k++;
    }
    while(j<=e){
        x[k]=a[j];
        j++;
        k++;
    }
    for(int i=s;i<=e;i++){
        a[i]=x[i-s];
    }
}

template<class T> 
void mergesort(vector<T> & v) {
    vector<T> x(v.size());
    msort<T>(v,x,0,v.size()-1);
}

template<class T>
bool sorted(vector<T> &a) {
	for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] > a[i + 1])return false;
	}
	return true;
}


int main(int argc, char * args[]) {
	vector<int> a;
	for (int i = 0; i < 1000; ++i) a.push_back(50+rand()%100);
	mergesort(a);
	assert(sorted(a));
	vector<int> b;
	for (int i = 0; i < 1001; ++i) b.push_back(-50 + rand() % 100);
	mergesort(b);
	assert(sorted(b));
	vector<int> c;
        c.push_back(2);
	mergesort(c);
	assert(sorted(c));
	vector<int> d;
        for(int i=1;i<6;i++)d.push_back(i);
        cout<<endl;
	mergesort(d);
	assert(sorted(d));

	cout << "All tests passed." << endl;	
}