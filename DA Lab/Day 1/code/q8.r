n <- as.integer(readline(prompt = "Enter the number of elements in the vector: "))
vec <- numeric(n)
for(i in 1:n) {
  vec[i] <- as.numeric(readline(prompt = paste("Enter element", i, ": ")))
}
print(vec)
max_val <- max(vec)
min_val <- min(vec)
print(paste("Maximum value is:", max_val))
print(paste("Minimum value is:", min_val))
