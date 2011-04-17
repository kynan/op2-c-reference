include_directories(${OP2_SOURCE_DIR} ${OP2_SOURCE_DIR}/op2 ${OP2_INCLUDE_DIRECTORIES})
add_executable(laplace1d_seq EXCLUDE_FROM_ALL laplace.c)
target_link_libraries(laplace1d_seq op2 m)

#------------------------------------------------------------------------------
# Install

install(TARGETS laplace1d_seq DESTINATION ${OP2_EXAMPLES_DIR} OPTIONAL)
