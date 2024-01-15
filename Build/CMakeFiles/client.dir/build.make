# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/shivaram/.local/bin/cmake

# The command to remove a file.
RM = /home/shivaram/.local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shivaram/Code/Project/gRPC_server_client_for_image_processing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build

# Include any dependencies generated for this target.
include CMakeFiles/client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/client.dir/flags.make

CMakeFiles/client.dir/src/image_client.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/image_client.cpp.o: ../src/image_client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/client.dir/src/image_client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/image_client.cpp.o -c /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/src/image_client.cpp

CMakeFiles/client.dir/src/image_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/image_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/src/image_client.cpp > CMakeFiles/client.dir/src/image_client.cpp.i

CMakeFiles/client.dir/src/image_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/image_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/src/image_client.cpp -o CMakeFiles/client.dir/src/image_client.cpp.s

CMakeFiles/client.dir/src/image_helper.cpp.o: CMakeFiles/client.dir/flags.make
CMakeFiles/client.dir/src/image_helper.cpp.o: ../src/image_helper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/client.dir/src/image_helper.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/client.dir/src/image_helper.cpp.o -c /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/src/image_helper.cpp

CMakeFiles/client.dir/src/image_helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/client.dir/src/image_helper.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/src/image_helper.cpp > CMakeFiles/client.dir/src/image_helper.cpp.i

CMakeFiles/client.dir/src/image_helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/client.dir/src/image_helper.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/src/image_helper.cpp -o CMakeFiles/client.dir/src/image_helper.cpp.s

# Object files for target client
client_OBJECTS = \
"CMakeFiles/client.dir/src/image_client.cpp.o" \
"CMakeFiles/client.dir/src/image_helper.cpp.o"

# External object files for target client
client_EXTERNAL_OBJECTS =

client: CMakeFiles/client.dir/src/image_client.cpp.o
client: CMakeFiles/client.dir/src/image_helper.cpp.o
client: CMakeFiles/client.dir/build.make
client: librg_grpc_proto.a
client: /home/shivaram/.local/lib/libabsl_flags.a
client: /home/shivaram/.local/lib/libabsl_flags_parse.a
client: /home/shivaram/.local/lib/libprotobuf.a
client: /home/shivaram/.local/lib/libgrpc++_reflection.a
client: /home/shivaram/.local/lib/libgrpc++.a
client: /home/shivaram/.local/lib/libprotobuf.a
client: /usr/local/lib/libopencv_gapi.so.4.7.0
client: /usr/local/lib/libopencv_highgui.so.4.7.0
client: /usr/local/lib/libopencv_ml.so.4.7.0
client: /usr/local/lib/libopencv_objdetect.so.4.7.0
client: /usr/local/lib/libopencv_photo.so.4.7.0
client: /usr/local/lib/libopencv_stitching.so.4.7.0
client: /usr/local/lib/libopencv_video.so.4.7.0
client: /usr/local/lib/libopencv_videoio.so.4.7.0
client: /home/shivaram/.local/lib/libabsl_log_internal_check_op.a
client: /home/shivaram/.local/lib/libabsl_leak_check.a
client: /home/shivaram/.local/lib/libabsl_die_if_null.a
client: /home/shivaram/.local/lib/libabsl_log_internal_conditions.a
client: /home/shivaram/.local/lib/libabsl_log_internal_message.a
client: /home/shivaram/.local/lib/libabsl_log_internal_nullguard.a
client: /home/shivaram/.local/lib/libabsl_examine_stack.a
client: /home/shivaram/.local/lib/libabsl_log_internal_format.a
client: /home/shivaram/.local/lib/libabsl_log_internal_proto.a
client: /home/shivaram/.local/lib/libabsl_log_internal_log_sink_set.a
client: /home/shivaram/.local/lib/libabsl_log_sink.a
client: /home/shivaram/.local/lib/libabsl_log_entry.a
client: /home/shivaram/.local/lib/libabsl_log_initialize.a
client: /home/shivaram/.local/lib/libabsl_log_globals.a
client: /home/shivaram/.local/lib/libabsl_log_internal_globals.a
client: /home/shivaram/.local/lib/libutf8_validity.a
client: /home/shivaram/.local/lib/libgrpc.a
client: /home/shivaram/.local/lib/libabsl_statusor.a
client: /home/shivaram/.local/lib/libupb_collections_lib.a
client: /home/shivaram/.local/lib/libupb_json_lib.a
client: /home/shivaram/.local/lib/libupb_textformat_lib.a
client: /home/shivaram/.local/lib/libutf8_range_lib.a
client: /home/shivaram/.local/lib/libupb.a
client: /home/shivaram/.local/lib/libre2.a
client: /home/shivaram/.local/lib/libz.a
client: /home/shivaram/.local/lib/libcares.a
client: /home/shivaram/.local/lib/libgpr.a
client: /home/shivaram/.local/lib/libabsl_status.a
client: /home/shivaram/.local/lib/libabsl_strerror.a
client: /home/shivaram/.local/lib/libabsl_random_distributions.a
client: /home/shivaram/.local/lib/libabsl_random_seed_sequences.a
client: /home/shivaram/.local/lib/libabsl_random_internal_pool_urbg.a
client: /home/shivaram/.local/lib/libabsl_random_internal_randen.a
client: /home/shivaram/.local/lib/libabsl_random_internal_randen_hwaes.a
client: /home/shivaram/.local/lib/libabsl_random_internal_randen_hwaes_impl.a
client: /home/shivaram/.local/lib/libabsl_random_internal_randen_slow.a
client: /home/shivaram/.local/lib/libabsl_random_internal_platform.a
client: /home/shivaram/.local/lib/libabsl_random_internal_seed_material.a
client: /home/shivaram/.local/lib/libabsl_random_seed_gen_exception.a
client: /home/shivaram/.local/lib/libssl.a
client: /home/shivaram/.local/lib/libcrypto.a
client: /home/shivaram/.local/lib/libaddress_sorting.a
client: /usr/lib/x86_64-linux-gnu/libsystemd.so
client: /home/shivaram/.local/lib/libabsl_flags_usage.a
client: /home/shivaram/.local/lib/libabsl_flags_usage_internal.a
client: /home/shivaram/.local/lib/libabsl_flags.a
client: /home/shivaram/.local/lib/libabsl_flags_internal.a
client: /home/shivaram/.local/lib/libabsl_flags_marshalling.a
client: /home/shivaram/.local/lib/libabsl_flags_reflection.a
client: /home/shivaram/.local/lib/libabsl_flags_config.a
client: /home/shivaram/.local/lib/libabsl_flags_private_handle_accessor.a
client: /home/shivaram/.local/lib/libabsl_flags_commandlineflag.a
client: /home/shivaram/.local/lib/libabsl_flags_commandlineflag_internal.a
client: /home/shivaram/.local/lib/libabsl_flags_program_name.a
client: /home/shivaram/.local/lib/libabsl_cord.a
client: /home/shivaram/.local/lib/libabsl_cordz_info.a
client: /home/shivaram/.local/lib/libabsl_cord_internal.a
client: /home/shivaram/.local/lib/libabsl_cordz_functions.a
client: /home/shivaram/.local/lib/libabsl_cordz_handle.a
client: /home/shivaram/.local/lib/libabsl_crc_cord_state.a
client: /home/shivaram/.local/lib/libabsl_crc32c.a
client: /home/shivaram/.local/lib/libabsl_str_format_internal.a
client: /home/shivaram/.local/lib/libabsl_crc_internal.a
client: /home/shivaram/.local/lib/libabsl_crc_cpu_detect.a
client: /home/shivaram/.local/lib/libabsl_raw_hash_set.a
client: /home/shivaram/.local/lib/libabsl_hash.a
client: /home/shivaram/.local/lib/libabsl_bad_variant_access.a
client: /home/shivaram/.local/lib/libabsl_city.a
client: /home/shivaram/.local/lib/libabsl_low_level_hash.a
client: /home/shivaram/.local/lib/libabsl_bad_optional_access.a
client: /home/shivaram/.local/lib/libabsl_hashtablez_sampler.a
client: /home/shivaram/.local/lib/libabsl_exponential_biased.a
client: /home/shivaram/.local/lib/libabsl_synchronization.a
client: /home/shivaram/.local/lib/libabsl_graphcycles_internal.a
client: /home/shivaram/.local/lib/libabsl_kernel_timeout_internal.a
client: /home/shivaram/.local/lib/libabsl_time.a
client: /home/shivaram/.local/lib/libabsl_civil_time.a
client: /home/shivaram/.local/lib/libabsl_time_zone.a
client: /home/shivaram/.local/lib/libabsl_stacktrace.a
client: /home/shivaram/.local/lib/libabsl_symbolize.a
client: /home/shivaram/.local/lib/libabsl_strings.a
client: /home/shivaram/.local/lib/libabsl_string_view.a
client: /home/shivaram/.local/lib/libabsl_strings_internal.a
client: /home/shivaram/.local/lib/libabsl_int128.a
client: /home/shivaram/.local/lib/libabsl_throw_delegate.a
client: /home/shivaram/.local/lib/libabsl_malloc_internal.a
client: /home/shivaram/.local/lib/libabsl_debugging_internal.a
client: /home/shivaram/.local/lib/libabsl_demangle_internal.a
client: /home/shivaram/.local/lib/libabsl_base.a
client: /home/shivaram/.local/lib/libabsl_raw_logging_internal.a
client: /home/shivaram/.local/lib/libabsl_log_severity.a
client: /home/shivaram/.local/lib/libabsl_spinlock_wait.a
client: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
client: /usr/local/lib/libopencv_dnn.so.4.7.0
client: /usr/local/lib/libopencv_calib3d.so.4.7.0
client: /usr/local/lib/libopencv_features2d.so.4.7.0
client: /usr/local/lib/libopencv_flann.so.4.7.0
client: /usr/local/lib/libopencv_imgproc.so.4.7.0
client: /usr/local/lib/libopencv_core.so.4.7.0
client: CMakeFiles/client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/client.dir/build: client

.PHONY : CMakeFiles/client.dir/build

CMakeFiles/client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/client.dir/clean

CMakeFiles/client.dir/depend:
	cd /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shivaram/Code/Project/gRPC_server_client_for_image_processing /home/shivaram/Code/Project/gRPC_server_client_for_image_processing /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build /home/shivaram/Code/Project/gRPC_server_client_for_image_processing/Build/CMakeFiles/client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/client.dir/depend
