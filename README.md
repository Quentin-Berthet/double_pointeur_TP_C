# Tests manuels

Pour lancer les tests automatisés manuellement sur votre code:

- clonez le dépôt git qui se trouve à l'adresse <https://githepia.hesge.ch/orestis.malaspin/prog_seq_automated_tests>
- allez dans le répertoire `prog_seq_automated_tests` qui vient d'être créé:
    ```
    cd prog_seq_automated_tests
    ```
- créez un répertoire `src`
    ```
    mkdir src
    ```
- allez dans le répertoire `src`
    ```
    cd src
    ```
- clonez votre projet
    ```
    git clone l_adresse_de_votre_projet
    ```
- retournez dans le répertoire `prog_seq_automated_tests`.
- exécutez `./run_tests`

# Tests automatisés sur `githepia`

Pour lancer les tests automatisés automatiquement sur l'outil d'intégration continue de `githepia`:

- clonez le dépôt `git` qui se trouve à l'adresse <https://githepia.hesge.ch/orestis.malaspin/prog_seq_automated_tests>
- créez au même endroit dans l'arborescence votre dépot `git` (ex: `double_pointeurs`).
- à la racine de votre dépot, copiez le fichier `.gitlab-ci.yml` se trouvant dans `prog_seq_automated_tests/double_pointeurs`.
- ajoutez `.gitlab-ci.yml` à votre dépot.
- à la racine de votre dépot, copiez également tous les fichiers se trouvant dans le répertoire `prog_seq_automated_tests/double_pointeurs`
- ajoutez les et "commitez".
- créez-y un répertoire `src`.
    ```
    mkdir src
    ```
- dans le répertoire `src` créez un répertoire avec le nom de votre choix, ex: `le_repertoire_avec_le_nom_de_mon_choix`.
    ```
    cd src
    mkdir le_repertoire_avec_le_nom_de_mon_choix
    ```
- dans le répertoire à votre nom, mettez tous vos fichiers sources et votre `makefile`.
- ajoutez les fichiers, "commitez" les et "pushez" les. **Attention pas de fichiers binaires!**

Normalement, les tests seront exécutés à chaque fois que vous faites un `git push` dans votre dépot.
