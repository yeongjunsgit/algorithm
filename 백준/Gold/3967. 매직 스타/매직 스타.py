'''
매직 스타는 1부터 12까지 숫자가 헥사그램에 채워져있는 모양으로 이루어져 있다.
매직 스타의 이름에 매직이 들어가는 이유는 숫자 네게로 이루어진 줄의 숫자를 모두 합하면 26이 돠기 때문이다.
매직 스타를 채우는 방법은 여러 가지가 있다. 일부만 채워진 매직스타가 주어졌을 때, 수를 전부 다 채워서
매직 스타를 만드는 프로그램을 만들어라.
x = 비어있는 구간
A~L 까지의 알파벳 = 1~12까지의 숫자를 뜻한다
매직스타를 만들 수 있는 방법 중에 사전 순으로 가장 앞서는 방법을 출력한다.
(모든 줄을 순서대로 붙여서 하나의 문자열로 만든 뒤, 사전 순으로 비교한다)(이걸 알려주네 ㄳㄳ)
'''
'''
흠 합이 26이 되어야한다는 건데 어렵네... 흠 각 위치를 배열로 받아서 인덱스 값으로 조절 하면 어떨까?
1개의 선이 이루어지는 경우를 각각 배열에 저장하고, 각각 위치를 변수로 넣어서 다루면 편하지 않을까?
괜찮은듯!
'''
def perm(now, end):
    if now == end:
        tmp = [sum([pq[0], pq[2], pq[5], pq[7]]),
               sum([pq[0], pq[3], pq[6], pq[10]]),
               sum([pq[1], pq[2], pq[3], pq[4]]),
               sum([pq[1], pq[5], pq[8], pq[11]]),
               sum([pq[4], pq[6], pq[9], pq[11]]),
               sum([pq[7], pq[8], pq[9], pq[10]])
               ]
        for t in tmp:
            if t != 26:
                break
        else:
            make_magic.append(pq.copy())

        return

    else:
        # 시간 초과가 나서 해당 구문을 추가했다 낮은 값부터 넣어보고 있으니까
        # 가장 처음 완성된게 사전 상 제일 앞에 있는 값이 아닐까?
        if make_magic:
            return
        if pq[now] == 0:
            for i in range(1, 13):
                if used[i] != 1:
                    used[i] = 1
                    pq[now] = i
                    perm(now+1, end)
                    used[i] = 0
                    pq[now] = 0

        else:
            perm(now+1, end)


magic_star = [list(input()) for _ in range(5)]

alpha_to_num = {'A': 1, 'B': 2, 'C': 3, 'D': 4, 'E': 5, 'F': 6, 'G': 7, 'H': 8,
                'I': 9, 'J': 10, 'K': 11, 'L': 12}

num_to_alpha = {1: 'A', 2: 'B', 3: 'C', 4: 'D', 5: 'E', 6: 'F', 7: 'G', 8: 'H',
                9: 'I', 10: 'J', 11: 'K', 12: 'L'}

pq = [0] * 12
used = [0] * 13
make_magic = []

stars = [magic_star[0][4], magic_star[1][1], magic_star[1][3], magic_star[1][5],
         magic_star[1][7], magic_star[2][2], magic_star[2][6], magic_star[3][1],
         magic_star[3][3], magic_star[3][5], magic_star[3][7], magic_star[4][4]]


for s in range(12):
    if stars[s] != 'x':
        pq[s] = alpha_to_num[stars[s]]
        used[alpha_to_num[stars[s]]] = 1

perm(0, 12)

# make_magic.sort()

cnt = 0
for p in range(5):
    for q in range(9):
        if magic_star[p][q] != '.':
            magic_star[p][q] = num_to_alpha[make_magic[0][cnt]]
            cnt += 1

for z in range(5):
    print(''.join(magic_star[z]))
