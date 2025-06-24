rm(list = ls(all.names = TRUE)) 

if (!require(arules)) install.packages("arules", dependencies = TRUE)
if (!require(arulesViz)) install.packages("arulesViz", dependencies = TRUE)
library(arules)
library(arulesViz)

transactions_list <- list(
  c("Hot Dogs", "Buns", "Ketchup"),
  c("Hot Dogs", "Buns"),
  c("Hot Dogs", "Coke", "Chips"),
  c("Chips", "Coke"),
  c("Chips", "Ketchup"),
  c("Hot Dogs", "Coke", "Chips")
)

View(transactions_list)

trans <- as(transactions_list, "transactions")
inspect(trans)

rules <- apriori( trans,
  parameter = list(supp = 0.5, conf = 0.8, target = "rules")
)

cat("\nAssociation Rules (conf ≥ 80%):\n")
inspect(rules)

rules_df <- as(rules, "data.frame")
write.csv(rules_df, file = "C:\\Users\\DELL\\OneDrive\\Desktop\\data3.csv")

plot(rules)                           
plot(rules, method = "grouped")     
plot(rules, method = "graph") 


#---------------------------------------------------------------------------------------------------------------------------

#extra rules

# Generate more rules with lower thresholds
rules <- apriori(
  trans,
  parameter = list(supp = 0.3, conf = 0.6, target = "rules")
)

cat("\nAssociation Rules (support ≥ 30%, confidence ≥ 60%):\n")
inspect(rules)

rules_df <- as(rules, "data.frame")
write.csv(rules_df, file = "C:\\Users\\DELL\\OneDrive\\Desktop\\data3.csv", row.names = FALSE)

if (length(rules) >= 1) {
  plot(rules, method = "scatterplot", main = "Scatterplot of Rules")
  try(plot(rules, method = "grouped", main = "Grouped Matrix of Rules"))
  try(plot(rules, method = "graph", main = "Graph View of Rules"))
} else {
  cat("No rules found. Try lowering support/confidence even more.\n")
}

