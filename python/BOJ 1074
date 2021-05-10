문제
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.


만약, N > 1이 라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

다음 예는 22 × 22 크기의 배열을 방문한 순서이다.

N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음은 N=3일 때의 예이다.


입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
1 ≤ N ≤ 15
0 ≤ r, c < 2N
예제 입력 1 
2 3 1
예제 출력 1 
11
예제 입력 2 
3 7 7
예제 출력 2 
63

---------------------------------------------------------------------------------

# 데이터의 개수가 많을때는 sys.stdin.readline()을 사용해야 빠르다
import sys
def square(size, x, y, r, c):
    if (r < x + size/2):
        if (c < y + size/2):
            return 1
        else:
            return 2
    else:
        if (c < y + size/2):
            return 3
        else:
            return 4
N, r, c = input().split()
N = int(N)
startx, starty, result = 0,0,0
while N > 0:
    size = 2 ** int(N)
    pos = square(size, startx, starty, int(r),int(c))
    sumsize = int((size/2) ** 2)
    if pos == 2:
        starty += size/2
        result += sumsize
    elif pos ==3:
        startx += size/2
        result += sumsize * 2
    elif pos == 4:
        startx += size/2
        starty += size/2
        result += sumsize * 3
    N -= 1
print(result)
