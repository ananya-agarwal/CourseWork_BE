clc
clear all
n=4;
x=[0;1;2;4];
f=[-5;-5;-3;7];
b=input('Enter point of interpolation');
s=0;
for i=1:n
l(i)=1;
for j=1:n
if j==i
        continue;
    else
        l(i)=l(i)*(b-x(j))/(x(i)-x(j));
    end
end
s=s+(l(i)*f(i));
end
s