T = int(raw_input())

while T > 0:
        T -= 1
        cw = int(raw_input())

        words = [str(raw_input()) for i in range(cw)]
        sol = ""

        while len(words) > 0:
                words.sort()
                lon = len(words) - 1
                sol += words[lon][0]
                words[lon] = words[lon][1:len(words[lon])]
                if len(words[lon]) == 0:
                        del words[lon]

        print (sol)

