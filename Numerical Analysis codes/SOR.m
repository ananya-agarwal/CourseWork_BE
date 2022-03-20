clc
clear all
w=1.2;
n=input('Enter the number of equations:');
A=[2 -1 0;-1 2 -1;0 -1 2];
b=[0;1;2];
tol=.0001;
err=10000;
x0=[0;0;0];
while(err>tol)
 x=x0;
 for i=1:n
     x0(i)=b(i);
     for j=1:i-1
         x0(i)=x0(i)-A(i,j)*x0((j));
     end
     for j=i+1:n
         x0(i)=x0(i)-A(i,j)*x((j));
     end
     x0(i)=x0(i)/A(i,i);
     x0(i)=((1-w)*x(i))+(w*x0(i));
 end
    err=max(abs(x-x0));
end
x0