N, M = map(int, input().split())

eruda = list(map(int, input().split()))
origin = list(map(int, input().split()))

eruda.sort()
origin.sort()

use_eruda = 0
use_origin = 0

timing_e = 0
timing_o = 0

for i in eruda:
    if timing_e == 0:
        use_eruda += 1
        timing_e = 100 + int(i)

    else:
        if timing_e > int(i):
            continue

        else:
            use_eruda += 1
            timing_e = int(i) + 100

for j in origin:
    if timing_o == 0:
        use_origin += 1
        timing_o = 360 + int(j)

    else:
        if timing_o > int(j):
            continue

        else:
            use_origin += 1
            timing_o = int(j) + 360

print(f'{use_eruda} {use_origin}')