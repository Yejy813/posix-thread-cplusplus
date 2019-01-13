file(GLOB SRC_FILES ./*.cpp)
file(GLOB HEADER_FILES ./*.h)

add_library(posixthread 
            ${SRC_FILES}
            ${HEADER_FILES}
            )

target_link_libraries(posixthread pthread rt)

target_install(posixthread)

install(FILES ${HEADER_FILES} DESTINATION include/posixthread)