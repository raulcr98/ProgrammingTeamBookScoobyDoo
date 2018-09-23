import sys

raw_input=lambda:sys.stdin.readline().rstrip()
input=lambda:int(raw_input())

while 1:
	a = raw_input()

	if a == "0":
		break;

	p = im = c = 0

	for i in a:
		if c % 2 == 0:
			p += int(i)
		else:
			im += int(i)
		c += 1

	if (p - im) % 11 == 0:
		print a, "is a multiple of 11."
	else:
		print a, "is not a multiple of 11."