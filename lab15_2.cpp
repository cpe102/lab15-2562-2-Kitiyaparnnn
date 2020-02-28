#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void randData(double *,int,int);

void findColSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,result,N,M); 
	showData(result,1,M);
}

//Write definition of randData(), showData() and findColSum()
void randData(double *dPtr,int n,int m)
{
	for(int i=0;i<(n*m);i++){
		*(dPtr+i)=((rand()%101)/100.000);
	}
}

void findColSum(const double *d,double *r,int n,int m){
	for(int i=0;i<m;i++){
		double sum=0;
		for(int j=0;j<n;j++)
		{
			sum += *(d+i+j*n);
		}
		*(r+i)=sum; 
	}
}

void showData(double *d,int n,int m){
	for(int i=0;i<n*m;i++){
		if(i%m==0) cout<<"\n";
		cout<<d[i]<<"  ";
	}
	cout<<"\n";
}