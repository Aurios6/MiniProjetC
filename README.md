# Titre du projet

Ce projet est un projet scolaire fait dans le cadre de l'apprentissage de la programmation bas niveau à l'IUT Paul Sabatier à Toulouse. L'objectif du programme est dans le but de développer des applications de gestion de parcs informatique, l’étude et l’extraction d’informations provenant d’une adresse IP et de son masque réseau.

## Pour commencer

Ce projet supporte l'utilisation de fichier ``.txt`` en entrée. Pour ce faire, il suffira à l'exécution d'indiquer un fichier ``.txt`` de la façon suivante ``./main votreFichier.txt``.\
Ce n'est cependant pas un prérequis, une version avec entrée dans la console est aussi intégrée directement. Il suffit de ne pas fournir de fichier lors de l'exécution du programme.

Ce projet a été fait par :

* Aurélien Vincent--Randonnier _alias_ [@Aurrios6](https://github.com/Aurios6)
* Nathanel Daunis _alias_ [@Stefffox](https://github.com/Stefffox)

Lisez la liste des [contributeurs](https://github.com/Aurios6/MiniProjetC/contributors) pour voir qui à aidé au projet !

### Fonction
[LeProjetGitLab](https://gitlab.info.iut-tlse3.fr/vnr4817a/MiniProjetC)
[LeProjetGitHub](https://github.com/Aurios6/MiniProjetC)

#### Fichier main.c

* Paramètre d'entrée --> char []
* Paramètre de sortie --> int
Déclenche une erreur si le fichier pris en paramètre n'a pas pu être ouvert.

#### Fichier conversion.c

* verifierFormat :
E : une chaîne de caractères  
S : int (1 si le résultat n'est pas valide, 0 sinon)  
Err : si l'adresse IP possède un format invalide  
* extractionDesChamps
E : une chaîne de caractères (l'adresse IP), une liste de chaîne de caractères
S : une chaîne de caractères (le masque au format ``string``)  
Err : à l'allocation mémoire, a l'exécution de ``memcpy``  
* convertToInt :
E : les 2 chaînes de caractères avec les valeurs IP et le masque au format ``string``, retourne les valeurs IP et le masque au format ``int``   
S : void  
Err : Si l'adresse IP possède un format invalide  
* verifierFormat :
E : un tableau d'entiers (l'adresse IP sans le masque)  
S : une chaîne de caractères indiquant la classe de l'adresse IP  
Err : Si l'adresse IP possède un format invalide
* decoderIP --> indique la classe de l'adresse et sont type
E : un tableau contenant l'adresse IP au format entier  
S : une chaîne de caractères 
Err : none  
* decoderMasqueIP --> indique le masque réseau et hôte
E : une liste d'entiers contenant l'adresse IP, un entier contenant le masque, un pointeur vers un fichier pour pouvoir écrire dans ce dernier  
S : void
Err : none
* global -- La fonction qui appelle les autres et lance l'écriture dans un fichier
E : une chaîne de caractères (L'adresse IP au format ``string``, un entier indiquant que le fichier a déjà été ouvert)(permet de ne pas écraser le contenu si plusieurs adresses ip sont fournis)  
S : void (fais uniquement de l'affichage)  
Err : Si le fichier dans lequel les réponses vont être écritent n'a pas pu être ouvert/créé
* nbOfChar
E : une chaîne de caractère, la caractère cible a compté.  
S : un entier égale au nombre de caractères cible  
Err : none  
* entierVersBin
E : une chaîne de caractères  
S : void  
Err : none  
* afficherAdresseIpDepuisLLU --> Ecrit dans le fichier l'adresse IP en binaire
E : un unsiged long long (l'adresse IP), le fichier dans lequel écrire
S : void
Err : none

### Pré-requis

  Aucune libraire extérieure n'est utilisée dans ce projet.

### Installation

  Exécuter la commande ``./main votreFichier.txt`` ou bien ``./main`` depuis le répertoire du projet.


Vous devriez obtenir un résultat semblable à celui-ci -->

## Fabriqué avec

  Ce projet a été conçu exclusivement avec :

  * [VisualStudioCode](https://code.visualstudio.com)


## Versions
  Une seule version est disponible pour le moment.

**Dernière version stable :** 1.0 
**Dernière version :** 1.0


## License

Ce projet est sous licence `MIT License`` - voir le fichier [LICENSE.md](LICENSE.md) pour plus d'informations
