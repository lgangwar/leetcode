#include "includes.h"

    void dfs(TreeNode* root, std::string& str){
        if(root == nullptr){
            str += "n,";
            return;
        }

        str += std::to_string(root->val) + ",";
        dfs(root->left, str);
        dfs(root->right, str);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string str;
        dfs(root, str);

        return str.substr(0, str.size()-1);
    }

    // Decodes your encoded data to tree.
    TreeNode* ddfs(std::vector<std::string>& data, int& i){
        
        std::string str = data[i++];
        if(str == "n"){
            return nullptr;
        }

        int val = stoi(str.c_str());
        TreeNode* node = new TreeNode(val);

        node->left = ddfs(data, i);
        node->right = ddfs(data, i);

        return node;
    }

    TreeNode* deserialize(string data) {
        std::stringstream ss(data);
        vector<std::string> v;
        std::string token;

        while(getline(ss, token, ',')){
            v.emplace_back(token);
        }

        TreeNode* root = nullptr;
        int i = 0;
        return ddfs(v, i);
    }