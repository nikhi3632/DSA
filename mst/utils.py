# Class to represent a graph
class Graph:
    def __init__(self):
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = {}

    def add_edge(self, vertex1, vertex2, weight):
        if vertex1 in self.graph:
            if vertex2 not in self.graph[vertex1]:
                self.graph[vertex1][vertex2] = weight
        else:
            self.graph[vertex1] = {vertex2: weight}

        if vertex2 in self.graph:
            if vertex1 not in self.graph[vertex2]:
                self.graph[vertex2][vertex1] = weight
        else:
            self.graph[vertex2] = {vertex1: weight}
    
    def get_edges(self):
        edges = []
        for vertex1, neighbors in self.graph.items():
            for vertex2, weight in neighbors.items():
                if not (vertex2, vertex1, weight) in edges:
                    edges.append((vertex1, vertex2, weight))
        return edges
    
    def get_vertices(self):
        return list(self.graph.keys())

    def display(self):
        for vertex, neighbors in self.graph.items():
            print(f"{vertex}: {', '.join(neighbors)}")

def create_graph_from_file(file_path) -> Graph:
    g = Graph()
    with open(file_path, 'r') as file:
        for line in file:
            source, destination, weight = line.split()
            g.add_vertex(source)
            g.add_vertex(destination)
            g.add_edge(source, destination, float(weight))
    return g
