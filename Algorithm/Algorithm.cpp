#include <iostream>
#include <stack>
#include <queue>
#include <windows.h>
using namespace std;

//�޸������̼� (memoization)
int cashe[50][50];

int combination(int n , int r)
{
	if (r == 0 || n == r)
		return 1;

	// �̹� ���� ���� �� ������ �ٷ� ��ȯ
	int& ret = cashe[n][r];
	if (ret != -1)
		return ret;

	//���� ���� ���ؼ� ĳ�ÿ� ����
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}


int main()
{
	::memset(cashe, -1, sizeof(cashe));

	auto start = GetTickCount64();

	combination(45, 6);

	auto end = GetTickCount64();

	cout << end - start << "ms" << endl;
}
