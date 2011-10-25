include_directories(${OP2_SOURCE_DIR} ${OP2_SOURCE_DIR}/op2 ${OP2_INCLUDE_DIRECTORIES})
add_executable(jac2_seq EXCLUDE_FROM_ALL jac.c)
target_link_libraries(jac2_seq op2 m)

#------------------------------------------------------------------------------
# Install

install(TARGETS jac2_seq DESTINATION ${OP2_EXAMPLES_DIR} OPTIONAL)
