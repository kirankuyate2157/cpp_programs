graph = {
    '0': ['1', '4'],
    '1': ['2', '3', '4'],
    '2': ['1', '3'],
    '3': ['1', '2'],
    '4': ['0', '1'],
}

vis = set()


def dfs(vis, graph, node):
    if node not in vis:
        print(node, end=", ")
        vis.add(node)
        for nbr in graph[node]:
            dfs(vis, graph, nbr)


# main code
dfs(vis, graph, '0')
