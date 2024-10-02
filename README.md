# lab
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=bugs)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=duplicated_lines_density)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
### Реализовано в лабораторной:
- инициализация всех локальных файлов через директорию
- инициализация класса файла через локальный файл
- инициализация класса файла через консоль
- вывод в консоль всех добавленых файлов
- очистка списка всех файлов
- вывод размера файла через friend функцию
- сортировка файлов по их размеру

### Структура проекта 
`item.cpp` - реализация класса хранящий данные о файле<br>
`itemlist.cpp` - реализация класса храняший список файлов<br>
`main.cpp` - главный файл<br>
`size_to_print.cpp` - файл реализующий дружественную функцию (функция которая переводит размер файла в читабелный для человека вид)<br>
`item.h`, `itemlist.h`, `friend.h` - хедер файлы

### Сборка
```bash
g++ main.cpp item.cpp itemlist.cpp -o main
```

### Ссылка на Sonar - [клац](https://sonarcloud.io/project/overview?id=Anton-Euro_labs)
