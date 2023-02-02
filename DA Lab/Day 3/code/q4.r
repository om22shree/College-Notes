# 5x4 matrix with row labels
mat6 <- matrix(1:20, ncol=4, dimnames=list(c("row1","row2","row3","row4","row5"), 
                                           c("col1","col2","col3","col4")))

# 3x3 matrix with row labels
mat7 <- matrix(1:9, ncol=3, dimnames=list(c("row1","row2","row3"), 
                                          c("col1","col2","col3")))

# 2x2 matrix with column labels
mat8 <- matrix(c(1,2,3,4), nrow=2, ncol=2, byrow=FALSE,
               dimnames=list(NULL, c("col1","col2")))

print(mat6)
print(mat7)
print(mat8)