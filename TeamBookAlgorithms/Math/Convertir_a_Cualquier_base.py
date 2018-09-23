def aCadena(n,base):
   cadenaConversion = "0123456789ABCDEF"
   if n < base:
      return cadenaConversion[n]
   else:
      return aCadena(n//base,base) + cadenaConversion[n%base]

print(aCadena(14,16))