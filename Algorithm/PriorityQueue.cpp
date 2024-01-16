#include <iostream>
#include <stack>
#include <queue>
using namespace std;

namespace PriortyQueue
{
	template<typename T, typename Container = vector<T>, typename Predicate = less<T>>
	class PriorityQueue
	{
	public:
		void push(const T& data)
		{
			//힙 구조 부터 맞춰 준다.
			_heap.push_back(data);

			int now = static_cast<int>(_heap.size()) - 1;

			//루드 노드까지 도장깨기 시작
			while (now > 0)
			{
				//부모 노드와 비교해서 더 작으면 패배
				int next = (now - 1) / 2;
				if (_predicate(_heap[now], _heap[next]))
					break;

				//데이터 교체
				::swap(_heap[now], _heap[next]);
				now = next;
			}

		}

		void pop()
		{
			_heap[0] = _heap.back();
			_heap.pop_back();

			int now = 0;

			while (true)
			{
				int left = 2 * now + 1;
				int right = 2 * now + 2;

				//리프에 도달한 경우
				if (left >= _heap.size())
					break;

				int next = now;

				//왼쪽과 비교
				if (_predicate(_heap[next], _heap[left]))
					next = left;

				//둘 중 승자를 오른쪽과 비교
				if (right < _heap.size() && _predicate(_heap[next], _heap[right]))
					next = right;

				if (next == now)
					break;

				::swap(_heap[now], _heap[next]);
				now = next;

			}

		}

		T& top()
		{
			return _heap[0];
		}

		bool empty()
		{
			return _heap.empty();
		}

	private:
		Container _heap = {};
		Predicate _predicate = {};
	};

}
