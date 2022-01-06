using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithm
{
	class PrioirtyQueue<T> where T : IComparable<T>
	{
		List<T> _heap = new List<T>();

		// O(logN)
		public void Push(T data)
		{
			_heap.Add(data);

			int now = _heap.Count - 1;

			// 맨 아래부터 올라오면서 비교하여 자기에게 맞는 자리 찾는다
			while (now > 0)
			{
				int next = (now - 1) / 2;
				if (_heap[now].CompareTo(_heap[next]) < 0)
					break;

				T temp = _heap[now];
				_heap[now] = _heap[next];
				_heap[next] = temp;

				now = next;
			}
		}

		// O(logN)
		public T Pop()
		{
			T ret = _heap[0];

			int lastIndex = _heap.Count - 1;
			_heap[0] = _heap[lastIndex];
			_heap.RemoveAt(lastIndex);
			lastIndex--;

			int now = 0;
			// 맨 위에서 부터 내려가면서 자기자리 찾는다.
			while (true)
			{
				int left = (now * 2) + 1;
				int right = (now * 2) + 2;

				int next = now;
				if (left <= lastIndex && _heap[next].CompareTo(_heap[left]) < 0)
				{
					next = left;
				}

				if (right <= lastIndex && _heap[next].CompareTo(_heap[right]) < 0)
				{
					next = right;
				}

				if (next == now) break;

				T temp = _heap[now];
				_heap[now] = _heap[next];
				_heap[next] = temp;

				now = next;
			}

			return ret;
		}

		public int Count { get { return _heap.Count; } }
	}
}
