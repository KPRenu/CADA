rm(list = ls(all.names = TRUE)) 

input = read.csv("C:\\Users\\DELL\\PES\\DA\\pgm6.csv")
print(input)
input$Gender <- as.numeric(factor(input$Gender))
input$Company <- as.numeric(factor(input$Company)) 

x = cor(input[,c(2:7)])
print(x)
pairs(input[,c(2:7)]) 
y = x[6,1:5] 
print(y)

x= sort(y,decreasing = TRUE)
print(x)
cnt =1
print("selected attributes")
while(cnt<=length(y)) 
{ if (y[cnt]>.5)
  print(y[cnt])
  cnt=cnt+1
}

