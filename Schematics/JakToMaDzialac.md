# JakToDziała.jpg

## Definicje żeby się nie zgubić

STM - najprawdopodobniej nucleo, które będzie połączone z AVR (pinami)
      i które będzie się komunikowało z PC

AVR - Ta pojebana płytka z jakąś ATmegą którą mamy testować

## Apka na kompa

### GUI i inne pierdoły

Najprawdopodobniej powinno być GUI w którym wyświetlałyby się test casy
(np. jak rozwijana lista z suwakiem) Może jak będzie nam się chciało to jakaś
grafika która wyświetla na mikrokontrolerze co działa a co nie. Jak nie to może
po prostu powiedzmy "terminal" w tym gui który wyświetlałby
który test case zaliczony a który nie. Można zrobić logowanie do terminala
poza GUI (jusful staf), jest taki fajny open soursik do tego -> [spdlog](https://github.com/gabime/spdlog)

### Komunikacja z uC

Najlepiej chyba przez USART/UART bo niby jak inaczej lul
Możliwe że jak się uda to najlepiej byłoby połączyć kompa jednocześnie do STMa i AVRa, żeby
móc odrazu zaprogramować AVR, najlepiej chyba przez AVRdude bo open sours i nie trzeba za niego
płacić tak jak za jakieś zjebane narzędzia o microchipa skurwysyna
Da się wywołać jeden program z drugiego, nawet na łindołsie, jeszcze nie wiem jak ale się dowiem (na lynuxie wiem)

### Przeprowadzanie testów

No nie unikniemy tego że za każdym razem trzeba napisać program testujący na AVR chyba że
zwiększymy wartość naszego projektu z 200k do około 700k, znajdziemy zagubiony czas i chęć życia

(1) Najlepiej byłoby żeby zrobić jakiś mini parser pytong-like/cmake-like języka w którym byłoby tak powiedzmy
z 10 komend typu:
-EXPECT_PIN(pin_nr, HIGH/LOW)
-SET/CLR/TOGGLE_PIN(pin_nr)
-WAIT(ticks) <-- ważne że to mają być takty zegara a nie ms/us/... (można taktować AVR z zewn źródła to nie powinno być problemu)
-{...}
W ten sposób można by było pisać krótkie skrypty testujące i "kompilować" je na serię komend wysyłanych przez USART
(np. komenda WAIT() ma kod 0x03, wysyłamy 1 bajt jako instrukcję (do STM) i kolejny jako argumenty a sam
STM znałby tylko powiedzmy te komendy, na koniec transmisji wysyłalibyśmy specjalną komendę, która symbolizowałaby
koniec przekazu PC->STM, STM wykonałby te wszytkie polecenia i wysłałby tyle bajtów ile komend EXPECT_*, każdy bajt to byłaby kolejna
tego typu komenda i każdy z tych bajtów byłby albo 0x00 albo 0x01, co oznaczałoby że test przeszedł albo nie)

(2) Ponieważ byłoby to w hui skomplikowane (ale może gość pozwoliłby tego nie kończyć tylko zostawić jako open source dla
kolejnych nieszczęsnych studentów xDD) to jest jeszcze studenckie rozwiązanie, czyli wysyłać USARTem kod testu na sztywno
zaprogramowanego w STM, a potem STM wysyłałby kolejno wyniki (SIMPLE SZIT). W ten sposób zrobienie kolejneych
testów jest zepchnięte na gościa który programuje STM (hehehe) (trzeba ogarniać jakąś modułowość tego żeby potem
dało się w tym ogarnąć)

### Programik na STM

W przypadku (1), trzeba by zrobić jakiś bufor komend, które potem byłyby wywołane w odpowiedniej
kolejności. Byłoby to w hui modułowe i troszcząc się o przyszłych studentów, nikt nie musiałby dotykać
kodu na STM, chyba że chciałby dodać nową komendę hehe.

W przypadku (2) byłoby trochę bardziej skomplikowanie, ponieważ trzeba by pisać cały test na STM,
fajnie byłoby zrobić jakiś mini framework do tego, tak żeby większość programu było wspólne dla wszytkich testów (xD)
No i oczywiście trzeba ogarniać jakieś pierdoły typu jak będzie przebiegała komunikacja, jak taktować AVR itp.

OGÓLNIE:
Wersja (1) Trudna do napisania apka na kompa + średnio trudny do napisania program na STM (+ mini programy na avr)
Wersja (2) W miare łatwa ale tak nie do końca apka na kompa + w miarę trudny programik na STM, ale wsm też nie tak jakoś w hui trudny (+ avr)
