# Print the pattern :-
# 1
# 2   2
# 3   3   3
# 4   4   4   4

n <- as.integer(readline(prompt="Enter the depth: "))
for(x in 1:n){
  cat(rep(x, x), '\n')
}