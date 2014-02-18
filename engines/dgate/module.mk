MODULE := engines/dgate

MODULE_OBJS := \
	detection.o \
	dgate.o

# This module can be built as a plugin
ifeq ($(ENABLE_DGATE), DYNAMIC_PLUGIN)
PLUGIN := 1
endif

# Include common rules
include $(srcdir)/rules.mk
