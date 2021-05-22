#include <iostream>
using namespace std;

int N;
int A[30 + 10];
int sol[30 + 10];

void InputData(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
}

void OutputData(){
	cout << N << endl;
	for(int i=0;i<N;i++){
		cout << sol[i] << " ";
	}
	cout << endl;
}

int main(){
	InputData();//	입력 함수

	//	코드를 작성하세요
	int index = 0;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(sol[index] == 0) break;
			index = (index + 1) % N;
		}
		cout << index << " " << i << " " << A[i] << endl;
		sol[index] = A[i];
		index = (index + A[i]) % N;
	}
	
	OutputData();//출력 
	return 0;
}