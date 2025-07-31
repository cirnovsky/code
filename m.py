import sympy as sp

s5 = sp.sqrt(5)
T = sp.Matrix([[0, 1], [1, 1]])

vecs = T.eigenvects()

for val, mult, vec in vecs:
    v = vec[0]
    v_sc = 2 * v / v[0]
    print(sp.latex(v_sc))
