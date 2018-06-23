#
# Given a directed graph, determine if route exists between 2 nodes.
# Joel Rorseth
#

# Q: Directed? Yes
# Q: Does graph contain cycles or self loops? No
# Complexity: O(V+E)

from collections import defaultdict

# Simplified DFS
def route_exists(start, end):

    stack = [start]
    v = set()

    while len(stack) != 0:
        node = stack.pop()

        if node in v:
            continue

        if node == end:
            return True

        v.add(node)

        for adj in graph[node]:
            stack.append(adj)

    return False



graph = defaultdict(set)
edges = [(1,2),(2,3),(1,4),(2,4),(4,5),(3,6)]
for a, b in edges:
    graph[a].add(b)

print(graph)
print(route_exists(1,6)) # 1->6 is True
