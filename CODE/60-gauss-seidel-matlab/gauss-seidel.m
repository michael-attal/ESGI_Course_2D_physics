A = [12,3,-5; 1,5,3; 3,7,13]
B = [1; 28; 76]

X = zeros(length(B),1);

%------------------------------------------------------------------
% Solve Ax=b using the Gauss-Seidel method (iterate 6 times)
%------------------------------------------------------------------
for iteration = 1:6
    for i = 1:length(B)
        X(i) = X(i) + (B(i)/A(i,i) - (dot(A(i,:),X)/A(i,i)));
    end
end

% Print the result that is inside X
X

% Compare it with the result provided by MATLAB's \ operator
expected = A\B