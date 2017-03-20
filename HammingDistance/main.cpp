#include <iostream>
#include <string>
#include "Solution.h"

using namespace std;

int main(){
	int x;
	/*cin >> x;*/
	Solution solution;
	vector<string> input{ "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	vector<int> row_1{ 0,1,5 };
	vector<int> row_2{ 2,4,6 };
	vector<int> row_3{ 3,7,8 };
	vector<vector<int>> board{ row_1, row_2, row_3 };
	vector<pair<int, int>> num0{ { 7, 0 }, { 4, 4 }, { 7, 1 }, { 5, 0 }, { 6, 1 }, { 5, 2 } };
	vector<pair<int, int>> balloon{ { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
	vector<vector<char>> boardMine{ { 'E', 'E', 'E', 'E', 'E' }, { 'E', 'E', 'M', 'E', 'E' }, { 'E', 'E', 'E', 'E', 'E' }, { 'E', 'E', 'E', 'E', 'E' } };
	vector<int> num1{ 1, 2, -1,-2,2,1,-2,1 };
	vector<int> num2{ 0 };
	string s = "abbcccAGG";
	string t = "aa";
	TreeNode* root = new TreeNode(5);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(-3);
	root->left = left;
	root->right = right;	
	ListNode* l1 = new ListNode(5);
	//ListNode* p = new ListNode(2);
	//l1->next = p;
	ListNode* l2 = new ListNode(5);
	int results = solution.findMinArrowShots(balloon);
	cout << results;
	/*for (string i : results){
			cout << i << "  ";
	}*/
	return 0;
}