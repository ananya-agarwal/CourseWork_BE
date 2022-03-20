clc
clear all
f=@(x,y)(5*x*x-y)/(exp(x+y));
b=1;
y=1;
a=0;
h=0.1;
n=(b-a)/h;
for i=1:n
    k1=h*f(a,y);
    k2=h*f(a+(h/2),y+(k1)/2);
    k3=h*f(a+(h)/2,y+(k2/2));
    k4=h*f(a+h,y+k3);
    y=y+(k1+2*k2+2*k3+k4)/6;
    a=a+h;
end
y