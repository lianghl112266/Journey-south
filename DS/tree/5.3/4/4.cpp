#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


#define TREE

#ifdef TREE
struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};

Node *buildTree(std::vector<int> &preOrder, std::vector<int> &inOrder) {
    if (preOrder.empty()) {
        return nullptr;
    }
    int i;
    for(i = 0; i < inOrder.size(); i++) if (inOrder[i] == preOrder[0]) break;
    int left_size = i;
    std::vector<int> pre1(preOrder.begin() + 1, preOrder.begin() + 1 + left_size);
    std::vector<int> pre2(preOrder.begin() + 1 + left_size, preOrder.end());
    std::vector<int> in1(inOrder.begin(), inOrder.begin() + left_size);
    std::vector<int> in2(inOrder.begin() + 1 + left_size, inOrder.end());
    Node *left = buildTree(pre1, in1);
    Node *right = buildTree(pre2, in2);
    return new Node(preOrder[0], left, right);
}
#endif




void solve(Node *root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* x = q.front();
        q.pop();
        cout << x->val << " ";
        if (x->right) q.push(x->right);
        if (x->left) q.push(x->left);
    }
}



int main() {
    int n; cin >> n;
    vector<int> preOrder(n), inOrder(n);
    for(int i = 0; i < n; i++) cin >> preOrder[i];
    for(int i = 0; i < n; i++) cin >> inOrder[i];
    solve(buildTree(preOrder, inOrder));
}