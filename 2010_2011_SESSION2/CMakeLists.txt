cmake_minimum_required(VERSION 3.0)

# Notre projet est étiqueté hello
project(exec1)

# Crée des variables avec les fichiers à compiler
set(SRCS1
    exo1.c
    )

set(SRCS2
    exo2.c
    )

set(SRCS3
    exo3.c
    )

set(SRCS4
    exo4.c
    )
set(SRCS5
    exo5.c
    )
  
set(HEADERS
    link.h
    )

# On indique que l'on veut un exécutable "hello" compilé à partir des fichiers décrits par les variables SRCS et HEADERS
add_executable(exec1 ${SRCS1} ${HEADERS})
add_executable(exec2 ${SRCS2} ${HEADERS})
add_executable(exec3 ${SRCS3} ${HEADERS})
add_executable(exec4 ${SRCS4} ${HEADERS})
add_executable(exec5 ${SRCS5} ${HEADERS})
