proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "XRCSERVO" "NUM_INSTANCES" "C_BASEADDR" "C_HIGHADDR" "DEVICE_ID" "NUMBER_OF_SERVOS" "MINIMUM_HIGH_PULSE_WIDTH_NS" "MAXIMUM_HIGH_PULSE_WIDTH_NS"
  xdefine_canonical_xpars $drv_handle "xparameters.h" "XRCSERVO" "NUM_INSTANCES" "C_BASEADDR" "C_HIGHADDR" "DEVICE_ID" "NUMBER_OF_SERVOS" "MINIMUM_HIGH_PULSE_WIDTH_NS" "MAXIMUM_HIGH_PULSE_WIDTH_NS"
}
