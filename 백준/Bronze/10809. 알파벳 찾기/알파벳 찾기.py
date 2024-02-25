word = list(input())

idx_dict = {}

alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
         'v', 'w', 'x', 'y', 'z']

for w in range(len(word)):
    if word[w] not in idx_dict:
        idx_dict[word[w]] = w


for a in alpha:
    if a in idx_dict:
        print(idx_dict[a], end=' ')

    else:
        print('-1', end=' ')
