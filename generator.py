import random
import string
from tqdm import trange
from disjoint_set import DisjointSet
import sys

N = int(5e5) # number of words in dictionary
M = int(1e2) # max length of a sentence
Q = int(4e3)    
U = int(6e3)
stringset, commands= [], []
idsset = set() # words in disjoint set
command_seq = ''
charset = string.digits + string.ascii_letters
ds = DisjointSet()

def rand_str():
    return ''.join(random.choice(charset) for i in range(4))

def rand_type(prob: float):
    r = random.uniform(0, 1)
    if r < prob:
        s = random.uniform(0, 1)
        return 'c' if s < 0.99 else 's'
    return 'u'

def rand_lang(length: int):
    a, b = '', ''
    for i in range(length):
        a += random.choice(stringset)
        b += random.choice(stringset)
    return a, b

def hit_lang(length: int):
    a, b = '', ''
    for i in range(length):
        wa = random.choice(tuple(idsset))
        wb = random.choice(tuple([i for i in idsset if ds.connected(wa, i)]))
        a += wa; b += wb
    return a, b


def rand_len() -> int:
    ret = random.uniform(1, M)
    while ret > M:
        ret // 2
    return max(1, int(ret))

def generate_union():
    a, b = rand_str(), rand_str()
    idsset.add(a); idsset.add(b)
    commands.append(('union', a, b))
    ds.union(a, b)

def generate_random_strcmp():
    l = rand_len()
    wa = random.choice(tuple(idsset))
    wb = random.choice(tuple([i for i in idsset if ds.connected(wa, i)]))
    a, b= rand_lang(l)
    
    s = random.uniform(0, 1)
    if s < 0.04:
        a, b = wa + a, wb + b
    commands.append(('compare', a, b))
    
def generate_hit_strcmp():
    l = rand_len()
    a, b = hit_lang(l)
    commands.append(('compare', a, b))

def main():
    global command_seq
    argv = sys.argv
    if len(argv) < 2:
        print(f"usage: {argv[0]} n_gen")
        sys.exit(0)
    # generate the dictionary of words
    while len(stringset) < N:
        stringset.append(rand_str())
        
    # generate the sequence for testcase, indicator only
    for i in range(Q + U):
        if i < ((Q + U) // 10): command_seq += 'u'
        else:
            t = rand_type(i / (Q+U))
            command_seq += t

    print(command_seq)
    print(command_seq.count('u'), command_seq.count('c'), command_seq.count('s'), )

    for i in trange(Q + U):
        c = command_seq[i]
        if c == 'u': generate_union()
        elif c == 'c': generate_random_strcmp()
        else: generate_hit_strcmp()
    # write all commands into file
    file_num = int(argv[1])
    fin = open(f'{file_num}.in', 'w')

    print(Q+U, file=fin)
    for i in range(Q+U):
        c = commands[i]
        print(f"{c[0]} {c[1]} {c[2]}", file = fin)

if __name__ == "__main__":
    main()
