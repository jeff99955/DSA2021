ds = "array, linked list, doubly linked list, stack, queue, deque, tree, heap, BST, disjoint set, hash table, RBTree, BTree, adjacency list, adjacency matrix".split(', ')

a = "binary search, linear search, divide and conquer, infix to postfix, parenthesis matching, postfix evaluation, selection sort, insertion sort, heap sort, insertion sort, shell sort, merge sort, tree sort, quick sort, Rabin-Karp, KMP, naive string compare, counting sort, radix sort, bucket sort, union by rank, union by size, path compression, linear probing, chaining, RBTree insertion, RBTree deletion, RBTree rotation, DFS, BFS, Topological Sort".split(', ')

k = [
        [ "課堂活動", "after class quizzes only", "kahoot", "學習單", "大地遊戲"],
        [ "上課互動", "slido", "YouTube 聊天室", "Cool 留言", "email" ],
        [ "hw", "HW0", "HW1", "HW2", "HW3" ],
    ]
custom = ['介紹一個你這學期學到最喜歡、最討厭或印象深刻的資料結構或演算法',
         '你覺得生活中，你最常用到資料結構或演算法的是哪個？為什麼？',
         '你覺得生活中，你覺得最少資料結構或演算法用到是哪個？為什麼？',
         '你覺得生活中，你覺得花你最多時間或力氣的資料結構或演算法是哪個？為什麼？',
        ]
chance = ['下次答題 + 10 sec', '下次答題 - 10 sec', '下次答題成功 往前3格', '下次答錯失敗 往後3格', '下次答題成功 往前2格', '下次答錯失敗 往後2格', '下次答題成功 往前1格', '下次答錯失敗 往後1格', '冷凍一回合，下次從特別重生點開始', '前進1格', '後退1格', '前進2格', '後退2格']

import random, time

TEXT_RESET = "\u001B[0m"
TEXT_YELLOW = "\u001b[33m"
TEXT_RED = "\u001B[31m"
TEXT_CYAN = "\u001B[36m"

def dice(r):
    C='● '
    s='-------\n| '+C[r<1]+' '+C[r<3]+' |\n| '+C[r<5]
    return (s+C[r&1]+s[::-1])

def choise(x):
    return TEXT_RED + str(random.choice(x)) + TEXT_RESET

def sel(x):
    return TEXT_YELLOW + x + TEXT_RESET

def q1():
    return "用三個動詞介紹" + choise(ds + a)

def q2():
    return "用三個名詞介紹" + choise(ds + a)

def q3():
    return "用三個形容詞介紹" + choise(ds + a)

def q4():
    return "簡單介紹" + choise(ds + a) + "及其時間，空間"

def kehuo():
    kc = random.choice(k)
    return "根據" + TEXT_YELLOW + "喜歡的程度" + TEXT_RESET + "sort\n" + TEXT_CYAN + kc[0] + ": " + str(kc [1:])+ TEXT_RESET+ "\n，並說明原因。"

def countdown(t = 60):
    while t:
        try:
            mins, secs = divmod(t, 60)
            timer = '{:02d}:{:02d}'.format(mins, secs)
            print(timer, end="\r")
            time.sleep(1)
            t -= 1
        except KeyboardInterrupt:
            break
    print('時間到')

questions = []

for i in (ds + a):
    questions.append("用三個動詞介紹" + sel(i))
    questions.append("用三個名詞介紹" + sel(i))
    questions.append("用三個形容詞介紹" + sel(i))
    questions.append("簡單介紹" + sel(i) + "及其時間，空間")

for i in k:
    for _ in range(30):
        questions.append("根據" + TEXT_YELLOW + "喜歡的程度" + TEXT_RESET + "sort\n" + TEXT_CYAN + i[0] + ": " + str(i[1:])+ TEXT_RESET+ "\n，並說明原因。")

for i in custom:
    for _ in range(30):
        questions.append(i)

random.seed()
input("Press Enter to Begin.......")
print(random.choice(("紅方先", "綠方先")))
while True:
    print("(1) q for question (2) d for dice (3) c for 機會 (4) e for exit", end=": ")
    cmd = input()
    if len(cmd) == 0:
        continue
    if cmd[0] == "q" or cmd[0] == "1":
        print(random.choice(questions))
        countdown()
    elif cmd[0] == "d" or cmd[0] == "2":
        print(dice(random.randint(0,2)))
    elif cmd[0] == 'c' or cmd[0] == '3':
        print("機會: " + TEXT_RED + random.choice(chance) + TEXT_RESET)
    elif cmd[0] == "e":
        break
    else:
        print("Invalid Command")

for i in range(2):
    print(q1())
    print(q2())
    print(q3())
    print(q4())
