![[medias/47 compute constraint impulses 2025-12-16 17.15.37.excalidraw]]

### implémentation
```cpp
class constraint{
	public:
		Body* a;
		Body* b;
		// chaque contrainte aura une matrice jacobienne (avec coefficients)
		MatMN jacobian;
		
		MatMN GetInvM() const;
		MatMN GetVelocities() const;
		
		void Solve();
};

VecN Constraint::GetVelocities() const{
	VecN V(6);
	V[0] = a->velocity.x;
	V[1] = a->velocity.y;
	V[2] = a->angularVelocity;
	V[3] = b->velocity.x;
	V[4] = b->velocity.y;
	V[5] = b->angularVelocity;
	return V;
}
```