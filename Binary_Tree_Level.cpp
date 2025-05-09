#include<iostream> 
#include<vector> 
#include<queue> 

using namespace std; 

struct TreeNode{
   int val; 
   TreeNode* left; 
   TreeNode* right; 
   TreeNode(): val(0), left(nullptr), right(nullptr){}
   TreeNode(int _val): val(_val), left(nullptr), right(nullptr){}
   TreeNode(int _val, TreeNode* _left, TreeNode* _right): val(_val), left(_left), right(_right){}
   
};

class Solution{
public: 
      vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> res; 
        if(!root) return res; 

        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()){
          int size = q.size();
          vector<int> currentLevel; 
          for(int i=0; i<size;++i){
            TreeNode* curr = q.front(); 
            q.pop(); 
            currentLevel.push_back(curr->val); 
            if(curr->left) q.push(curr->left); 
            if(curr->right) q.push(curr->right); 
          }
          res.push_back(currentLevel); 
        }
        return res; 
      }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);
    
    // Output the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0; 
}
