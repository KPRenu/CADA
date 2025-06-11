head(mtcars)
x<-mtcars$cyl
y<-mtcars$carb

plot(x, y, xlab="cyl", ylab="carb", main="positive corelation", pch=20)
cor(x,y)

head(mtcars)
x<-mtcars$cyl
y<-mtcars$mpg

plot(x, y, xlab="cyl", ylab="carb", main="negative corelation", pch=20)
cor(x,y)
