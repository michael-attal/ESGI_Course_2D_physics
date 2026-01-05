Moment d’inertie des polygones à N côtés

Un petit détail que nous avions laissé de côté et que nous n’avons jamais vraiment implémenté est le calcul correct du moment d’inertie pour les polygones. Si vous vous souvenez, nous avions simplement ajouté un “5000” en dur pour tester, et nous n’avions jamais intégré la fonction correcte.

Sachez simplement que l’ajout du calcul correct du moment d’inertie ne changera probablement rien visuellement à ce que nous avons actuellement dans notre moteur. J’ajoute ce code ici juste pour ne pas laisser de bouts en suspens dans notre moteur.

Si vous voulez compléter votre classe Polygon, voici un exemple d’implémentation possible pour calculer le moment d’inertie des polygones :

```cpp
float PolygonShape::PolygonArea() const {
    float area = 0.0;
    for (int i = 0; i < localVertices.size(); i++) {
        int j = (i+1) % localVertices.size();
        area += localVertices[i].Cross(localVertices[j]);
    }
    return area / 2;
}

Vec2 PolygonShape::PolygonCentroid() const {
    Vec2 cg {0, 0};
    for (int i = 0; i < localVertices.size(); i++) {
        int j = (i+1) % localVertices.size();
        cg += (localVertices[i] + localVertices[j]) * localVertices[i].Cross(localVertices[j]);
    }
    return cg / 6 / PolygonArea();
}

float PolygonShape::GetMomentOfInertia() const {
    float acc0 = 0;
    float acc1 = 0;
    for (int i = 0; i < localVertices.size(); i++) {
        auto a = localVertices[i];
        auto b = localVertices[(i + 1) % localVertices.size()];
        auto cross = abs(a.Cross(b));
        acc0 += cross * (a.Dot(a) + b.Dot(b) + a.Dot(b));
        acc1 += cross;
    }
    return acc0 / 6 / acc1;
}

```

Comprendre en profondeur comment calculer les moments d’inertie n’est pas vraiment utile pour nous en tant que programmeurs dans ce cours d’introduction. Mais en résumé, on parcourt tous les sommets du polygone pour trouver l’aire totale et combiner les centroïdes (centre de gravité) de tous les triangles formés à partir du polygone original. Le code ci-dessus utilise également des applications astucieuses des produits vectoriels (_cross_) et scalaires (_dot_) pour calculer la valeur finale du moment d’inertie.