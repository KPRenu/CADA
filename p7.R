rm(list = ls(all.names = TRUE)) 

data(iris)
str(iris)
install.packages("ClusterR")
install.packages("cluster")
library(ClusterR)
library(cluster)
iris_1 <- iris[, -5]
set.seed(240) 

km <- kmeans(iris_1, centers = 3, nstart = 20)
km
km $ cluster

cm <- table(iris$Species, km$cluster)
cm

plot(iris_1[c("Sepal.Length", "Sepal.Width")],
     col = km$cluster,
     main = "K-means with 3 clusters")

km$centers
km$centers[, c("Sepal.Length", "Sepal.Width")]
points(km$centers[, c("Sepal.Length", "Sepal.Width")],
       col = 1:3, pch = 8, cex = 3)

y_kmeans <- km$cluster
clusplot(iris_1[, c("Sepal.Length", "Sepal.Width")],
         y_kmeans,
         labels = 2,
         lines = 0,
         color = TRUE,
         span = TRUE,
         shade = TRUE,
         plotchar = FALSE,
         main = paste("Cluster iris"),
         xlab = 'Sepal.Length',
         ylab = 'Sepal.Width')

