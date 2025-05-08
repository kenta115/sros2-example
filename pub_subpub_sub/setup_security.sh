#!/bin/bash

WORKSPACE_DIR=/workspace
PACKAGE_DIR=${WORKSPACE_DIR}/pub_subpub_sub

source ${PACKAGE_DIR}/install/local_setup.bash

export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp

export ROS_SECURITY_KEYSTORE=${PACKAGE_DIR}/keystore
export ROS_SECURITY_ENABLE=true
export ROS_SECURITY_STRATEGY=Enforce