## LED kostka 8×8×8

Maturitní práce, SPŠ na Proseku, obor Elektrotechnika, 2024.
512 LED diod, vlastní deska plošného spoje navržená v KiCadu,
ovládání mobilní aplikací MIT app inventor přes Bluetooth.

![LED kostka v provozu](docs/cube-dark.jpg)

**▶ [Video ukázka](https://youtu.be/GqQKeZAHj2E)**

---

## Co to umí

- 29 zobrazovacích funkcí — animace deště, 3D matrix, rotující krychle, padající kapky
- zobrazení času a data (RTC modul), teploty a vlhkosti (čidlo DHT)
- výpis textu zadaného v aplikaci — psaním nebo hlasem
- režim náhodných animací
- signalizační LED stavu spárování

## Technické řešení

| | |
| --- | --- |
| Řídicí jednotka | Arduino Mega 2560 |
| Zobrazovač | 512× červená LED 5 mm, matice 8×8×8 |
| Řízení sloupců | 8× posuvný registr SN74HC595 (64 sloupců, 3 datové piny) |
| Řízení vrstev | 8 digitálních pinů přímo z Arduina |
| Multiplex | po vrstvách, střída 1/8 |
| Komunikace | UART → Bluetooth modul HC-05 |
| Senzory | DHT (teplota, vlhkost), RTC modul reálného času |
| Napájení a data | konektor USB-B (VCC, GND, RX, TX), pojistka 400 mA |
| Deska | dvouvrstvá, návrh v KiCadu |
| Konstrukce | dřevěná skříň, kryt z plexiskla, krytí IP20 |
| Rozměry | 260 × 260 × 380 mm |

## Proč Arduino Mega

Vybíral jsem mezi Raspberry Pi Zero, ESP32 a Arduinem Mega podle čtyř
kritérií: počet pinů, velikost paměti, programovací jazyk a cena.
Raspberry Zero mělo nejvíc paměti i integrovaný Bluetooth, ale
znamenalo by naučit se Python v době, kdy jsem potřeboval hlavně dodat
funkční zařízení. ESP32 vypadalo dobře, ale tehdy jsem ho vyřadil kvůli
počtu pinů — dnes vím, že se u něj piny dají přemapovat, takže to
rozhodnutí stálo na mojí neznalosti. Arduino Mega nabídlo 54 pinů
a dostatečnou paměť za cenu externího Bluetooth modulu.

## Jak funguje adresování

Matice je rozdělená na 64 sloupců a 8 vrstev. Rozsvícení konkrétní
diody znamená nastavit její sloupec a její vrstvu — funguje to jako
souřadnice. Posuvné registry umožnily ovládat 64 sloupců pouhými
24 datovými piny.... 8 x (data, latch, clock) místo 64.

## Co bych dnes udělal jinak

Buzení vrstev Osm vrstev jsem spínal přímo digitálními piny
Arduina. Při rozsvícené vrstvě tak jedním pinem teče proud všech
64 diod, zatímco pin ATmega2560 má doporučený proud 20 mA a absolutní
maximum 40 mA. Pin si proud omezil vlastní výstupní impedancí — proto
diody svítily zhruba na polovinu jasu a celkový odběr vyšel kolem
170 mA. Zařízení fungovalo spíš navzdory
návrhu než díky němu.

Správné řešení: MOSFETy na spínání vrstev,
případně konstantně proudový budič typu TLC5940, aby proud určoval
návrh a ne parametry čipu.

Mechanika. Vodiče mezi deskou a LED konstrukcí jsem navrhl příliš
krátké, takže se při manipulaci uvolňovaly z konektorů a občas
nesvítil celý sloupec. Delší vodiče a zajištěné konektory.

Software. Původně jsem měl přes 7000 řádků v jediném souboru.
Rozdělení do hlavičkových souborů — jedna funkce na soubor a společný
`variables.h` — byla nejlepší změna v celém projektu. Dnes bych
od začátku napsal framework pro definici animací, aby se nová funkce
dala popsat jako poloha diod v čase, ne jako vlastní logika.
Software má obrovské množství možností, ale omezuje mě paměť, 
proto bych přidal SD karta modul nebo jinou externí paměť, třeba 
EEPROM paměť AT24C256. Potom by se na kostce dala naprogramovat jednoduchá 3D hra,
třeba 3D tetris nebo 3D snake.


## Plán do budoucna

Rozšířit projekt na LED kostku 32x32x32.


## Obsah repozitáře

```
hardware/    schéma, layout, Gerbery (KiCad)
firmware/    .ino a hlavičkové soubory
app/         aplikace (MIT App Inventor)
docs/        fotky, text maturitní práce
```

- [Schéma v PDF](hardware/schematic.pdf)
- [Text maturitní práce](docs/led-kostka-prace.pdf)



Ivan Hvězda · [free.hvezda.lance@gmail.com]

