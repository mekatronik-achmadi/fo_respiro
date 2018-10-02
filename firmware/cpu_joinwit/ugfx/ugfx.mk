GFXINC	+= ./ugfx/
GFXSRC	+=
GFXDEFS += -DGFX_USE_CHIBIOS=TRUE

include $(GFXLIB)/drivers/ginput/touch/ADS7843/driver.mk

