# TODO - so_long


## 📋 Parsing de la carte

- [x] Vérifier l'extension `.ber` du fichier de carte (`filename_is_correct()`)
- [x] Lire et stocker la carte en mémoire (get_next_line intégré)
- [x] Vérifier que la carte est rectangulaire (`is_rectangle()`)
- [x] Stocker la carte en structure de données (2D array/liste)
- [x] Vérifier que la carte est entourée de murs (caractère `1`) (`map_surrounded_by_wall()`)
- [x] Valider la présence des éléments obligatoires :
  - [x] Au moins 1 sortie (`E`)
  - [x] Au moins 1 position de départ (`P`)
  - [x] Au moins 1 collectible (`C`)
- [x] Vérifier qu'il y a exactement 1 joueur et 1 sortie (`map_is_valid()`)
- [x] Vérifier que seuls les caractères valides sont présents (`0`, `1`, `C`, `E`, `P`) (`map_is_valid()`)
- [x] Implémenter une vérification stricte de chemin valide (flood fill) (`map_can_be_done()`)
  - [x] Correction du flood fill pour explorer toutes les cases accessibles (utilisation correcte des coordonnées)
  - [x] Le joueur peut atteindre tous les collectibles
  - [x] Le joueur peut atteindre la sortie
  - [x] Affichage debug de la map après flood fill pour valider le chemin


## 🎮 Gestion de la MiniLibX (MLX)

- [x] Initialiser la connexion MLX
  - Utiliser `mlx_init()` pour obtenir un pointeur de connexion.
- [x] Créer une fenêtre (ex: 1920x1080)
  - `mlx_new_window()` pour créer la fenêtre principale.
- [ ] Charger les textures/sprites nécessaires
  - [ ] Préparer les fichiers XPM pour chaque sprite (mur, sol, joueur, collectible, sortie...)
  - [ ] Utiliser `mlx_xpm_file_to_image()` pour charger chaque image et récupérer un pointeur d'image.
  - [ ] Stocker les pointeurs d'images dans une structure dédiée (ex: `t_sprites`).
- [ ] Afficher les images à l'écran
  - [ ] Utiliser `mlx_put_image_to_window()` pour dessiner chaque sprite à la bonne position selon la carte.
  - [ ] Parcourir la map et afficher le bon sprite pour chaque case.
- [ ] Gérer les hooks d'événements
  - [x] Fermer la fenêtre proprement (ESC et croix rouge) avec `mlx_hook()` et `mlx_destroy_window()`.
  - [ ] Gérer les touches pour le déplacement du joueur (`mlx_key_hook()` ou `mlx_hook()` avec l'événement clavier).
- [ ] Libérer correctement la mémoire MLX à la sortie
  - [x] Détruire la fenêtre avec `mlx_destroy_window()`.
  - [ ] Détruire chaque image chargée avec `mlx_destroy_image()`.
  - [ ] Libérer la connexion MLX si nécessaire.
- [ ] Gérer les erreurs MLX
  - [ ] Vérifier le retour de chaque fonction MLX (pointeur NULL = erreur).
  - [ ] Afficher un message d'erreur explicite et quitter proprement si une étape échoue.

**Conseils pratiques MLX :**
- Les images doivent être au format XPM (support natif MLX).
- Attention à bien libérer chaque ressource MLX pour éviter les fuites mémoire.
- Centraliser les pointeurs MLX (fenêtre, images, etc.) dans une structure principale (ex: `t_game`).
- Tester le rendu avec différentes tailles de cartes et de sprites.

## 🖼️ Affichage graphique

- [ ] Définir la taille des tiles/sprites
- [ ] Créer ou récupérer les sprites pour :
  - [ ] Mur
  - [ ] Sol
  - [ ] Collectible
  - [ ] Joueur (possiblement plusieurs directions)
  - [ ] Sortie (fermée/ouverte optionnel)
- [ ] Implémenter le rendu de la carte à l'écran (prochaine étape)
- [ ] Afficher le compteur de mouvements
- [x] Mettre en place le système de pixels (my_mlx_pixel_put)

## 🕹️ Gameplay
- [x] Gérer les inputs clavier (hook en place)
- [ ] Supporter W/A/S/D ou flèches
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

- [x] Afficher "Error\n" suivi d'un message explicite en cas de problème
- [x] Gérer les cas d'erreur :
  - [x] Fichier inexistant ou inaccessible
  - [x] Carte invalide
  - [x] Problème d'allocation mémoire
  - [x] Échec d'initialisation MLX
- [x] Libérer toute la mémoire allouée en cas d'erreur


## 🧹 Nettoyage et normes

- [ ] Vérifier la Norme (norminette)
- [ ] S'assurer qu'il n'y a pas de fuites mémoire (valgrind)
- [ ] Créer/Vérifier le Makefile avec les règles :
  - [ ] `all`
  - [ ] `clean`
  - [ ] `fclean`
  - [ ] `re`
  - [ ] Pas de relink
- [x] Tester avec différentes cartes valides et invalides (dont collectibles inaccessibles)

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

---2026-01-14
**Statut:** MLX initialisée, fenêtre créée, flood fill validé. Fermeture propre et libération mémoire MLX OK. Prochaine étape: chargement de la carte et rendu graphique.
**Dernière mise à jour:** 2026-01-14
