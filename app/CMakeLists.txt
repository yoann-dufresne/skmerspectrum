add_executable(${PROJECT_NAME} main.cpp)
#target_compile_definitions(${PROJECT_NAME} PRIVATE DMAX_C=${MAX_C})
target_link_libraries(${PROJECT_NAME} PRIVATE build_type_flags headers)

#target_link_libraries(${PROJECT_NAME} PRIVATE pthread)