import sympy as sp

# Define symbols
n = sp.symbols('n', integer=True)
s5 = sp.sqrt(5)

# Define the matrix
T = sp.Matrix([[0, 1],
               [1, 1]])

# Eigen decomposition
eigvals = T.eigenvals()
eigvecs = T.eigenvects()

# Build P and D
P = sp.Matrix.hstack(eigvecs[0][2][0], eigvecs[1][2][0])  # Eigenvectors
D = sp.diag(*eigvals.keys())  # Eigenvalues in diagonal

# Compute T^n = P * D^n * P^{-1}
Dn = D**n
Tn = P * Dn * P.inv()

# Simplify
Tn = sp.simplify(Tn)

# Display
sp.pprint(Tn)
