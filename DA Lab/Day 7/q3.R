beaver1 <- data.frame("TEMP" = c(9,10,12))
beaver2 <- data.frame("TEMP" = c(8,7,13)) 
ID <- 1 
beaver1$ID <- ID 
ID <- 2 
beaver2$ID <- ID 
print(beaver1) 
print(beaver2) 
beaver3 <- subset(rbind(beaver1,beaver2),subset = TEMP > 10) 
print("Final Result") 
print(beaver3)