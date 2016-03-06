cmake_minimum_required(VERSION 3.3)
project(BadBlood)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES LinkedList/Node.h LinkedList/LinkedList.cpp LinkedList/LinkedList.h LinkedList/LinkedListExp.cpp
        LinkedList/LinkedListExp.h Makhluk/Makhluk.h Makhluk/Makhluk.cpp Makhluk/Hewan/Hewan.h Makhluk/Hewan/Hewan.cpp
        Makhluk/Hewan/Herbivore.h Makhluk/Hewan/Herbivore.cpp Makhluk/Hewan/Carnivore.h Makhluk/Hewan/Carnivore.cpp
        Makhluk/Hewan/Omnivore.h Makhluk/Hewan/Omnivore.cpp Makhluk/Bakteri/Bakteri.h Makhluk/Bakteri/Bakteri.cpp
        Makhluk/Manusia/Manusia.h Makhluk/Manusia/Manusia.cpp Makhluk/Manusia/Female.h Makhluk/Manusia/Female.cpp
        Makhluk/Manusia/Men.h Makhluk/Manusia/Men.cpp Makhluk/Tumbuhan/Tumbuhan.h Makhluk/Tumbuhan/Tumbuhan.cpp
        Makhluk/Tumbuhan/Beracun.h Makhluk/Tumbuhan/Beracun.cpp Makhluk/Tumbuhan/NonBeracun.h Makhluk/Tumbuhan/NonBeracun.cpp
        Matriks/Matriks.h Matriks/Matriks.cpp Main.cpp)
add_executable(BadBlood ${SOURCE_FILES})