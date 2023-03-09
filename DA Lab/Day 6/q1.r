binary <- "11011010"
hex <- ""
for (i in seq(1, nchar(binary), by = 4)) {
  four <- substring(binary, i, i + 3)
  hex <- as.hexmode(paste0("0x", four))
  hex <- paste0(hex, hex)
}
print(paste(hex))