student <- data.frame(   
  "Roll_No"=c(101,102,103,104,105),   
  "Name"= c("Ajay","Arun","Rohit","Rahul","Prem"),   
  "DEPT"= c("CSE","CSE","ECE","Mech","IT"),   
  "COURSE"="BTech",   
  "YoJ"= c(2020,2020,2022,2024,2021), stringsAsFactors = FALSE ) 
  print(student)  
  fun1 <- function(x){   print(subset(student,subset = YoJ == x)) } 
  fun2 <- function(y){   print(subset(student,subset = Roll_No == y)) } 
  x = as.integer(readline("Enter a year: ")) 
  fun1(x) 
  y = as.integer(readline("Enter a Roll No: ")) 
  fun2(y)