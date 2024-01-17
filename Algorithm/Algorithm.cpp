#include <iostream>
#include <stack>
#include <queue>
#include <windows.h>
using namespace std;

//메모이제이션 (memoization)
int cashe[50][50];

int combination(int n , int r)
{
	if (r == 0 || n == r)
		return 1;

	// 이미 답을 구한 적 있으면 바로 반환
	int& ret = cashe[n][r];
	if (ret != -1)
		return ret;

	//새로 답을 구해서 캐시에 저장
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
