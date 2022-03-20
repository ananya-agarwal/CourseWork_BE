f=@(x)x^3-2*x+5;
a=input('Enter the value of a: ');
b=input('Enter the value of b: ');
n=input('Enter no. of sub intervals: ');
h=(b-a)/n;
xn=a;
sum=0;
for i=1:n
    x=xn;
    xn =a +((i+1)-1)*h;
    sum=sum+(h/2*(f(x)+f(xn)));
end
fprintf('value of integral is :%f',sum);