self_numbers = set() # 셀프 넘버들
gen_numbers = set() # 생성자가 있는 숫자들

for i in range(1,10001):
    self_numbers.add(i)

for num in range(1,10001):
    for i in str(num): # 각 자리의 숫자를 원본 숫자에 더함
        num += int(i)
    gen_numbers.add(num)  # 계산된 결과를 생성자 집합에 추가

result = list(self_numbers - gen_numbers) # 1~10000 숫자를 저장해놨던 집합에서 생성자 숫자들을 제거하고 셀프 넘버들로 구성
result.sort()

for x in result:
    print(x)