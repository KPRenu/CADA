# Remove all objects in the workspace
rm(list = ls(all.names = TRUE))  

# Initialize the input data frame
x <- data.frame(
  name = c("Bala", "Ganesh", "Geevan"),
  age = c(43, 38, 42),
  education = c(2.0, 4.2, 4.1)
)
print(x)

# Extract age and education
age <- x$age
print(age)

edu <- x$education
print(edu)

# Form matrix M1 using raw age and education
M1 <- matrix(c(age, edu), nrow = 3, byrow = FALSE)
print(M1)

# Euclidean distance for M1
E1 <- dist(M1, method = 'euclidean')
print(E1)

# Age in decades
ageD <- age / 10
print(ageD)

# Form matrix M2 using age in decades
M2 <- matrix(c(ageD, edu), nrow = 3, byrow = FALSE)
print(M2)

# Euclidean distance for M2
E2 <- dist(M2, method = 'euclidean')
print(E2)

# Min-Max Normalize Age
rangA <- max(age) - min(age)
print(rangA)
mi_maA <- (age - min(age)) / rangA
print(mi_maA)

# Min-Max Normalize Education
rangE <- max(edu) - min(edu)
print(rangE)
mi_maE <- (edu - min(edu)) / rangE
print(mi_maE)

# Form matrix M3 with normalized age and education
M3 <- matrix(c(mi_maA, mi_maE), nrow = 3, byrow = FALSE)
print(M3)

# Euclidean distance for M3
E3 <- dist(M3, method = 'euclidean')
print(E3)

# Final display
print("_______Data frame with different similarity measure matrix results______")
print(x)
print(E1)
print(E2)
print(E3)

