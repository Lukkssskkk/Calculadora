# Calculadora  
  Uma calculadora gráfica feita em C++ com FLTK, suportando números reais,  
  soma, subtração, multiplicação, radiciação e potenciação.

# Modo de uso  
  Coloque a parte inteira, depois a parte decimal, a operação desejada,  
  outro número e por fim o sinal de igual.

# Linux  
  cmake .  
  make  
  ./calculadora

# Windows  
  cmake . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake  
  cmake --build .  
  ./calculator.exe

# Dependências:  
  Linux:  
    -> FLTK (1.3.0 ou superior);  
    -> g++ ou clang com suporte ao C++17;  
    -> cmake;  

  Windows:  
    -> Windows 10 ou superior (64 bits recomendado);  
    -> vcpkg;  
    -> cmake;
