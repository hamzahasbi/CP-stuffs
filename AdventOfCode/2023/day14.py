from bisect import bisect_left
from bisect import insort


def binarySearch(array, x):
    low = 0
    high = len(array) - 1
    while low <= high:

        mid = low + (high - low)//2
        if array[mid] == x:
            return mid

        elif array[mid] < x:
            low = mid + 1

        else:
            high = mid - 1

    return -1

grid = []
with open("../../io/input.in") as fp:
    Lines = fp.readlines()
    for line in Lines:
        enhanced = list(line.strip())
        grid.append(enhanced)



n = int(len(grid))
m = int(len(grid[0]))
# grid.reverse()
bag = {}
in_place = {}
for j in range(0, m):
  bag[j] = []
  for i in range(0, n):
    if (grid[i][j] == '.'):
        bag[j].append(i)
    in_place[i] = 0

start = n;
for i in range(0, n):
    for j in range(0, m):
       if (grid[i][j] == 'O'):
          if (i == 0):
             in_place[i] += 1
            #  bag[j].pop(0)
             continue
          k = i - 1
          soFar = i
          used = -1
          while (k >= 0 ):
            target = binarySearch(bag[j], k)
            if (target == -1) :
               break
            soFar = k
            used = target
            k -= 1
          # print("looking for ", i, j, " Matching ", soFar)
          if (used != -1 ):
            bag[j].pop(used)
            insort(bag[j], i)
          in_place[soFar] += 1


ans = 0
for line in in_place:
    ans += in_place[line] * start
    start -= 1

print(ans)

