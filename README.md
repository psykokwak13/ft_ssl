Ordre de priorité pour l'affichage d'une source donnée (stdin / -s / fichier) :

1. -q gagne toujours sur le formatage : peu importe -r, le résultat est juste hash tout seul, sans label.

2. -p est indépendant : il ne fait qu'ajouter une ligne supplémentaire = le contenu de stdin recopié tel quel. Cette ligne n'est jamais inversée par -r (regarde l'exemple -p -r file : la ligne stdin garde son format ("...")= hash, seule la ligne file est inversée).

3. Si ni -q ni -r : format par défaut MD5 (x) = hash (ou (stdin)= hash pour stdin sans -p).

4. Si -r seul (sans -q) : hash x.



ATTENTION !!!! : ON DOIT RETIRER LES PRINTF -> PAS AUTORISE PAR LE SUJET
                 -> on importe ft_printf
REVOIR : - beta_version pour handle_file et handle_stdin
         - algorithme md5 / manip bit etc

FAIRE : - output pour stdin
        - beta_version
        - ALGO SHA256



src :
https://fr.wikipedia.org/wiki/MD5
https://www.okta.com/fr-fr/identity-101/md5/
https://datatracker.ietf.org/doc/html/rfc1321

sha-256 :
