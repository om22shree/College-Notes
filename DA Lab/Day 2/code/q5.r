vec1 <- as.integer(strsplit(readline(), " ")[[1]])
vec2 <- sort(vec1, decreasing = TRUE)
print(vec2[2])

bubble_sort_descending <- function(vec) {
  n <- length(vec)
  for (i in 1:(n-1)) {
    for (j in 1:(n-i)) {
      if (vec[j] < vec[j+1]) {
        temp <- vec[j]
        vec[j] <- vec[j+1]
        vec[j+1] <- temp
      }
    }
  }
  return(vec)
}

vec2 <- (bubble_sort_descending(vec1))
print(vec2[2])