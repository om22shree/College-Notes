# Palindromic string :-

x <- readline(prompt="Enter the string: ")
n <- nchar(x)
flag <- TRUE
for (i in 1:(n/2)) {
  if (substr(x, i, i) != substr(x, n-i+1, n-i+1)) {
    # Comparing the ith character from first and last of the string
    flag <- FALSE
    break
  }
}
print(flag)