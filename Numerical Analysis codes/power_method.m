clc
clear all
A=[1 0 0 0 ; 2 3 0 0 ; 4 -2 -5 0 ; 0 1 -3 4];
n=4;
tol=0.0001;
err=10000;
x=[1 ; 1 ; 1 ; 1];
y=A*x;
u=y(1);
for i=2:n
   if(abs(u)<abs(y(i)))
      u=y(i);
   end
end
x=y/u;
while((err)>tol)%err=u pichli -u ab vali
    u0=u;
      y=A*x;
      u=y(1);
           for i=2:n
                if(abs(u)<abs(y(i)))
                     u=y(i);
                end
           end
    x=y/u;
    err=abs(u-u0);
end
u
    