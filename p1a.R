head(women)

x <- women$height
y <- women$weight

plot(x, y, xlab = "height", ylab = "weight", main = "positive correlation", pch = 20)
cor(x, y)

# Custom data with expected negative correlation
x <- c(10, 12, 15, 14, 45, 56, 78, 43, 56, 10)
y <- c(20, 34, 54, 67, 12, 10, 4, 5, 6, 7)

plot(x, y, xlab = "height", ylab = "weight", main = "negative correlation", pch = 20)
cor(x, y)

