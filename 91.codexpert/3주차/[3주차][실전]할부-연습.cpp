// B�� N-1�� ������ ��� �������� 0�� ��츸 �ּҰ��� �ִ밪-1�� �� �� ����
// B + (B/N-1) <= �� ����
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
    InputData();// �Է¹޴� �κ�

    // ���⼭���� �ۼ�
    solve();

    cout << solmin << " " << solmax;// ����ϴ� �κ�
    return 0;
}