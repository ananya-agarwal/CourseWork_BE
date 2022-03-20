f=@(x) x^3-2*x+5;
a=input('Enter the value of a: ');
b=input('Enter the value of b: ');
n=input('Enter no. of EVEN sub intervals: ');
h=(b-a)/n;
xn=a;
sum=0;
for i=1:2:n
    xp=xn;
    x=xp+h;
    xn=x+h;
    sum=sum+(h/3*(f(xp)+4*f(x)+f(xn)));
end
fprintf('value of integral is :%f',sum);