# ft\_Printf

Parce que je suis fatigué d'utiliser putnbr et putstr
Ce projet vise à reconstruire la bibliothèque printf avec des fonctionnalités de base. J'ai essayé d'implémenter autant que possible l'original, et j'ai également quelques choses supplémentaires que j'ai trouvées assez utiles.
Certains choix n'étaient pas intentionnels (certains comportements ont été répliqués à partir de printf d'OS X, d'autres n'ont pas été répliqués) et dans l'ensemble, le code est plus compliqué que je ne l'aurais souhaité. Au moins ça marche!

## Usage

Utilisez-le comme vous utiliseriez la fonction  `printf` :

```c
int i;

i = 42;
ft_printf("value: %d\n", i);

// value: 42
```

## License
`ft_printf` est sous la  **GNU General Public License 3.0**.
