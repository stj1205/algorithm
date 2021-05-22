#include<iostream>
#include<algorithm>
using namespace std;

int N;
int A[1000+10];
void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
			cin >> A[i];
	}
}

int main(){
	InputData();// 입력받는 부분
	
	sort(A, A+N);
	int sum = 1;
	for(int i=0; i<N; i++){
		if(sum < A[i]) break;
		sum += A[i];
	}
	cout << sum << endl;
	return 0;
}