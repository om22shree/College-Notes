# Vector initialization :-
vec1 <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)
vec2 <- c(10, 11, 12, 13, 14, 15, 16, 17, 18)

# Array attributes :-
rnames <- c('r1', 'r2', 'r3')
cnames <- c('c1', 'c2', 'c3')
matnames <- c('mat1', 'mat2')

# Array initialization :-
arr <- array(c(vec1, vec2), dim=c(3, 3, 2), dimnames = 
               list(rnames, cnames, matnames))

# Printing the entire array :-
print(arr)
