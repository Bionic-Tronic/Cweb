cmake_minimum_required(VERSION 3.20.0)
project(cweb)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
include_directories(
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/src
)
file(GLOB SRCS
	"${PROJECT_SOURCE_DIR}/include/*"
	"${PROJECT_SOURCE_DIR}/src/*"
)
set(SOURCES
    src/main.c
    src/cweb.c
    src/server.c
    src/http.c
    src/cdo.c
    src/files.c
    src/smtp.c
    src/api.c
    src/json.c
)
add_executable(cweb ${SRCS})
find_package(SQLite3 REQUIRED)
target_link_libraries(cweb ${SQLite3_LIBRARIES})
find_package(CURL REQUIRED)
target_link_libraries(cweb ${CURL_LIBRARIES})
find_package(OpenSSL REQUIRED)
target_link_libraries(cweb ${OPENSSL_LIBRARIES})