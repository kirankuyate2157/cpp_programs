graph = {
    '0': ['1', '4'],
    '1': ['2', '3', '4'],
    '2': ['1', '3'],
    '3': ['1', '2'],
    '4': ['0', '1'],
}

vis = []
q = []


def bsf(vis,  graph, node):
    vis.append(node)
    q.append(node)
    while q:
        k = q.pop(0)
        print(k, end=" ")
        for nbr in graph[k]:
            if nbr not in vis:
                vis.append(nbr)
                q.append(nbr)


# main code
bsf(vis, graph, '0')
