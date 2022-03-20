clc
clear all
a=[2 3 -1 5;0 -2 -1 -7;0 0 -5 -15];
n=3;
for k=n:-1:1
    sum=0;
    for j=k+1:n
        sum=sum+a(k,n+1)*x(j);
        x(2)
    end
    x(k)=(a(k,n+1)-sum)/a(k,k);
    x
end
x