#!/bin/bash

for i in {0..14}; do
    echo "add_executable(image_send$i src/image_send$i.cpp)"
    echo "target_link_libraries(image_send$i \${catkin_LIBRARIES})"
    echo "add_dependencies(image_send$i \${\${PROJECT_NAME}_EXPORTED_TARGETS} \${catkin_EXPORTED_TARGETS})"
    echo ""
done