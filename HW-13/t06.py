def f(e,i=0):
    if e[i] in '+-*/':
        n={'op':e[i],'l':None,'r':None}
        l,li=f(e,i+1)
        r,ri=f(e,li)
        n['l']=l
        n['r']=r
        return n,ri
    else:
        return {'op':e[i]},i+1

def p(n):
    prec={'+':1,'-':1,'*':2,'/':2}
    if len(n)==1:
        return n['op']
    l=n['l']
    r=n['r']
    op=n['op']
    sL=p(l)
    sR=p(r)
    pl=prec.get(l['op'],3)
    pr=prec.get(r['op'],3)
    po=prec[op]
    if pl<po: sL='('+sL+')'
    if pr<po or (pr==po and op in '-/'): sR='('+sR+')'
    return sL+op+sR

x=input().strip()
tree,_=f(x)
print(p(tree))