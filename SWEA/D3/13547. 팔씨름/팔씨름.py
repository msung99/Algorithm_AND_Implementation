T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    print(f'#{test_case}', end=' ')
    game_result = input()
    win_cnt = 0
    for result in game_result:
        if result == 'o':
            win_cnt += 1

    rest_game = 15 - len(game_result)
    if win_cnt + rest_game >= 8:
        print('YES')
    else:
        print('NO')
