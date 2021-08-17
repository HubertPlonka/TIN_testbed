# TIN_testbed

## Jak to skonfigurować?

Projekt jest ustawiony w taki sposób że powinien działać    \
"z biegu", wystarczy skopiować folder wxWidgets do folderu  \
w do którego jest sklonowane repozytorium.

Przykład: \
Sklonowano repo do folderu

```batch
D:\mujFolderek\he\he
```

Czyli znajduje się w lokalizacji:

```batch
D:\mujFolderek\he\he\TIN_testbed
```

Wtedy folder ```wxWidgets``` powinien być w:

```batch
D:\mujFolderek\he\he
```

Proste no nie ? xD

Folder można pobrać tu -> [wxWidgets](https://drive.google.com/file/d/19QC6fGoTbvylOnT7RSkwvBJ8GiaywVZF/view?usp=sharing)

Jeżeli nie chcesz pobierać tych ~160MB to można zawsze pobrać źródła \
wxWidgets i skompilować samodzielnie (trwa to zależnie od \
komputera ~10 - 20 min), następnie podać w VS2019 ścieżkę do katalogu  ```vc_lib``` (dołączenie statycznej biblioteki)
```include``` oraz ```include\msvc```

### WAŻNA SPRAWA O KTÓREJ ZAPOMNIAŁEM WCZEŚNIEJ

Żeby projekt się skompilował w VS2019 target musi być ustawiony na ```x86``` a konfiguracja buildu na `relase`
Jest tak dlatego że statyczne biblioteki wxWidgets są turbo ciężkie (wszystko razem waży ok. 2-3GB) dlatego
zostawiłem tylko 1 konfiguracjię :)

## Dodawanie test casów

Ponieważ robienie własnego gcc raczej nie leży w naszych możliwościach \
czasowych nowe test casy można pisać w C++ w pliku ```TCtable``` (najlepiej  \
zgodnie z tutorialem na początku pliku)

## Wygląd GUI

![Obrazek](https://github.com/Commentsareuseless/TIN_testbed/blob/main/Schematics/GUI.PNG)
