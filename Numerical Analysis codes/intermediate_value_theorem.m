f=@(x) x^2-x-12; 
tmp=1;
while (temp>0)
a=input('enter the value of a: such that f(a)*f(b)<0');
b=input('enter the value of b: such that f(a)*f(b)<0');
temp=f(a)*f(b)
end
c=(a+b)/2;
tol=input('enter the value of tolerance:');
while(abs (b-a) > tol)
    if (f(c)==0)
        fprint('c is a root and value is %f',c)
        return;
    end
    if f(a)*f(c)<0
        b=c;
    else 
        a=c;
    end
    c=(a+b)/2;
end
 disp(c)
