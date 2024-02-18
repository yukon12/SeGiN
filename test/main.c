#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>
#include <SeGiN/array.h>
#include <SeGiN/prefix_sum_array.h>
#include <SeGiN/segment_tree.h>
#include <SeGiN/kadane.h>
#include <SeGiN/heap.h>
#include <SeGiN/knapsack.h>
#include <SeGiN/graph.h>
#include <SeGiN/dijkstra.h>
#include <SeGiN/disjoint_set_union.h>

int main()
{
    // ARRAY
    int arraySize = 10;
    int array[10] = {-3, 5, -6, 7, 8, 9, -2, 4, -6, 1};
    int minimalValue = SGN_arrayMinimum(array, arraySize);
    int maximalValue = SGN_arrayMaximum(array, arraySize);
    assert(minimalValue==-6);
    assert(maximalValue==9);

    // PREFIX SUM ARRAY
    int* prefixSumArray = SGN_constructPrefixSumArray(array, arraySize);
    assert(SGN_queryPSA(prefixSumArray, arraySize, 0, 9)==17);
    assert(SGN_queryPSA(prefixSumArray, arraySize, 0, 2)==-4);
    assert(SGN_queryPSA(prefixSumArray, arraySize, 8, 9)==-5);
    assert(SGN_queryPSA(prefixSumArray, arraySize, 3, 5)==24);

    // SEGMENT TREE
    int segmentTreeSize = 10;
    int* segmentTree = SGN_constructSegmentTree(array, segmentTreeSize);
    assert(SGN_queryST(segmentTree, segmentTreeSize, 1, 3)==6);
    assert(SGN_queryST(segmentTree, segmentTreeSize, 6, 9)==-3);
    SGN_updateST(segmentTree, segmentTreeSize, 0, 10);
    assert(SGN_queryST(segmentTree, segmentTreeSize, 0, 3)==16);

    // KADANE
    int leftBound;
    int rightBound;
    int kadaneValue = SGN_kadaneMinimum(array, arraySize, &leftBound, &rightBound);
    assert(kadaneValue==-6);
    assert((leftBound==2&&rightBound==2)||(leftBound==8&&rightBound==8));
    kadaneValue = SGN_kadaneMaximum(array, arraySize, &leftBound, &rightBound);
    assert(kadaneValue==26);
    assert(leftBound==3&&rightBound==7);

    // HEAP
    int heapSize = 10; 
    int heapCapacity = 20;
    int* heap = SGN_constructHeap(array, heapSize, heapCapacity);
    assert(heap[0]==9);
    SGN_insertNode(heap, heapSize, heapCapacity, 11);
    heapSize++;
    assert(heap[0]==11);
    SGN_deleteNode(heap, heapSize, 0);
    heapSize--;
    assert(heap[0]==9);

    // KNAPSACK
    int weight[] = {7, 4, 5, 10, 6};
    int profit[] = {10, 20, 15, 20, 10};
    int amount = 5;
    int maximalWeight = 20;
    assert(knapsack(weight, profit, amount, maximalWeight)==55);

    // GRAPH
    int graphSize = 10;
    int** graph = SGN_constructGraph(graphSize);
    assert(graph[7][5]==INT_MAX);
    assert(graph[0][0]==INT_MAX);
    assert(graph[9][9]==INT_MAX);
    SGN_addUndirectedEdge(graph, graphSize, 7, 5, 1);
    assert(graph[7][5]==1);
    assert(graph[5][7]==1);
    SGN_addDirectedEdge(graph, graphSize, 1, 3, 5);
    assert(graph[1][3]==5);
    assert(graph[3][1]==INT_MAX);
    SGN_addUndirectedEdge(graph, graphSize, 1, 3, 5);
    assert(graph[1][3]==5);
    assert(graph[3][1]==5);

    //DIJKSTRA
    SGN_addUndirectedEdge(graph, graphSize, 0, 2, 9);
    SGN_addUndirectedEdge(graph, graphSize, 0, 7, 4);
    SGN_addUndirectedEdge(graph, graphSize, 7, 1, 3);
    SGN_addUndirectedEdge(graph, graphSize, 1, 2, 7);
    SGN_addUndirectedEdge(graph, graphSize, 2, 4, 20);
    SGN_addUndirectedEdge(graph, graphSize, 1, 4, 5);
    SGN_addUndirectedEdge(graph, graphSize, 4, 6, 1);
    SGN_addUndirectedEdge(graph, graphSize, 8, 5, 5);
    SGN_addUndirectedEdge(graph, graphSize, 8, 3, 9);
    SGN_addUndirectedEdge(graph, graphSize, 8, 9, 2);
    int* distance = SGN_dijkstra(graph, graphSize, 0);
    assert(distance[0]==0);
    assert(distance[1]==7);
    assert(distance[2]==9);
    assert(distance[3]==12);
    assert(distance[4]==12);
    assert(distance[5]==5);
    assert(distance[6]==13);
    assert(distance[7]==4);
    assert(distance[8]==10);
    assert(distance[9]==12);

    // DISJOINT SET UNION
    int dsuSize = 10;
    int* dsuRank = (int*)calloc(dsuSize, sizeof(int));
    int* dsu = SGN_constructDisjointSetUnion(dsuSize);
    assert(SGN_findDSU(dsu, dsuSize, 8)==8);
    assert(dsu[7]==7);
    assert(dsuRank[4]==0);
    SGN_unionDSU(dsu, dsuRank, dsuSize, 0, 1);
    assert(SGN_findDSU(dsu, dsuSize, 0)==SGN_findDSU(dsu, dsuSize, 1));

    printf("All tests passed.\n");
    return 0;
}
