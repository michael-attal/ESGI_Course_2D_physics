![[medias/45 VecN class 2025-12-15 10.11.09.excalidraw]]


### VecN prototype
```cpp
// vecN.h
struct VecN {
	int N; // nombre de components
	float* data; // array de valeurs
	// float* data = new float[N];
	// 3 constructeurs
	VecN();
	VecN(int N);
	VecN(const VecN& v);
	// destructeur
	~VecN();
	
	// TODO:
	
	void Zero(); // v1.Zero()
	
	// .Dot(v)
	float Dot (const VecN& v) const; // v1.Dot(v2)
	// +
	VecN operator + (const VecN& v); //v1+v2
	// -
	VecN operator - (const VecN& v); //v1-v2
	
	// * (scale)
	VecN operator * (float n); //v1*n
	
	// +=
	const VecN& operator += (const VecN& v);// v1+=v2
	
	// -=
	const VecN& operator -= (const VecN& v);//v1-=v2
	
	// *=
	const VecN& operator *= (const float n);//v1*=n
	
	// v[2] // fetch value with index
	float operator [] (const int index) const; // v[index]
	float& operator [] (const int index); // v[index]
	
	
};
```

### VecN.cpp

```cpp
VecN::VecN(): N(0) data(nullptr) {}

VecN::VecN(int N): N(N){
	data = new float[N];
}

VecN::VecN(const VecN& v){
	N = v.N;
	data = new float[N];
	for(int i=0; i < N; i++)
	{
		data[i] = v.data[i];
	}
}	

VecN::~VecN(){
	delete[] data;
}

void VecN::Zero(){
	for(int i=0; i < N; i++)
	{
		data[i] = 0.0f;
	}
}

float Dot(VecN& v) const {
	float sum = 0.0;
	for(int i=0; i < N; i++)
		result += data[i] * v.data[i];
	return sum;
}

// operator overload

// assignment
VecN& VecN::operator = (const VecN& v)
{
	delete[] data;
	N= v.N;
	data = new float[N];
	for(int i=0; i < N; i++)
		data[i] = v.data[i];
	return *this;
}

VecN VecN::operator * (float n) const{
	VecN result = *this;
	result *= n; // defini plus bas...
	return result;
}

VecN VecN::operator + (const VecN& v) const{
	VecN result = *this;
	for(int i=0; i < N; i++)
		result.data[i] += v.data[i]
	return result;
}

VecN VecN::operator - (const VecN& v) const{
	VecN result = *this;
	for(int i=0; i < N; i++)
		result.data[i] -= v.data[i]
	return result;
}

const VecN& VecN::operator *= (float n)
{
	for(int i=0; i < N; i++)
		data[i] *= n;
	return *this;
}

const VecN& VecN::operator += (const VecN& v)
{
	for(int i=0; i < N; i++)
		data[i] += v.data[i];
	return *this;
}

const VecN& VecN::operator -= (const VecN& v)
{
	for(int i=0; i < N; i++)
		data[i] -= v.data[i];
	return *this;
}

float VecN::operator [] (const int index) const{
 return data[index];
}

// si on veut assigner un valeur
float& VecN::operator [] (const int index){
 return data[index];
}
```