'''
지민 파티간다.
파티에서 인싸다
재밌는 얘기 말한다.
거짓말 보태면 더 재밌다.
근데 거짓말쟁이 되기 싫다.
아는 애 앞에서 거짓말 안한다.
거짓말 듣고 나중에 진실 들으면 들통난다.
이때도 미리 진실 말한다.
'''
'''
진실을 아는 사람이 섞여있을 때, 같이 애기를 들은 사람도 다
진실을 아는 사람이 된다.
이 점을 인지하면서 문제를 풀면 될 것 같은데? 
'''
def chain_true(num):
    global cnt

    true_set.add(num)
    if num in false_dict:
        for f in false_dict[num]:
            if lie_party[f] is True:
                lie_party[f] = False
                cnt -= 1

                if f in lie_dict:
                    for l in range(len(lie_dict[f])):
                        if lie_dict[f][l] not in true_set:
                            chain_true(lie_dict[f][l])


# N = 인원 수, M = 파티의 개수
N, M = map(int, input().split())

true_lis = list(map(int, input().split()))
true_set = set(true_lis[1:])

false_dict = {}
lie_party = [False for _ in range(M)]
lie_dict = {}

cnt = 0

for m in range(M):
    party_info = list(map(int, input().split()))
    members = party_info[0]
    party_members = party_info[1:]

    for e in range(members):
        if party_members[e] in true_set:
            for b in range(members):
                chain_true(party_members[b])

            break

    else:
        cnt += 1
        lie_party[m] = True
        lie_dict[m] = party_members
        for r in range(members):
            if party_members[r] not in false_dict:
                false_dict[party_members[r]] = [m]

            else:
                false_dict[party_members[r]].append(m)

print(cnt)
