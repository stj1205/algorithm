// B를 N-1로 나누는 경우 나머지가 0인 경우만 최소값이 최대값-1이 될 수 있음
// B + (B/N-1) <= 총 개수
#include <iostream>
using namespace std;

int N, B;
int solmin, solmax;
void InputData(){
    cin >> N >> B;
}

void solve(){
    int val = B / (N-1);
    int ismin = B % (N-1);
    
    solmax = B + val;
    if(ismin == 0) solmin = solmax-1;
    else solmin = solmax;
}

int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    solve();

    cout << solmin << " " << solmax;// 출력하는 부분
    return 0;
}