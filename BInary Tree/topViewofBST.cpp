#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (!root) return ans;

        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end())
                mpp[line] = node->data;

            if (node->left)
                q.push({node->left, line - 1});
            if (node->right)
                q.push({node->right, line + 1});
        }

        for (auto it : mpp)
            ans.push_back(it.second);

        return ans;
    }
};

int main() {
    /*
            1
           / \
          2   3
           \
            4
             \
              5
               \
                6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    Solution sol;
    vector<int> result = sol.topView(root);

    cout << "Top view: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
