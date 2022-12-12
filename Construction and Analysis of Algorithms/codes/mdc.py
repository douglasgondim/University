def mdc(a,b):
    if(b == 0): return a
    resto = a%b
    return mdc(b, resto)

print(mdc(124, 21))