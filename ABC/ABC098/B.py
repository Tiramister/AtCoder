n = int(input())
s = str(input())

ans = 0
for i in range(1, n):
    f = s[:i]
    b = s[i:]
    cnt = 0
    for c in [chr(j + ord('a')) for j in range(26)]:
        if c in f and c in b:
            cnt += 1
    ans = max(ans, cnt)

print(ans)
