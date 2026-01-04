```cpp
// MatMN.h
static VecN SolveGaussSeidel(const& MatMN& A, const VecN& b);
// MatMN.cpp
VecN MatMN::SolveGaussSeidel(const& MatMN& A, const VecN& b)
	const int N = b.N;
	VecN X(N);
	X.Zero();
	// iterate N times
	for(int iterations=0; i < N; iterations++)
		for(int i=0; i< N; i++)
			if(A.rows[i][i]!=0.0f)
				X[i] += (b[i]/A.rows[i][i]) - (A.rows[i].Dot(X) / A.rows[i][i]);
	return X;
```