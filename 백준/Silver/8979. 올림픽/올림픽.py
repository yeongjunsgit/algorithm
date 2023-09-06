N, K = map(int, input().split())

grade = [[] for _ in range(N+1)]
my_grade = []

for n in range(N):
    c, g, s, b = map(int, input().split())
    my_grade.append([c, g, s, b])

my_grade.sort(key=lambda x:x[1], reverse=True)

grade[1].append(my_grade[0][0])
now_grade = 1

for i in range(1, N):
    if my_grade[i-1][1] == my_grade[i][1]:
        if my_grade[i-1][2] == my_grade[i][2]:
            if my_grade[i-1][3] == my_grade[i][3]:
                grade[now_grade].append(i+1)
            else:
                now_grade += 1
                grade[now_grade].append(i+1)
        else:
            now_grade += 1
            grade[now_grade].append(i+1)
    else:
        now_grade += 1
        grade[now_grade].append(i+1)

for i in range(N+1):
    if K in grade[i]:
        print(i)