airquality = read.csv("/home/AirQualityIndex.csv")
iris=read.csv("/home/Iris.csv")
heart=read.table("/home/HartDatasetDescription.txt")
summary(heart)
print(airquality)

#plot(airquality$Ozone)
print(iris)

#plot(iris$Petal.Length)
summary(iris)

#PIE CHART
x<-c(25,30,45)
label<-c("setosa","versicolor","virginica")
radius<-40
color<-c("orange","brown","pink")

pie(x,label,40,main = "Specis of iris flower",col = color,clockwise = FALSE)
y<-c(summary(iris$Species))
color<-c("orange","blue","pink")
pie(y,label,40,main = "Specis of iris flower",col = color,clockwise = FALSE)

#BAR CHARTS
yaxis=c(10,20,30,40,50,60,70,80.90,100)
summary(airquality)
barplot(airquality$Temp,main = "Temperature")
barplot(c(30,46,14),ylab = c("setosa","versicolor","virginica"),xlab = yaxis , main = "species quantity" )
barplot(c(30,46,14), main = "species quantity",names.arg = c("setosa","versicolor","virginica") )
barplot(iris$Sepal.Length, main = "sepalgth of iris flower" )

hist(iris$Sepal.Length,main = "sepal length of iris flower",col="darkmagenta",
     freq=FALSE)
hist(airquality$Temp,main="Maximum daily temperature",
     xlab="Temperature in degrees Fahrenheit",border = 2)

h <- hist(airquality$Temp,ylim=c(0,40),border = 1,col = 5)
text(h$mids,h$counts,labels=h$counts, adj=c(0.5, -0.5))

#LINE CHART
plot(airquality$Solar.R,type = "o",main="ozone",xlab = "days of month",col=c("pink","blue"))

#box plot
boxplot(airquality$Month,airquality,notch = TRUE,varwidth = TRUE,names = c("jan","feb","march","april","may","june","july","aug","sept","oct","nov","dec"))

#scatterplot
plot(iris$Petal.Length,iris$Petal.Width,main = "Iris Petals Analysis",xlab = "Length",ylab = "Width",xlim = c(0,8),ylim = c(0,2.5),axes = TRUE,col=1)