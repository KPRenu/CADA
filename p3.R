rm(list = ls(all.names = TRUE)) 

airqual=airquality 
summary(airquality) 
#View(airquality)

airqual[!complete.cases(airqual),]
boxplot(airqual)
boxplot(airqual$Ozone,horizontal = TRUE) 
boxplot(airqual$Wind,horizontal = TRUE)

Updated_airqual=subset(airqual,Ozone<130 & Wind<17) 
boxplot(Updated_airqual)

airqual$Ozone[is.na(airqual$Ozone)]<-mean(Updated_airqual$Ozone)
summary(airqual)
airqual$Solar.R[is.na(airqual$Solar.R)]<-mean(Updated_airqual$Solar.R,na.rm = TRUE)
summary(airqual)

data_airquality=subset(airqual,Ozone<70 & Wind<17)
boxplot(data_airquality)
nrow(data_airquality)
data_airquality=subset(airqual,Ozone<70 & Wind<17 & Wind>2)
boxplot(data_airquality)

