project(ytdl)
cmake_minimum_required(VERSION 3.7)
find_package(Boost REQUIRED filesystem date_time system)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/spdlog)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/json)

file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)
add_executable(ytdl ${SRC})



target_link_directories(ytdl PUBLIC ${Boost_LIBRARY_DIR})
target_link_libraries(ytdl
  PUBLIC ${Boost_LIBRARIES} pthread spdlog::spdlog)

target_include_directories(ytdl
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/spdlog/include
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/json/include
  ${Boost_INCLUDE_DIR})
