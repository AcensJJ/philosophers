# philosophers

![Screenshot 2020-10-21_19-05-33-326](https://user-images.githubusercontent.com/45235527/96754056-0d781c00-13d1-11eb-8784-218becc41a82.png)

<strong>Description</strong>

Ce projet est une introduction au bases du threading de processus, et comment travailler sur le même espace mémoire.
Vous apprendrez comment faire des threads.
Vous découvrirez les mutex, les semaphores, et la mémoire partagée.


# Partie obligatoire

Vous devez faire 3 programmes respectant le même set de règles basiques :

- Ce projet doit êre codé en C. Tout crash, fuite mémoire, comportement indéterminé
ou erreur de norme rapporte 0 au projet.
- Un nombre de philosophes sont assis autour d’une table et font trois choses :
manger, penser et dormir.
- Lorsqu’ils mangent, ils ne peuvent pas penser ou dormir, lorsqu’ils dorment, ils
ne peuvent pas manger ou penser, et enfin, lorsqu’ils pensent, ils ne peuvent pas
manger ou dormir.
- La table est circulaire et a un large plat de spaghettis au centre.
- Il y a des fourchettes sur la table.
- Comme il n’est pas aisé de se servir et manger avec une seule fourchette, nous
assumerons qu’un philosophe doit manger avec deux fourchettes, une dans chaque
main.
- Les philosophes ne doivent jamais être affamés.
- Tous les philosophes ont besoin de manger.
- Les philosophes ne communiquent pas entre eux.
- Les philosophes ne savent pas lorsque l’un d’entre eux est sur le point de mourir.
- Dès qu’un philosophe a fini de manger, il pose ses fourchettes et se met à dormir.
- Quand un philosophe a fini de dormir, il se met a penser.
- La simulation s’arrête dès qu’un philosophe meurt.
- Tous les programmes auront les mêmes options : number_of_philosopher time_to_die
time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat]
- Each programs should have the same option : number_of_philosopher time_to_die
time_to_eat time_to_sleep [number_of_time_each_philosophers_must_eat]
  - number_of_philosopher : correspond au nombre de philosophes et au nombre
de fourchettes.
  - time_to_die : en millisecondes. Si un philosophe ne commence pas a manger
dans ’time_to_die’ millisecondes après avoir commencer son dernier repas ou
le début de la simulation, il meurt.
  - time_to_eat : en millisecondes. C’est le temps que prend un philosophe à
manger. Il garde les deux fourchette pendant ce temps.
  - time_to_sleep : en millisecondes. C’est le temps que prend un philosophe à
dormir.
  - number_of_time_each_philosophers_must_eat : Optionnel, si tous les philosophes mangent au moins ’number_of_time_each_philosophers_must_eat’
la simulation s’arrête. Si ce temps n’est pas spécifié, la simulation s’arrête dès
qu’un philosophe meurt.
- Chaque philosophe se verra assigné un nombre de 1 à ’number_of_philosopher’.
- Philosophe 1 est à coté de philosophe ’number_of_philosopher’. Tous les autres
philosophes sont N sont à coté de leur N + 1 et N - 1.
- Tout changement de statut d’un philosophe doit être écrit comme suit (X remplacant le numéro de philosophe et timestamp_in_ms le timestamp, en millisecondes)
  - timestamp_in_ms X has taken a fork
  - timestamp_in_ms X is eating
  - timestamp_in_ms X is sleeping
  - timestamp_in_ms X is thinking
  - timestamp_in_ms X died
- Le statut affiché ne doit pas être mélangé avec le statut d’un autre philosophe.
- Vous ne pouvez pas avoir plus de 10ms de retard entre la mort d’un philosophe et
l’affichage de sa mort.
- Les philosophes doivent éviter de mourir !


## Contraintes

--- IMG ---

Dans cette version, les règles supplémentaires seront :

- Il y a une fourchette entre chaque philosophe, donc il y aura une fourchette à
gauche et a droite de chaque philosophe.
- Pour éviter aux philosophes d’accidentellement dupliquer des fourchettes, vous
devez protéger l’état des fourchettes à l’aide de mutex.
- Vous devez attacher chaque philosophe à un thread différent.

--- IMG ---

Dans cette version, les règles supplémentaires seront :

- Toutes les fourchettes sont au milieu de la table.
- Elles n’ont pas d’état spécifique en mémoire, mais le nombre de fourchettes disponibles est représenté par un semaphore
- Vous devez attacher chaque philosophe à un thread différent.

--- IMG ---

Dans cette version, les règles supplémentaires seront :

- Toutes les fourchettes sont au milieu de la table.
- Elles n’ont pas d’état spécifique en mémoire, mais le nombre de fourchettes disponibles est représenté par un semaphore
- Chaque philosophe est représenté par un processus différent. Le processus principal
ne devrait pas être un philosophe.
