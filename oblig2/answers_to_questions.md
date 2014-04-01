# Oblig 2, svar på spørsmål

**1.** *En del av klassene inneholder en del `protected` datamedlemmer. Er dette lurt? Nevn noen fordeler og ulemper, og hvordan dette kunne vært gjort anderledes for å unngå ulempene.*
  
**Svar**: Implementere dem som private, og lage get/set-metoder for disse. Dette vil resultere i mere kode, men også et sikrere system.

**2.** *Anta at vi ønsket å implementere fyrverkeriet med et annet grafikkbibliotek, `fancyGraphics`. Hva kunne vært gjort anderledes i designet for at dette skulle kunne blitt gjort enklere?*
  
**Svar**: Putte alle "Fl-oppgaver" inn under et namespace. For å siden få kjørt fancyGraphics kan vi istedet bara bytte hvilken namespace vi skal bruke.

**3.** *Basert på ditt forrige svar; hvis du skulle laget ett eller flere "namespaces" i dette prosjektet, hvilke skulle det vært? Hvilke filer skulle vært med i hvilket namespace og hvilke filer skulle hatt `using namespace ...` for de ulike (hvis flere) namespacene?*

**Svar**: Alle metoder som bruker noe fra FL-biblioteket. F.eks. fl_pie hade f.eks. kunnet hete draw_circle. Vid using namespace fltk hade fl_pie blitt kallt på, men ved FG hade dens metode for å tegne en circle blitt kallt på.

**4.** *Klassene `animated` og `animation_canvas` legger opp til polymorfi. Kunne `animation_canvas` vært implementert med templates i stedet? Hva ville vært fordeler og ulemper?*

**Svar**: Ja, det kunde den har varit. Enligt wikipedia vil fordelen med templates være at den er type-safe, og programmet vil innholde mindre kode. Ulempen vil være at noen kompilatorer har dårlig støtte for templates, og kan ge utydlige feil-meldinger og gjøre debugging vanskligere.

**5.** *Bortsett fra det du har diskutert, ser du andre svakheter i designet, eller andre ting du ville gjort anderledes?*

**Svar**: Nei.