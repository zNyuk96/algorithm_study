# https://www.acmicpc.net/problem/13907
import sys
import heapq

if __name__ == '__main__':
    n_city, n_edge, times = map(int, sys.stdin.readline().split())
    src, dst = map(int, sys.stdin.readline().split())
    edge = [dict() for _ in range(n_city)]
    costs = [[1300001] * n_city for _ in range(n_city)]
    costs_min = [[n_city, 1300001] for _ in range(n_city)]    # 간선 개수, 비용
    djik_queue = []

    for _ in range(n_edge):
        _src, _dst, _cost = map(int, sys.stdin.readline().split())

        edge[_src - 1][_dst - 1] = min(edge[_src - 1].get(_dst - 1, 1000), _cost)
        edge[_dst - 1][_src - 1] = min(edge[_dst - 1].get(_src - 1, 1000), _cost)
        
    # 다익스트라
    costs[src - 1][0] = 0
    costs_min[src - 1] = [0, 0]
    heapq.heappush(djik_queue, (0, 0, src - 1))  # 비용, 간선 개수, 현재 노드

    while djik_queue:
        cur_cost, edge_cnt, cur_node = heapq.heappop(djik_queue)

        if edge_cnt + 1 < n_city:
            for neigh in edge[cur_node].keys():
                if costs_min[neigh][0] > edge_cnt + 1:
                    if costs_min[neigh][1] > cur_cost + edge[cur_node][neigh]:
                        costs_min[neigh][0] = edge_cnt + 1
                        costs_min[neigh][1] = cur_cost + edge[cur_node][neigh]

                    if cur_cost + edge[cur_node][neigh] < costs[neigh][edge_cnt + 1]:
                        costs[neigh][edge_cnt + 1] = cur_cost + edge[cur_node][neigh]
                        heapq.heappush(djik_queue, (costs[neigh][edge_cnt + 1], edge_cnt + 1, neigh))

                elif costs_min[neigh][1] > cur_cost + edge[cur_node][neigh]:
                    costs_min[neigh][1] = cur_cost + edge[cur_node][neigh]
                    costs_min[neigh][0] = edge_cnt + 1

                    if cur_cost + edge[cur_node][neigh] < costs[neigh][edge_cnt + 1]:
                        costs[neigh][edge_cnt + 1] = cur_cost + edge[cur_node][neigh]
                        heapq.heappush(djik_queue, (costs[neigh][edge_cnt + 1], edge_cnt + 1, neigh))

    time = 0
    print(min(costs[dst - 1]))
    for _ in range(times):
        time = int(sys.stdin.readline())

        for i in range(n_city):
            if costs[dst - 1][i] != 1300001:
                costs[dst - 1][i] += i * time

        print(min(costs[dst - 1]))
