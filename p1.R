rm(list = ls(all.names = TRUE)) 

head(women)

x <- women$height
y <- women$weight

plot(x, y, xlab = "height", ylab = "weight", main = "positive correlation", pch = 20)
cor(x, y)

# Custom data with expected negative correlation
x <- c(100,90,80,70,60,50,40,30)
y <- c(10,20,30,40,50,60,70,80)

plot(x, y, xlab = "height", ylab = "weight", main = "negative correlation", pch = 20)
cor(x, y)

#------------------------------------------------------------------------------------------

rm(list = ls(all.names = TRUE)) 

head(mtcars)
x<-mtcars$cyl
y<-mtcars$carb

plot(x, y, xlab="cyl", ylab="carb", main="positive corelation", pch=20)
cor(x,y)

head(mtcars)
x<-mtcars$cyl
y<-mtcars$mpg

plot(x, y, xlab="cyl", ylab="mpg", main="negative corelation", pch=20)
cor(x,y)
