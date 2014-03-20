> ###Student s188900:
> #### Tilbakemelding på oblig 1:

> stringlong: Her skulle man utnytte minnet direkte, ved å skrive direkte og hente direkte fra minnet. Unsigned long long er minst 64 bits, og dermed 8 bytes. Det kan man skrive direkte fra og til ved pointer casting. Uansett, så fungerer programmet, og det er bra skrevet! Bra at du brukte sizeof(), selv om bitset<> bruker magiske tall.

> wordcloud_fast: Bra implementasjon. *(ptr + i) er det samme som ptr[i]. For eksempel bruker du c = *(ptr + (++i)) som er det samme som ptr[++i]. '\0' er det samme som 0 i og med at det er snakk om char, som er et heltall med sizeof(char) == 1. Du trenger ikke avbryte programmet med exit(0) (som kjører exit handlere og terminerer,) siden du allerede er ferdig med programmet. Bare return 0; istedet.

> wordcloud_stl: Mye av det samme som i wordcloud_fast, men bra bruk av C++ og SL. Husk at struct er en åpen klasse i C++, og trenger ikke samme syntax som i C. Du trenger heller ikke referere til List inni List klassen (med List::).

```
struct node_t
{
   node_t* next;
   std::string word;
   int count;
};
node_t* head;
node_t* tail;
nide_t* ptr;
```

> **Konklusjon:** Godkjent.
