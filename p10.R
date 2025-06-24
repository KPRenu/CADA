rm(list = ls(all.names = TRUE)) 

# Create the data frame
df <- data.frame(
  hours = c(1, 2, 4, 5, 5, 6, 6, 7, 8, 10, 11, 11, 12, 12, 14),
  score = c(64, 66, 76, 73, 74, 81, 83, 82, 80, 88, 84, 82, 91, 93, 89)
)

View(df)

scatter.smooth(df$hours, df$score, main = 'Hours Studied vs. Exam Score')
boxplot(df$score, main = "Boxplot of Exam Scores", ylab = "Score")
boxplot(df$hours, main = "Boxplot of hours", ylab = "hours")
model <- lm(score ~ hours, data = df)
summary(model)
res <- resid(model)

plot(fitted(model), res,
     main = "Residuals vs. Fitted Values",
     xlab = "Fitted values",
     ylab = "Residuals")

abline(h = 0, col = "red")
qqnorm(res, main = "Q-Q Plot of Residuals")
qqline(res, col = "blue")
