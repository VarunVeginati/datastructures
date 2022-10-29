#include<bits/stdc++.h>
using namespace std;

class Trie{
private:
    long max_profit = 0;
    struct Node {
        long profit_sum=0;
        int bit_value = -1;
        Node* left;
        Node* right;

        Node() : bit_value(-1), left(nullptr), right(nullptr) {}
        Node(int bit) : bit_value(bit), left(NULL), right(NULL) {} 
    } *Root, *curr;

public:
    Trie() {
        Root = new Node();
    }

    void insert(string s, long profit) {
        curr = Root;

        for(char c: s) {
            if(c == '0' && curr->left == NULL) {
                curr->left = new Node(0);
            } else if(c=='1' && curr->right == NULL) {
                curr->right = new Node(1);
            }
            curr = c=='0'?curr->left:curr->right;
            curr->profit_sum += profit;
        }
    }

    long getMaxProfit(string k) {
        queue<Node*> q;
        Node* trieTree = Root;

        if(trieTree->left!=NULL) q.push(trieTree->left);
        if(trieTree->right!=NULL) q.push(trieTree->right);

        int k_index = -1;

        while(!q.empty()) {
            int size = q.size();
            long curr_level_profit = 0;
            k_index++;

            for(int i=0; i<size; i++) {
                Node* curr = q.front();
                q.pop();

                if(k[k_index]=='1') {
                    if(curr->left!=NULL) q.push(curr->left);
                    if(curr->right!=NULL) q.push(curr->right);
                    if(curr->bit_value==0) {
                        curr_level_profit += curr->profit_sum;
                    }
                } else {
                	if(curr->bit_value==0) {
                    	if(curr->left!=NULL) q.push(curr->left);
                    	if(curr->right!=NULL) q.push(curr->right);
                	}
                }
            }

            max_profit = max(max_profit, curr_level_profit);
        }

        return max_profit;
    }
};

string getBinary(int n) {
    string s = "";

    while(n>0) {
        s += to_string(n%2);
        n=n/2;
    }

    reverse(s.begin(), s.end());

    return s;
}

int main() {
	Trie trie = Trie();

	vector<int> indicators = {2,3,1,5,9};
	vector<int> profit = {1,2,6,1,5};
	int k = 3;

	string k_binary = getBinary(k+1);
	vector<string> indicators_binary;
	int max_string_len = k_binary.length();

	for(int i=0; i<indicators.size(); i++) {
		string str = getBinary(indicators[i]);
		max_string_len = max(max_string_len, (int)str.length());
		indicators_binary.push_back(str);
	}

	for(int i=0; i<indicators.size(); i++) {
		if(indicators_binary[i].length()<max_string_len) {
			int l = max_string_len-indicators_binary[i].length();
			string s(l, '0');
			indicators_binary[i] = s+indicators_binary[i];
		}
	}

	if(k_binary.length() < max_string_len) {
			int l = max_string_len-k_binary.length();
			string s(l, '0');
			k_binary = s+k_binary;
	}

	for(int i=0; i<indicators.size(); i++) {
		trie.insert(indicators_binary[i], profit[i]);
	}

	cout << trie.getMaxProfit(k_binary) << endl;
}