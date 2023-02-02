# Column arrangement
mat1 <- matrix(c(3:14), nrow=4)
print(mat1)

# Row arrangement
mat2 <- matrix(c(3:14), nrow=4, byrow=TRUE)
print(mat2)

# name the columns and rows.
cnames <- c("c1", "c2", "c3", "c4")
rnames <- c("r1", "r2", "r3")
mat3 <- matrix(c(3:14), nrow=3, ncol=4, byrow=TRUE)
rownames(mat3) <- rnames
colnames(mat3) <- cnames
print(mat3)

# Access [1, 3] element
print(mat3[1, 3])
# Access [2, 4] element
print(mat3[2, 4])

# Access the 2nd row
print(mat3[2, ])
# Access the 3rd column
print(mat3[, 3])
