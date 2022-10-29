#include<bits/stdc++.h>
using namespace std;

class MinHeap{
private:
	vector<int> heap;

public:
	MinHeap() {
		heap.push_back(0);
	}

	void swap(int i, int j) {
		int a = heap[i];
		heap[i] = heap[j];
		heap[j] = a;
	}

	void push(int num) {
		heap[0]++;
		heap.push_back(num);
		int curr = heap.size()-1;

		while(curr>1 && heap[curr/2]>heap[curr]) {
			swap(curr/2, curr);
			curr = curr/2;
		}
	}

	void pop() {
		if(heap.size()<=1) return;
		else if(heap.size()==2) {
			heap[0]--;
			heap.pop_back();
		}
		else {
			heap[0]--;
			heap[1] = heap.back();
			heap.pop_back();
			int size = heap.size()-1;
			int curr = 1;

			while(2*curr<=size && (2*curr)+1<=size &&
				(heap[curr]>heap[2*curr] || heap[curr]>heap[(2*curr)+1])) {
				if(heap[2*curr] < heap[(2*curr)+1]) {
					swap(curr, 2*curr);
					curr = 2*curr;
				} else {
					swap(curr, (2*curr)+1);
					curr = (2*curr)+1;
				}
			}
		}
	}

	void printHeap() {
		for(int i=0; i<heap.size(); i++) {
			cout << heap[i] << ",";
		}
		cout << endl;
	}
};

int main() {
	MinHeap heap = MinHeap();
	heap.push(6);
	heap.push(9);
	heap.push(10);
	heap.push(15);
	heap.push(12);

	heap.pop();

	heap.printHeap();
}