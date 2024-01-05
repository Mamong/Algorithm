//
//  graph.c
//  Algorithm
//
//  Created by marco on 2019/3/22.
//  Copyright © 2019 flywire. All rights reserved.
//

#include "graph.h"

#define MAX 100000
#define VNUM 10+1

//邻接矩阵
int edge[VNUM][VNUM] = {};
//记录Vnew中每个点到V中邻接点的最短边值
int lowcost[VNUM]={0};
//标记某点是否已加入Vnew
int addvnew[VNUM];
//记录V中每点和Vnew中邻接的点
int adjacent[VNUM]={0};


void prim(int start)
{
    //辅助量
    int sum = 0;
    int i,j,k=0;
    
    //使用start初始化
    for(i=1;i<VNUM;i++){
        addvnew[i]=-1;
        lowcost[i]=edge[start][i];
    }
    addvnew[start]=0;
    adjacent[start]=start;
    
    //对剩余的点执行以下步骤
    for (i=1; i<VNUM-1; i++) {
        int min = MAX;
        int v = -1;
        for (j=1; j<VNUM; j++) {
            //如果这个点在Vnew中，看看这个点到V中邻接的点的距离是不是最短的
            if (addvnew[j]!=-1 && lowcost[j]<min) {
                min = lowcost[j];
                v = j;
            }
        }
        
        if(v != -1){
            printf("%d %d %d\n",adjacent[v],v,lowcost[v]);
            
            //如果存在最近的点，则将其加入Vnew，并计算当前路径长度
            addvnew[v] = 0;
            sum += min;
            
            //调整lowcost和adjacent
            for (k=1; k<VNUM; k++) {
                //V中该点不在Vnew中，且新拓展点到该点距离比原先Vnew内所有点到该点的距离短
                if (addvnew[k] == -1 && edge[v][k]<lowcost[k]) {
                    lowcost[k] = edge[v][k];
                    adjacent[k] = v;
                }
            }
        }
    }
    printf("the minmum weight is %d",sum);
}


//-----------------Kruskal---------------------
#define VertexNum 10
#define EdgeNum 10

//图：顶点数组，边表邻接矩阵，顶点和边的数量
typedef struct {
    char vertex[VertexNum];
    int edges[VertexNum][VertexNum];
    int n,e;
}MyGraph;

//边：起始顶点，结束顶点和权重
typedef struct {
    int u;
    int v;
    int w;
}Edge;

void someSort(Edge edges[],int count,int size){
    
}

void kruskal(MyGraph G){
    int i,j,sn1,sn2;
    //判断两个订单是否连通
    int vset[VertexNum];
    //存放全部边
    Edge E[EdgeNum];
    int k=0;
    
    for (i=0; i<G.n; i++) {
        for (j=0; j<G.e; j++) {
            if (G.edges[i][j] != 0 && G.edges[i][j] != MAX) {
                E[k].u = i;
                E[k].v = j;
                E[k].w = G.edges[i][j];
                k++;
            }
        }
    }
    //按权值对边进行排序
    someSort(E,k,sizeof(Edge));
    
    //初始化辅助数组，每个顶点属于各自集合
    for (i=0; i<G.n; i++) {
        vset[i]=i;
    }
    
    //k是边数，j是E下标
    k=0;
    j=0;
    //k从1到G.n
    while (k<G.n-1) {
        //得到两顶点属于的集合编号，并查集思想
        sn1 = vset[E[j].u];
        sn2 = vset[E[j].v];
        //属于不同集合
        if (sn1 != sn2) {
            //增加边
            k++;
            //将其中一个顶点加入另一个顶点的集合
            for (i=0; i<G.n; i++) {
                if (vset[i] == sn2) {
                    vset[i] = sn1;
                }
            }
        }
        j++;
    }
}

//--------------------Dijkstra---------------------------
void Dijkstra(MyGraph G,int start)
{
    //两个节点间的距离表
    int dist[VertexNum];
    //已找到最短路径的点的集合
    int s[VertexNum];
    //表明顶点V到某个顶点的最短路径已求得
    bool vis[VertexNum];
    
    int i,j,k;
    for (i=0; i<G.n; i++) {
        vis[i] = false;
        dist[i] = G.edges[start][i];
    }
    s[0]=start;
    vis[start]=true;
    
    for (i=1; i<G.n; i++) {
        int v = -1;
        int min=MAX;
        for (j=0; j<G.n; j++) {
            if (!vis[i] && dist[i] < min) {
                min = dist[i];
                v=i;
            }
        }
        if (v != -1) {
            s[i] = v;
            vis[v] = true;
            
            for (k=0; k<G.n; k++) {
                if (!vis[k] && dist[k] > dist[v]+G.edges[v][k]) {
                    dist[k] = dist[v]+G.edges[v][k];
                }
            }
        }
    }
}
