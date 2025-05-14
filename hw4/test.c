#include <stdio.h>
#include <limits.h>

#define V 5  // 图中顶点的数量

// 使用邻接矩阵表示图
int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

// 查找权值最小的未被访问的顶点
int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// 实现Prim算法来找到最小生成树
void primMST(int graph[V][V]) {
    int parent[V]; // 用来存储最小生成树的构造树
    int key[V];    // 存储每个顶点的最小权重
    int mstSet[V]; // 判断顶点是否已包含在最小生成树中

    // 初始化所有的键值为无限大，mstSet为false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    // 从顶点0开始
    key[0] = 0; // 起点的键值为0
    parent[0] = -1; // 根节点没有父节点

    // 计算最小生成树
    for (int count = 0; count < V - 1; count++) {
        // 选择最小键值的顶点
        int u = minKey(key, mstSet);

        // 标记u顶点已包含在最小生成树中
        mstSet[u] = 1;

        // 更新u的相邻顶点的键值和父节点
        for (int v = 0; v < V; v++) {
            // 更新key值和parent数组
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    // 打印最小生成树
    printf("边 \t权重\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    primMST(graph);
    return 0;
}
