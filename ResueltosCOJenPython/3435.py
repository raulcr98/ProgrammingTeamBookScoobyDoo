'''
    se puede optimizar la entrada y la salida con stdin.readline().strip() y stdout.write()
'''

N = int(raw_input())

cad = [str(raw_input()) for i in range(N) ]
sol = []
cad.sort()

for i in range(N):
    for j in range(N):
        if len(cad[j]) < len(cad[i]) and cad[j] in cad[i]:
            sol.append([j, i])

sol.sort()
print (len(sol))
for i in sol:
    print (cad[i[0]] + " " + cad[i[1]])
