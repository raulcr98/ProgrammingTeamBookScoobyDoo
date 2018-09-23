'''
    Vivo ejemplo de cuando crees que lo sabes todo y no sabes nada. Todo lo que esta afuera del comentario se resume a lo siguiente
    dic = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
    while(True):
        n = raw_input().split(" ")
        if n[0] == "0":
            break
        print("".join(([dic[(dic.find(x) + int(n[0]))] for x in n[1][::-1]])))
'''

from sys import stdout

alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."

def position(a):
    for i in range(len(alph)):
        if alph[i] == a:
            return i


def corrim(a, cant):
    for i in range(position(a), len(alph)):
        if cant == 0:
            return alph[i]
        cant -= 1
         
    for i in range(position(a)):
        if cant == 0:
            return alph[i]
        cant -= 1


while True:
   try:
      c, en = raw_input().split(' ')
      c = int(c)
   except Exception as e:
      break

   sol = []

   for i in range(len(en)):
       sol.append(corrim(en[i], c))

   sol.reverse()

   for i in range(len(sol)):
      stdout.write(str(sol[i]))

   stdout.write("\n")
