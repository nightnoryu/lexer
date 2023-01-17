add_executable(lexer-test
               Lexer.test.cpp
               ../src/Token.h
               ../src/Lexer.cpp
               ../src/Lexer.h
               ../src/TokensPrinter.cpp
               ../src/TokensPrinter.h
               ../src/NumberParser.cpp
               ../src/NumberParser.h)

target_link_libraries(lexer-test PUBLIC catch2)
add_test(NAME lexer-test COMMAND lexer-test)
