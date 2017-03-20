#include "Codec.h"

string Codec::serialize(TreeNode* root){
	TreeNode* p = root;
	queue<TreeNode*> q;
	string res;
	if (root == NULL) return res;
	q.push(root);
	while (!q.empty()){
		p = q.front();
		q.pop();
		res += (to_string(p->val) + ',');
		if (p->left) q.push(p->left);
		if (p->right) q.push(p->right);
	}
	return res;
}

TreeNode* Codec::deserialize(string data){
	if (data == "") return NULL;
	vector<int> v;
	int i = 0;
	while (data != ""){
		size_t it = data.find(',');
		v.push_back(atoi(data.substr(0, it).c_str()));
		data = data.substr(it + 1);
	}
	TreeNode* root = new TreeNode(v[0]);
	TreeNode* p = root;
	for (int i = 1; i < v.size(); i++){
		TreeNode* q = new TreeNode(v[i]);
		while (p){
			if (v[i] > p->val){
				if (p->right)
					p = p->right;
				else{
					p->right = q;
					break;
				}
			}
			else{
				if (p->left)
					p = p->left;
				else{
					p->left = q;
					break;
				}
			}
		}
		p = root;
	}
	return root;
}