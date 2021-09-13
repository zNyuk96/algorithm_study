# https://programmers.co.kr/learn/courses/30/lessons/12929
import sys


def solution(n):
    memo = [[0 if row != 0 else 1] * (n + 1) for row in range(n + 1)]  # '(' 와 ')'의 남은 개수에 따른 경우의 수 저장
    # '('가 0개 남은 경우는 남은 ')'을 모두 쓰는 경우 1가지 밖에 없음

    for row in range(1, n + 1):
        for col in range(row, n + 1):
            memo[row][col] = (memo[row - 1][col] + memo[row][col - 1]) % 1000000007

    return memo


if __name__ == '__main__':
    memo = solution(2500)

    for _ in range(int(sys.stdin.readline())):
        n = int(sys.stdin.readline())

        if n % 2:
            print(0)
        else:
            print(memo[n // 2][n // 2])
