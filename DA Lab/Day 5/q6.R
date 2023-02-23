# Create 2 3*3 matrices from 2 given vectors :-

# Vector initialization :-
vec1 = c(1, 2, 3, 4, 5, 6, 7, 8, 9)
vec2 = c(10, 11, 12, 13, 14, 15, 16, 17, 18)

# Matrix creation :-
mat = array(c(vec1, vec2), dim = c(3, 3, 2))
print(mat)