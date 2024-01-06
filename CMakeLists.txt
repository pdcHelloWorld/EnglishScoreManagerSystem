cmake_minimum_required(VERSION 3.27)
project(CProject C)

set(CMAKE_C_STANDARD 11)

add_executable(AnsQuestion AnsQuestion.c)
add_executable(CalScore CalScore.c)
add_executable(DelInfo DelInfo.c)
add_executable(QueryScore QueryScore.c)
add_executable(ShowScore ShowScore.c)
add_executable(SortScore SortScore.c)
add_executable(SumScore SumScore.c)
add_executable(InputQuestion InputQuestion.c)
add_executable(CProject main.c)