include_directories(${OP2_SOURCE_DIR} ${OP2_SOURCE_DIR}/op2 ${OP2_INCLUDE_DIRECTORIES})
add_executable(jac2_seq jac.c)
target_link_libraries(jac2_seq op2 m)
ADD_CUSTOM_TARGET( jac2_example DEPENDS jac2_seq COMMENT "Build jac2 examples" )
