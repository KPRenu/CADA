lungcapdata = read.csv("C:\\Users\\DELL\\PES\\DA\\LungCapData.csv", header=T)
lungcapdata<-data.frame(lungcapdata)
attach(lungcapdata)
# View(lungcapdata)
agegroups<-cut(lungcapdata$Age,breaks=c(0,13,15,17,25),labels=c("<13","14/15","16/17",">=18"))
head(lungcapdata)

boxplot(lungcapdata$LungCap~lungcapdata$Smoke,ylab="lung capacity",main="lung capacity of smokers vs non smokers",las=1)

boxplot(lungcapdata$LungCap[lungcapdata$Age>=18]~lungcapdata$Smoke[lungcapdata$Age>=18],ylab="lung capacity",main="lung capacity smokers vs non smokers above 18", las=1)

boxplot(lungcapdata$LungCap~lungcapdata$Smoke*agegroups,ylab="lung capacity",main="lung capacity of smokers vs non smokers",col = c(4,2),las=2)
