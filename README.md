# Titre du projet

Ce projet est un projet scolaire fait dans le cadre de l'apprentissage de la programmation bas niveau à l'IUT Paul Sabatier à Toulouse. L'objectif du programme est de le but de développer des applications de gestion de parcs informatique, l’étude et l’extraction d’informations provenant d’une adresse IP et de son masque réseau.

## Pour commencer

Ce projet supporte l'utilisation de fichier ``.txt`` en entrer. Pour ce faire il suffira a l'éxection d'indiquer un fichier ``.txt`` de la façon suivante ``./main votreFichier.txt``.\
Ce n'est cependant pas un prérequis une version avec entrer dans la console est aussi integrer directement. Il suffit de ne pas fournir de fichier lors de l'exectuon du programme.

Ce projet à été fait par:

* Aurélien Vincent--Randonnier _alias_ [@Aurrios6](https://github.com/Aurios6)
* Nathanel Daunis _alias_ [@Stefffox](https://github.com/Stefffox)

Lisez la liste des [contributeurs](https://github.com/Aurios6/MiniProjetC/contributors) pour voir qui à aidé au projet !

### Fonction

#### Fichier main.c

* Paramètre d'entrer --> char []
* Paramètre de sortie --> int
Déclenche une erreur si le fichier pris en paramètre n'a pas pu être ouvert

#### Fichier conversion.c

* verifierFormat :
  E : une chaine de caractere  
  S : int (1 si le résultat n'est pas valide, 0 sinon)  
  Err : Si l'adresse IP possède un format invalide  
* extractionDesChamps
  E : une chaine de caractere (l'adresse IP), une liste de chaine de caractere  
  S : une chaine de caracter (le masque au format ``string``)  
  Err : A l'allocation mémoire, a l'éxéction de ``memcpy``  
* convertToInt :
  E : les 2 chaine de caracter avec les valeurs IP et le masque au format ``string``, retourn les valeurs IP et le masque au format ``int``   
  S : void  
  Err : Si l'adresse IP possède un format invalide  
* verifierFormat :
  E : un tableau d'entier (l'adresse IP sans le masque)  
  S : une chaine de caractere indiquant la classe de l'adresse IP  
  Err : Si l'adresse IP possède un format invalide
* global -- C'est la fonction qui appel les autres et lance l'écriture dans un fichier
  E : une chain de carctere (l'adrsse IP au format ``string``, un entier indiquant que le fichier a deja été ouvert (permet de ne pas ecrasé le contenu si plusieur adresse ip sont fournis)
  S : void (fais uniquement de l'affichage)
  Err : Si le fichier dans lequel les réponse vont etre ecrite n'a pas pu être ouvert /créé


### Pré-requis

Aucune libraire extèrieur n'est utilisé dans ce projet.

### Installation

Les étapes pour installer votre programme....

Dites ce qu'il faut faire...

Exectuer la commande ``./main votreFichier.txt`` ou bien ``./main`` depuis le repertoir du projet.


Vous devriez obtenir un résultat semblable à celui ci -->

## Fabriqué avec

Ce projet à été conçu exlusivement avec :

_exemples :_
* [VisualStudioCode](https://code.visualstudio.com)


## Versions
Une seul version est disponible pour le moment

**Dernière version stable :** 1.0  
**Dernière version :** 1.0

## Auteurs
Listez le(s) auteur(s) du projet ici !
* **Jhon doe** _alias_ [@outout14](https://github.com/outout14)


## License

Ce projet est sous licence `MIT License`` - voir le fichier [LICENSE.md](LICENSE.md) pour plus d'informations

