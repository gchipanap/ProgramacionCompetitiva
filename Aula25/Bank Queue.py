#1. Bank Queue
#https://open.kattis.com/problems/bank

from heapq import heappush, heappop

n, t = list(map(int, input().split()))
people = {}

for i in range(n):
    a, b = list(map(int, input().split()))
    if b in people:
        people[b].append(a)
    else:
        people[b] = [a]

q = []
tot = 0

for i in range(t-1, -1, -1):
    if i in people:
        for j in people[i]:
            heappush(q, -j)
    if q:
        tot += heappop(q)
        
print(-tot)