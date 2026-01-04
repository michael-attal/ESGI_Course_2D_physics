```cpp
class Constraint{
	public:
		Body* a;
		Body* b;
		// TODO: jacobian matrix
		// on ne veut pas d'un seul type de contrainte => héritage
		//     - distance constraint 
		//       (joint, 2 points qui doivent garder une certaine distance)
		//     - penetration constraint()
		//       () 
		virtual ~Constraint() = default;		
		MatMN GetInvM() const;
		VecN GetVelocities() const;
		// dans le solve on calcule la magnitude de l'impulse, la direction de l'impulse
		// et on applique l'impulse aux objets A et B
		virtual void Solve() {};
		
};

class DistanceConstraint:: public Constraint{
	// TODO
	// MatMN jacobian()
	// void Solve() override;
};

class PenetrationConstraint:: public Constraint{
	// TODO
	// MatMN jacobian()
	// void Solve() override;
};
```

```cpp
// Constraint.cpp
MatMN Constraint::GetInvM() const{
	MatMN invM(6,6);
	invM.Zero();
	invM.rows[0][0] = a->invMass;
	invM.rows[1][1] = a->invMass;
	invM.rows[2][2] = a->invI;
	invM.rows[3][3] = b->invMass;
	invM.rows[4][4] = b->invMass;
	invM.rows[5][5] = b->invI;
	return invM;
}

VecN Constraint::GetVelocities() const{
	VecN V(6);
	V.Zero();
	V[0] = a->velocity.x;
	V[1] = a->velocity.y;
	V[2] = a->angularVelocity;
	V[3] = b->velocity.x;
	V[4] = b->velocity.y;
	V[5] = b->angularVelocity;
	return V;
}
```