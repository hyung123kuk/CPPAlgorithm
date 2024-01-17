#include <iostream>
#include <stack>
#include <queue>
using namespace std;

namespace SortAlgorithm 
{



	// 1) ���� ���� (Bubble Sort) : �ϳ��� ���ϸ� �ٲ㰣��.
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

	// 2) ���� ���� (Selection Sort) : ���� ���� ���� ã�� ���� �״��� ���� ã�� 2��°... (���� ����)
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

	// 3) ���� ���� (Insertion Sort) : ������� �ϳ��� ������ ��� ������ ã�� �ִ´�. ���ʿ� ���ĵ� �� , �����ʿ� ���� �ؾ��� ����
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

	// 4) �� ���� (Heap Sort) O(NlogN) : priority_queue�� �̿��Ͽ� �����ϴ� ��� (���� Ư���� �̿��� ����)
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


	// 5) ���� ����
	// ���� ���� (Divide and Conquer)
	// - ���� (Divide)  : ������ �� �ܼ��ϰ� �����Ѵ�.
	// - ���� (Conquer) : ���ҵ� ������ �ذ�
	// - ���� (Combine) : ����� �����Ͽ� ������
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

		// ������ ���� ��������, ������ ������ ������ ����
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

	// �� ��Ʈ
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