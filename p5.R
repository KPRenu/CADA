rm(list = ls(all.names = TRUE)) 

x <- data.frame(name = c("Bala","Ganesh","Geevan"),
                age = c(43,38,42),
                education = c(2.0,4.2,4.1))
print(x)

age = x$age
print(age)
edu = x$education
print(edu)

M1 <- matrix(c(age,edu), nrow = 3, byrow = FALSE) 
print(M1)
E1 = dist(M1,method= 'euclidean') 
print(E1)

ageD = age/10
print(ageD)

M2 <- matrix(c(ageD,edu), nrow = 3, byrow = FALSE) 
print(M2)
E2 = dist(M2,method= 'euclidean')
print(E2)

rangA = max(age) - min(age)
print(rangA)
mi_maA = (age-min(age))/rangA
print(mi_maA)

rangE = max(edu) - min(edu)
print(rangE)
mi_maE = (edu-min(edu))/rangE
print(mi_maE)

M3 <- matrix(c(mi_maA,mi_maE), nrow = 3, byrow = FALSE)
print(M3)
E3 = dist(M3,method= 'euclidean')
print(E3)

print("Data frame with different similarity measure matrix results_")
print(x)
print(E1)
print(E2)
print(E3)