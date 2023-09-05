word_dict = {'000000': 'A', '001111': 'B', '010011': 'C',
             '011100': 'D', '100110': 'E', '101001': 'F',
             '110101': 'G', '111010': 'H'}
word_list = ['000000', '001111', '010011', '011100', '100110', '101001', '110101', '111010']

N = int(input())

arr = list(input())

tmp = []

result = []
ok = True

for i in range(0, (N*6), 6):
    if ok is True:
        cnt = 0
        tmp.append(arr[i])
        tmp.append(arr[i+1])
        tmp.append(arr[i+2])
        tmp.append(arr[i+3])
        tmp.append(arr[i+4])
        tmp.append(arr[i+5])

        tmp_word = ''.join(tmp)

        if tmp_word in word_list:
            result.append(word_dict[tmp_word])
            tmp = []

        else:
            for j in range(6):
                if tmp[j] == '0':
                    tmp[j] = '1'

                else:
                    tmp[j] = '0'

                tmp_change = ''.join(tmp)
                if tmp_change in word_list:
                    result.append(word_dict[tmp_change])
                    tmp = []
                    break
                else:
                    cnt += 1

                    if cnt == 6:
                        result = (int(i)+1) // 6
                        ok = False
                        break
                    if tmp[j] == '0':
                        tmp[j] = '1'
                    else:
                        tmp[j] = '0'
if ok is True:
    result = ''.join(result)
    print(result)
else:
    print(result+1)

