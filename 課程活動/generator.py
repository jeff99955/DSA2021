import random
import string

n = int(5e2) # number of words
m = int(1) # max length of words
Q = int(4e4) # number of query
U = int(6e4) # number of union operation
stringset = []
compset, unionset = [], []
charset = string.digits + string.ascii_letters

def rand_str():
    return ''.join(random.choice(charset) for i in range(4))

def rand_type(prob: float):
    r = random.uniform(0, 1)
    if r < prob:
        return 'compare'
    return 'union'

def rand_lang(length: int) -> string:
    ret = ''
    for i in range(length):
        r = random.uniform(0, 1)
        ret += random.choice(stringset)
    if ret == '':
        print(length)
    return ret

def rand_len() -> int:
    return 1
    # ret = random.uniform(1, m * 10)
    # while ret > m:
    #     ret //= 2
    # return int(ret)

while len(stringset) < n:
    stringset.append(rand_str())


for i in range(Q):
    target_length = rand_len()
    compset.append((rand_lang(target_length), rand_lang(target_length)))

for i in range(U):
    unionset.append((rand_str(), rand_str()))

# print(compset)
# print(unionset[:10])

f = open('0.in', 'w')
print(Q+U, file = f)
q, u = Q, U
for i in range(Q + U):
    t = rand_type(i / (Q + U))
    if q == 0:
        print('union', unionset[u - 1][0], unionset[u - 1][1], file = f)
        u -= 1
    elif u == 0:
        print('compare', compset[q - 1][0], compset[q - 1][1], file = f)
        q -= 1
    else:
        pr = rand_type(i / (Q + U) / 10)
        if pr == 'union':
            print('union', unionset[u - 1][0], unionset[u - 1][1], file = f)
            u -= 1
        else:
            print('compare', compset[q - 1][0], compset[q - 1][1], file = f)
            q -= 1