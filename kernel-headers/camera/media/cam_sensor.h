/****************************************************************************
 ****************************************************************************
 ***
 ***   This header was automatically generated from a Linux kernel header
 ***   of the same name, to make information necessary for userspace to
 ***   call into the kernel available to libc.  It contains only constants,
 ***   structures, and macros generated from the original header, and thus,
 ***   contains no copyrightable information.
 ***
 ***   To edit the content of this header, modify the corresponding
 ***   source file (e.g. under external/kernel-headers/original/) then
 ***   run bionic/libc/kernel/tools/update_all.py
 ***
 ***   Any manual change here will be lost the next time this script will
 ***   be run. You've been warned!
 ***
 ****************************************************************************
 ****************************************************************************/
#ifndef __UAPI_CAM_SENSOR_H__
#define __UAPI_CAM_SENSOR_H__
#include <linux/types.h>
#include <linux/ioctl.h>
#include <camera/media/cam_defs.h>
#define CAM_SENSOR_PROBE_CMD (CAM_COMMON_OPCODE_MAX + 1)
#define CAM_FLASH_MAX_LED_TRIGGERS 2
#define MAX_OIS_NAME_SIZE 32
#define CAM_CSIPHY_SECURE_MODE_ENABLED 1
struct cam_sensor_query_cap {
  __u32 slot_info;
  __u32 secure_camera;
  __u32 pos_pitch;
  __u32 pos_roll;
  __u32 pos_yaw;
  __u32 actuator_slot_id;
  __u32 eeprom_slot_id;
  __u32 ois_slot_id;
  __u32 flash_slot_id;
  __u32 csiphy_slot_id;
} __attribute__((packed));
struct cam_csiphy_query_cap {
  __u32 slot_info;
  __u32 version;
  __u32 clk_lane;
  __u32 reserved;
} __attribute__((packed));
struct cam_actuator_query_cap {
  __u32 slot_info;
  __u32 reserved;
} __attribute__((packed));
struct cam_eeprom_query_cap_t {
  __u32 slot_info;
  __u16 eeprom_kernel_probe;
  __u16 is_multimodule_mode;
} __attribute__((packed));
struct cam_ois_query_cap_t {
  __u32 slot_info;
  __u16 reserved;
} __attribute__((packed));
struct cam_cmd_i2c_info {
  __u32 slave_addr;
  __u8 i2c_freq_mode;
  __u8 cmd_type;
  __u16 reserved;
} __attribute__((packed));
struct cam_ois_opcode {
  __u32 prog;
  __u32 coeff;
  __u32 pheripheral;
  __u32 memory;
} __attribute__((packed));
struct cam_cmd_ois_info {
  __u32 slave_addr;
  __u8 i2c_freq_mode;
  __u8 cmd_type;
  __u8 ois_fw_flag;
  __u8 is_ois_calib;
  char ois_name[MAX_OIS_NAME_SIZE];
  struct cam_ois_opcode opcode;
} __attribute__((packed));
struct cam_cmd_probe {
  __u8 data_type;
  __u8 addr_type;
  __u8 op_code;
  __u8 cmd_type;
  __u32 reg_addr;
  __u32 expected_data;
  __u32 data_mask;
  __u16 camera_id;
  __u16 reserved;
} __attribute__((packed));
struct cam_power_settings {
  __u16 power_seq_type;
  __u16 reserved;
  __u32 config_val_low;
  __u32 config_val_high;
} __attribute__((packed));
struct cam_cmd_power {
  __u32 count;
  __u8 reserved;
  __u8 cmd_type;
  __u16 more_reserved;
  struct cam_power_settings power_settings[1];
} __attribute__((packed));
struct i2c_rdwr_header {
  __u32 count;
  __u8 op_code;
  __u8 cmd_type;
  __u8 data_type;
  __u8 addr_type;
} __attribute__((packed));
struct i2c_random_wr_payload {
  __u32 reg_addr;
  __u32 reg_data;
} __attribute__((packed));
struct cam_cmd_i2c_random_wr {
  struct i2c_rdwr_header header;
  struct i2c_random_wr_payload random_wr_payload[1];
} __attribute__((packed));
struct cam_cmd_read {
  __u32 reg_data;
  __u32 reserved;
} __attribute__((packed));
struct cam_cmd_i2c_continuous_wr {
  struct i2c_rdwr_header header;
  __u32 reg_addr;
  struct cam_cmd_read data_read[1];
} __attribute__((packed));
struct cam_cmd_i2c_random_rd {
  struct i2c_rdwr_header header;
  struct cam_cmd_read data_read[1];
} __attribute__((packed));
struct cam_cmd_i2c_continuous_rd {
  struct i2c_rdwr_header header;
  __u32 reg_addr;
} __attribute__((packed));
struct cam_cmd_conditional_wait {
  __u8 data_type;
  __u8 addr_type;
  __u16 reserved;
  __u8 op_code;
  __u8 cmd_type;
  __u16 timeout;
  __u32 reg_addr;
  __u32 reg_data;
  __u32 data_mask;
} __attribute__((packed));
struct cam_cmd_unconditional_wait {
  __s16 delay;
  __s16 reserved;
  __u8 op_code;
  __u8 cmd_type;
  __u16 reserved1;
} __attribute__((packed));
struct cam_csiphy_info {
  __u16 reserved;
  __u16 lane_assign;
  __u16 mipi_flags;
  __u8 lane_cnt;
  __u8 secure_mode;
  __u64 settle_time;
  __u64 data_rate;
} __attribute__((packed));
struct cam_csiphy_acquire_dev_info {
  __u32 combo_mode;
  __u16 cphy_dphy_combo_mode;
  __u8 csiphy_3phase;
  __u8 reserve;
} __attribute__((packed));
struct cam_sensor_acquire_dev {
  __u32 session_handle;
  __u32 device_handle;
  __u32 handle_type;
  __u32 reserved;
  __u64 info_handle;
} __attribute__((packed));
struct cam_sensor_streamon_dev {
  __u32 session_handle;
  __u32 device_handle;
  __u32 handle_type;
  __u32 reserved;
  __u64 info_handle;
} __attribute__((packed));
struct cam_flash_init {
  __u32 flash_type;
  __u8 reserved;
  __u8 cmd_type;
  __u16 reserved1;
} __attribute__((packed));
struct cam_flash_set_rer {
  __u32 count;
  __u8 opcode;
  __u8 cmd_type;
  __u16 num_iteration;
  __u32 led_on_delay_ms;
  __u32 led_off_delay_ms;
  __u32 led_current_ma[CAM_FLASH_MAX_LED_TRIGGERS];
} __attribute__((packed));
struct cam_flash_set_on_off {
  __u32 count;
  __u8 opcode;
  __u8 cmd_type;
  __u16 reserved;
  __u32 led_current_ma[CAM_FLASH_MAX_LED_TRIGGERS];
  __u64 time_on_duration_ns;
} __attribute__((packed));
struct cam_flash_query_curr {
  __u16 reserved;
  __u8 opcode;
  __u8 cmd_type;
  __u32 query_current_ma;
} __attribute__((packed));
struct cam_flash_query_cap_info {
  __u32 slot_info;
  __u32 max_current_flash[CAM_FLASH_MAX_LED_TRIGGERS];
  __u32 max_duration_flash[CAM_FLASH_MAX_LED_TRIGGERS];
  __u32 max_current_torch[CAM_FLASH_MAX_LED_TRIGGERS];
  __u32 flash_type;
} __attribute__((packed));
#endif
