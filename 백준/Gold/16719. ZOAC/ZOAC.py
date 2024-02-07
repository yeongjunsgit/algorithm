'''
성우는 ZOAC의 오프닝을 담당하게  되었다.
화려하게 오프닝을 시작하고 싶은 성우는 타이틀을 사전순으로 한글자씩 보여주고 싶어한다.
주어지는 타이틀이 사전순으로 출력되는 과정을 출력하자!
'''
'''
모든 입력이 대문자로 주어지니까 인덱스값을 가진채로 사전순으로 정렬해서 넣은 후에 처음 인덱스 값에 맞게 출력해주면 어떨까?
아아 단어를 사전별로 넣는게 아니라...
넣어서 완성되는 중간타이틀들이 사전순으로 나와야한다.
맨처음 가장 작은 사전순의 문자 중 가장 인덱스 값이 낮은 알파벳을 넣고 
인덱스값 뒤에있는 다음 사전순 문자를 출력, 더 이상 없다면 다시 전체에서 확인하는 식이면 좋을듯?
아스키 코드를 이용하자... 0부터 끝까지 구간을 나누어 해당 값중 가장 사전순으로 빠른 값을 원래 인덱스 값에 넣고
거기서 부터 다시 범위로 하여 찾는다 만약 해당 구간을 다 찾았다면 다시 나와서 마저 찾는다.
그런식으로 가면될거같은데...
'''
def find_min(start, end):
    while True:
        target = min(title[start:end])
        if target == '[':
            return

        for i in idx_dict[target]:
            if start <= i <= end:
                new_title[i].append(target)
                title[i] = '['
                idx_dict[target].remove(i)

                for j in range(N):
                    if new_title[j]:
                        print(new_title[j][0], end="")

                print()

                find_min(i, end)
                break


title = list(input())

N = len(title)

new_title = [[] for _ in range(N)]
idx_title = []
idx_dict = {}

for t in range(N):
    if title[t] not in idx_dict:
        idx_dict[title[t]] = [t]
    else:
        idx_dict[title[t]].append(t)

    idx_title.append([title[t], t])

sort_title = sorted(title)
cnt = 0

find_min(0, N)
