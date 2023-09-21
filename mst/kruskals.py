from utils import Graph

def find_set(vertex, parent):
    if vertex == parent[vertex]:
        return vertex
    parent[vertex] = find_set(parent[vertex], parent)
    return parent[vertex]

def union_sets(u, v, parent, rank):
    u = find_set(u, parent)
    v = find_set(v, parent)
    if u != v:
        if rank[u] < rank[v]:
            u, v = v, u
        parent[v] = u
        if rank[u] == rank[v]:
            rank[u] += 1

def kruskal(g: Graph):
    kruskal_mst = Graph()
    edges = [(u, v, weight) for u, v, weight in g.get_edges()]
    edges.sort(key=lambda x: x[2])  # Sort edges by weight
    parent = {vertex: vertex for vertex in g.get_vertices()}
    rank = {vertex: 0 for vertex in g.get_vertices()}

    # Union Find
    for u, v, weight in edges:
        if find_set(u, parent) != find_set(v, parent):
            kruskal_mst.add_vertex(u)
            kruskal_mst.add_vertex(v)
            kruskal_mst.add_edge(u, v, weight)
            union_sets(u, v, parent, rank)

    return kruskal_mst

def main(g):
    kruskal_mst = kruskal(g)
    print("\nKruskal's Minimum Spanning Tree:")
    mst_edges = [(u, v, {'weight': weight}) for u, v, weight in kruskal_mst.get_edges()]
    print(mst_edges)
