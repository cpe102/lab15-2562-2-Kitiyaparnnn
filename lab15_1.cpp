#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void showData(double *,int,int);

int main(){
	srand(time(0));
	const int N = 7, M = 7;
	double data[N][M] = {};
	double result[N] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,result,N,M);
	showData(result,N,1);
}

//Write definition of randData(), showData() and findRowSum()
void randData(double *dPtr,int n,int m)
{
	for(int i=0;i<(n*m);i++){
		*(dPtr+i)=((rand()%101)/100.000);
	}
}

void findRowSum(const double *d,double *r,int n,int m){
	double sum=0;
	for(int i=1;i<=n*m;i++){
		sum += *d;
		if(i%m==0){
			*r=sum;
			r++;
			sum=0;
		}
		else d++;
	}
}

void showData(double *d,int n,int m){
	for(int i=0;i<n*m;i++){
		if(i%m==0) cout<<"\n";
		cout<<d[i]<<"  ";
	}
	cout<<"\n";
}