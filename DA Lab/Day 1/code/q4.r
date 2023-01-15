num <- as.integer(readline(prompt = "Enter a 3-digit number: "))
digit1 <- num %/% 100
digit2 <- (num %/% 10) %% 10
digit3 <- num %% 10
sum_of_digits <- digit1 + digit2 + digit3
print(paste("Sum of the digits:", sum_of_digits))
