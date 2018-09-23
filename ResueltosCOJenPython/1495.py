import sys

raw_input=lambda:sys.stdin.readline().rstrip()
input=lambda:int(raw_input())

a = int(raw_input())
list = []
	
while a > 0:
	list.append(int(raw_input()))
	a -= 1

list.sort()

for i in list:
	print i