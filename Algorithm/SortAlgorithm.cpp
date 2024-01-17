#include <iostream>
#include <stack>
#include <queue>
using namespace std;

namespace SortAlgorithm 
{



	// 1) 버블 정렬 (Bubble Sort) : 하나씩 비교하며 바꿔간다.
	void BubbleSort(vector<int>& v)
	{
		const int n = (int)v.size();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < (n - 1 - i); j++)
			{
				if (v[j] > v[j + 1])
				{
					int temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
				}
			}
		}
	}

	// 2) 선택 정렬 (Selection Sort) : 가장 작은 것을 찾아 왼쪽 그다음 것을 찾아 2번째... (승자 고르기)
	void SelectionSort(vector<int>& v)
	{
		const int n = (int)v.size();
		for (int i = 0; i < n - 1; i++)
		{
			int bestIdx = i;

			for (int j = i + 1; j < n; j++)
			{
				if (v[j] < v[bestIdx])
					bestIdx = j;
			}

			int temp = v[i];
			v[i] = v[bestIdx];
			v[bestIdx] = temp;
		}
	}

	// 3) 삽입 정렬 (Insertion Sort) : 순서대로 하나씩 순서가 어디에 들어가는지 찾아 넣는다. 왼쪽에 정렬된 것 , 오른쪽에 정렬 해야할 값들
	void InsertionSort(vector<int>& v)
	{
		const int n = (int)v.size();

		for (int i = 1; i < n; i++)
		{
			int inserData = v[i];
			int j;
			for (j = i - 1; j >= 0; j--)
			{
				if (v[j] > inserData)
					v[j + 1] = v[j];
				else
					break;
			}

			v[j + 1] = inserData;
		}
	}

	// 4) 힙 정렬 (Heap Sort) O(NlogN) : priority_queue를 이용하여 정렬하는 방식 (힙의 특성을 이용한 정렬)
	void HeapSort(vector<int>& v)
	{
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int num : v)
			pq.push(num);

		v.clear();

		while (pq.empty() == false)
		{
			v.push_back(pq.top());
			pq.pop();
		}
	}


	// 5) 병합 정렬
	// 분할 정복 (Divide and Conquer)
	// - 분할 (Divide)  : 문제를 더 단순하게 분할한다.
	// - 정복 (Conquer) : 분할된 문제를 해결
	// - 결합 (Combine) : 결과를 취합하여 마무리
	void MergeResult(vector<int>& v, int left, int mid, int right)
	{
		int leftIdx = left;
		int rightIdx = mid + 1;

		vector<int> temp;

		while (leftIdx <= mid && rightIdx <= right)
		{
			if (v[leftIdx] <= v[rightIdx])
			{
				temp.push_back(v[leftIdx]);
				leftIdx++;
			}
			else
			{
				temp.push_back(v[rightIdx]);
				rightIdx++;
			}
		}

		// 왼쪽이 먼저 끝났으면, 오른쪽 나머지 데이터 복사
		if (leftIdx > mid)
		{
			while (rightIdx <= right)
			{
				temp.push_back(v[rightIdx]);
				rightIdx++;
			}
		}
		else
		{
			while (leftIdx <= mid)
			{
				temp.push_back(v[leftIdx]);
				leftIdx++;
			}
		}

		for (int i = 0; i < temp.size(); i++)
			v[left + i] = temp[i];

	}

	void MergeSort(vector<int>& v, int left, int right)
	{
		if (left >= right)
			return;

		int mid = (left + right) / 2;
		MergeSort(v, left, mid);
		MergeSort(v, mid + 1, right);

		MergeResult(v, left, mid, right);
	}

	// 퀵 소트
	int Partition(vector<int>& v, int left, int right)
	{
		int pivot = v[left];
		int low = left + 1;
		int high = right;

		while (low <= high)
		{
			while (low <= right && pivot >= v[low])
				low++;

			while (high >= left + 1 && pivot <= v[high])
				high--;

			if (low < high)
				swap(v[low], v[high]);
		}

		swap(v[left], v[high]);
		return high;
	}
	void QuickSort(vector<int>& v, int left, int right)
	{
		if (left > right)
			return;

		int pivot = Partition(v, left, right);
		QuickSort(v, left, pivot - 1);
		QuickSort(v, pivot + 1, right);
	}

}