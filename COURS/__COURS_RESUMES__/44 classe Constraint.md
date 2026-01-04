
```cpp
// constraint.h

class Constraint{
	public:
		Body* a;
		Body* b;
		// nouveau type de data structure
		// approche + dynamique avec MatMN et VecN
		MatMN GetInvM(); // rows + cols
		VecN vec; // only rows
		void Solve();		
};
```