from disjoint_set import DisjointSet

ds = DisjointSet()

n = int(input())

for i in range(n):
    buf = input()
    cmd, a, b = buf.split()
    if cmd == 'union':
        ds.union(a,b)
    elif cmd == 'compare':
        str_n = len(a) // 4
        same = True
        for i in range(str_n):
            if not ds.connected(a[4 * i: 4 * (i+1)], b[4 * i: 4 * (i+1)]):
                same = False 
                break
        print(same)