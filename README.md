## Como compilar

### Dependências
- CMake 3.x+
- g++ ou clang++

### Build
```bash
mkdir build
cd build
cmake ..
make
```

Isso funciona porque o SFML já está incluído na pasta `libs/` do projeto, então não precisa instalar nada além do CMake e de um compilador C++.
