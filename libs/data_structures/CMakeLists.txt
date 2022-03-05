add_library(data_structures
        string_/string_.c
        string_/tasks/task1.h
        string_/tasks/task2.h
        string_/tasks/task3.h
        string_/tasks/task4.h
        string_/tasks/task5.h
        string_/tasks/task6.h)

target_link_libraries(data_structures algorithms)