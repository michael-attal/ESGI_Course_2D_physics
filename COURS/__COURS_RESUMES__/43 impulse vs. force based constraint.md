![[medias/43 impulse vs. force based constraint 2025-12-14 18.18.59.excalidraw]]

### classe Constraint   (pseudo code)

```cpp
class Constraint{
	public:
		Body* a;
		Body* b;
		Mat6x6 GetInvM() const;
		// Solve() va calculer les impulses qui permettent de valider la contrainte
		// et aussi va appliquer ces impulses aux 2 bodies
		void Solve();		
};
```

```cpp
Mat6x6 Constraint::GetInvM() const{
	Mat6x6 invM(6,6);
	invM.rows[0][0] = a->invMass;
	invM.rows[1][1] = a->invMass;
	invM.rows[2][2] = a->invI;

	invM.rows[3][3] = b->invMass;
	invM.rows[4][4] = b->invMass;
	invM.rows[5][5] = b->invI;
	
	return invM;
}
```