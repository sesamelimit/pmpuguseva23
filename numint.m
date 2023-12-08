precise_int=10.83954510946909397740794566485262705081;

%условия задачи
a=1.3;
b=2.2;
alpha=0;
beta=5/6;
N=3;
%% Вариант Ньютона-Котса
%Построить интерполяционную квадратурную формулу
% disp('ИКФ для трех точек')
% anwser=ikf_newton_cotes(a,b);
% %Оценить методическую погрешность построенного правила (11)
% R=1/factorial(3)*(-(65*(-1)*exp(-(5*a)/4))/16-(11637*(-1)*exp(b/8))/64-(71*(-1)*exp(-(5*b)/4))/8-(3887*(-1)*exp(b/8))/256)*(-(6561*9^(1/6)*(20*10^(5/6) - 31*20^(5/6)))/34580000);
% disp('методическая погрешность')
% disp(R)
% %сравнить её с точной погрешностью
% disp('сравнить её с точной погрешностью')
% disp(abs(anwser-precise_int));
% %построить составную КФ и,уменьшая длину шага h, добиться заданной точности ε = 10−6.
% anwser=0;
% eps=1e-6;
% L=2;n=1;
% % На каждых по-следовательных трёх точках оценивать скорость сходимости по правилу Эйткена
% S_1=skf_newton_cotes(a,b,(b-a)/L);
% S_2=skf_newton_cotes(a,b,(b-a)/L^2);
% S_3=skf_newton_cotes(a,b,(b-a)/L^3);
% m=-log((S_3-S_2)/(S_2-S_1))/log(L);
% R=(S_3-S_2)/(L^m-1);
% n=4;
% while (abs(R)>=eps)
% S_1=skf_newton_cotes(a,b,(b-a)/L^n);
% R=(S_3-S_1)/(L^m-1);    
% if abs(R)<eps
%     result=S_1;
%     break;end
% S_2=skf_newton_cotes(a,b,(b-a)/L^(n+1));
% R=(S_2-S_1)/(L^m-1);    
% if abs(R)<eps
%     result=S_2;
%     break;end
% S_3=skf_newton_cotes(a,b,(b-a)/L^(n+2));
% n=n+3;
% m=-log((S_3-S_2)/(S_2-S_1))/log(L);
% R=(S_3-S_2)/(L^m-1);
% result=S_3;
% end
% anwser2=result;
% disp('сравнение с точным значением')
% disp(abs(anwser2-precise_int));
% disp('количество итераций');disp(n);
% %использовать оценку скорости сходимости и выбрать оптимальный шаг hopt. Начать расчёт c шага hopt и снова довести до требуемой точности ε.
% S_1=ikf_newton_cotes(a,b);
% S_2=skf_newton_cotes(a,b,(b-a)/2);
% S_3=skf_newton_cotes(a,b,(b-a)/4);
% L=2;
% m=-log((S_3-S_2)/(S_2-S_1))/log(L);
% R=(S_3-S_2)/(L^m-1);
% h_opt=(b-a)/4*(eps/abs(R))^(1/m);
% n=3;
% while (abs(R)>=eps)
% S_1=skf_newton_cotes(a,b,h_opt);
% m=-log((S_1-S_2)/(S_2-S_3))/log(L);
% R=(S_3-S_1)/(L^m-1);    
% if abs(R)<eps
%     result=S_1;break;break;
%     end
% S_2=skf_newton_cotes(a,b,(h_opt/2));
% m=-log((S_2-S_1)/(S_1-S_3))/log(L);
% R=(S_2-S_1)/(L^m-1);    
% if abs(R)<eps
%     result=S_2;break;break;
% end
% S_3=skf_newton_cotes(a,b,(h_opt/4));
% h_opt=h_opt/8;
% m=-log((S_3-S_2)/(S_2-S_1))/log(L);
% R=(S_3-S_2)/(L^m-1);
% result=S_3;
% n=n+3;
% end
% anwser3=result;
% disp('сравнение с точным значением')
% disp(abs(anwser3-precise_int));
% disp('количество итераций');disp(n);
clf
N=40;
y=zeros(N,1);
sumofa=zeros(N);
for n=2:N+1
[y(n-1),sumofa]=ikf_newton_cotes(a,b,n);
end
n=[2:N]';
plot(n,y);hold on;grid on;
% plot(n,sumofa,'LineWidth',1);
line([1 N],[precise_int precise_int])
legend('приближение интеграла','точное значение интеграла')

%% Вариант Гаусса
%Построить интерполяционную квадратурную формулу
disp('ИКФ Гаусса для трех точек')
anwser=ikf_gauss(a,b);
%Оценить методическую погрешность построенного правила (11)
% cle
R=1/factorial(2*N)*((45233019*exp(b/8))/16384 - (15939*exp(-(5*a)/4))/1024 + (4615*exp(-(5*a)/4))/256 + (2151607535*exp(b/8))/131072);
disp('методическая погрешность')
disp(R)
%сравнить её с точной погрешностью
disp('сравнить её с точной погрешностью')
disp(abs(anwser-precise_int));
%построить составную КФ и,уменьшая длину шага h, добиться заданной точности ε = 10−6.
anwser=0;
eps=1e-6;
L=2;n=1;
% На каждых по-следовательных трёх точках оценивать скорость сходимости по правилу Эйткена
S_1=skf_gauss(a,b,(b-a)/L);
S_2=skf_gauss(a,b,(b-a)/L^2);
S_3=skf_gauss(a,b,(b-a)/L^3);
m=-log((S_3-S_2)/(S_2-S_1))/log(L);
R=(S_3-S_2)/(L^m-1);
n=4;
while (abs(R)>=eps)
S_1=skf_gauss(a,b,(b-a)/L^n);
R=(S_3-S_1)/(L^m-1);    
if abs(R)<eps
    result=S_1;
    break;end
S_2=skf_gauss(a,b,(b-a)/L^(n+1));
R=(S_2-S_1)/(L^m-1);    
if abs(R)<eps
    result=S_2;
    break;end
S_3=skf_gauss(a,b,(b-a)/L^(n+2));
n=n+3;
m=-log((S_3-S_2)/(S_2-S_1))/log(L);
R=(S_3-S_2)/(L^m-1);
result=S_3;
end
anwser2=result;
disp('сравнение с точным значением')
disp(abs(anwser2-precise_int));
disp('количество итераций');disp(n);
%использовать оценку скорости сходимости и выбрать оптимальный шаг hopt. Начать расчёт c шага hopt и снова довести до требуемой точности ε.
S_1=ikf_gauss(a,b);
S_2=skf_gauss(a,b,(b-a)/2);
S_3=skf_gauss(a,b,(b-a)/4);
L=2;
m=-log((S_3-S_2)/(S_2-S_1))/log(L);
R=(S_3-S_2)/(L^m-1);
h_opt=(b-a)/4*(eps/abs(R))^(1/m);
n=3;
while (abs(R)>=eps)
S_1=skf_gauss(a,b,h_opt);
m=-log((S_1-S_2)/(S_2-S_3))/log(L);
R=(S_3-S_1)/(L^m-1);    
if abs(R)<eps
    result=S_1;break;break;
    end
S_2=skf_gauss(a,b,(h_opt/2));
m=-log((S_2-S_1)/(S_1-S_3))/log(L);
R=(S_2-S_1)/(L^m-1);    
if abs(R)<eps
    result=S_2;break;break;
end
S_3=skf_gauss(a,b,(h_opt/4));
h_opt=h_opt/8;
m=-log((S_3-S_2)/(S_2-S_1))/log(L);
R=(S_3-S_2)/(L^m-1);
result=S_3;
n=n+3;
end
anwser3=result;
disp('сравнение с точным значением')
disp(abs(anwser3-precise_int));
disp('количество итераций');disp(n);

function [result,sumofa] = skf_newton_cotes(a,b,h)
sumofa=0;result=0;buff1=0;buff2=0;
z=a:h:b;
if z(size(z))<b
    z=[z,b];
end
for i=1:size(z,2)-1
    [buff1,buff2]=ikf_newton_cotes(z(i),z(i+1),2);
result=result+buff1;
sumofa=sumofa+buff2;
end
end

function [result,sumofa] = ikf_newton_cotes(z1,z2,N)
a=1.3;b=2.2;
x=[z1:(z2-z1)/N:z2];
if x(N)~=z2
    x=[x;z2]
end
f = @(t) 4.*cos(0.5.*t).*exp(-5.*t./4)+2.*sin(4.5.*t).*exp(t./8)+2;
beta=5/6;
mu = @(j) sum(arrayfun(@(k) b^k*nchoosek(j,k)*(-1)^(j-k)/(j-k-beta+1)*((b-z1)^(j-k-beta+1)-(b-z2)^(j-k-beta+1)),0:j));
x_s_j=[ones(1,6)];
MU=[mu(0)];
for i=1:N-1
x_s_j=[x_s_j;x^i];
MU = [MU;mu(i)];
end
A=linsolve(x_s_j,MU);
for i=1:N
if A(i)<0
    disp('отрицательный коэф') 
end
end
result=dot(A,f(x));
sumofa=sum(abs(A));
end

function result = skf_gauss(a,b,h)
z=a:h:b;
if z(size(z))<b
    z=[z,b];
end
result=0;
for i=1:size(z,2)-1
result=result+ikf_gauss(z(i),z(i+1));
end
end

function result = ikf_gauss(z1,z2)
a=1.3;b=2.2;
f = @(t) 4.*cos(0.5.*t).*exp(-5.*t./4)+2.*sin(4.5.*t).*exp(t./8)+2;
beta=5/6;
n=3;
mu = @(j) sum(arrayfun(@(k) b^k*nchoosek(j,k)*(-1)^(j-k)/(j-k-beta+1)*((b-z1)^(j-k-beta+1)-(b-z2)^(j-k-beta+1)),0:j));
x_s_j=zeros(n,n);
for i=0:n-1
for j=0:n-1
    x_s_j(i+1,j+1)=mu(i+j);
end
end

MU=arrayfun(@(t) -mu(t),n:2*n-1);
a=linsolve(x_s_j,MU');
syms x;
omega = [1];
for i=n-1:-1:0
omega = [omega a(i+1)];
end
x=sort(roots(omega));x1=zeros(1);
for i=1:size(x)
    if x(i)>=1.3 || x(i)<=2.2
        x1(1)=x(i);
        for j=i+1:size(x)
            if x(j)>=1.3 || x(j)<=2.2
                x1=[x1 x(j)];
            end
        end
        break
    end
end
x=x1;
x_s_j=[[1,1,1];x;x.^2];
MU=[mu(0);mu(1);mu(2)];
result=dot(linsolve(x_s_j,MU),f(x));
end


