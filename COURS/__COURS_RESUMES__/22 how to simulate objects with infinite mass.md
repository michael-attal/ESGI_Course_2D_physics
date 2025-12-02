```cpp
// dans la class Body
if(mass != 0.0) this->invMass = 1.0 / mass;
else this->invMass = 0.; // car 1/999999999 ~= 0.0000001
```

```cpp
bool Body::IsStatic() const{
	const float epislon = 0.005f;
	return fabs(invMass-0.0) <= epsilon;
}
```