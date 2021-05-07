import random
import string
from disjoint_set import DisjointSet

N = int(5e3) # number of words in dictionary
M = int(1e2) # max length of a sentence
Q = int(4)
U = int(6)
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
        return 'c' if s < 0.5 else 's'
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
    print(f"{a}\nxxx\n{b}")
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
    a, b= rand_lang(l)
    commands.append(('compare', a, b))
    
def generate_hit_strcmp():
    l = rand_len()
    a, b = hit_lang(l)
    commands.append(('compare', a, b))

def main():
    global command_seq
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

    for c in command_seq:
        if c == 'u': generate_union()
        elif c == 'c': generate_random_strcmp()
        else: generate_hit_strcmp()
    # write all commands into file
    file_num = 0
    fin = open(f'{file_num}.in', 'w')


    for c in commands:
        print(f"{c[0]} {c[1]} {c[2]}", file = fin)

if __name__ == "__main__":
    main()

"""
union IUyB SiAs
union 5KCO wNt2
union m2WM a1A2
union STQr 3CuS
union 0Ar9 TbMZ
union jsjz rznq
compare D04iB29mVNtNHLNF7Xpofq8NRKEEVgX7y84l7cQ5v6k8clCJg01zwh464ab16GCmGGoRvbxiQvdLapmMCeByeKakYzGS4W02CiFyL9f316QaH96PMPduX9wuv3hPZrZpZLS3PDoxspKSfColwFBf0iRFMrIyMtBa oSSOvJF9vdpf6ER1CYYUsP5w0sgfoWRR47VDpyzsHO7nNJHCmBfa39NVkImB7zlYAMmRRCuJhApULr6rHRakxrg0f2kcsnr7b5QL9ocmpY4OLB4fSq8P3biQrnmRwelb118pv8OjKBdpMxmBwJCAGgnIA3rwGanR
compare IjGYidmSaV7dhwzPWnLtnlMa3JRxPkRTFxc8Ai5TswMogfTKVx75elqCilSPRwHzAjgp4rF21i2rnJzgFYpWVNYA2ZjWi89g6Y4udJgAGZz2VZYpstlHifvE5Ax0oY0LiFDpQZBJd3JGEYj6ghR0N2Py3vqUU9odYsHa7hDFS7fTYqzNEBSIWQdWf0Zuuq54tG1Epsf0wiuHBugIqSUoUzlXJy3VpFVn9Gu7iiEvdOPo1XTSChlpmneTw5nLmFl7dSDn53ywA6SOffyttO8YZTKpozAirrD4EreukgUq3Kr2qOQwLmTQPL3gaUwgJK4Nvtbuqf2gqypRmUSS0ShFzWIQn8730lYM Q41VBrsOPtanItFNDOINTSbmyBz6sRVUsJUWuzPlqiCrKQtFsnZCblzRBSGpefOeldLCPpq7QBpx7cBGfNjhQvunrsjJqeahY1MvoE4qjwQnW3bu0abPDftpm6r6AvbvoXGRPWkxMbQmyUtbtwnnbuva4qUIX5GJiGfboPpR7zDw9MMlRbCi9Y8aCul6nlMaJuCM4zcqwghkW7eMtgfEGCYrQUXaafzYo4O5t4OhYwhRhFkLRm2EwFUopqxgADSH4lkUFxc8spLsv0pCPwajBxXa3S2ArXb9YW4bPIBpeZh7BPZx59AtNGuUd3k9ZxYUjVwyk00LTj3I7QPoFpBW9mVne5CTJWxC
compare SiAsSiAsm2WMTbMZm2WMSTQrIUyBSTQrTbMZTbMZm2WMjsjzTbMZSTQrSTQrSTQrrznq0Ar9rznqm2WMSTQr3CuS3CuSSTQrSiAsrznqa1A2STQrIUyB5KCOSiAsa1A23CuSSiAsjsjza1A2rznqwNt25KCOjsjzwNt20Ar9a1A2a1A2IUyB5KCO5KCO5KCOrznq5KCOrznqSTQrTbMZTbMZ3CuSwNt2jsjzrznqa1A2rznqrznqa1A2TbMZSiAsrznq0Ar9 IUyBSiAsa1A2TbMZm2WMSTQrSiAsSTQrTbMZ0Ar9m2WMrznq0Ar93CuSSTQr3CuSjsjzTbMZrznqa1A23CuSSTQrSTQr3CuSSiAsjsjzm2WMSTQrSiAswNt2IUyBm2WMSTQrIUyBrznqm2WMjsjz5KCOwNt2rznq5KCO0Ar9a1A2a1A2IUyBwNt25KCOwNt2rznqwNt2jsjzSTQrTbMZTbMZSTQrwNt2jsjzjsjzm2WMjsjzjsjzm2WMTbMZSiAsrznq0Ar9
compare DugnwOKMkgbvy0ZiTa2XeU5AR5Y4al4fDCBNwEKc6a7jal4fN6N9Yfw9DnaLBoo4KwJpVWTB2lsPFckQhhF2W8l4dJsozmQXsoYe3biQv4oYsXZcH1viUGRpV5IBH9uAyWD0jUaOVmJ8fgPe28HV4Ky9jQKOBtv5MU1s49UPou7YTj3IQUXaFGDgZyvd AckNM6k5hXWmQMqwdhaY9mVniqlOM81QuY91MJx2Xijx7D4dAzsSZcP1DCBNTPXzTFvhgAw6LV8oXc8Kz17pWm9afjnqiHy6I5CVKcxFMgkoizqq18o059uYEvuUnfTrA1BSk58fx1EkDszAfColrlSHbK412va8ldX7Sg9dMbzx6ReO4qIzrsFUX8eU
uuuuuuccsc
"""