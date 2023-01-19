vec1 <- as.integer(strsplit(readline("Enter the space separated vector: "), " ")[[1]])
x <- readline("Enter the target value: ")

if(x %in% vec1) {
  print("Element found in the vector")
} else {
  print("Element not found in the vector")
}