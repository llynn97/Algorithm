#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;



struct Node {
	int idx, x, y;
	Node* left;
	Node* right;
	bool operator<(const Node& other)const {
		if (y == other.y) {
			return x < other.x;
		}
		return y > other.y;
	}
};


vector <Node> tree;
vector <vector<int>> answer(2);

void insert(Node* parent, Node* child) {
	if (child->x < parent->x) {
		if (parent->left == NULL) {
			parent->left = child;
		}
		else {
			insert(parent->left, child);
		}
	}
	else {
		if (parent->right == NULL) {
			parent->right = child;
		}
		else {
			insert(parent->right, child);
		}
	}
}

void visit(Node* node, vector<int>& v) {
	v.push_back(node->idx);
	return;
}

void preorder(Node* node) {
	if (node == NULL) {
		return;
	}
	visit(node, answer[0]);
	preorder(node->left);
	preorder(node->right);
}

void postorder(Node* node) {
	if (node == NULL) {
		return;
	}
	postorder(node->left);
	postorder(node->right);
	visit(node, answer[1]);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	int len = nodeinfo.size();
	tree.resize(len);

	for (int i = 0; i < len; ++i) {
		tree[i] = { i + 1, nodeinfo[i][0], nodeinfo[i][1] };
	}
	sort(tree.begin(), tree.end());

	Node* root = &tree[0];
	for (int i = 1; i < len; ++i) {
		insert(root, &tree[i]);
	}

	preorder(root);
	postorder(root);

	return answer;
}



int main(void) {
	vector<vector<int>> nodeinfo;
	nodeinfo = { {5,3} ,{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2} };
	vector<vector<int>> v=solution(nodeinfo);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

}