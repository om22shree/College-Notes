# Vector initialization :-
vec1 <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)
vec2 <- c(10, 11, 12)

# Array attributes :-
rnames <- c('r1', 'r2')
cnames <- c('c1', 'c2', 'c3')
matnames <- c('mat1', 'mat2')

# Array initialization :-
arr <- array(c(vec1, vec2), dim=c(2, 3, 2), dimnames = 
               list(rnames, cnames, matnames))

# Printing the array :-
print(arr)
print(arr[2, 3, 2])
print(arr[2, , 1])
print(arr[, 2, 2])
print(arr[2, , ])

# Updating existing elements :-
arr[2, 3, 2] = 77
print(arr[2, 3, 2])

# Length of the array :-
print(length(arr))

# Q1 : R program to create an array of 2 3*3 matrices. 
#Print the second row of the second matrix of the array. 

# Q2 : Pint the element in the third row of the third column of the array.

# Q3 : Write an R program to create an array using 4 given columns, 
# 3 given rows and 2 given tables.

# Q4 : Calculate the sum of the rows across all the matrices.

# Q5 : Calculate the maximum and minimum element of the array.

# Q6 : Write an R program to create an array of 2 3*3 matrices
# from 2 given vectors.