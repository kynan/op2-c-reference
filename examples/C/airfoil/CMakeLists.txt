include_directories(${OP2_SOURCE_DIR} ${OP2_SOURCE_DIR}/op2 ${OP2_INCLUDE_DIRECTORIES})
add_executable(airfoil_seq EXCLUDE_FROM_ALL airfoil.c)
target_link_libraries(airfoil_seq op2 m)

#------------------------------------------------------------------------------
# Install

install(TARGETS airfoil_seq DESTINATION ${OP2_EXAMPLES_DIR} OPTIONAL)
