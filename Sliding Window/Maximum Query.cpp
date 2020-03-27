#include <bits/stdc++.h>

using namespace std;

void printKMax(int arr[], int n, int k)
{
	/// Create a Double Ended Queue, Q that will store indexes of array elements
	/// The queue will store indexes of useful elements in every window and it will
	/// maintain decreasing order of values from front to rear in Q, i.e.,
	/// arr[Q.front[]] to arr[Q.rear()] are sorted in decreasing order
	deque<int> Q(k);

	/// Process first k (or first window) elements of array
	int i;
	for (i = 0; i < k; ++i) {
		/// For every element, the previous smaller elements are useless so
		/// remove them from Q
		while ((!Q.empty()) && arr[i] >= arr[Q.back()]) {
			Q.pop_back(); // Remove from rear
		}

		/// Add new element at rear of queue
		Q.push_back(i);
	}

	/// Process rest of the elements, i.e., from arr[k] to arr[n-1]
	for (i = k; i < n; ++i) {
		/// The element at the front of the queue is the largest element of
		/// previous window, so print it
		cout << arr[Q.front()] << " ";

		/// Remove the elements which are out of this window
		while ((!Q.empty()) && Q.front() <= i - k) {
			/// Remove from front of queue
			Q.pop_front();
		}

		/// Remove all elements smaller than the currently
		/// being added element (remove useless elements)
		while ((!Q.empty()) && arr[i] >= arr[Q.back()]) {
			Q.pop_back();
		}

		/// Add current element at the rear of Q
		Q.push_back(i);
	}

	/// Print the maximum element of last window
	cout << arr[Q.front()];
}

int main()
{
	int arr[] = { 12, 1, 78, 90, 57, 89, 56 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int k = 3;
	printKMax(arr, n, k);
	return 0;
}
