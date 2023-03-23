sen = readline("Enter a string: ") 
split <- unlist(strsplit(sen," ")) 
for(i in 1:length(split))   
  if(nchar(split[i]) == 5)     
    split[i] = "V-Day" 
print(paste(split,collapse = " "))