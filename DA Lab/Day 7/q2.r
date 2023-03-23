set.seed(120)
pets <- sample(c("dog", "cat", "hamster", "goldfish"), 1000, replace = TRUE)
print(head(pets))
print(table(pets))