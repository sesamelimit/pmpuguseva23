f=@(x) 3*(5-x)^(4/3) + 2*x^2;
eps=0.025; a=1.5;b=2;

[xmin,ymin] = goldenratio(a,b,f,eps);
disp(ymin-f(a));
[xmin,ymin] = dichotomy(a,b,f,eps);
disp(ymin-f(a));




function [xmin,ymin] = fibonacci(a_0,b_0,f,eps)
a=a_0;b=b_0; n=0;
delta=eps;
while ((sqrt(5)-1)/2)^n*(b-a)>=eps 
    n=n+1; %колво шагов \ge ln(eps/(b-a))/ln((sqrt(5)-1)/2)
x1=a+(b-a)*(3-sqrt(5))/2;
x2=a+(b-a)*(sqrt(5)-1)/2;
if f(x1) <= f(x2)
    b=x2;
    xmin=x1;
else
    a=x1;
    xmin=x2;
end
end
ymin=f(xmin);
disp(n);
end

function [xmin,ymin] = goldenratio(a_0,b_0,f,eps)
a=a_0;b=b_0; n=0;
delta=eps;
while ((sqrt(5)-1)/2)^n*(b-a)>=eps 
    n=n+1; %колво шагов \ge ln(eps/(b-a))/ln((sqrt(5)-1)/2)
x1=a+(b-a)*(3-sqrt(5))/2;
x2=a+(b-a)*(sqrt(5)-1)/2;
if f(x1) <= f(x2)
    b=x2;
    xmin=x1;
else
    a=x1;
    xmin=x2;
end
end
ymin=f(xmin);
disp(n);
end

%метод дихотомии
function [xmin,ymin] = dichotomy(a_0,b_0,f,eps) 
a=a_0;b=b_0; n=0;
delta=eps;
while (b-a)/2>=eps 
    n=n+1;
x1=(a+b-delta)/2;x2=(a+b+delta)/2;
if f(x1) <= f(x2)
    b=x2;
else
    a=x1;
end
end
xmin=(a+b)/2; ymin=f(xmin);disp(n);
end

%метод пассивного поиска
function [xmin,ymin] = passive_search(a_0,b_0,f,N) 
[ymin,xmin]=min(arrayfun(@(t) f(t),a_0:(b_0-a_0)/N:b_0));
end


