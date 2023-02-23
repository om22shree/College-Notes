# Q3 : Write an R program to create an array using 4 given columns, 
# 3 given rows and 2 given tables.

# Data initialization :-
col_values <- c(1, 2, 3, 4)
row_values <- c(10, 20, 30, byRow=TRUE)
table_values <- c("table1", "table2")

# Create the array using the row values
rarr <- array(row_values, dim = c(1, 3, 1))
print(rarr)

# Create the array using the column values 
carr <- array(col_values, dim = c(4, 1, 1))
print(carr)

# Create the array using tables :-
tarr <- array(table_values, dim = c(1, 2, 1))
print(tarr)