# TODO - so_long


## 📋 Parsing de la carte

- [x] Vérifier l'extension `.ber` du fichier de carte (`filename_is_correct()`)

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
  - [x] Charger les textures/sprites nécessaires
    - [x] Préparer les fichiers XPM pour chaque sprite (mur, sol, joueur, collectible, sortie...)
    - [x] Utiliser `mlx_xpm_file_to_image()` pour charger chaque image et récupérer un pointeur d'image.
    - [x] Stocker les pointeurs d'images dans une structure dédiée (ex: `t_sprites`).
  - [x] Afficher les images à l'écran
    - [x] Utiliser `mlx_put_image_to_window()` pour dessiner chaque sprite à la bonne position selon la carte.
    - [x] Parcourir la map et afficher le bon sprite pour chaque case.
  - [x] Gérer les hooks d'événements
    - [x] Fermer la fenêtre proprement (ESC et croix rouge) avec `mlx_hook()` et `mlx_destroy_window()`.
    - [x] Gérer les touches pour le déplacement du joueur (`mlx_key_hook()` ou `mlx_hook()` avec l'événement clavier).
  - [x] Libérer correctement la mémoire MLX à la sortie
    - [x] Détruire la fenêtre avec `mlx_destroy_window()`.
    - [x] Détruire chaque image chargée avec `mlx_destroy_image()` (image principale OK)
    - [x] Libérer la connexion MLX (free et destroy_display)
  - [x] Gérer les erreurs MLX
    - [x] Vérifier le retour de chaque fonction MLX (pointeur NULL = erreur).
    - [x] Afficher un message d'erreur explicite et quitter proprement si une étape échoue.

## 🖼️ Affichage graphique
- [x] Définir la taille des tiles/sprites (TILE_SIZE dans le code)
- [x] Créer un affichage basique couleur pour chaque type (pas encore de sprites XPM)
- [x] Créer ou récupérer les sprites XPM pour :
  - [x] Mur
  - [x] Sol
  - [x] Collectible
  - [x] Joueur (possiblement plusieurs directions)
  # Todo List

  - [x] Parsing de la carte : toutes validations
  - [x] Gestion MLX : fenêtre, sprites, hooks
  - [x] Affichage graphique : rendu carte, sprites
  - [x] Gameplay : déplacement joueur, collisions, compteur mouvements
  - [ ] Gameplay : victoire et collecte complète
  - [ ] Supporter W/A/S/D (flèches OK)
  - [ ] Vérifier la norme (norminette)
  - [x] Nettoyage mémoire (valgrind OK)
  - [x] Makefile : all, clean, fclean, re, pas de relink
  - [x] Tests avec cartes valides/invalides
  - [ ] Bonus : animations, compteur mouvements à l'écran
  - [ ] Bonus : ennemis patrouilleurs, textures direction
  - [x] Mettre à jour le compteur de collectibles
