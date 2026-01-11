# TODO - so_long

## 📋 Parsing de la carte

- [x] Vérifier l'extension `.ber` du fichier de carte (`filename_is_correct()`)
- [x] Lire et stocker la carte en mémoire (get_next_line intégré)
- [x] Vérifier que la carte est rectangulaire (`is_rectangle()`)
- [ ] Stocker la carte en structure de données (2D array/liste)
- [ ] Vérifier que la carte est entourée de murs (caractère `1`)
- [ ] Valider la présence des éléments obligatoires :
  - [ ] Au moins 1 sortie (`E`)
  - [ ] Au moins 1 position de départ (`P`)
  - [ ] Au moins 1 collectible (`C`)
- [ ] Vérifier qu'il y a exactement 1 joueur et 1 sortie
- [ ] Vérifier que seuls les caractères valides sont présents (`0`, `1`, `C`, `E`, `P`)
- [ ] Implémenter une vérification de chemin valide (flood fill ou BFS/DFS)
  - [ ] Le joueur peut atteindre tous les collectibles
  - [ ] Le joueur peut atteindre la sortie

## 🎮 Gestion de la MiniLibX

- [ ] Initialiser la connexion MLX
- [ ] Créer une fenêtre
- [ ] Charger les textures/sprites nécessaires
- [ ] Gérer la fermeture propre de la fenêtre (ESC et croix rouge)
- [ ] Libérer correctement la mémoire MLX à la sortie

## 🖼️ Affichage graphique

- [ ] Définir la taille des tiles/sprites
- [ ] Créer ou récupérer les sprites pour :
  - [ ] Mur
  - [ ] Sol
  - [ ] Collectible
  - [ ] Joueur (possiblement plusieurs directions)
  - [ ] Sortie (fermée/ouverte optionnel)
- [ ] Implémenter le rendu de la carte à l'écran
- [ ] Afficher le compteur de mouvements

## 🕹️ Gameplay

- [ ] Gérer les inputs clavier (W/A/S/D ou flèches)
- [ ] Implémenter le mouvement du joueur
  - [ ] Vérifier les collisions avec les murs
  - [ ] Incrémenter et afficher le compteur de mouvements
  - [ ] Afficher le nombre de mouvements dans le terminal
- [ ] Gérer la collecte des items
  - [ ] Retirer le collectible de la carte
  - [ ] Mettre à jour le compteur de collectibles
- [ ] Gérer la condition de victoire
  - [ ] Tous les collectibles sont ramassés
  - [ ] Le joueur atteint la sortie
  - [ ] Fermer le jeu proprement

## 🛠️ Gestion des erreurs

- [ ] Afficher "Error\n" suivi d'un message explicite en cas de problème
- [ ] Gérer les cas d'erreur :
  - [ ] Fichier inexistant ou inaccessible
  - [ ] Carte invalide
  - [ ] Problème d'allocation mémoire
  - [ ] Échec d'initialisation MLX
- [ ] Libérer toute la mémoire allouée en cas d'erreur

## 🧹 Nettoyage et normes

- [ ] Vérifier la Norme (norminette)
- [ ] S'assurer qu'il n'y a pas de fuites mémoire (valgrind)
- [ ] Créer/Vérifier le Makefile avec les règles :
  - [ ] `all`
  - [ ] `clean`
  - [ ] `fclean`
  - [ ] `re`
  - [ ] Pas de relink
- [ ] Tester avec différentes cartes valides et invalides

## 🎁 Bonus (optionnel)

- [ ] Animations de sprites
- [ ] Affichage du compteur de mouvements à l'écran (pas seulement terminal)
- [ ] Ennemis patrouilleurs (perte si contact)
- [ ] Gérer plusieurs textures pour le joueur selon la direction

## 📝 Notes

- Pense à la structure de tes données (structs pour la carte, le jeu, les sprites, etc.)
- Garde ton code modulaire et bien organisé
- Teste régulièrement avec des cartes de différentes tailles
- N'oublie pas la gestion de la mémoire !

---
**Dernière mise à jour:** En cours de développement
