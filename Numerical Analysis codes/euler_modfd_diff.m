clc
clear all
f=@(x,y)(5*x*x-y)/(exp(x+y));
b=1;%jispe want to find value
y=1;%jis a=0 pe given hai corrspndng y
h=0.1;
a=0;
n=(b-a)/h;
for i=1:n
    yp=y+h*(f(a,y));
    y=y+h*(f(a+h,yp)+f(a,y))/2;
    a=a+h;
end
y