## Como compilar

### Dependências
- CMake 3.x+
- g++ ou clang++

### Build
```bash
mkdir build && cd build
cmake .. -DSFML_DIR="../libs/SFML-2.5/lib/cmake/SFML" -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
```

Isso funciona porque o SFML já está incluído na pasta `libs/` do projeto, então não precisa instalar nada além do CMake e de um compilador C++.
