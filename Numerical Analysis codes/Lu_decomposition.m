clc
clear all
fprintf ('matrix A');
n=3;
A=[3 -1 1 ; 1 6 2; -2 -4 10]
u=A;
fprintf ('RHS vector B');
b=[4 ; 19 ; 20]
l=eye(n);
for k=1:n-1
    for i=k+1:n
        mf=u(i,k)/u(k,k);
        u(i,:)=u(i,:)-mf*u(k,:);
        l(i,k)=mf;
    end
end
y=inv(l)*b;
x=inv(u)*y;
for i=1:n
fprintf('x%d=%f',i,x(i));
end
