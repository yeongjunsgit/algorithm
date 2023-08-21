word = list(input())

N = len(word)
cnt = 1
for i in range(1, N):
    cnt += 1
    if word[i] == 'j':
        if word[i-1] == 'n' or word[i-1] == 'l':
            cnt -= 1
    elif word[i] == '=':
        if word[i-1] == 'c' or word[i-1] == 's':
            cnt -= 1
        elif word[i-1] == 'z':
            if word[i-2] == 'd':
                cnt -= 2
            else:
                cnt -= 1
    elif word[i] == '-':
        if word[i-1] == 'c' or word[i-1] == 'd':
            cnt -= 1

print(cnt)
