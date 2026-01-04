![[medias/53 trouver la matrice jacobienne de la constrainte de distance 2025-12-19 18.42.25.excalidraw]]

### implémentation

```cpp
const Vec2 pa = a->LocalSpaceToWorldSpace(aPoint);
const Vec2 pb = b->LocalSpaceToWorldSpace(bPoint);

const Vec2 ra = pa-a->position;
const Vec2 rb = pb-b->position;

Vec2 J1 = (pa-pb)*2.0;
jacobian.rows[0][0] = J1.x;
jacobian.rows[0][1] = J1.y;

float J2 = ra.Cross(pa-pb) * 2.0;
jacobian.rows[0][2] = J2;

Vec2 J3 = (pb-pa) *2.0;
jacobian.rows[0][3] = J3.x;
jacobian.rows[0][4] = J3.y;

float J4 = rb.Cross(pb-pa) * 2.0;
jacobian.rows[0][5] = J4;

const VecN V= GetVelocities();
const MatMN invM = GetInvM(); 
// jacobian transpose
const MatMN Jt = jacobian.Transpose();

// TODO: compute lambda
// TODO: apply lambda impulse to A and B





```