import time

A=[
    [0,1,3],
    [0,8,4],
    [0,7,5],
    [0,0,6],
    [0,3,8],
    [0,5,9],
    [0,4,12],
    [0,1,13],
    [0,1,16],
    [1,9,3],
    [1,4,7],
    [1,9,8],
    [1,1,9],
    [1,2,13],
    [1,0,15],
    [1,5,18],
    [2,0,3],
    [2,8,6],
    [2,7,7],
    [2,2,9],
    [2,2,10],
    [2,3,12],
    [2,8,14],
    [2,7,17],
    [2,8,18],
    [2,1,19],
    [3,5,4],
    [3,7,6],
    [3,8,9],
    [3,7,11],
    [3,4,15],
    [3,2,17],
    [3,4,19],
    [4,3,5],
    [4,4,6],
    [4,7,9],
    [4,9,10],
    [4,5,17],
    [4,2,18],
    [5,5,6],
    [5,4,10],
    [5,5,12],
    [5,2,13],
    [5,6,18],
    [6,8,7],
    [6,0,10],
    [6,9,12],
    [6,5,13],
    [6,9,15],
    [6,7,17],
    [6,3,18],
    [7,9,8],
    [7,8,9],
    [7,8,11],
    [7,9,13],
    [7,3,15],
    [7,2,16],
    [7,0,17],
    [7,1,18],
    [8,6,9],
    [8,4,10],
    [8,5,12],
    [8,0,13],
    [8,0,14],
    [8,3,17],
    [8,3,18],
    [8,7,19],
    [9,8,10],
    [9,7,11],
    [9,7,13],
    [9,2,14],
    [9,6,15],
    [9,2,16],
    [9,5,17],
    [9,1,19],
    [10,5,11],
    [10,3,15],
    [10,9,18],
    [11,9,13],
    [11,6,14],
    [11,9,15],
    [11,1,16],
    [11,6,17],
    [11,6,18],
    [11,5,19],
    [12,3,14],
    [12,9,15],
    [12,7,16],
    [12,4,18],
    [13,7,14],
    [13,1,16],
    [13,7,17],
    [13,9,18],
    [13,3,19],
    [14,9,16],
    [14,2,17],
    [15,6,19],
    [16,7,17],
    [16,7,19],
    [17,8,18]
]

a=0
def shortest(x,F,c):
    global a
    global min
    global path

    for i in range(len(A)):

        if A[i][0]==x:

            if A[i][2] in F:
                continue

            else:
                a+=1
                Y=F.copy()
                Y.append(A[i][2])
                d=c
                d+=A[i][1]

                if A[i][2]==t:
                    try:
                        if d<=min:
                            min=d
                            path=[Y,min]
                        else:
                            continue
                    except:
                        min=d
                        path=[Y,min]  

                else:
                    shortest(A[i][2],Y,d)

        else:
            continue  
        
    return path

t1=time.time()

s=0
t=19
F=[s]
c=0
path=[]
print(shortest(s,F,c))

t2=time.time()

print(t2-t1)
print(a)