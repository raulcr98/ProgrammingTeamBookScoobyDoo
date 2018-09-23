a = input() 

fq = [int(0) for i in range(1, 200)]
sol = 0

for i in a:
        fq[ord(i)] += 1

for i in a:
        if fq[ord(i)] != 0:
                sol += (fq[ord(i)] - 1)

sol += len(a)

print(sol)
