# Make the matrix
mat11 = matrix(c(1:16), nrow = 4, byrow = TRUE)
print(mat11)

# sub-matrix with column values > 7
result = mat11[mat11[, 3] > 7, ]
print(result)