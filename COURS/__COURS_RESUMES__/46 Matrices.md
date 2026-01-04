![[medias/46 Matrices 2025-12-15 11.08.57.excalidraw]]

### Implémentation

#### header / prototype

```cpp
// MatMN.h
struct MatMN{
	int M; // rows
	int N; // cols
	
	VecN* rows; // rows of the matrix (array of several VecN)
	
	MatMN();
	MatMN(int M, int N);
	MatMN(const MatMN& m);
	~MatMN();
	
	void Zero();
	MatMN Transpose() const;
	
	const MatMN& operator = (const MatMN& m); // m1 = m2
	VecN operator * (const VecN& v) const; // m * v
	MatMN operator * (const MatMN& m) const; // m1 * m2
};

```

#### fichier .cpp

```cpp
MatMN::MatMN(): M(O), N(0), rows(nullptr) {}

MatMN::MatMN(int M, int N): M(M), N(N){
	rows = new VecN(M);
	for(int i=0;i<M;i++)
		rows[i] = VecN(N);
}

MatMN::MatMN(const MatMN& m)
{
	*this = m; // operateur overloaded plus bas
}

MatMN::~MatMN(){
	delete[] rows;
}

void MatMN::Zero()
{
	for(int i=0; i < M; i++)
		rows[i].Zero();
}

MatMN MatMN::Transpose() const
{
	MatMN result(N,M);
	for(int i = 0; i < M; i++)
		for(int j = 0; j < N; j++)
			result.rows[j][i] = result.rows[i][j];
	return result;
}


const MatMN&  MatMN::operator = (const MatMN& m)
{
	M = m.M;
	N = m.N;
	rows = new VecN(M);
	for(int i=0; i< M; i++)
	{
		rows[i] = m.rows[i];
	}
	return *this;
}
// 2. multiplication matrice-vecteur

VecN MatMN::operator * (const VecN& v) const{
	if(v.N != N)
		return v;
	VecN result(M);
	
	for(int i =0; i< M; i++)
		result[i] v.Dot(rows[i])
	return result;
}

// 1. multiplication matrice-matrice
MatMN MatMN::operator * (const MatMN& m) const{
	if(m.M != N && m.N != M)
		return m;
	// pour éviter de multiplier rows * columns mais plutôt rows*rows
	MatMN transposed = m.Transpose();
	MatMN result(M,m.n);
	for(int i= 0; i < M; i++)
		for(int j= 0; j < M; j++)
			result.rows[i][j] = rows[i].Dot(transposed.rows[j]);
	return result;
		

}




```
