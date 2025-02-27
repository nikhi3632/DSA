import matplotlib.pyplot as plt
import networkx as nx
import collections

class Graph:
    def __init__(self):
        self.graph = {}
        self.edges = []
    
    def add_edge(self, u, v):
        # Assuming an undirected graph
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []
        self.graph[u].append(v)
        self.graph[v].append(u)
        self.edges.append((u, v))
    
    def print_adjacency_list(self):
        print("\nAdjacency List:\n")
        for node in self.graph:
            print(f"{node}: {self.graph[node]}")

    def visualize(self, filename="graph.png"):
        G = nx.Graph()
        G.add_edges_from(self.edges)
        
        plt.figure(figsize=(15, 15))
        nx.draw(G, with_labels=True, node_color='lightblue', edge_color='gray', node_size=2000, font_size=10)
        
        plt.savefig(filename, format='png')
        print(f"Graph saved as {filename}")
    
    def dfs(self, start):
            """DFS follows the LIFO principle (process the most recently added node first)."""
            visited = set()
            stack = [start]

            while stack:
                node = stack.pop()
                if node not in visited:
                    print(node, end=' ')
                    visited.add(node)
                    for neighbor in reversed(self.graph.get(node, [])):
                        if neighbor not in visited:
                            stack.append(neighbor)

    def bfs(self, start):
        """BFS follows the FIFO principle (process nodes in the order they are discovered)."""
        visited = set()
        queue = collections.deque([start])  # Using deque for O(1) popleft()

        while queue:
            node = queue.popleft()
            if node not in visited:
                print(node, end=' ')
                visited.add(node)
                for neighbor in self.graph.get(node, []):
                    if neighbor not in visited:
                        queue.append(neighbor)

if __name__ == "__main__":
    g = Graph()
    root_node = 0

    g.add_edge(0, 1)
    g.add_edge(0, 2)
    g.add_edge(1, 3)
    g.add_edge(1, 4)
    g.add_edge(2, 5)
    g.add_edge(2, 6)
    g.add_edge(3, 7)
    g.add_edge(4, 8)
    g.add_edge(5, 9)
    g.add_edge(6, 10)
    g.add_edge(7, 11)
    g.add_edge(8, 12)
    g.add_edge(9, 13)
    g.add_edge(10, 14)

    g.print_adjacency_list()
    print("\n")
    g.visualize()
    print("\n")
    print("DFS Traversal:")
    g.dfs(root_node)
    print("\n")
    print("BFS Traversal:")
    g.bfs(root_node)
    print("\n")
