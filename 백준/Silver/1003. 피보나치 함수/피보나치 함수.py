# 재귀문 이용했더니 런타임에러 발생
# 점화식(패턴)을 찾아낸다. 
# 입력 값 n에 대한 0(또는 1)의 호출 횟수 = 입력 값 n-1 에 대한 0(또는 1)의 호춣 횟수 + 입력값 n-2 에 대한 0의 호출횟수

# 각 리스트에 연산 결과(0 또는 1에 대한 호출횟수)를 append 해나간다.
zero = [1,0,1] # 0의 호출횟수 리스트
one = [0,1,1] # 1의 호출횟수 리스트

testCase = int(input())

def fib(num):
    length = len(zero)
    if length <= num:
        for i in range(length,num+1):
            zero.append(zero[i-1]+zero[i-2])
            one.append(one[i-1]+one[i-2])
    print("%d %d"%(zero[num],one[num]))

for _ in range(testCase):
    a = int(input())
    fib(a)