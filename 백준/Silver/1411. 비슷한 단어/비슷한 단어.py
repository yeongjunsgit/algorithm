'''
어떤 단어 A를 다른 단어 B로 만들 수 있다면 이 두 쌍을 비슷한 단어라고 한다.
단, 다른 단어로 바꿀때는 A에 등장하는 모든 알파벳을 다른 알파벳으로 바꿔야한다.
그리고, 단어에 등장하는 알파벳의 순서는 바뀔 수 없다. 두 개의 다른 알파벳을 하나의 알파벳으로 바꿀 수 없고,
임의의 알파벳을 자기 자신으로 바꾸는 것은 가능하다.
예시로 abca와 zbxz가 있다고 가정하자. a는 z로 바꾼다(이떄, a가 2개이므로, 2개 다 바뀜) b는 그대로 b,
c를 x로 바꾸면 zbxz로 바뀌게 된다.
이와 같이 A를 B로 바꿀 수 있는 쌍의 개수를 구하여라
'''
'''
우선 모든 알파벳이 전부 바꿔지길 시도해야한다.
자기 자신으로 바꿀 수는 있지만, 이미 사용한 알파벳을 또 쓸 수는 없다.
이 조건을 지키면서 가능한 경우의 수를 찾자.
브루트 포스 일듯!
'''


def judgement(a, b):
    used = []
    match = {}
    tmp_lis = [0] * len(a)
    for i in range(len(a)):
        if a[i] in match:
            tmp_lis[i] = match[a[i]]

        else:
            if b[i] not in used:
                match[a[i]] = b[i]
                used.append(b[i])
                tmp_lis[i] = b[i]

            elif b[i] in used:
                return 0

    else:
        if tmp_lis == b:
            return 1
        else:
            return 0

# N = 단어의 개수
N = int(input())

words = []

for n in range(N):
    word = list(input())
    words.append(word)

cnt = 0

for p in range(N):
    for q in range(p+1, N):
        cnt += judgement(words[p], words[q])

print(cnt)
