#Calling fibonacci using dynamic programming

#This is slow fibonacci

def fib(n):

    global numCalls

    numCalls += 1

    if n <= 1:

        return n

    else:

        return fib(n-1) + fib(n-2)

numCalls = 0

n1 = 5 #for normal fibonacci

print 'fib of ', n, '=', fib(n1)

print 'number of calls slow fibonacci took is :', numCalls




#This is fast fibonacci

def fastfib(n):

    #declaring a global dictionary
    
    global memo

    global numCalls2

    numCalls2 += 1

    #checking if the particular is not in the dictionary
    
    if not n in memo:

        memo[n] = fastfib(n-1) + fastfib(n-2)

    return memo[n]

#initializing the dictionary

memo = {0:0 , 1:1}

numCalls2 = 0 

n2 = 5#for the fast fibonacci

print 'fib of ', n, '=', fastfib(n2)


print 'number of calls fast fibonacci took is :', numCalls2





    
    
