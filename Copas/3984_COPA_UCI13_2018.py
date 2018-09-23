'''
	By tassK!ll
'''
import sys

raw_input=lambda:sys.stdin.readline().rstrip()
input=lambda:int(raw_input())

a = raw_input()

sol = a[0]
leng = 1

for i in range(1, len(a)):
	if ant == a[i]:
		lena += 1
	else:
		if leng < lena:
			sol = ant
			leng = lena
		ant = a[i]
		lena = 1

if leng < lena:
	sol = ant
	leng = lena

print (str(leng) + " " + str(sol) + "\n")
