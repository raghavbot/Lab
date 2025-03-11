def evaluate(postfix):
    token=postfix.split()
    stack=[]
    operators=('*','-','+','/','^')
    for a in token:
        if a not in operators:
            stack.append(float(a))
        else:
            op1=stack.pop()
            op2=stack.pop()
            if a=='*':
                result=op1*op2
            elif a=='-':
                    result=op1-op2
            elif a=='+':
                    result=op1+op2
            elif a=='/':
                    result=op1/op2
            elif a=='^':
                    result=op2**op1
            stack.append(result)
    return stack[0]
postfix=input("Enter your postfix:")
result=evaluate(postfix)
print(result)