# Pseudo_Tetris

Projet en C de la deuxième année de Licence Informatique de l'UJM.

## Objectif du projet

L'objectif de ce projet est d'implémenter un jeu vidéo Tetris-like en utilisant la bibliothèque
graphique [MLV](http://www-igm.univ-mlv.fr/~boussica/mlv/api/French/html/index.html).

### Fonctionnalités de bases

Ce projet devait obligatoirement comporter les fonctionnalités suivantes :

* Une fonctionnalité pause pour interrompre une partie, et la sauvegarder pour la reprendre ultérieurement (la
  possibilité de sauvegarder différentes parties étant un plus).
* La sauvegarde et l'affichage des 10 meilleurs scores sur l'ensemble des parties (et donc sauvegardés également).
* Un menu comportant les options suivantes :
    * Lancer une nouvelle partie.
    * Sauvegarder une partie.
    * Charger une partie sauvegardée.
    * Afficher les meilleurs scores.

Étant un projet universitaire, le code devait être rigoureusement commenté, et adopter un style de codage clair et
cohérent. De plus, il fallait coder de façon modulaire, c'est-à-dire, un module par fonctionnalité.  
L'utilisation de petites fonctions avec des rôles précis était également recommandée.  
La gestion des erreurs était aussi un point important.

### Pour aller plus loin
Pour améliorer le jeu, il y avait la possibilité d'ajouter des fonctionnalités supplémentaires, comme par exemple :
* Un mode multijoueur, à deux sur le même écran.
* utiliser des images, personnages, etc... pour les pièces.
* Montrer quelle sera la prochaine pièce à tomber.
* Faire des animations lors de la suppression de lignes et de la chute des pièces.
* Sauvegarder les données de jeux via des fichiers binaires.
* tout ce qui semblait sympathique à ajouter...