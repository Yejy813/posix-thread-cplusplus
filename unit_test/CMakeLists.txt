file(GLOB SRC_FILES ./*.cpp)
file(GLOB HEADER_FILES ./*.h)

#  将给定目录添加到编译器用于搜索包含文件的目录中。相对路径被解释为相对于当前源目录。
include_directories(${CMAKE_SOURCE_DIR}/src)

if(ENABLE_TEST)
    include_directories(
        ${CMAKE_SOURCE_DIR}/3rdlib/googletest/googlemock/include
        ${CMAKE_SOURCE_DIR}/3rdlib/googletest/googletest/include
        )
endif()

add_executable(posix_thread_test.exx 
            ${SRC_FILES}
            )

target_link_libraries(posix_thread_test.exx 
            gtest
            posixthread   
)

target_install(posix_thread_test.exx)