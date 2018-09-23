'''
	Busqueda Binaria
	By tassK!ll
'''
import sys

raw_input=lambda:sys.stdin.readline().rstrip()
input=lambda:int(raw_input())

a, b, c, d = raw_input().split(' ')
a, b, c, d = int(a), int(b), int(c), int(d)

ini = 0
fin = 10 ** 18

while fin > ini:
	m = ini + fin
	m /= 2

	pv, sv, tv = int(m / c), int(m / d), int(m / (c * d))

	val = m - pv - sv + tv

	pv -= tv
	pv = b - pv
	sv -= tv
	sv = a - sv
	if pv < 0:
		pv = 0
	if sv < 0:
		pv = 0
	if pv + sv  <= val:
		fin = m
	else:
		ini = m + 1

print (int(fin))
