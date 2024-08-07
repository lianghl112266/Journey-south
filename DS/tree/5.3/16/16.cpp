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


void solve(Node *root1, Node *root2) {
    Node *head = new Node();
    function<bool(Node*, Node*)> f = [&](Node *o1, Node* o2) -> bool {
        if (!o1 || !o2) return o1 == o2;
        return f(o1->left, o2->left) && f(o1->right, o2->right);
    };

    cout << f(root1, root2);
    
}



int main() {
    int n, m; cin >> n >> m;
    vector<int> preOrder1(n), inOrder1(n);
    for(int i = 0; i < n; i++) cin >> preOrder1[i];
    for(int i = 0; i < n; i++) cin >> inOrder1[i];
    vector<int> preOrder2(m), inOrder2(m);
    for(int i = 0; i < m; i++) cin >> preOrder2[i];
    for(int i = 0; i < m; i++) cin >> inOrder2[i];
    solve(buildTree(preOrder1, inOrder1), buildTree(preOrder2, inOrder2));
}