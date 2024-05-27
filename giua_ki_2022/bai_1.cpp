//yeulaptrinh.home.blog

#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main(){
	long long n,a[1000001],x=1,kq=0;
	cin>>n;
	for (int i=1;i<=n;i++) 
	   cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		if (a[i]==a[i+1]) x++; 
		else 
		{
			kq=kq+x*(x-1)/2;
			x=1;
		}
	}
	cout<<kq;
}