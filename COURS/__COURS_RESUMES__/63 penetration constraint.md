![[medias/63 penetration constraint 2025-12-27 09.46.17.excalidraw]]

### Implémentation
```cpp
// constraint.h
class PenetrationConstraint : public Constraint {
private:
    MatMN jacobian;
    VecN cachedLambda;
    float bias;
    Vec2 normal;

public:
    PenetrationConstraint();
    PenetrationConstraint(
	    Body* a, Body* b, const Vec2& aCollisionPoint, const Vec2& bCollisionPoint, const Vec2& normal
	);
    void PreSolve(const float dt) override;
    void Solve() override;
    void PostSolve() override;
    
};
// constraint.cpp
PenetrationConstraint::PenetrationConstraint(
	    Body* a, Body* b, const Vec2& aCollisionPoint, const Vec2& bCollisionPoint, const Vec2& normal
	)
	{
		this->a =a;
		this->b =b;
		this->aPoint =a->WordlSpaceToLocalSpace(aCollisionPoint);
		this->bPoint =b->WordlSpaceToLocalSpace(bCollisionPoint);
		// normal dans le local space de A
		this->normal =a->WordlSpaceToLocalSpace(normal;);
		cachedLambda.Zero();
	}

PenetrationConstraint::PreSolve(float dt)
{
	// get the collision point in world space
    const Vec2 pa = a->LocalSpaceToWorldSpace(aPoint);
    const Vec2 pb = b->LocalSpaceToWorldSpace(bPoint);
    Vec2 n = a->LocalSpaceToWorldSpace(normal);

    const Vec2 ra = pa - a->position;
    const Vec2 rb = pb - b->position;

    jacobian.Zero();

    Vec2 J1 = -n;
    jacobian.rows[0][0] = J1.x; // A linear velocity.x
    jacobian.rows[0][1] = J1.y; // A linear velocity.y
    
    float J2 = -ra.Cross(n):
    jacobian.rows[0][2] = J2; // 
    
    Vec2 J3 =n;
    jacobian.rows[0][3] = J3.x; // A linear velocity.x
    jacobian.rows[0][4] = J3.y; // A linear velocity.y
    
    float J4 = rb.Cross(n):
    jacobian.rows[0][5] = J4; // 
    // warm starting
    const MatMN Jt = jacobian.Transpose();
    VecN impulses = Jt*cachedLambda;
    
    a->ApplyImpulseLinear(Vec2(impulses[0], impulses[1]));
    a->ApplyImpulseAngular(Vec2(impulses[2]));
    b->ApplyImpulseLinear(Vec2(impulses[3], impulses[4]));
    b->ApplyImpulseAngular(Vec2(impulses[5]));
    
    // compute the bias term (baumgarte stabilization)
    const float beta = 0.2f;
    // distance constraint
    float C = (pb-pa).Dot(-n);
    C = std::min(0.0f, C+0.01f);
    bias = (beta/dt) * C;
    
}

PenetrationConstraint::Solve()
{
	cons VecN V = GetVelocities();
	cons MatMN invM = GetInvM();
	
	const MatMN J = jacobian;
	const MatMN Jt = jacobian.Transpose();
	
	MatMN lhs = J* invM*Jt;// A
	VecN rhs = J* V*-1.0f; // b
	rhs[0] -= bias;
	// `lambda` représente ici **Δλ**, pas encore la valeur finale accumulée
	
	VecN lambda = MatMN::SolveGaussSeidel(lhs, rhs);
	// on sauvegarde l'ancien oldLambda
	// - `cachedLambda` stocke la **valeur cumulée de λ** sur plusieurs itérations / frames
    
//- Avantage :
//    - convergence plus rapide
//    - contraintes plus stables (warm starting)
	VecN oldLambda= cachedLambda;
	cachedLambda += lambda;
	// clamp pour valeurs positives
	//- Une contrainte de pénétration est **unilatérale** :
	    //- elle peut **pousser** (λ ≥ 0)
        
	    //- mais jamais **tirer**
//- On impose donc :

    //λ≥0\lambda \ge 0λ≥0

// Cela correspond physiquement à une **réaction de contact** normale.
	cachedLambda[0] = (cachedLambda[0]<0.0f) ? 0.0f : cachedLambda[0];
	/*
	- Après le clamp, la correction réelle appliquée peut être différente
    
- On recalcule donc **l’incrément valide** :
    
    Δλ=λnew−λold

C’est **ce Δλ** qui sera converti en impulsion.
*/*
	lambda = cachedLamnda - oldLambda;
	
	VecN impulses = Jt*lambda;
	
	a->ApplyImpulseLinear(Vec2(impulses[0], impulses[1]));
    a->ApplyImpulseAngular(Vec2(impulses[2]));
    b->ApplyImpulseLinear(Vec2(impulses[3], impulses[4]));
    b->ApplyImpulseAngular(Vec2(impulses[5]));
	
	
	
}

PenetrationConstraint::PostSolve()
{
	// clamp values
}
/*
1. on ajoute une nouvelle contrainte de pénétration
dans World.cpp, on enlève CheckCollision()
si on détecte une collision, plutôt que de faire ResolveCollision
*/
PenetrationConstraint penetration(contact.a, contact.b, contact.start, contact.end, contact.normal);
penetrations.push_back(penetration);
/*
2. dans update on crée un vecteur de contraintes de pénétration qui sera résolu à chauqe frame
*/
std::vector<PenetrationConstraint> penetrations;
/*
3. on résoud les penetration constraints
*/

for(auto& constraint::penetrations)
	constraint.PreSolve(dt);

// on itere 5 fois...
for(auto& constraint::penetrations)
	constraint.Solve(dt);
	   

```

![[medias/63 penetration constraint-20251231.png]]

**Contraintes de pénétration et _warm starting_**

À titre de précision, nous n’exploitons pas encore pleinement le potentiel du _warm starting_ dans nos contraintes de pénétration.

En effet, le vecteur des pénétrations est recréé une seule fois par appel à la fonction `update`. Par conséquent, tout le travail effectué sur les pénétrations lors de l’itération précédente est perdu avant l’appel suivant.

Il existe néanmoins plusieurs autres techniques que nous pouvons encore appliquer afin d’améliorer la résolution des contraintes de pénétration, et nous en implémenterons certaines très prochainement.

Mais avant cela, reprenons et réintroduisons la friction dans notre simulation.
