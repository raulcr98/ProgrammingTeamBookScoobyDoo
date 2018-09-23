import sys
raw_input=lambda:sys.stdin.readline().rstrip()
input=lambda:int(raw_input())

A, B = raw_input().split(' ')
A = int(A)
B = int(B)

R = (A+B) + (A-B) + (B+A) + (B-A)

print R