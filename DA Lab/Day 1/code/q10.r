# Using function call
calculate_stats <- function(vector) {
  mean <- mean(vector)
  sum <- sum(vector)
  product <- prod(vector)
  return(c(mean, sum, product))
}

vector_input <- readline("Enter a space separated vector: ")
vector <- as.numeric(unlist(strsplit(vector_input, " ")))
stats <- calculate_stats(vector)
cat("Mean:", stats[1], "\n")
cat("Sum:", stats[2], "\n")
cat("Product:", stats[3], "\n")
