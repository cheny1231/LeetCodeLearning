#include "Solution.h"
#include <string>
#include <array>
#include <sstream>
#include <algorithm>
#include <map>
#include <stack>


 int Solution::hammingDistance(int x, int y) {
	int r_x, r_y;
	int cnt = 0;
	while (x > 0 || y > 0){
		r_x = x % 2;
		x = x >> 1;
		r_y = y % 2;
		y = y >> 1;
		if (r_x != r_y)
			cnt++;
	}
	return cnt;
}

 int Solution::findComplement(int num){
	 int mask = ~0;
	 while (mask & num)
		 mask <<= 1;
	 mask = ~mask;
	 return mask ^ num;
 }

 vector<string> Solution::findWords(vector<string>& words){
	 vector<char> row_1{ 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' };
	 vector<char> row_2{ 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' };
	 vector<char> row_3{ 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
	 vector<vector<char>> rows{ row_1, row_2, row_3 };
	 vector<string> results;
	 bool flag = true;
	 int row;
	 for each (string var in words){
		 for (int i = 0; i < 3; i++){
			 if (find(rows[i].begin(), rows[i].end(), (char)tolower(var.c_str()[0])) != rows[i].end()){
				 row = i;
				 break;
			 }
		 }
		 for (int i = 1; i < var.length(); i++){
			 if (find(rows[row].begin(), rows[row].end(), (char)tolower(var.c_str()[i])) == rows[row].end()){
				 flag = false;
				 break;
			 }
		 }

		 if (flag)
			 results.push_back(var);
		 else
			 flag = true;
	 }
	 return results;
 }
 
 int Solution::countBattleships(vector<vector<char>>& board){
	 int cnt = 0;
	 vector<array<int,2>> result;
	 for (int row = 0; row < board.size(); row++){
		 for (int col = 0; col < board[row].size(); col++){
			 if (board[row][col] == 'X'){
				 array<int,2> pos = { row, col };
				 if (find(result.begin(), result.end(), pos) == result.end()){
					 result.push_back(pos);
					 cnt++;
					 int tmpr = row;
					 int tmpc = col;
					 while (++tmpr < board.size() && board[tmpr][col] == 'X'){
						 array<int, 2> pos = { tmpr, col };
						 result.push_back(pos);
					 }
					 while (++tmpc < board[row].size() && board[row][tmpc] == 'X'){
						 array<int, 2> pos = { row, tmpc };
						 result.push_back(pos);
					 }
				 }

			 }	 
		 }
	 }
	 return cnt;
 }

 vector<int> Solution::countBits(int num){
	 vector<int> results{ 0 };
	 if (num == 0) return results;
	 results.push_back(1);
	 for (int i = 2; i <= num; i++){
		 int n = (int)log2(i);
		 int dis = i - pow(2, n);
		 if (dis < pow(2, n - 1)){
			 results.push_back(results[i - pow(2, n - 1)]);
		 }
		 else
			 results.push_back(results[i - pow(2, n - 1)] + 1);
	 }
	 return results;
 }

 vector<int> Solution::nextGreaterElement(vector<int>& findNums, vector<int>& nums){
	 vector<int> results;
	 for (int i : findNums){
		 auto it = find(nums.begin(), nums.end(), i);
		 while (it != nums.end()){
			 if (*it > i){
				 results.push_back(*it);
				 break;
			 }
			 ++it;
		 }
		 if (it == nums.end()) results.push_back(-1);
	 }
	 return results;
 }

 vector<string> Solution::fizzBuzz(int n){
	 vector<string> results;
	 for (int i = 1; i <= n; i++){
		 string str;
		 if (i % 3 == 0){
			 str.append("Fizz");
		 }
		 if (i % 5 == 0){
			 str.append("Buzz");
		 }
		 if (str == ""){
			 str.append(to_string(i));
		 }
		 results.push_back(str);
	 }
	 return results;
 }

 string Solution::reverseString(string s){
	 int i = 0; 
	 int j = s.length() - 1;
	 while (i < j){
		 swap(s[i++], s[j--]);
	 }
	 return s;
 }

 int Solution::islandPerimeter(vector<vector<int>>& grid){
	 int perimeter = 0;
	 for (int i = 0; i < grid.size(); i++){
		 for (int j = 0; j < grid[0].size(); j++){
			 if (grid[i][j] == 1){
				 if (i == 0 || grid[i - 1][j] == 0)
					 perimeter++;
				 if (i == grid.size() - 1|| grid[i + 1][j] == 0)
					 perimeter++;
				 if (j == 0 || grid[i][j - 1] == 0)
					 perimeter++;
				 if (j == grid[0].size() - 1 || grid[i][j + 1] == 0)
					 perimeter++;
			 }
		 }
	 }
	 return perimeter;
 }

 bool Solution::detectCapitalUse(string word){
	 for (int i = 0; i < word.length(); i++){
		 if (word[i] > 64 && word[i] < 91){
			 if (i != 0 && (word[i - 1] > 96 || word[i + 1] > 96))
				 return false;
		 }
	 }
	 return true;
 }

 int Solution::findBottomLeftValue(TreeNode* root){
	 queue<TreeNode*> qu;
	 TreeNode* p = root;
	 qu.push(root);
	 while (!qu.empty()){
		 p = qu.front();
		 qu.pop();
		 if (p->right != NULL) qu.push(p->right);
		 if (p->left != NULL) qu.push(p->left);
	 }
	 return p->val;
 }

 int Solution::findMaxConsecutiveOnes(vector<int>& nums){
	 int cnt = 0;
	 int tmp = 0;
	 for (int i : nums){
		 tmp = i ? (tmp + 1) : 0;
		 cnt = (tmp > cnt) ? tmp : cnt;
	 }
	 return cnt;
 }

 bool Solution::canWinNim(int n){
	 return n % 4 > 0;
 }

 int Solution::numberOfArithmeticSlices(vector<int>& A){
	 int cnt = 0;
	 int tmp = 2;
	 if (A.size() < 3) return 0;
	 for (int i = 0; i < A.size() - 2; i++){
		 if ((A[i + 2] - A[i + 1]) == (A[i + 1] - A[i])){
			 tmp++;
		 }
		 else{
			 cnt = cnt + (tmp - 2) * (tmp - 1) / 2;
			 tmp = 2;
		 }
	 }
	 cnt = cnt + (tmp - 2) * (tmp - 1) / 2;
	 return cnt;
 }

 vector<pair<int, int>> Solution::reconstructQueue(vector<pair<int, int>>& people){
	 vector<pair<int, int>> results;
	 auto compare = [](pair<int, int> p1, pair<int, int> p2)
	 {return (p1.first > p2.first) || (p1.first == p2.first && p1.second <= p2.second); };
	 sort(people.begin(), people.end(), compare);
	 for (int i = 0; i < people.size(); i++){
		 results.insert(results.begin() + people[i].second, people[i]);		
	 }
	 return results;
 }

 vector<int> Solution::findDisappearedNumbers(vector<int>& nums){
	 vector<int> results;
	 if (nums.size() == 0) {
		 results.push_back(0);
		 return results;
	 }
	 sort(nums.begin(), nums.end());
	 for (int i = 0; i < nums.size() - 1; i++){
		 if (nums[i + 1] - nums[i] > 1){
			 for (int j = 1; j < (nums[i + 1] - nums[i]); j++){
				 results.push_back(nums[i] + j);
			 }
		 }
	 }
	 if (nums[nums.size() - 1] < nums.size()){
		 for (int j = 0; j < (nums.size() - nums[nums.size() - 1]); j++){
			 results.push_back(nums[nums.size() - 1] + j + 1);
		 }
	 }
	 if (nums[0] > 1){
		 for (int j = 1; j < nums[0]; j++){
			 results.push_back(j);
		 }
	 }
	 return results;
 }
 
 int Solution::singleNumber(vector<int>& nums){
	int result = 0;
	for (int i = 0; i<nums.size(); i++){
		result ^= nums[i];
	}
	return result;
}

 int node_depth(TreeNode* root, TreeNode* node){
	 int d;
	 if (root == NULL) return 0;
	 if (node == root) return 1;
	 d = node_depth(root->left, node);
	 if(d > 0) return d + 1;
	 d = node_depth(root->right, node);
	 if(d > 0) return d + 1;
	 return 0;
 }
 
 vector<int> Solution::largestValues(TreeNode* root){
	 int layer = 0;
	 vector<int> results;
	 if (root == NULL) return results;
	 TreeNode* p = root;
	 queue<TreeNode*> q;
	 q.push(root);
	 int mini = (numeric_limits<int>::min)();
	 while (!q.empty()){
		 int qsize = q.size();
		 int max = mini;
		 for (int i = 0; i < qsize; i++){
			 p = q.front();
			 q.pop();
			 if (p->left) q.push(p->left);
			 if (p->right) q.push(p->right);
			 if (p->val > max) max = p->val;
		 }
		 results.push_back(max);		
	 }
	 return results;
 }

 int Solution::findPoisonedDuration(vector<int>& timeSeries, int duration){
	 if (timeSeries.size() == 0) return 0;
	 int result = timeSeries.size() * duration;
	 for (int i = 0; i < timeSeries.size() - 1; i++){
		 if (timeSeries[i + 1] - timeSeries[i] < duration)
			 result = result - duration + timeSeries[i + 1] - timeSeries[i];
	 }
	 return result;
 }

 void PostOrder(TreeNode* T)//ºóÐòµÝ¹é±éÀú
 {
	 if (T != NULL)
	 {
		 PostOrder(T->left);
		 PostOrder(T->right);
		 if (T->left != NULL && T->right != NULL)
			 T->val += T->left->val + T->right->val;
		 else if (T->left != NULL)
			 T->val += T->left->val;
		 else if (T->right != NULL)
			 T->val += T->right->val;

	 }
 }

 vector<int> Solution::findFrequentTreeSum(TreeNode* root){
	 vector<int> results;
	 if (root == NULL) return results;
	 stack<TreeNode*> stk;
	 TreeNode* p = root;
	 TreeNode* visited = NULL;
	 map<int, int> m;
	 while (p || !stk.empty()){
		 while (p){
			 stk.push(p);
			 p = p->left;
		 }
		 p = stk.top();
		 //p has no right child, or p.right child has been visited, then visit p
		 if (p->right == NULL || p->right == visited){
			 if (p->left != NULL && p->right != NULL)
				 p->val += p->left->val + p->right->val;
			 else if (p->left != NULL)
				 p->val += p->left->val;
			 else if (p->right != NULL)
				 p->val += p->right->val;
			 if (m.count(p->val)) m[p->val]++;
			 else m.insert(pair<int, int>(p->val, 1));
			 visited = p;
			 stk.pop();
			 p = NULL;
		 }
		 else
			 p = p->right;
	 }
	 int max = 0;
	 for (pair<int, int> i : m){
		 if (max < i.second){
			 max = i.second;
			 results.clear();
			 results.push_back(i.first);
		 }
		 else if (max == i.second)
			 results.push_back(i.first);
	 }
	 return results;
 }

 vector<int> Solution::findDuplicates(vector<int>& nums){
	 vector<int> results;
	 if (nums.size() == 0) return results;
	 for (int i = 0; i < nums.size(); i++){
		 int num = abs(nums[i]) - 1;
		 if (nums[num] > 0) nums[num] = -nums[num];
		 else results.push_back(num);
	 }
	 return results;
 }

 int Solution::minMoves2(vector<int>& nums){
	 sort(nums.begin(), nums.end());
	 int med = nums[nums.size() / 2];
	 int result = 0;
	 for (int i : nums){
		 result += abs(med - i);
	 }
	 return result;
 }

 int Solution::maxDepth(TreeNode* root){
	 queue<TreeNode*> q;
	 TreeNode* p;
	 int depth = 0;
	 if (root == NULL) return depth;
	 q.push(root);
	 while (!q.empty()){
		 int qsize = q.size();
		 for (int i = 0; i < qsize; i++){
			 p = q.front();
			 q.pop();
			 if (p->left != NULL) q.push(p->left);
			 if (p->right != NULL) q.push(p->right);
		 }
		 depth++;
	 }
	 return depth;
 }

 int Solution::getSum(int a, int b){
	 int sum = 0;

	 while (a != 0 || b != 0){
		 if (((a >> 1) << 1) != a){
			 if (((b >> 1) << 1) != b){
				 sum = (sum | 1) << 1;
			 }
			 else{
				 sum = (sum << 1) | 1;
			 }
		 }
		 else{
			 if (((b >> 1) << 1) != b){
				 sum = (sum << 1) | 1;
			 }
			 else{
				 sum = sum << 1;
			 }
		 }
		 a = a >> 1;
		 b = b >> 1;
	 }
	 return sum;
 }

 char Solution::findTheDifference(string s, string t){
	 if (s == "") return t[0];
	 sort(s.begin(), s.end());
	 sort(t.begin(), t.end());
	 for (int i = 0; i < s.length(); i++){
		 if (s[i] != t[i])
			 return t[i];
	 }
	 return t[t.size() - 1];
 }

 int counts(int N, int pos, vector<int>& used){
	 int ans = 0;
	 if (pos > N) return 1;
	 for (int i = 1; i <= N; i++){
		 if (used[i] == 0 && (i % pos == 0 || pos % i == 0)){
			 used[i] = 1;
			 ans += counts(N, pos + 1, used);
			 used[i] = 0;
		 }
	 }
	 return ans;
 }

 int Solution::countArrangement(int N){
	 int cnt = 0;
	 vector<int> arrange(N + 1, 0);
	 return counts(N, 1, arrange);
 }

 vector<vector<char>> Solution::updateBoard(vector<vector<char>>& board, vector<int>& click){
	 int m = board.size(), n = board[0].size();
	 int x = click[0], y = click[1];
	 if (board[x][y] == 'M'){
		 board[x][y] = 'X';
		 return board;
	 }
	 else {
		 int cnt = 0;
		 vector<int> tmp;
		 if (board[x][y] == 'E'){
			 for (int i = -1; i < 2; i++){
				 for (int j = -1; j < 2; j++){
					 if (x + i > -1 && x + i < m && y + j > -1 && y + j < n){
						 if (board[x + i][y + j] == 'M')
							 cnt++;
					 }
				 }
			 }
			 if (cnt == 0){
				 board[x][y] = 'B';
				 for (int i = -1; i < 2; i++){
					 for (int j = -1; j < 2; j++){
						 if (i == 0 && j == 0) continue;
						 if (x + i > -1 && x + i < m && y + j > -1 && y + j < n){
							 tmp.clear();
							 tmp.push_back(x + i);
							 tmp.push_back(y + j);
							 board = updateBoard(board, tmp);
						 }
					 }
				 }
				 return board;
			 }
			 else{
				 board[x][y] = cnt + '0';
				 return board;
			 }
		 }
		 else
			 return board;
	 }
	 return board;
 }

 int Solution::addDigits(int num){
	 int result = num;
	 while (result > 9){
		 result = 0;
		 while (num > 0){
			 result += num % 10;
			 num = num / 10;
		 }
		 num = result;
	 }
	 return result;
 }

 TreeNode* Solution::invertTree(TreeNode* root){
	 if (root == NULL) return root;
	 TreeNode* p = root;
	 TreeNode* tmp;
	 queue<TreeNode*> qNode;
	 qNode.push(root);
	 while (!qNode.empty()){
		 int qSize = qNode.size();
		 for (int i = 0; i < qSize; i++){
			 p = qNode.front();
			 qNode.pop();
			 tmp = p->left;
			 p->left = p->right;
			 p->right = tmp;
			 if (p->left != NULL){
				 qNode.push(p->left);
			 }
			 if (p->right != NULL) {
				 qNode.push(p->right);
			 }
		 }
	 }
	 return root;

	 // Recursive Solution
	 /*if (root == NULL) return root;
	 TreeNode* p = root;
	 TreeNode* tmp = root->left;
	 root->left = invertTree(root->right);
	 root->right = invertTree(tmp);
	 return root;*/
 }

 bool compare(pair<char, int> p1, pair<char, int> p2){
	 return p1.second > p2.second;
 }

 string Solution::frequencySort(string s){
	 if (s == "") return s;
	 map<char, int> m;
	 string result;
	 for (char c : s){
		 if (m.find(c) != m.end()){
			 m[c]++;
		 }
		 else
			 m.insert(pair<char,int>(c, 1));
	 }
	 vector<pair<char, int>> v(m.begin(), m.end());
	 auto compare = [](pair<char, int> p1, pair<char, int> p2){
		 return p1.second > p2.second;};
	 sort(v.begin(), v.end(), compare);
	 for (pair<char, int> i : v){
		 result.append(i.second, i.first);
	 }
	 return result;
 }

 vector<int> Solution::singleNumberIII(vector<int>& nums){
	 vector<int> results{ 0, 0 };
	 int dif = 0;
	 for (int i : nums)
		 dif ^= i;
	 dif &= -dif;
	 for (int i : nums){
		 if (dif & i)
			 results[0] ^= i;
		 else
			 results[1] ^= i;
	 }
	 return results;
 }

 vector<int> Solution::constructRectangle(int area){
	 int root = (int)sqrt(area);
	 while (area % root != 0) root--;
	 return vector<int>{ area / root, root };
 }

 int Solution::getMinimumDifference(TreeNode* root){
	 TreeNode* p = root;
	 queue<TreeNode*> qNode;
	 vector<int> v;
	 int min;
	 qNode.push(root);
	 while (!qNode.empty()){
		 p = qNode.front();
		 qNode.pop();
		 v.push_back(p->val);
		 if (p->left != NULL)
			 qNode.push(p->left);
		 if (p->right != NULL)
			 qNode.push(p->right);
	 }
	 int size = v.size();
	 sort(v.begin(), v.end());
	 min = v[1] - v[0];
	 for (int i = 0; i < size - 1; i++){
		 if (v[i + 1] - v[i] < min)
			 min = v[i + 1] - v[i];
	 }
	 return min;
 }

 vector<string> Solution::findRelativeRanks(vector<int>& nums){
	 vector<int> sorted;
	 vector<string> results;
	 int n = nums.size();
	 if (n == 1) return vector<string>{"Gold Medal"};
	 for (int i = 0; i < n; i++){
		 sorted.push_back(nums[i]);
	 }
	 sort(sorted.begin(), sorted.end());
	 map<int, string> m;
	 m.insert(pair<int, string>{sorted[n - 1], "Gold Medal"});
	 m.insert(pair<int, string>{sorted[n - 2], "Silver Medal"});
	 if (n > 2){
		 m.insert(pair<int, string>{sorted[n - 3], "Bronze Medal"});
		 if (n > 3){
			 for (int i = n - 4; i >= 0; i--){
				 m.insert(pair<int, string>{sorted[i], to_string(n - i)});
			 }
		 }
	 }
	 for (int i : nums){
		 results.push_back(m[i]);
	 }

	 return results;
 }

 void Solution::moveZeroes(vector<int>& nums){
	 int pos = -1;
	 for (int i = 0; i < nums.size(); i++){
		 if (pos < 0 && nums[i] == 0 ) pos = i;
		 else if (pos >= 0 && nums[i] != 0 ){
			 swap(nums[i], nums[pos]);
			 pos++;
		 }
	 }
 }

 vector<int> Solution::twoSum(vector<int>& numbers, int target){
	 int end = numbers.size();
	 vector<int> results;
	 int sum;
	 for (int i = 0; i < end; i++){
		 for (int j = i + 1; j < end; j++){
			 if (numbers[i] + numbers[j] == target){
				 return vector<int> {i+1, j+1};
			 }
			 if (numbers[i] + numbers[j] > target){
				 end = j;
				 break;
			 }

		 }
	 }

	 //int left = 0, right = numbers.size() - 1;
	 //int v = numbers[left] + numbers[right];
	 //while (v != target) {		
//         if (v > target) {
		//	 right--;
		// }
		// else {
		//	 left++;
		// }
	 // int v = numbers[left] + numbers[right];
	 //}
	 //return vector<int> {left + 1, right + 1};
 }

 int Solution::findContentChildren(vector<int>& g, vector<int>& s){
	 int result = 0;
	 int j = g.size() - 1;
	 sort(g.begin(), g.end());
	 sort(s.begin(), s.end());
	 for (int i = s.size() - 1; i > -1; i--){
		 while (j > -1){
			 if (s[i] < g[j]){
				 j--;
			 }
			 else{
				 j--;
				 result++;
				 break;
			 }
		 }
	 }
	 return result;
 }//Greedy algorithm

 int Solution::minMoves(vector<int>& nums){
	 int result = 0;
	 int min = nums[0];
	 for (int i : nums){
		 min = i > min ? min : i;
	 }
	 for (int i : nums){
		 result += (i - min);
	 }
	 return result;
 }// We need Maths sometimes~

 vector<int> Solution::productExceptSelf(vector<int>& nums){
	 int n = nums.size();
	 vector<int> results(n,1);
	 int from_begin = 1;
	 int from_end = 1;
	 for (int i = 0; i < n; i++){
		 results[i] *= from_begin;
		 from_begin *= nums[i]; 
		 results[n - i - 1] *= from_end;
		 from_end *= nums[n - i - 1];
	 }
	 return results;
 }

 vector<int> Solution::topKFrequent(vector<int>& nums, int k){
	 vector<int> results;
	 map<int, int> m;
	 for (int i : nums){
		 m[i]++;
	 }
	 priority_queue<pair<int, int>> pq;
	 for (auto i : m){
		 pq.push(pair<int, int>{i.second, i.first});
	 }
	 for (int i = 0; i < k; i++){
		 results.push_back(pq.top().second);
		 pq.pop();
	 }
	 return results;
 }// Dont't be afraid~~~

 vector<int> Solution::findDiagonalOrder(vector<vector<int>>& matrix){
	 vector<int> results;
	 if (matrix.empty()) return results;
	 int m = matrix.size();
	 int n = matrix[0].size();
	 int i = 0, j = 0;
	 int cnt = 0;
	 results.push_back(matrix[0][0]);
	 while (i < m - 1 || j < n - 1){
		 if (i == 0 && j + 1 < n){
			 j++;
			 for (; j > -1; j--){
				 if (i < m){
					 results.push_back(matrix[i++][j]);
				 }
				 else
					 break;
			 }
			 j++;
			 i--;
		 }
		 else if (j == n - 1 && i + 1 < m){
			 i++;
			 for (; j > -1; j--){
				 if (i < m){
					 results.push_back(matrix[i++][j]);
				 }
				 else
					 break;
			 }
			 j++;
			 i--;
		 }
		 else if (j == 0 && i + 1 < m ){
			 i++;
			 for (; i > -1; i--){
				 if (j < n){
					 results.push_back(matrix[i][j++]);
				 }
				 else 
					 break;
			 }
			 i++;
			 j--;
		 }
		 else if (i == m - 1 && j + 1 < n){
			 j++;
			 for (; i > -1; i--){
				 if (j < n){
					 results.push_back(matrix[i][j++]);
				 }
				 else
					 break;
			 }
			 i++;
			 j--;
		 }
	 }
	 return results;
 }//Not so bad actually~~

 string Solution::convertToBase7(int num){
	 if (num == 0) return "0";
	 int n = (int)(log(abs(num)) / log(7)) + 1;
	 string result(n, '0');
	 if (num < 0){
		 result.insert(0,"-");
		 num = -num;
		 n++;
	 }
	 int tmp; 
	 for (int i = 1; i <= n; i++){
		 result[n - i] += num % 7;
		 num = num / 7;
	 }
	 return result;

	 //string result;
	 //int x = abs(num);
	 //while (x){
		// result = to_string(x % 7) + result;
		// x = x / 7;
	 //}
	 //if (num < 0){
		// result = "-" + result;
	 //}
	 //return result;	 
 }// Not so good T^T

 bool Solution::canConstruct(string ransomNote, string magazine){
	 for (int i = 0; i < ransomNote.size(); i++){
		 size_t found = magazine.find(ransomNote[i]);
		 if (found != string::npos)
			 magazine[found] = '0';
		 else
			 return false;
	 }
	 return true;
 }

 vector<int> Solution::nextGreaterElements(vector<int>& nums){
	 stack<int> s;
	 map<int, int> m;
	 int n = nums.size();
	 vector<int> results(n,-1);
	 for (int i = 0; i < 2 * n; i++){
		 if (m.find(i % n) != m.end()) continue;
		 while (!s.empty() && nums[i%n] > nums[s.top()]){
			 results[s.top()] = nums[i % n];
			 s.pop();		 
		 }
		 if (results[i % n] != -1) continue;
		 if (i < n)
			 s.push(i);
	 }
	 return results;
 }

 int Solution::sumOfLeftLeaves(TreeNode* root){
	 int sum = 0;
	 if (root){
		 if (root->right) sum += sumOfLeftLeaves(root->right);
		 if (root->left){
			 if (root->left->left == NULL && root->left->right == NULL)
				sum += root->left->val;
			 sum += sumOfLeftLeaves(root->left);
		 }
	 }
	 return sum;
 }

 vector<int> Solution::intersection(vector<int>& nums1, vector<int>& nums2){
	 vector<int> results;
	 unordered_set<int> s(nums1.begin(),nums1.end());
	 for (int i : nums2){
		 if (s.count(i)){
			 results.push_back(i);
			 s.erase(i);
		 }			 
	 }
	 return results;
 }

 ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2){
	 if (l1->val == 0) return l2;
	 if (l2->val == 0) return l1;
	 stack<int> s1;
	 stack<int> s2;
	 int cnt1 = 0, cnt2 = 0;
	 int num1 = 0, num2 = 0;
	 ListNode* p = l1;
	 while (p){
		 s1.push(p->val);
		 p = p->next;
	 }
	 p = l2;
	 while (p){
		 s2.push(p->val);
		 p = p->next;
	 }
	 p = l1;
	 int sum = 0;
	 ListNode* result = new ListNode(0);
	 p = result;
	 while (!s1.empty() || !s2.empty()){
		 if (!s1.empty()){
			 sum += s1.top();
			 s1.pop();
		 }
		 if (!s2.empty()){
			 sum += s2.top();
			 s2.pop();
		 }
		 p->val = sum % 10;
		 ListNode* q = new ListNode(sum / 10);
		 q->next = p;
		 p = q;
		 sum = sum / 10;
	 }
	 return p->val == 0 ? p->next : p;
 }

 int Solution::firstUniqChar(string s){
	 int result = s.length();
	 map<char, pair<int, int>> m;
	 for (int i = 0; i < s.length(); i++){
		 m[s[i]].first = i;
		 m[s[i]].second++;
	 }
	 for (pair<char, pair<int, int>> i : m){
		 if (i.second.second == 1){
			 result = result < i.second.first ? result : i.second.first;
		 }
	 }
	 if (result == s.length()) return -1;
	 return result;
 }

 int Solution::totalHammingDistance(vector<int>& nums){
	 int n = nums.size();
	 int result = 0;
	 int tmp = 1;
	 int cnt = 0;
	 for (int i = 0; i < 32; i++){
		 for (int j : nums){
			 if (j & tmp) cnt++;
		 }
		 tmp = tmp << 1;
		 result += cnt * (n - cnt);
		 cnt = 0;
	 }
	 return result;
 }

 int Solution::maxProfit(vector<int>& prices){
	 int result = 0;
	 if (prices.size() == 0) return result;
	 for (int i = 0; i < prices.size() - 1; i++){
		 int change = prices[i + 1] - prices[i];
		 if (change > 0)
			 result += change;
	 }
	 return result;
 }

 int Solution::titleToNumber(string s){
	 int result = 0;
	 for (int i = 0; i < s.length(); i++){
		 result = result * 26 + (s[i] - 'A' + 1);
	 }
	 return result;
 }

 int Solution::magicalString(int n){
	 if (n == 0) return 0;
	 if (n < 4) return 1;
	 vector<int> v{ 1, 2, 2 };
	 int pos = 2;
	 int result = 1;
	 int sum = 3;
	 while (sum < n){
		 if (pos % 2 == 0){
			 for (int i = 0; i < v[pos]; i++){
				 v.push_back(1);
			 }
			 if (sum + v[pos] > n)
				 result += 1;
			 else
				 result += v[pos];
		 }
		 else{
			 for (int i = 0; i < v[pos]; i++){
				 v.push_back(2);
			 }
		 }
		 sum += v[pos];
		 pos++;
	 }
	 return result;

	/* string S = "122";
	 int i = 2;
	 while (S.size() < n)
		 S += string(S[i++] - '0', S.back() ^ 3);
	 return count(S.begin(), S.begin() + n, '1');*/
 }

 void Solution::deleteNode(ListNode* node){
	 ListNode* p = node->next;
	 *node = *p;
	 delete p;
 }

 bool Solution::isSameTree(TreeNode* p, TreeNode* q){
	 if (p == NULL && q == NULL) return true;
	 else if (p && q);
	 else return false;
	 bool result;
	 if (p->val != q->val) return false;
	 if (p->left && q->left) result = isSameTree(p->left, q->left);
	 if (p->right && q->right) result = isSameTree(p->right, q->right);
	 return result;
 }

 int Solution::countNumbersWithUniqueDigits(int n){
	 int result = 0;
	 vector<int> v{1, 9, 9, 8, 7, 6, 5, 4, 3, 2};
	 if (n > 9) return 8877691;
	 for (int i = 1; i < 10; i++){
		 v[i] *= v[i - 1];
	 }
	 for (int i = 0; i <= n; i++){
		 result += v[i];
	 }
	 return result;
 }

 int Solution::majorityElement(vector<int>& nums){
	 sort(nums.begin(), nums.end());
	 return nums[(nums.size() - 1) / 2];

	 //int major = nums[0], count = 1;
	 //for (int i = 1; i<nums.size(); i++){
		// if (count == 0){
		//	 count++;
		//	 major = nums[i];
		// }
		// else if (major == nums[i]){
		//	 count++;
		// }
		// else count--;

	 //}
	 //return major;
 }

 bool Solution::isAnagram(string s, string t){
	 vector<int> v(26,0);
	 for (char c : s){
		 v[c - 'a']++;
	 }
	 for (char c : t){
		 v[c - 'a']--;
	 }
	 for (int i : v){
		 if (i != 0)
			 return false;
	 }
	 return true;
 }

 int Solution::integerBreak(int n){
	 if (n == 2) return 1;
	 if (n == 3) return 2;
	 int rem = n % 3;
	 int num = n / 3;
	 if (rem == 0)
		 return pow(3, num);
	 if (rem == 1)
		 return pow(3, num - 1) * 4;
	 if (rem == 2)
		 return pow(3, num) * 2;
 }

 int Solution::fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D){
	 map<int, int> m;
	 for (int i : A){
		 for (int j : B){
			 m[i + j]++;
		 }
	 }
	 int result = 0;
	 for (int i : C){
		 for (int j : D){
			 result += m[-i - j];
		 }
	 }
	 return result;
 }

 int Solution::longestPalindrome(string s){
	 map<char, int> m;
	 for (char c : s){
		 m[c]++;
	 }
	 int result = 0;
	 int flag = 0;
	 for (pair<char, int> i : m){
		 result += i.second;
		 if (i.second % 2 != 0){
			 result--;
			 flag = 1;
		 }
	 }
	 return result + flag;
 }

 vector<int> Solution::inorderTraversal(TreeNode* root){
	 vector<int> result;
	 stack<TreeNode*> s;
	 TreeNode* cur = root;
	 while (!s.empty() || cur != NULL){
		 while (cur){
			 s.push(cur);
			 cur = cur->left;
		 }
		 cur = s.top();
		 s.pop();
		 result.push_back(cur->val);
		 cur = cur->right;
	 }
	 return result;
 }

 vector<string> Solution::readBinaryWatch(int num){
	 vector<string> result;
	 for (int h = 0; h < 12; h++){
		 for (int m = 0; m < 60; m++){
			 if (bitset<10>(h << 6 | m).count() == num){
				 result.push_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));
			 }
		 }
	 }
	 return result;
 }

 bool Solution::containsDuplicate(vector<int>& nums){
	 unordered_set<int> s;
	 for (int i : nums){
		 if (s.count(i))
			 return true;
		 else
			 s.insert(i);
	 }
	 return false;
 }

 int Solution::findTargetSumWays(vector<int>& nums, int S){
	 int sum = accumulate(nums.begin(), nums.end(), 0);
	 if ((sum + S) % 2 != 0 || sum < S) return 0;
	 int s = (sum + S) >> 1;
	 vector<int> dp(s + 1, 0);
	 dp[0] = 1;
	 for (int n : nums){
		 for (int i = s; i >= n; i--){
			 dp[i] += dp[i - n];
		 }
	 }
	 return dp[s];
 }

 bool Solution::canPartition(vector<int>& nums){
	 int sum = accumulate(nums.begin(), nums.end(), 0);
	 if (sum & 1) return false;
	 int s = sum >> 1;
	 vector<int> dp(s + 1, 0);
	 dp[0] = 1;
	 for (int n : nums){
		 for (int i = s; i >= n; i--){
			 dp[i] += dp[i - n];
		 }
	 }
	 return (dp[s] != 0);
 }

 int Solution::romanToInt(string s){
	 int result = 0;
	 map<char, int> m = { { 'I', 1 },
	 { 'V', 5 },
	 { 'X', 10 },
	 { 'L', 50 },
	 { 'C', 100 },
	 { 'D', 500 },
	 { 'M', 1000 } };
	 for (int i = 0; i < s.length() - 1; i++){
		 if (m[s[i]] < m[s[i + 1]])
			 result -= m[s[i]];
		 else
			 result += m[s[i]];
	 }
	 result += m[s[s.length() - 1]];
	 return result;
 }

 ListNode* Solution::reverseList(ListNode* head){ 
	 if (head == NULL) return head;
	 ListNode* q = head;
	 stack<ListNode*> s;
	 while (q){
		 s.push(q);
		 q = q->next;
	 }
	 q = s.top();
	 s.pop();
	 ListNode* p = q;
	 while (!s.empty()){
		 q->next = s.top();
		 q = s.top();
		 s.pop();		
	 }
	 q->next = NULL;
	 return p;
 }

 bool Solution::isSubsequence(string s, string t){
	 size_t it = 0;
	 for (char c : s){
		 it = t.find_first_of(c, it);
		 if (it > t.length())
			 return false;
		 it++;
	 }
	 return true;
 }

 int Solution::findMaximumXOR(vector<int>& nums){
	 int max = 0;
	 int mask = 0;
	 for (int i = 31; i > -1; i--){
		 mask |= (1 << i);
		 unordered_set<int> s;
		 for (int num : nums){
			 s.insert(num & mask);
		 }

		 int tmp = max | (1 << i);
		 for (int prefix : s){
			 if (s.find(tmp ^ prefix) != s.end()){
				 max = tmp;
				 break;
			 }
		 }
	 }
	 return max;
 }

 vector<int> Solution::intersect(vector<int>& nums1, vector<int>& nums2){
	 vector<int> results;
	 map<int, int> m;
	 for (int num : nums1){
		 m[num]++;
	 }
	 for (int num : nums2){
		 if (m.find(num) != m.end() && m[num] > 0){
			 m[num]--;
			 results.push_back(num);
		 }
	 }
	 return results;
 }

 int Solution::missingNumber(vector<int>& nums){
	 int n = nums.size();
	 nums.push_back(n+1);
	 for (int i = 0; i < n; i++){
		 if (nums[i] < n + 1)
			 nums[nums[i]] = nums[nums[i]] + n + 2;
		 else
			 nums[nums[i] - n - 2] = nums[nums[i] - n - 2] + n + 2;
	 }
	 for (int i = 0; i < n + 1; i++){
		 if (nums[i] < n + 2)
			 return i;
	 }

	 /*int xor = 0, i = 0;
	 for (i = 0; i < nums.length; i++) {
		 xor = xor ^ i ^ nums[i];
	 }

	 return xor ^ i;*/
 }

 vector<int> Solution::preorderTraversal(TreeNode* root){ 
	 stack<TreeNode*> s;
	 vector<int> res;
	 if (root == NULL) return res;
	 TreeNode* p = root;
	 s.push(root);
	 while (!s.empty()){
		 p = s.top();
		 s.pop();
		 res.push_back(p->val);
		 if (p->right) s.push(p->right);
		 if (p->left) s.push(p->left);
	 }
	 return res;
 }

 struct compare_kth{
	 bool operator()(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b){
		 return a.first>b.first;
	 }
 };

 int Solution::kthSmallest(vector<vector<int>>& matrix, int k){
	 pair<int, pair<int, int>> res;
	 int cnt = 0;
	 priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare_kth> pq;
	 for (int i = 0; i < matrix.size(); i++)
		 pq.push(pair<int, pair<int, int>> { matrix[0][i], pair<int, int>{0, i}});
	 while (cnt < k){
		 res = pq.top();
		 pq.pop();
		 cnt++;
		 if (res.second.first < matrix.size() - 1)
			 pq.push(pair<int, pair<int, int>> { matrix[res.second.first + 1][res.second.second], pair<int, int>{res.second.first + 1, res.second.second}});

	 }
	 return res.first;
 }

 string Solution::intToRoman(int num){
	 string res = "";
	 char* c[4][10] = {
		 { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
		 { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
		 { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
		 { "", "M", "MM", "MMM" }
	 };
	 res += c[3][num / 1000]; 
	 res += c[2][(num % 1000) / 100];
	 res += c[1][(num % 100) / 10];
	 res += c[0][num % 10];
	 return res;
 }

 int getDistance(pair<int, int> p1, pair<int, int> p2){
	 int dx = p1.first - p2.first;
	 int dy = p1.second - p2.second;
	 return dx * dx + dy * dy;
 }

 int Solution::numberOfBoomerangs(vector<pair<int, int>>& points){
	 int res = 0;
	 int n = points.size();
	 for (int i = 0; i < n; i++){
		 map<int, int> m;
		 for (int j = 0; j < n; j++){
			 int dis = getDistance(points[i], points[j]);
			 m[dis]++;
		 }
		 for (pair<int, int> i : m){
			 res += (i.second * (i.second - 1));
		 }
	 }
	 return res;
 }

 int totalNQueensHelper(vector<int> &v, int n, int cnt){
	 bool obey = true;
	 for (int col = 0; col < v.size(); col++){
		 v[n] = col;
		 for (int m = 0; m < n; m++){
			 if (v[m] == v[n] || v[m] - v[n] == m - n || v[m] - v[n] == n - m){
				 obey = false;
				 break;
			 }
		 }
		 if (obey){
			 if (n == v.size() - 1){
				 return cnt + 1;
			 }
			 cnt = totalNQueensHelper(v, n + 1, cnt);
		 }
		 else
			 obey = true;
	 }
	 return cnt;
 }

 int Solution::totalNQueens(int n){
	 vector<int> v(n, -1);
	 return totalNQueensHelper(v, 0, 0);
 }

 void combinationSum3Helper(vector<vector<int>> &res, vector<int> &v, int num, int k, int n){
	if (n < 10 && k == 1){
		for (int i = 0; i < num; i++){
			if (n <= v[i]) return;
		}
		v[num] = n;
		vector<int> v1 (v);
		res.push_back(v1);
		return;
	}
	else if (n > 9 && k == 1){
		return;
	}
	else{
		for (int i = num > 0 ? (v[num - 1] + 1) : 1; i < 10 && i < n; i++){
			bool flag = false;
			for (int j = 0; j < num; j++){
				if (i == v[j]){ flag = true; break; }
			}
			if (flag) continue;
			v[num] = i;
			combinationSum3Helper(res, v, num + 1, k - 1, n - i);
		}
	}
	return;
 }

 vector<vector<int>> Solution:: combinationSum3(int k, int n){
	 vector<vector<int>> res;
	 vector<int> v(k, 0);
	 combinationSum3Helper(res, v, 0, k, n);
	 return res; 
 }

 string Solution::originalDigits(string s) {
	 string res;
	 vector<int> v;
	 map<char, int> m;
	 for (char c : s){
		 m[c]++;
	 }
	 res.append(m['z'], '0');
	 res.append(m['o'] - m['z'] - m['w'] - m['u'], '1');
	 res.append(m['w'], '2');
	 res.append(m['h'] - m['g'], '3');
	 res.append(m['u'], '4');
	 res.append(m['f'] - m['u'], '5');
	 res.append(m['x'], '6');
	 res.append(m['s'] - m['x'], '7');
	 res.append(m['g'], '8');
	 res.append(m['i'] - m['g'] - m['x'] - m['f'] + m['u'], '9');
	 return res;
 }

 int Solution::maxProduct(vector<string>& words){
	 int n = words.size();
	 vector<int> v(n, 0);
	 int max = 0;
	 for (int i = 0; i < n; i++){
		 for (char c : words[i]){
			 v[i] |= 1 << (c - 'a');
		 }
	 }
	 for (int i = 0; i < n - 1; i++){
		 for (int j = i + 1; j < n; j++){
			 if((v[i] & v[j]) == 0){
				 int tmp = words[i].length() * words[j].length();
				 max = max > tmp ? max : tmp;
			 }
		 }
	 }
	 return max;
 }

 void generateParenthesisHelper(vector<string> &results, string &s, int i, int left, int right){
	 if (left == 0 && right == 0){
		 results.push_back(s);
		 return;
	 }
	 if (left == right){
		 s[i] = '(';
		 generateParenthesisHelper(results, s, i + 1, left - 1, right);
	 }
	 else if(left < right){
		 if (left > 0){
			 s[i] = '(';
			 generateParenthesisHelper(results, s, i + 1, left - 1, right);
		 }
		 s[i] = ')';
		 generateParenthesisHelper(results, s, i + 1, left, right - 1);
	 }
	 return;
 }

 vector<string> Solution::generateParenthesis(int n){
	 vector<string> results;
	 string s(2 * n, ' ');
	 generateParenthesisHelper(results, s, 0, n, n);
	 return results;
 }

 int Solution::kthSmallest(TreeNode* root, int k){
	 int cnt = 0;
	 int result;
	 vector<int> v;
	 TreeNode* cur = root;
	 stack<TreeNode*> s;
	 while (cnt < k){
		 while (cur){
			 s.push(cur);
			 cur = cur->left;
		 }
		 cur = s.top();
		 s.pop();
		 cnt++;
		 result = cur->val;
		 cur = cur->right;
	 }
	 return result;
 }

//int kthSmallest(TreeNode* root, int k) {
//	 int count = countNodes(root->left);
//	 if (k <= count) {
//		 return kthSmallest(root->left, k);
//	 }
//	 else if (k > count + 1) {
//		 return kthSmallest(root->right, k - 1 - count); // 1 is counted as current node
//	 }
//
//	 return root->val;
//}
//
//int countNodes(TreeNode n) {
//	 if (n == null) return 0;
//
//	 return 1 + countNodes(n.left) + countNodes(n.right);
//}

 bool findMinArrowShotsHelper(pair<int, int> p1, pair<int, int> p2){
	 return p1.second == p2.second ? p1.first < p2.first : p1.second < p2.second;
 }

 int Solution::findMinArrowShots(vector<pair<int, int>>& points){
	 sort(points.begin(), points.end(), findMinArrowShotsHelper);
	 int cnt = 0;
	 int arrow = INT_MIN;
	 for (int i = 0; i < points.size(); i++){
		 if (arrow != INT_MIN && points[i].first <= arrow){ 
			 continue;
		 }
		 arrow = points[i].second;
		 cnt++;
	 }
	 return cnt;
 }

 ListNode* Solution::oddEvenList(ListNode* head){
	 if (head == NULL) return head;
	 int cnt = 1;
	 int n = 1;
	 ListNode* p = head;
	 ListNode* q = head;
	 while (p->next){
		 p = p->next;
		 n++;
	 }
	 n = n / 2;
	 for (; cnt <= n; cnt++){
		 p->next = q->next;
		 q->next = q->next->next;
		 p->next->next = NULL;
		 p = p->next;
		 q = q->next;
	 }
	 return head;
 }

 int Solution::findDuplicate(vector<int>& nums){
	 for (int i : nums){
		 int tmp = abs(i);
		 if (nums[tmp] > 0)
			 nums[tmp] = -nums[tmp];
		 else
			 return tmp;
	 }
 }

 vector<int> robHelper(TreeNode* root){
	 vector<int> res(2, 0);
	 if (root == NULL) return res;

	 vector<int> left = robHelper(root->left);
	 vector<int> right = robHelper(root->right);

	 res[0] = (left[0] > left[1] ? left[0] : left[1]) + (right[0] > right[1] ? right[0] : right[1]);
	 res[1] = root->val + left[0] + right[0];

	 return res;
 }

 int Solution::rob(TreeNode* root){
	 vector<int> res = robHelper(root);
	 return res[0] > res[1] ? res[0] : res[1];
 }

 int Solution::longestPalindromeSubseq(string s){
	 int n = s.size();
	 vector<vector<int>> res(n, vector<int>(n, 0));
	 for (int i = 0; i < n; i++){
		 res[i][i] = 1;
	 }
	 for (int i = n - 2; i >= 0; i--){
		 for (int j = i + 1; j < n; j++){
			 if (s[i] == s[j]){
				 res[i][j] = res[i + 1][j - 1] + 2;
			 }
			 else{
				 res[i][j] = res[i + 1][j] > res[i][j - 1] ? res[i + 1][j] : res[i][j - 1];
			 }
		 }
	 }
	 return res[0][n - 1];
 }

 vector<int> diffWaysToComputeHelper(string input, map<string, vector<int>> &dp){
	 vector<int> res;
	 int n = input.size();
	 for (int i = 0; i < n; i++){
		 char cur = input[i];
		 if (cur == '+' || cur == '-' || cur == '*'){
			 string substrLeft = input.substr(0, i);
			 string substrRight = input.substr(i + 1);
			 vector<int> resultLeft, resultRight;
			 if (dp.find(substrLeft) != dp.end())
				 resultLeft = dp[substrLeft];
			 else
				 resultLeft = diffWaysToComputeHelper(substrLeft, dp);
			 if (dp.find(substrRight) != dp.end())
				 resultRight = dp[substrRight];
			 else
				 resultRight = diffWaysToComputeHelper(substrRight, dp);
			 for (auto left : resultLeft){
				 for (auto right : resultRight){
					 switch (cur){
					 case '+': res.push_back(left + right); break;
					 case '-': res.push_back(left - right); break;
					 case '*': res.push_back(left * right); break;
					 }
				 }
			 }
		 }
	 }
	 if (res.empty()) res.push_back(atoi(input.c_str()));
	 dp[input] = res;
	 return res;
 }

 vector<int> Solution::diffWaysToCompute(string input){
	 map<string, vector<int>> dp;
	 diffWaysToComputeHelper(input, dp);
	 return dp[input];
 }

 int Solution::bulbSwitch(int n){
	 return sqrt(n);
 }

 int Solution::maxCoins(vector<int>& nums){
	 nums.insert(nums.begin(), 1);
	 nums.push_back(1);
	 int n = nums.size();
	 vector<vector<int>> dp(n, vector<int>(n, 0));
	 for (int k = 2; k < n; k++){
		 for (int i = 0; i < n - k; i++){
			 int j = i + k;
			 for (int n = i + 1; n < j; n++){
				 int tmp = dp[i][n] + dp[n][j] + nums[i] * nums[n] * nums[j];
				 dp[i][j] = dp[i][j] > tmp ? dp[i][j] : tmp;
			 }
		 }
	 }
	 return dp[0][n - 1];
 }