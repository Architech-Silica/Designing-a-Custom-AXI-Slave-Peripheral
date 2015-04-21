void rc_servo_set_servo_position(int baseaddr, int servo_number, int position);
int rc_servo_get_servo_position(int baseaddr, int servo_number);
void rc_servo_enable_manual_mode(int baseaddr, int servo_number);
void rc_servo_disable_manual_mode(int baseaddr, int servo_number);
void rc_servo_set_servo_register(int baseaddr, int offset, int value);
int rc_servo_get_servo_register(int baseaddr, int offset);
void rc_servo_assert_manual_output(int baseaddr, int servo_number);
void rc_servo_deassert_manual_output(int baseaddr, int servo_number);
int rc_servo_get_low_endstop(int baseaddr, int servo_number);
int rc_servo_get_high_endstop(int baseaddr, int servo_number);
void rc_servo_set_low_endstop(int baseaddr, int servo_number, int value);
void rc_servo_set_high_endstop(int baseaddr, int servo_number, int value);

