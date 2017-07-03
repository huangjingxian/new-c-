#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n;
int divider=0;
int check[10]={0};

bool choose(int a, int b){
	if(b>=100000){
		return false;
	}
	int m = a;
	int n = b;
	
	for(int i = 0;i<=4;i++){
		int c = pow(10,4-i);
		check[i]=m/c;
		check[i+5] = n/c;
		m = m-check[i]*c;
		n = n-check[i+5]*c;
	}
	for(int i=0;i<10;i++){
		for(int j = 0;j<10;j++){
			if(i!=j && check[i]==check[j]){
				return false;
			}
		}
	}
	return true;
}


int main(){
	cin >> n;
	for(int i = 1234;i<=98765;i++){
		divider = i*n;
		if(choose(i,divider)){
			for(int i = 5;i<=9;i++){
				cout << char(check[i]+48);
			}
			cout <<" / ";
			for(int i=0;i<=4;i++){
				cout << char(check[i]+48);
			}
			cout << " = " << n << endl;
		}
	}




}