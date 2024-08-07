#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define pb push_back
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

Node* buildTree(vector<int>& preOrder, vector<int>& inOrder) {
        if(!preOrder.size()) return NULL;

        Node * root = new Node;
        root->val = preOrder[0];
        root->left = root->right = NULL;

        if(preOrder.size() == 1) return root;

        vector<int>::iterator it = find(inOrder.begin(), inOrder.end(), preOrder[0]);

        vector<int>pl(preOrder.begin() + 1, preOrder.begin() + 1 + (it - inOrder.begin()));
        vector<int>pr(preOrder.begin() + 1 + (it - inOrder.begin()), preOrder.end());
        vector<int>il(inOrder.begin(), it);
        vector<int>ir(it + 1, inOrder.end());

        root->left = buildTree(pl, il);
        root->right = buildTree(pr, ir);

        return root;
}

void debugTree(Node *root) {
    if (!root) return;
    vector<Node*> q{root};
    while(!q.empty()) {
        vector<Node*> p(q);
        q.clear();
        for(auto x: p) {
            cout << x->val << " ";
            if (x->left) q.pb(x->left);
            if(x->right) q.pb(x->right);
        }
    }
}

#endif




void solve(Node *root) {
    function<void(Node*)> f = [&](Node *node) -> void {
        if (!node) return ;
        auto tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        f(node->left);
        f(node->right);
    };
    f(root);
    debugTree(root);
}



int main() {
    int n; cin >> n;
    vector<int> preOrder(n), inOrder(n);
    for(int i = 0; i < n; i++) cin >> preOrder[i];
    for(int i = 0; i < n; i++) cin >> inOrder[i];
    solve(buildTree(preOrder, inOrder));
}