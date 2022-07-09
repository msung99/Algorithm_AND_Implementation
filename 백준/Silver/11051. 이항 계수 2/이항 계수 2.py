import sys
input = sys.stdin.readline

N, K = map(int, input().split())

# 파스칼 삼각형을 활용한 DP 풀이 (nCk = (n-1)C(k-1) + (n-1)Ck)
# 비어있는 파스칼 삼각형 구축해놓기
pascal = [0]
for depth in range(2, N+2):
    pascal.append([0]*depth)

# pascal[i] = [1, ?, ?, ..., ?, 1]에서 i는 nCk에서 n, 리스트의 인덱스는 k를 의미
# nC0 = 1
pascal[1] = [1, 1]

for depth in range(2, N):
    pascal[depth][0] = 1
    for idx in range(1, depth):
        pascal[depth][idx] = (pascal[depth-1][idx-1] + pascal[depth-1][idx]) % 10007
    pascal[depth][-1] = 1

if K == 0 or K == N:
    print(1)
else:
    print((pascal[N-1][K-1] + pascal[N-1][K]) % 10007)