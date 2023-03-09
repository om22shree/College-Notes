# Print the pattern :-
#       1
#     2   2
#   3   3   3
# 4   4   4   4

n <- as.integer(readline(prompt="Enter the depth: "))
i = 1
while(i <= n) {
  j = i
  while(j > 0) {
    res = n - i
    while(res > 0) {
      cat(" ")
      res = res - 1
    }
    cat(paste(i, " "))
    j = j - 1
  }
  cat("\n")
  i = i + 1
}