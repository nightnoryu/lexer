add_executable(lexer-test
               Lexer.test.cpp)

target_link_libraries(lexer-test PUBLIC catch2)
add_test(NAME lexer-test COMMAND lexer-test)
