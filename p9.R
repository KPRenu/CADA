rm(list = ls(all.names = TRUE)) 

install.packages("ggplot2")
library(ggplot2)
require("class")
data("iris")
str(iris)
summary(iris)
head(iris)
set.seed(99)

rnum<-sample(rep(1:150))
rnum

iris<-iris[rnum,]
head(iris)
normalize<-function(x){return((x-min(x))/(max(x)-min(x)))}
iris.new<-as.data.frame(lapply(iris[,c(1,2,3,4)],normalize))
head(iris.new)

iris.train<-iris.new[1:130,]
iris.train.target<-iris[1:130,5]
iris.test<-iris.new[130:150,]
iris.test.target<-iris[130:150,5]
summary(iris.new)

model1<-knn(train=iris.train, test=iris.test, cl=iris.train.target, k=16)
table(iris.test.target, model1)
ggplot(data=iris, aes(x=Sepal.Length, y=Sepal.Width, col=Species)) + geom_point()
