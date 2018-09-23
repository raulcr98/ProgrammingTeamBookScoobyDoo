import sys

raw_input=lambda:sys.stdin.readline().rstrip()
input=lambda:int( raw_input() )

n = int(raw_input())

while n > 0:
	a = raw_input().split(' ')
	for i in range(0, 4):
		if a[i] + 1 != a[i + 1]:
			print "N"
			continue
		print "Y"
	n -= 1