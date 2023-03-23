x = readline("Enter a string: "); 
count<-0 
y <- strsplit(x,"")[[1]] 
v <- c("a","A","e","E","i","I","o","O","u","U") 
for(i in y)   
  if(i %in% v)     
    count = count + 1 
cat("Total no of vowels in string is: ",count)
