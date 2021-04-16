# scrabble_game-INCOMPLETE-


TASK 0 - Am folosit un for in for pentru a declara matricea de 15x15 si am populat-o cu '.', la output am folosit functia print_board din fisierul print_board.h.

TASK 1 - Am impartit inputul ( coordonatele pe oriziontala, verticala si directia) ( nu am stiut cum sa despart inputul altfel decat prin numararea literelor (len_int si len_before_word)
, iar cu strtok am vazut ca se folosesc pointeri si am incercat sa-i ocolesc), iar in functia task1_matrix, in functie de input, am plasat cuvintele la locul lor. (Am stocat intr-un
vector cuvintele pentru ca imi va fi de folos in viitor)

TASK 2 - Am folosit, precum a fost sugerat in tema, un vector ce stoca valorile literelor. Cu ajutorul acestui vector si al modului de parcurgere cuvantului ( asemanator task-ului 1)

TASK 3 - M-am folosit de modul in care am rezolvat task 2 pentru citirea cuvintelor si prelucrarea lor, am folosit functia calculate_player_points pentru a calcula punctajul fiecarui cuvant
si am mai creat o functie power pentru a calcula numere la putere ( aceasta se va folosi la bonusuri), iar bonusurile au fost gasite cu ajutorul bonus_board-ului din fisierul scrabble.h
si functiilor check_for_bonus1 ce verifica daca cuvantul are litere "XX" si check_for_bonus2 ce verifica daca cuvantul se termina cu "YY" ( am folosit functia strstr). In interiorul functiei
calculate_bonus (apare si un vector in care am stocat cunvintele, ma va ajuta la task-urile urmatoare) verific daca exista pe locul cuvantului 2 sau 1 si de cate ori apare. La sfarsit calculez
punctajele la fel ca la task 2 doar ca inmultesc si cu puterile lui 2 si 3 daca e nevoie.

TASK 4 - m-am folosit de functia de la task 1 pentru a stoca intr-un vector cuvintele deja folosite apoi am cautat in ordinea in care cuvintele sunt asezate in vectorul words  din fisierul 
scrabble.h. Am verificat daca cuvantul exista deja pe board, daca nu, verifica daca exista prima litera a cuvantului pe tabla si apoi daca are loc, pe orizontala sau verticala, sa fie jucat.

TASK 5 - Rezolvarea acestui task incepe ca la 4, verifica daca cuvantul poate sa fie jucat si calculeaza cate puncte ar avea daca ar fi jucat, acest cuvant este stocat intr un vector,
iar daca gaseste alt cuvant mai bun, acesta este inlocuit. 	
