- Si l'une des contrainte n'est pas satisfaite, ne pas laisser le move se faire :3 



todos
Person.isValid(Container current)
Ajouter pointeurs utiles dans chaque sous classe

Child.isWithPrimaryParent(Parent*)

parent et child abstrait

candrive au niveau parent et child return .

move _persons allocation in Controller

simulation de mov: juste copier un container (liste de pointeurs c'est light).


container liste de ptr de Person.

pas de switch sur les opérations du CLI (faire une map string => function)

erreur de saisie et erreur de personne non trouvée et erreur action invalide (attention à bien afficher ###...)


pour avoir le message derreur d'action invalide, peut-être retourner un struct {boolean status; string error;}



----
questions
- au lieu de primary secondary getters, ca pourrait pas être directement des attribtus dans child Parent primaryParent and secondaryParent and just changing order in constructor call.

new Boy("paul", mere, pere),
new Boy("piere", mere, pere),
new Girl("julie", mere, pere),
new Girl("jeanne", mere, pere),


- container explicit constructor ??
- tous les TODO avec ?