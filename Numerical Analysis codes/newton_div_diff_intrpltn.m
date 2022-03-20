clc
clear all
n=3;
x=[3;1;0];
f=[26;4;5];
b=input('Enter point of interpolation');
for i=1:n
   d(1,i)=f(i);
end
for i=2:n
   for j=1:n-i+1
    d(i,j)=(d(i-1,j+1)-d(i-1,j))/(x(i+j-1)-x(j));
   end
end
 s=d(1,1); 
for i=2:n 
    p=1;
    for j=1:i-1 
    p=p*(b-x(j));
    end
    s=s+(d(i,1)*p);
end
s