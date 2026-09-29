add_executable(hello hello.cpp)
target_link_libraries(hello PRIVATE project_warnings)

add_executable(calculator calculator.cpp)
target_link_libraries(calculator PRIVATE project_warnings)
