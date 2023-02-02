# create a sample matrix
mat12 <- matrix(c(1, 2, 3, 4, 5, 6, 7, 8, 9), nrow = 3, ncol = 3)

# find elements less than 5 and set them to 0
mat12[mat12 < 5] <- 0

# print the modified matrix
print(mat12)
