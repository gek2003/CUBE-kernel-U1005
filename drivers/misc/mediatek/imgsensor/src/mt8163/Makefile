#
# Copyright (C) 2015 MediaTek Inc.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#

#
# Makefile for misc devices that really don't fit anywhere else.

define FILTER_PROJECT_DRV
ifeq ($(wildcard $(srctree)/drivers/misc/mediatek/mach/$(MTK_PLATFORM)/$(ARCH_MTK_PROJECT)/imgsensor/$(1)),)
platform_drv += $(1)
endif
endef

obj-y				+= kd_sensorlist.o
obj-y				+= camera_hw/

CONFIG_CUSTOM_KERNEL_IMGSENSOR := $(shell ls $(srctree)/drivers/misc/mediatek/imgsensor/src/mt8163/mid/)
$(info ****************MID_IMGSENSOR: $(CONFIG_CUSTOM_KERNEL_IMGSENSOR) ********************)
$(foreach drv,$(subst $\",,$(CONFIG_CUSTOM_KERNEL_IMGSENSOR)),$(eval $(call FILTER_PROJECT_DRV,$(drv))))
custom_kernel_imgsensor := $(addsuffix /, $(shell echo $(platform_drv)))
custom_kernel_imgsensor := $(addprefix mid/, $(shell echo $(custom_kernel_imgsensor)))
$(info custom_kernel_imgsensor: $(custom_kernel_imgsensor))
obj-y += $(custom_kernel_imgsensor)
$(info imgsensor drv by platform $(platform_drv))
