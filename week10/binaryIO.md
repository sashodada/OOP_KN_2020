# Binary IO
Двуичните файлове работят с байтове и за да ги използваме в своите приложения се нуждаем от начин да манипулираме данните си на ниво байт. В примера отдолу ще обясним как се случва това.

## Изход
Да вземем една променлива `x` от целочислен тип.
```c++
int x = 42;
```

Искаме да я запишем в двуичен файл `numbers.bin`. За целта първо трябва да отворим файла за писане.
```c++
std::ofstream numbersBin("numbers.bin", std::ios::binary | std::ios::trunc);
```

В хода на курсовете по УП и ООП сме говорили за размерите на различни типове данни досега. Нека приемем, че `int` е с размер 4 байта. Стандартно, `char` е 1 байт. При работа с двуични файлове още от езика **C** се работи с `char` масиви. Сигнатурата на функцията за писане във файл е следната:
```c++
numbersBin.write(<char *-compatible data>, <size of data to write>)
```

За да преобразуваме произволен тип данни към удобен такъв за работата на тази функция се налага да минем през следните стъпки:
1. да вземем адреса на променливата (ако е статична променлива, ако е масив или друг указател тази стъпка се пропуска)
```c++
&x;
```

2. да преобразуваме получения от първата стъпка указател в `char` указател
```c++
(char*)&x;
```

3. да определим размера на данните, които искаме да запишем (ако е единичен обект това може да се случи със `sizeof(<типа на променливата>)`; за масиви `sizeof` **НЕ работи!**)
4. да извикаме функцията с така определените аргументи
```c++
numbersBin.write((char *)&x, sizeof(int));
```

## Вход
При въвеждането на данни от двуичен файл процедурата е аналогична: дефинира се променлива, в която да се прочете информацията, трансформнира се до `char *` по горепосочения начин и се указва колко байта данни да се извлекат.
```c++
int x;
numbersBin.read((char *)&x, sizeof(int));
```
