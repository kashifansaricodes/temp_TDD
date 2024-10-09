# Define the executable (shell-app)
add_executable(shell-app
  main.cpp  # The main source file for the executable
)

# Include directories for this target
target_include_directories(shell-app PUBLIC
  ${CMAKE_SOURCE_DIR}/include  # Include directory for header files
)

# Link the shell-app target with dependent libraries
target_link_libraries(shell-app PUBLIC
  PID_Control  # Link with the PID_Control library
)

# Specify any additional link options if needed
target_link_options(shell-app PUBLIC
  --static  # Linking statically
)
