#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
};

TreeNode *root;

bool pfound, qfound;

TreeNode* findLCA(struct TreeNode* root, int n1, int n2)
{
	// Base case
	if (root == NULL) return NULL;

	if (root->val == n1 || root->val == n2)
		return root;

	// Look for keys in left and right subtrees
	TreeNode *left_lca = findLCA(root->left, n1, n2);
	TreeNode *right_lca = findLCA(root->right, n1, n2);

	// If both of the above calls return Non-NULL, then one key
	// is present in once subtree and other is present in other,
	// So this node is the LCA
	if (left_lca && right_lca)  return root;

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL) ? left_lca : right_lca;
}

int maxdepth(TreeNode *t){
	if (t == NULL)
		return 0;
	int left = 1, right = 1;

	left = left + maxdepth(t->left);
	right = right + maxdepth(t->right);

	return max(left, right);
}


void invertBinaryTree(TreeNode *root){
	
	if (root == NULL) return;

	queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode *Top = q.front();
		q.pop();
		if(Top->left!=NULL)
			q.push(Top->left);
		if (Top->right != NULL)
			q.push(Top->right);

		if(Top->left !=NULL || Top->right != NULL)
			swap(Top->left, Top->right);
		
	}
}

// level order insertion via a queue
void insertNode(TreeNode *t) {
	
	queue<TreeNode*>q;

	q.push(root);
	while (true) {
		TreeNode *Top = q.front();
		q.pop();
		if (Top->left == NULL) {
			Top->left = t;
			break;
		}
		else if (Top->right == NULL) {
			Top->right = t;
			break;
		}
		q.push(Top->left);
		q.push(Top->right);

	}
	
}

//level order traversing via a queue

void traverse() {

	queue<TreeNode*>q;

	q.push(root);
	while (!q.empty()) {
		TreeNode *Top = q.front();
		cout << Top->val << " ";
		q.pop();

		if (Top->left != NULL) q.push(Top->left);
		if (Top->right != NULL) q.push(Top->right);
	}
}

TreeNode* makeNode(int Value) {
	TreeNode *t = new TreeNode;
	t->val = Value;
	t->left = NULL;
	t->right = NULL;

	return t;
}
int main() {
	root = new TreeNode;

	int value = 1;

	root = makeNode(value++);
	insertNode(makeNode(value++));
	insertNode(makeNode(value++));
	insertNode(makeNode(value++));
	insertNode(makeNode(value++));

	traverse();
	cout << endl;

	cout << findLCA(root,4,3)->val;
	cout << endl;
}