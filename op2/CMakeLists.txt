set(OP2_H op2.h)
install(FILES ${OP2_H} DESTINATION ${OP2_INCLUDE_DIR} COMPONENT Development)

#------------------------------------------------------------------------------
# OP2 source directories

set(OP2_DIRS
  common
  reference
  )

#------------------------------------------------------------------------------
# Install header files

foreach(DIR ${OP2_DIRS})
  file(GLOB _HEADERS ${DIR}/*.h)
  list(APPEND HEADERS ${_HEADERS})
  install(FILES ${_HEADERS} DESTINATION ${OP2_INCLUDE_DIR}/op2/${DIR} COMPONENT Development)

  file(GLOB _SOURCES ${DIR}/*.c ${DIR}/*.cpp)
  list(APPEND SOURCES ${_SOURCES})
endforeach()

#------------------------------------------------------------------------------
# Add include directories and libs of required packages

# PETSc
if (PETSC_FOUND)
  list(APPEND OP2_CXX_DEFINITIONS "-DHAS_PETSC")
  list(APPEND OP2_INCLUDE_DIRECTORIES ${PETSC_INCLUDES})
  list(APPEND OP2_TARGET_LINK_LIBRARIES ${PETSC_LIBRARIES})
endif()

#------------------------------------------------------------------------------
# Set compiler flags, include directories and library dependencies

# Add compiler include directories
include_directories(${OP2_SOURCE_DIR} ${OP2_INCLUDE_DIRECTORIES})

# Add CXX defintions
add_definitions(${OP2_CXX_DEFINITIONS})

# Define libraries
if (CUDA_FOUND)
  # CUDA library
  CUDA_ADD_LIBRARY(op2 ${OP2_H} ${HEADERS} ${SOURCES} ${CU_SOURCES})
  #set_target_properties(op2 PROPERTIES ${OP2_LIBRARY_PROPERTIES})
else()
  add_library(op2 ${OP2_H} ${HEADERS} ${SOURCES})
  #set_target_properties(op2 PROPERTIES ${OP2_LIBRARY_PROPERTIES})
endif()

# Link against target libraries
target_link_libraries(op2 ${OP2_TARGET_LINK_LIBRARIES})

#------------------------------------------------------------------------------
# Install

install(TARGETS op2
  RUNTIME DESTINATION ${OP2_LIB_DIR} COMPONENT RuntimeExecutables
  LIBRARY DESTINATION ${OP2_LIB_DIR} COMPONENT RuntimeLibraries
  ARCHIVE DESTINATION ${OP2_LIB_DIR} COMPONENT Development
  )
