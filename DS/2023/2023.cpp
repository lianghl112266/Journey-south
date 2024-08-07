/*
遍历即可， 设边的起始顶点度-1, 终点节点度+1, 最后度大于0， 的节点就是k节点
时间复杂度 O(n^2)
空间复杂度 O(n)

输入格式： 第一行2个数字代表顶点数和边数，剩余行代表边
输出格式： 1（true), 0(false)

测试用例1
4 5
0 1
0 3
1 2
1 3
2 3
expected output: 
0 1
2

*/
#include<bits/stdc++.h>
 
using namespace std;

const int MAXV = 10;

struct MGraph {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
};

int solve(MGraph g) {
    int ans = 0;
    vector<int> deg(g.numVertices);
    for (int i = 0; i < g.numVertices; i++){
        for (int j = 0; j < g.numVertices; j++) {
            if (g.Edge[i][j])
            {
                deg[i] += 1;
                deg[j] -= 1;
            }
        }
    }
    for (int i = 0; i < g.numVertices; i++){
        if (deg[i] > 0)
        {
            cout << i << " ";
            ans += 1;
        }
    }
    cout << '\n';
    return ans;
}

//用于输入
int main() {
    MGraph g;
    memset(g.Edge, 0, sizeof(int) * MAXV * MAXV);
    cin >> g.numVertices >> g.numEdges;
    for (int t = g.numEdges; t; t--) {
        int x, y;
        cin >> x >> y;
        g.Edge[x][y] = 1;
    }
    cout << solve(g);
}