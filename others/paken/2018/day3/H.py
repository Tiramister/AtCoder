m = int(input())

out = ""
n = m

while n > 0:
    out += "+1"
    ex = 0

    while 5 ** (ex + 1) <= n:
        ex += 1

    for i in range(ex):
        out += "*5"

    out += "*" + str(n // (5 ** ex))
    n %= (5 ** ex)

out = out.replace("*1", "")
out = out.replace("1*", "")
out = out[1:]

print(out)
