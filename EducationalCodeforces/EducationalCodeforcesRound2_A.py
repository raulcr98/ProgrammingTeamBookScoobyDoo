a = input().split(',')

b = []

for i in a:
	b.append(i.split(';'))

num = []
alpha = []

for i in b:
	for j in i:
		flag = 0
		if (len(j) == 0) or (len(j) > 1 and j[0] == '0'):
			alpha.append(j)
			continue
		for l in j:
			if l >= '0' and l <= '9':
				continue
			else:
				flag = 1
		if flag == 1:
			alpha.append(j)
		else:
			num.append(j)


if len(num) == 0:
    print('-')
else:
    sal = '"'
    sal = sal + num[0]
    for i in range(1, len(num)):
        sal = sal + ',' + num[i]
    sal = sal + '"'
    print (sal)
if len(alpha) == 0:
    print('-')
else:
    sal = '"'
    sal = sal + alpha[0]
    for i in range(1, len(alpha)):
        sal = sal + ',' + alpha[i]
    sal = sal + '"'
    print (sal)
