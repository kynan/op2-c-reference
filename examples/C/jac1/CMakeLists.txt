include_directories(${OP2_SOURCE_DIR} ${OP2_SOURCE_DIR}/op2 ${OP2_INCLUDE_DIRECTORIES})
add_executable(jac1_seq EXCLUDE_FROM_ALL jac.c)
target_link_libraries(jac1_seq op2 m)

#------------------------------------------------------------------------------
# Install

install(TARGETS jac1_seq DESTINATION ${OP2_EXAMPLES_DIR} OPTIONAL)
