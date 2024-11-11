# lab
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=alert_status)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=bugs)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=code_smells)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=Anton-Euro_labs&metric=duplicated_lines_density)](https://sonarcloud.io/summary/new_code?id=Anton-Euro_labs)
### Реализовано в лабораторной:
- графический интерфейс
- инициализация всех локальных файлов через директорию
- инициализация класса файла через локальный файл
- инициализация класса файла через консоль
- вывод в консоль всех добавленых файлов
- очистка списка всех файлов
- сортировка файлов по их размеру
- множественное наследование классов
- виртуальные функции и абстрактные классы
- класс исключений
- экспорт в json
- класс контейнеров

### Структура проекта 
`item.cpp` - реализация класса хранящий данные о файле<br>
`itemlist.cpp` - реализация класса храняший список файлов<br>
`main.cpp` - главный файл<br>
`file.cpp` - класс с релизацией item в виде файла<br>
`dir.cpp` - класс с релизацией item в виде директории<br>
`item.h`, `itemlist.h`, `file.h`, `dir.h` - хедер файлы<br>
`container.h` - файл реализации контейнера

### Сборка
```bash
cmake --build .
```

### Ссылка на Sonar - [клац](https://sonarcloud.io/project/overview?id=Anton-Euro_labs)
