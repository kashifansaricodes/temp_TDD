# Define the PID_Control library
add_library(PID_Control
  PID_Control.cpp  # The source file for PID_Control implementation
)

# Include directories for the PID_Control library
target_include_directories(PID_Control PUBLIC
  ${CMAKE_SOURCE_DIR}/include  # Include directory for header files
)

# Include directories for the common library
target_link_libraries(PID_Control PUBLIC ${COMMON_LIBS})
target_link_options(PID_Control PUBLIC --static)