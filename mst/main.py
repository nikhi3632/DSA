from utils import create_graph_from_file
import prims
import kruskals
import sys

'''
    The Minimum Spanning Tree (MST) does not depend on the choice of start and end vertices.
    The MST is a subgraph of the original graph that includes all the vertices of the original graph
    with the minimum possible total edge weight. It is a tree, which means it is connected and acyclic.
    The choice of start and end vertices is typically irrelevant when finding the MST using algorithms 
    like Prim's or Kruskal's.

    In a connected graph with distinct edge weights, the Minimum Spanning Tree (MST) found by
    Prim's algorithm and Kruskal's algorithm will be the same. Both algorithms are guaranteed to find
    the same MST in such a graph. However, if there are multiple edges with the same weight between 
    two vertices, the MSTs found by Prim's and Kruskal's algorithms may not be unique. In this case,
    the MSTs found by both algorithms may differ, but both of them will have the same minimum total weight.

    Prim's and Kruskal's algorithms are used to find the Minimum Spanning Tree (MST) of a graph,
    which is a tree that spans all the vertices of the graph with the minimum possible total edge weight.
    Both algorithms guarantee to find a Minimum Spanning Tree, but they may not produce the same tree
    when there are multiple edges with the same weight in the graph. It's important to note that while the
    MSTs may differ in terms of which edges are chosen, both MSTs are valid and have the 
    same minimum total weight, which means they are both correct solutions to the MST problem.

    The output of Prim's and Kruskal's algorithms differs because these algorithms construct 
    minimum spanning trees (MSTs) differently. While both MSTs will contain the same set of vertices,
    the order in which edges are selected and added to the MST can vary, leading to differences
    in the edge weights and the specific structure of the MST.

    Prim's Algorithm: Prim's algorithm starts with an initial vertex and repeatedly adds the
    minimum-weight edge that connects a vertex in the MST to a vertex outside the MST.
    This process continues until all vertices are included in the MST. The order in which edges are added
    depends on the starting vertex and the specific implementation of the algorithm. As a result, one may 
    get different MSTs starting from different vertices.

    Kruskal's Algorithm: Kruskal's algorithm, on the other hand, sorts all edges by weight and then 
    iteratively adds the smallest-weight edge to the MST, as long as adding the edge does not create a cycle.
    This approach is not dependent on the choice of the starting vertex and always produces the same MST
    for a given graph.
'''

def main():
    g = create_graph_from_file('data.txt')
    print('Original Graph...')
    g.display()
    if sys.argv[2] == 'prims':
        prims.main(g)
    elif sys.argv[2] == 'kruskals':
        kruskals.main(g)
    elif sys.argv[2] == 'run':
        prims.main(g)
        kruskals.main(g)
    else:
        sys.exit(1)

if __name__ == "__main__":
    main()
