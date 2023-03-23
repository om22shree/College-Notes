emp <- data.frame(
  Name <- c("Om", "Anand", "Rohit", "Sinha", "Sourav"),
  empID <- c(1:5),
  Dept <-c("IT", "CSE", "CSSE", "CSCE", "Maths"),
  Salary <- c(10000, 20000, 30000, 40000, 50000)
)

print(emp$Name)
print(emp[2])
print(emp[["Name"]])