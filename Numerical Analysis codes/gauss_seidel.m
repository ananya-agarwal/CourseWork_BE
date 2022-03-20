clc
clear all
n=input('Enter the number of equations:')
fprintf('Define the coefficient matrix A:')
A=[3 -1 1;1 6 2;-2 -4 10]
fprintf('Enter the RHS vector B:')
b=[4;19;20]
fprintf('enter tolerance:')
tol=.0001
err=10000
x0=[0;0;0]
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
 end
    err=max(abs(x-x0))
end
x0