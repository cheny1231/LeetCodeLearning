#pragma once
#include <vector>
#include <queue>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

 struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	int hammingDistance(int x, int y);
	int findComplement(int num);
	vector<string> findWords(vector<string>& words);
	int countBattleships(vector<vector<char>>& board);
	vector<int> countBits(int num);
	vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums);
	vector<string> fizzBuzz(int n);
	string reverseString(string s);
	int islandPerimeter(vector<vector<int>>& grid);
	bool detectCapitalUse(string word);
	int findBottomLeftValue(TreeNode* root);
	int findMaxConsecutiveOnes(vector<int>& nums);
	bool canWinNim(int n);
	int numberOfArithmeticSlices(vector<int>& A);
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people);
	vector<int> findDisappearedNumbers(vector<int>& nums);
	int singleNumber(vector<int>& nums);
	vector<int> largestValues(TreeNode* root);
	int findPoisonedDuration(vector<int>& timeSeries, int duration);
	vector<int> findFrequentTreeSum(TreeNode* root);
	vector<int> findDuplicates(vector<int>& nums);
	int minMoves2(vector<int>& nums);
	int maxDepth(TreeNode* root);
	int getSum(int a, int b);
	char findTheDifference(string s, string t);
	int countArrangement(int N);
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click);
	int addDigits(int num);
	TreeNode* invertTree(TreeNode* root);
	string frequencySort(string s);
	vector<int> singleNumberIII(vector<int>& nums);
	vector<int> constructRectangle(int area);
	int getMinimumDifference(TreeNode* root);
	vector<string> findRelativeRanks(vector<int>& nums);
	void moveZeroes(vector<int>& nums);
	vector<int> twoSum(vector<int>& numbers, int target);
	vector<int> productExceptSelf(vector<int>& nums);
	int findContentChildren(vector<int>& g, vector<int>& s);
	int minMoves(vector<int>& nums);
	vector<int> topKFrequent(vector<int>& nums, int k);
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix);
	string convertToBase7(int num);
	bool canConstruct(string ransomNote, string magazine);
	vector<int> nextGreaterElements(vector<int>& nums);
	int sumOfLeftLeaves(TreeNode* root);
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int firstUniqChar(string s);
	int totalHammingDistance(vector<int>& nums);
	int maxProfit(vector<int>& prices);
	int titleToNumber(string s);
	int magicalString(int n);
	void deleteNode(ListNode* node);
	bool isSameTree(TreeNode* p, TreeNode* q);
	int countNumbersWithUniqueDigits(int n);
	int majorityElement(vector<int>& nums);
	bool isAnagram(string s, string t);
	int integerBreak(int n);
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D);
	int longestPalindrome(string s);
	vector<int> inorderTraversal(TreeNode* root);
	vector<string> readBinaryWatch(int num);
	bool containsDuplicate(vector<int>& nums);
	int findTargetSumWays(vector<int>& nums, int S);
	bool canPartition(vector<int>& nums);
	int romanToInt(string s);
	ListNode* reverseList(ListNode* head);
	bool isSubsequence(string s, string t);
	int findMaximumXOR(vector<int>& nums);
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2);
	int missingNumber(vector<int>& nums);
	vector<int> preorderTraversal(TreeNode* root);
	int kthSmallest(vector<vector<int>>& matrix, int k);
	string intToRoman(int num);
	int numberOfBoomerangs(vector<pair<int, int>>& points);
	int totalNQueens(int n);
	vector<vector<int>> combinationSum3(int k, int n);
	string originalDigits(string s);
	int maxProduct(vector<string>& words);
	vector<string> generateParenthesis(int n);
	int kthSmallest(TreeNode* root, int k);
	int findMinArrowShots(vector<pair<int, int>>& points);
	ListNode* oddEvenList(ListNode* head);
	int findDuplicate(vector<int>& nums);
	int rob(TreeNode* root);
	int longestPalindromeSubseq(string s);
	vector<int> diffWaysToCompute(string input);
	int bulbSwitch(int n);
	int maxCoins(vector<int>& nums);
	int combinationSum4(vector<int>& nums, int target);
	vector<vector<int>> permute(vector<int>& nums);
	string addStrings(string num1, string num2);
	vector<int> findRightInterval(vector<Interval>& intervals);
	string licenseKeyFormatting(string S, int K);
};