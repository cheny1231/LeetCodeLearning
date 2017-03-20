#pragma once
#include "Solution.h"

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root); 

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data); 
};