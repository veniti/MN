clc
clear all
close all

% odpowiednie fragmenty kodu mo¿na wykonaæ poprzez znazaczenie i wciœniêcie F9
% komentowanie/ odkomentowywanie: ctrl+r / ctrl+t

% W³¹czanie dziennika:
diary('dziennik_165600_ab3');

% Zadanie A
%------------------
N = 100;
density = 3; % parametr decyduj¹cy o gestosci polaczen miedzy stronami
indeks =   165600;
[Edges] = generate_network(N, density, indeks)
max(max(Edges))
%-----------------

% Zadanie B
%------------------
% generacja macierzy I, A, B i wektora b
% ...

 [A, B, I, b, t] = pr(Edges);



save zadB_indeks A B I b
%-----------------


% Zadanie D
%------------------
clc
clear all
close all

G = [500, 1000, 3000, 6000, 12000];
density = 10;
index = 165600;


for i = 1:5
% obliczenia

N = G(i); 
[Edges] = generate_network(N, density, indeks)
max(max(Edges))
Ex = Edges(1,:);
Ey = Edges(2,:);
    
     
d = 0.85;
     
I = speye(N);
     
b = sparse(ones(N, 1).*((1-d)/N));
B = sparse(Ey, Ex, 1);
     
     
L = sparse(1./sum(B,1));
A = sparse(diag(L));

M = I - d*B*A;
M = sparse(M);
tic
r = M\b; 
czas_Gauss(i) = toc;
end

loglog(G, czas_Gauss)
grid on 


%------------------



% Zadanie E
%------------------
clc
clear all
close all

% przyk³ad dzia³ania funkcji tril, triu, diag:
% Z = rand(4,4)
% tril(Z,-1) 
% triu(Z,1) 
% diag(diag(Z))


resSav = [];


for i = 1:5
N = G(i); 
[Edges] = generate_network(N, density, indeks);
max(max(Edges));
Ex = Edges(1,:);
Ey = Edges(2,:);
    
     
d = 0.85;
     
I = speye(N);
     
b = sparse(ones(N, 1).*((1-d)/N));
B = sparse(Ey, Ex, 1);
     
     
L = sparse(1./sum(B,1));
A = sparse(diag(L));

M = I - d*B*A;
M = sparse(M);

tic
D = diag(diag(M));
L = tril(M, -1);
U = triu(M, 1);

r = ones(length(M), 1);
r1 = [];
residuum = 1;

count = 0;
while residuum > 10^-14
    r1 = -D\(L+U)*r+D\b;
    r=r1;
    residuum = norm(M*r1-b);
    count = count + 1;
    resSav(i, count) = residuum; 
end

czas_Jacobi(i) = toc;
iter_Jacobi(i) = count;
end

loglog(G, czas_Jacobi);
grid on
loglog(G, l_iteracji);
grid on

figure
semilogy(resSav');
grid on

%------------------
diary off





Jacobi i Seidel

tic
D = diag(diag(M));
L = tril(M, -1);
U = triu(M, 1);

r = ones(length(M), 1);
r1 = [];
residuum = 1;

count = 0;
while residuum > 10^-14
    r1 = -D\(L+U)*r+D\b;
    r=r1;
    residuum = norm(M*r1-b);
    count = count + 1;
    resJacobi(count) = residuum; 
end

czas_Jacobi = toc;
iter_Jacobi = count;





tic
D = diag(diag(M));
L = tril(M, -1);
U = triu(M, 1);

r = ones(length(M), 1);
r1 = [];
residuum = 1;

count = 0;
while residuum > 10^-14
    r1 = -(D+L)\U*r+(D+L)\b;
    r=r1;
    residuum = norm(M*r1-b);
    count = count + 1;
    resSeidel(count) = residuum; 
end

czas_Seidel = toc;
iter_Seidel = count;

















