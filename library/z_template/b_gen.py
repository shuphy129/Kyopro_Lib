# 乱数 randintは閉区間(以上&以下)
# N = randint(1, 10)
# print(N)

# 配列
# A = [randint(1, 10) for _ in range(N)]
# print(*A)
# 区切り文字を変えるとき: print(*A, sep="")

# 文字列 
# S = [choice(string.ascii_lowercase) for _ in range(N)]
# print("".join(S))

# 1~Nの順列
# A = list(range(1, N+1))
# shuffle(A)
# print(*A)

# ---

from random import randint
from random import shuffle
from random import choice
import string

def test_case():
    # ここから
    N = randint(4, 4)
    print(N)
    for i in range(3):
        S = []
        for _ in range(N):
            S.append(0)
        for _ in range(N):
            S.append(1)
        shuffle(S)
        print(*S, sep="")

# テストケース形式なら print(T)
T = randint(1, 1)
# print(T)
for _ in range(T):
    test_case()