graph={   '0':[('1',2),('7',3),('3',2)],
          '1':[('0',1),('4',4)],
          '7':[('4',5),('5',6)],
          '3':[('5',7),('0',1)],
          '4':[('6',4)],
          '5':[('6',2)]
        }
def path_total_cost(path):
    total_cost =0

    for (node ,cost) in path :
        total_cost += cost
    path_end = path[-1][0]
    return   total_cost, path_end
def Uniform_Cost_Search (graph, ST, goal):
    visited=[]
    queue=[[(ST,0)]]
    while queue:
      queue.sort(key=path_total_cost)
      path=queue.pop(0)
      node = path[-1][0]
      if node in visited:
             continue
      visited.append(node)
      if node == goal:
          return path
      else:
          adjacent_node = graph.get(node, [])
          for (next_node,cost) in adjacent_node:
            new_path = path.copy()
            new_path.append((next_node, cost))
            queue.append(new_path)
best_path= Uniform_Cost_Search (graph, '0', '6')
print('best bath solution is',best_path)
print('and it\'s cost =',path_total_cost(best_path)[0])