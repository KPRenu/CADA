# Load iris dataset and inspect structure
data("iris")
str(iris)
summary(iris)

# Set seed for reproducibility and split data into training and testing sets (80%-20%)
set.seed(111)
ind <- sample(2, nrow(iris), replace = TRUE, prob = c(0.8, 0.2))
training <- iris[ind == 1, ]
testing <- iris[ind == 2, ]

# Load psych package to create correlation matrix with scatterplot and density
library(psych)

# Pair plot with color-coded species
pairs.panels(training[, -5],  # remove Species column for numerical analysis
             gap = 0,
             bg = c("red", "yellow", "blue")[training$Species],
             pch = 21)

# Perform PCA (Principal Component Analysis) on training set (excluding Species)
pc <- prcomp(training[, -5],
             center = TRUE,
             scale. = TRUE)

# Check PCA attributes and summary
attributes(pc)
pc$center    # mean used for centering
pc$scale     # std deviation used for scaling
print(pc)    # components and rotation matrix
summary(pc)  # importance of each principal component

