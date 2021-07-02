from disjoint_set import DisjointSet

ds = DisjointSet()

class word():
    def __init__(self, s):
        self.n = len(s) // 4
        self.content = []
        for i in range(self.n):
            self.content.append(s[i * 4:(i+1) * 4])
    def __eq__(self, o):
        diff = True
        for i in range(self.n):
            if not ds.connected(self.content[i], o.content[i]):
                return False
        return True


def main():
    n = int(input())
    print(n)
    for i in range(n):
        command, a, b = input().split()
        if command == 'union':
            ds.union(a, b)
        else:
            check = (word(a) == word(b))
            print(check)

if __name__ == "__main__":
    main()