f=@(x) x^2-x-12;
tol=input ('enter the value of tolerance:');
a=input ('enter the value of starting of the interval such that only one root lies in that interval');
b=input ('enter the value of ending of the interval such that only one root lies in that interval');
if f(b)*f(a)<=0
    c=b-((b-a)*f(b)/(f(b)-f(a)));
while abs(c-b)>tol
    if f(c)==0
        break;
    elseif f(c)*f(b)<0
        a=c;
    else
        b=c;
    end
    c=b-((b-a)*f(b)/(f(b)-f(a)));
end
      fprintf('approximate root of the function is : %f',c);
else
    fprintf('root does not lie in the interval [%f,%f]',b,a);
   end
