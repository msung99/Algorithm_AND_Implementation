def is_seq():
    global b
    for i in range(0, len(b)-1):
        if(b[i] != b[i+1]):
            return False
    return True


num = int(input())
a = list()
b = list()
count = 0


for x in range(1, num+1):
    a = list(map(int,str(x)))
    b.clear()
    for i in range(0, len(a)-1):
        b.append(a[i+1]-a[i])
    if(is_seq()):
        count += 1
        
print(count)
