import sys
input = sys.stdin.readline

def kmp_table(text, pattern):

    pt, pp = 1, 0
    table = [0 for _ in range(maxi+1)]

    while pt != maxi:
        if pattern[pt] == pattern[pp]:
            pt, pp = pt+1, pp+1
            table[pt] = pp
        elif pp == 0:
            pt += 1
        else:
            pp = table[pp]

    pt = pp = 0

    while pt != maxi*2 and pp != maxi:
        if text[pt] == pattern[pp]:
            pt, pp = pt+1, pp+1
        elif pp == 0:
            pt += 1
        else:
            pp = table[pp]

    if pp == maxi:
        print("possible")
        return

    print("impossible")
    return

n = int(input())
maxi = 360000
r1, r2 = list(map(int,input().split())), list(map(int,input().split()))
text, pattern = ['0' for _ in range(maxi)], ['0' for __ in range(maxi)]

for i in range(n):
    text[r1[i]] = '1'
    pattern[r2[i]] = '1'

text, pattern = ("".join(text)) * 2, "".join(pattern)
kmp_table(text, pattern)