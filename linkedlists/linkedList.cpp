#include<bits/stdc++.h>
using namespace std;

class LinkedList{
private:
	struct Node{
		int h;
        int k;
        // older version of c++ doesn't set default value as NULL.
		Node* next = NULL;

		Node() {}
		Node(int h, int k): h(h),k(k) {}
	} *Head;

public:
	LinkedList() {
		Head = new Node();
	}

	void addNodeAtEnd(int h, int k) {
		Node* curr = Head;
		while(curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = new Node(h,k);
	}

	void addNodeAtBegining(int h, int k) {
		Node * curr = Head;
		Node * currNext = curr->next;
		curr->next = new Node(h,k);
		curr->next->next = currNext;
	}

	void addNodeInBetween(int h, int k, int index) {
		Node* curr = Head;

		while(index > 0) {
			curr = curr->next;
			index--;
		}

		Node* currNext = curr->next;
		curr->next = new Node(h,k);
		curr->next->next = currNext;
	}
    
    vector<vector<int>> getFinalList() {
        Node* curr = Head;
        curr = curr->next;
        vector<vector<int>> vec;
        
        while(curr != NULL) {
            vec.push_back({curr->h, curr->k});
            curr = curr->next;
        }
        
        return vec;
    }

    void printList() {
    	Node* curr = Head;
    	curr = curr->next;

    	while(curr!=NULL) {
    		cout << curr->h << "," << curr->k << endl;
    		curr = curr->next;
    	}
    }
};

int main() {
	LinkedList linkedList = LinkedList();
	linkedList.addNodeInBetween(7, 0, 0);
	linkedList.addNodeInBetween(7, 1, 1);
	linkedList.printList();
}