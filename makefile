PROJ_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
BUILD_DIR := $(PROJ_DIR)/build/
SRC_DIR := $(PROJ_DIR)/src

