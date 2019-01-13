cmake_minimum_required(VERSION 2.8)

add_definitions(-std=c++11)

project(thread_pool C CXX)

# add_all_subdirectories()
# Add all subdirectories that exist CMakeLists.txt
include(CMakeParseArguments)
function(add_all_subdirectories)
    cmake_parse_arguments(SUBDIR "" "" "EXCLUDE" ${ARGN})
    file(GLOB ALL_FILES *)
    
    foreach(subdir ${ALL_FILES})
        if((IS_DIRECTORY ${subdir})
            AND (EXISTS ${subdir}/CMakeLists.txt))
            file(RELATIVE_PATH relPath ${CMAKE_CURRENT_SOURCE_DIR} ${subdir})
            if(SUBDIR_EXCLUDE)
                list(FIND SUBDIR_EXCLUDE ${relPath} _index)
                if (_index EQUAL -1)
                    add_subdirectory(${subdir})
                elseif(CMAKE_DEBUG)
                    message("Exclude [${relPath}] when add_all_subdirectories")
                endif()
            else()
                add_subdirectory(${subdir})
            endif()
        endif()
    endforeach()
endfunction()

# 条件编译参数
option(ENABLE_TEST "编译测试代码" OFF)

# 设置安装路径
set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/output")
message("Install prefix: ${CMAKE_INSTALL_PREFIX}")

#project用的库文件安装函数
function(target_install OBJECTS)
    install(TARGETS ${OBJECTS}
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )
endfunction()

add_all_subdirectories()