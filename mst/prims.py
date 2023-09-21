from utils import Graph

def prim(g: Graph):
    prim_mst = Graph()
    visited = set()
    start_vertex = next(iter(g.graph.keys()))

    visited.add(start_vertex)

    while len(visited) < len(g.graph):
        min_edge = None

        for u in visited:
            for v, weight in g.graph[u].items():
                if v not in visited and (min_edge is None or weight < min_edge[2]):
                    min_edge = (u, v, weight)

        if min_edge:
            u, v, weight = min_edge
            prim_mst.add_vertex(u)
            prim_mst.add_vertex(v)
            prim_mst.add_edge(u, v, weight)
            visited.add(v)

    return prim_mst

def main(g):
    prim_mst = prim(g)
    print("\nPrim's Minimum Spanning Tree:")
    mst_edges = [(u, v, {'weight': weight}) for u, v, weight in prim_mst.get_edges()]
    print(mst_edges)