aghyaddeeb@Aghyads-MacBook-Pro translation % get_idf
Setting IDF_PATH to '/Users/aghyaddeeb/esp/esp-idf'
Detecting the Python interpreter
Checking "python" ...
/Users/aghyaddeeb/esp/esp-idf/tools/detect_python.sh:16: command not found: python
Checking "python3" ...
Python 3.10.0
"python3" has been detected
Adding ESP-IDF tools to PATH...
Using Python interpreter in /Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python
Checking if Python packages are up to date...
/Users/aghyaddeeb/esp/esp-idf/tools/check_python_dependencies.py:12: DeprecationWarning: pkg_resources is deprecated as an API. See https://setuptools.pypa.io/en/latest/pkg_resources.html
  import pkg_resources
Python requirements from /Users/aghyaddeeb/esp/esp-idf/requirements.txt are satisfied.
Updated PATH variable:
  /Users/aghyaddeeb/esp/esp-idf/components/esptool_py/esptool:/Users/aghyaddeeb/esp/esp-idf/components/espcoredump:/Users/aghyaddeeb/esp/esp-idf/components/partition_table:/Users/aghyaddeeb/esp/esp-idf/components/app_update:/Users/aghyaddeeb/.espressif/tools/xtensa-esp-elf-gdb/11.2_20220823/xtensa-esp-elf-gdb/bin:/Users/aghyaddeeb/.espressif/tools/xtensa-esp32-elf/esp-2021r2-patch5-8.4.0/xtensa-esp32-elf/bin:/Users/aghyaddeeb/.espressif/tools/esp32ulp-elf/2.35_20220830/esp32ulp-elf/bin:/Users/aghyaddeeb/.espressif/tools/openocd-esp32/v0.11.0-esp32-20221026/openocd-esp32/bin:/Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin:/Users/aghyaddeeb/esp/esp-idf/tools:/Users/aghyaddeeb/.opam/4.12.0/bin:/opt/local/bin:/opt/local/sbin:/Library/Frameworks/Python.framework/Versions/3.10/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/MacGPG2/bin:/opt/X11/bin:~/.dotnet/tools:/Library/Apple/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/Users/aghyaddeeb/micromamba/condabin:/Users/aghyaddeeb/.opam/4.12.0/bin:/opt/local/bin:/opt/local/sbin:/Library/Frameworks/Python.framework/Versions/3.10/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/Users/aghyaddeeb/.rvm/bin:/Users/aghyaddeeb/.rvm/bin:/Users/aghyaddeeb/.rvm/bin
Done! You can now compile ESP-IDF projects.
Go to the project directory and run:

  idf.py build

/Users/aghyaddeeb/esp/esp-idf/tools/check_python_dependencies.py:12: DeprecationWarning: pkg_resources is deprecated as an API. See https://setuptools.pypa.io/en/latest/pkg_resources.html
  import pkg_resources
aghyaddeeb@Aghyads-MacBook-Pro translation % idf.py -p /dev/cu.usbserial-01D41078 flash monitor
/Users/aghyaddeeb/esp/esp-idf/tools/check_python_dependencies.py:12: DeprecationWarning: pkg_resources is deprecated as an API. See https://setuptools.pypa.io/en/latest/pkg_resources.html
  import pkg_resources
Executing action: flash
Running ninja in directory /Users/aghyaddeeb/esp/translation/build
Executing "ninja flash"...
[1/5] cd /Users/aghyaddeeb/es...slation/build/hello_world.bin
hello_world.bin binary size 0x12e5e0 bytes. Smallest app partition is 0x180000 bytes. 0x51a20 bytes (21%) free.
[2/5] Performing build step for 'bootloader'
[1/1] cd /Users/aghyaddeeb/esp/translation/build/bootloader/esp-idf/esptool_py && /Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python /Users/aghyaddeeb/esp/esp-idf/components/partition_table/check_sizes.py --offset 0x8000 bootloader 0x1000 /Users/aghyaddeeb/esp/translation/build/bootloader/bootloader.bin
Bootloader binary size 0x63b0 bytes. 0xc50 bytes (11%) free.
[4/5] cd /Users/aghyaddeeb/es...tool_py/run_serial_tool.cmake
esptool.py esp32 -p /dev/cu.usbserial-01D41078 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 40m --flash_size 2MB 0x1000 bootloader/bootloader.bin 0x10000 hello_world.bin 0x8000 partition_table/partition-table.bin
esptool.py v3.3.2
Serial port /dev/cu.usbserial-01D41078
Connecting....
Chip is ESP32-D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: 24:62:ab:b0:30:f8
Uploading stub...
Running stub...
Stub running...
Changing baud rate to 460800
Changed.
Configuring flash size...
Flash will be erased from 0x00001000 to 0x00007fff...
Flash will be erased from 0x00010000 to 0x0013efff...
Flash will be erased from 0x00008000 to 0x00008fff...
Compressed 25520 bytes to 15996...
Writing at 0x00001000... (100 %)
Wrote 25520 bytes (15996 compressed) at 0x00001000 in 0.8 seconds (effective 266.6 kbit/s)...
Hash of data verified.
Compressed 1238496 bytes to 659058...
Writing at 0x00010000... (2 %)
Writing at 0x0001c5b9... (4 %)
Writing at 0x0002ae0a... (7 %)
Writing at 0x00037e70... (9 %)
Writing at 0x00046ce2... (12 %)
Writing at 0x000551b3... (14 %)
Writing at 0x0005af6e... (17 %)
Writing at 0x00061012... (19 %)
Writing at 0x00066b94... (21 %)
Writing at 0x0006c344... (24 %)
Writing at 0x000725ac... (26 %)
Writing at 0x000785fb... (29 %)
Writing at 0x0007e085... (31 %)
Writing at 0x000843d1... (34 %)
Writing at 0x0008a34c... (36 %)
Writing at 0x00090294... (39 %)
Writing at 0x00095e68... (41 %)
Writing at 0x0009ba12... (43 %)
Writing at 0x000a17a1... (46 %)
Writing at 0x000a742c... (48 %)
Writing at 0x000ad0c1... (51 %)
Writing at 0x000b2d83... (53 %)
Writing at 0x000b8a64... (56 %)
Writing at 0x000be98f... (58 %)
Writing at 0x000c4c56... (60 %)
Writing at 0x000caee9... (63 %)
Writing at 0x000d0d0a... (65 %)
Writing at 0x000d66ce... (68 %)
Writing at 0x000dc250... (70 %)
Writing at 0x000e3568... (73 %)
Writing at 0x000eb000... (75 %)
Writing at 0x000f36fb... (78 %)
Writing at 0x000f950c... (80 %)
Writing at 0x0010229d... (82 %)
Writing at 0x001086c1... (85 %)
Writing at 0x0011103b... (87 %)
Writing at 0x0012637f... (90 %)
Writing at 0x0012ba1f... (92 %)
Writing at 0x001316e0... (95 %)
Writing at 0x00136eeb... (97 %)
Writing at 0x0013ce0e... (100 %)
Wrote 1238496 bytes (659058 compressed) at 0x00010000 in 16.3 seconds (effective 606.4 kbit/s)...
Hash of data verified.
Compressed 3072 bytes to 105...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (105 compressed) at 0x00008000 in 0.1 seconds (effective 361.9 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
Executing action: monitor
Running idf_monitor in directory /Users/aghyaddeeb/esp/translation
Executing "/Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python /Users/aghyaddeeb/esp/esp-idf/tools/idf_monitor.py -p /dev/cu.usbserial-01D41078 -b 115200 --toolchain-prefix xtensa-esp32-elf- --target esp32 --revision 0 /Users/aghyaddeeb/esp/translation/build/hello_world.elf -m '/Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python' '/Users/aghyaddeeb/esp/esp-idf/tools/idf.py' '-p' '/dev/cu.usbserial-01D41078'"...
--- idf_monitor on /dev/cu.usbserial-01D41078 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ets Jun  8 2016 00:22:57

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:6664
load:0x40078000,len:14944
load:0x40080400,len:3816
0x40080400: _init at ??:?

entry 0x40080698
I (27) boot: ESP-IDF v4.4.4 2nd stage bootloader
I (27) boot: compile time 10:47:33
I (27) boot: chip revision: v1.0
I (30) boot_comm: chip revision: 1, min. bootloader chip revision: 0
I (37) boot.esp32: SPI Speed      : 40MHz
I (41) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (59) boot: ## Label            Usage          Type ST Offset   Length
I (67) boot:  0 nvs              WiFi data        01 02 00009000 00005000
I (74) boot:  1 phy_init         RF data          01 01 0000e000 00002000
I (82) boot:  2 factory          factory app      00 00 00010000 00180000
I (89) boot: End of partition table
I (93) boot_comm: chip revision: 1, min. application chip revision: 0
I (100) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=3adf4h (241140) map
I (196) esp_image: segment 1: paddr=0004ae1c vaddr=3ffbdb60 size=051fch ( 20988) load
I (205) esp_image: segment 2: paddr=00050020 vaddr=400d0020 size=c5800h (808960) map
I (498) esp_image: segment 3: paddr=00115828 vaddr=3ffc2d5c size=0f924h ( 63780) load
I (523) esp_image: segment 4: paddr=00125154 vaddr=40080000 size=1945ch (103516) load
I (582) boot: Loaded app from partition at offset 0x10000
I (582) boot: Disabling RNG early entropy source...
I (594) cpu_start: Pro cpu up.
I (594) cpu_start: Starting app cpu, entry point is 0x40081404
0x40081404: call_start_cpu1 at /Users/aghyaddeeb/esp/esp-idf/components/esp_system/port/cpu_start.c:148

I (0) cpu_start: App cpu up.
I (610) cpu_start: Pro cpu start user code
I (610) cpu_start: cpu freq: 160000000
I (610) cpu_start: Application information:
I (615) cpu_start: Project name:     hello_world
I (620) cpu_start: App version:      04fba14-dirty
I (626) cpu_start: Compile time:     Jul  9 2023 13:31:58
I (632) cpu_start: ELF file SHA256:  d673c1daf3f0f9da...
I (638) cpu_start: ESP-IDF:          v4.4.4
I (643) heap_init: Initializing. RAM available for dynamic allocation:
I (650) heap_init: At 3FFAFF10 len 000000F0 (0 KiB): DRAM
I (656) heap_init: At 3FFB6388 len 00001C78 (7 KiB): DRAM
I (662) heap_init: At 3FFB9A20 len 00004108 (16 KiB): DRAM
I (668) heap_init: At 3FFDB9A0 len 00004660 (17 KiB): DRAM
I (674) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (681) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (687) heap_init: At 4009945C len 00006BA4 (26 KiB): IRAM
I (695) spi_flash: detected chip: generic
I (698) spi_flash: flash io: dio
W (702) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (720) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (796) BTDM_INIT: BT controller compile version [8020d24]
I (798) system_api: Base MAC address is not set
I (798) system_api: read default base MAC address from EFUSE
I (806) phy_init: phy_version 4670,719f9f6,Feb 18 2021,17:07:07
BT available: 22

Inner while: 9

press release: 12

BT available: 2

Inner while: 1

press release: 1

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 5

press release: 9

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 60

Inner while: 1

press release: 65

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 4

press release: 9

BT available: 14

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 118

Inner while: 0

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 45

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 116

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 45

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0


Done
aghyaddeeb@Aghyads-MacBook-Pro translation % idf.py -p /dev/cu.usbserial-01D41078 flash monitor
/Users/aghyaddeeb/esp/esp-idf/tools/check_python_dependencies.py:12: DeprecationWarning: pkg_resources is deprecated as an API. See https://setuptools.pypa.io/en/latest/pkg_resources.html
  import pkg_resources
Executing action: flash
Running ninja in directory /Users/aghyaddeeb/esp/translation/build
Executing "ninja flash"...
[1/5] cd /Users/aghyaddeeb/es...slation/build/hello_world.bin
hello_world.bin binary size 0x12e5e0 bytes. Smallest app partition is 0x180000 bytes. 0x51a20 bytes (21%) free.
[2/5] Performing build step for 'bootloader'
[1/1] cd /Users/aghyaddeeb/esp/translation/build/bootloader/esp-idf/esptool_py && /Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python /Users/aghyaddeeb/esp/esp-idf/components/partition_table/check_sizes.py --offset 0x8000 bootloader 0x1000 /Users/aghyaddeeb/esp/translation/build/bootloader/bootloader.bin
Bootloader binary size 0x63b0 bytes. 0xc50 bytes (11%) free.
[4/5] cd /Users/aghyaddeeb/es...tool_py/run_serial_tool.cmake
esptool.py esp32 -p /dev/cu.usbserial-01D41078 -b 460800 --before=default_reset --after=hard_reset write_flash --flash_mode dio --flash_freq 40m --flash_size 2MB 0x1000 bootloader/bootloader.bin 0x10000 hello_world.bin 0x8000 partition_table/partition-table.bin
esptool.py v3.3.2
Serial port /dev/cu.usbserial-01D41078
Connecting......
Chip is ESP32-D0WDQ6 (revision 1)
Features: WiFi, BT, Dual Core, 240MHz, VRef calibration in efuse, Coding Scheme None
Crystal is 40MHz
MAC: 24:62:ab:b0:30:f8
Uploading stub...
Running stub...
Stub running...
Changing baud rate to 460800
Changed.
Configuring flash size...
Flash will be erased from 0x00001000 to 0x00007fff...
Flash will be erased from 0x00010000 to 0x0013efff...
Flash will be erased from 0x00008000 to 0x00008fff...
Compressed 25520 bytes to 15996...
Writing at 0x00001000... (100 %)
Wrote 25520 bytes (15996 compressed) at 0x00001000 in 0.8 seconds (effective 264.6 kbit/s)...
Hash of data verified.
Compressed 1238496 bytes to 659058...
Writing at 0x00010000... (2 %)
Writing at 0x0001c5b9... (4 %)
Writing at 0x0002ae0a... (7 %)
Writing at 0x00037e70... (9 %)
Writing at 0x00046ce2... (12 %)
Writing at 0x000551b3... (14 %)
Writing at 0x0005af6e... (17 %)
Writing at 0x00061012... (19 %)
Writing at 0x00066b94... (21 %)
Writing at 0x0006c344... (24 %)
Writing at 0x000725ac... (26 %)
Writing at 0x000785fb... (29 %)
Writing at 0x0007e085... (31 %)
Writing at 0x000843d1... (34 %)
Writing at 0x0008a34c... (36 %)
Writing at 0x00090294... (39 %)
Writing at 0x00095e68... (41 %)
Writing at 0x0009ba12... (43 %)
Writing at 0x000a17a1... (46 %)
Writing at 0x000a742c... (48 %)
Writing at 0x000ad0c1... (51 %)
Writing at 0x000b2d83... (53 %)
Writing at 0x000b8a64... (56 %)
Writing at 0x000be98f... (58 %)
Writing at 0x000c4c56... (60 %)
Writing at 0x000caee9... (63 %)
Writing at 0x000d0d0a... (65 %)
Writing at 0x000d66ce... (68 %)
Writing at 0x000dc250... (70 %)
Writing at 0x000e3568... (73 %)
Writing at 0x000eb000... (75 %)
Writing at 0x000f36fb... (78 %)
Writing at 0x000f950c... (80 %)
Writing at 0x0010229d... (82 %)
Writing at 0x001086c1... (85 %)
Writing at 0x0011103b... (87 %)
Writing at 0x0012637f... (90 %)
Writing at 0x0012ba1f... (92 %)
Writing at 0x001316e0... (95 %)
Writing at 0x00136eeb... (97 %)
Writing at 0x0013ce0e... (100 %)
Wrote 1238496 bytes (659058 compressed) at 0x00010000 in 16.4 seconds (effective 604.6 kbit/s)...
Hash of data verified.
Compressed 3072 bytes to 105...
Writing at 0x00008000... (100 %)
Wrote 3072 bytes (105 compressed) at 0x00008000 in 0.1 seconds (effective 352.5 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
Executing action: monitor
Running idf_monitor in directory /Users/aghyaddeeb/esp/translation
Executing "/Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python /Users/aghyaddeeb/esp/esp-idf/tools/idf_monitor.py -p /dev/cu.usbserial-01D41078 -b 115200 --toolchain-prefix xtensa-esp32-elf- --target esp32 --revision 0 /Users/aghyaddeeb/esp/translation/build/hello_world.elf -m '/Users/aghyaddeeb/.espressif/python_env/idf4.4_py3.10_env/bin/python' '/Users/aghyaddeeb/esp/esp-idf/tools/idf.py' '-p' '/dev/cu.usbserial-01D41078'"...
--- idf_monitor on /dev/cu.usbserial-01D41078 115200 ---
--- Quit: Ctrl+] | Menu: Ctrl+T | Help: Ctrl+T followed by Ctrl+H ---
ets Jun  8 2016 00:22:57

rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:2
load:0x3fff0030,len:6664
load:0x40078000,len:14944
load:0x40080400,len:3816
0x40080400: _init at ??:?

entry 0x40080698
I (27) boot: ESP-IDF v4.4.4 2nd stage bootloader
I (27) boot: compile time 10:47:33
I (27) boot: chip revision: v1.0
I (30) boot_comm: chip revision: 1, min. bootloader chip revision: 0
I (37) boot.esp32: SPI Speed      : 40MHz
I (41) boot.esp32: SPI Mode       : DIO
I (46) boot.esp32: SPI Flash Size : 2MB
I (50) boot: Enabling RNG early entropy source...
I (56) boot: Partition Table:
I (59) boot: ## Label            Usage          Type ST Offset   Length
I (67) boot:  0 nvs              WiFi data        01 02 00009000 00005000
I (74) boot:  1 phy_init         RF data          01 01 0000e000 00002000
I (82) boot:  2 factory          factory app      00 00 00010000 00180000
I (89) boot: End of partition table
I (93) boot_comm: chip revision: 1, min. application chip revision: 0
I (100) esp_image: segment 0: paddr=00010020 vaddr=3f400020 size=3adf4h (241140) map
I (196) esp_image: segment 1: paddr=0004ae1c vaddr=3ffbdb60 size=051fch ( 20988) load
I (205) esp_image: segment 2: paddr=00050020 vaddr=400d0020 size=c5800h (808960) map
I (498) esp_image: segment 3: paddr=00115828 vaddr=3ffc2d5c size=0f924h ( 63780) load
I (523) esp_image: segment 4: paddr=00125154 vaddr=40080000 size=1945ch (103516) load
I (582) boot: Loaded app from partition at offset 0x10000
I (582) boot: Disabling RNG early entropy source...
I (594) cpu_start: Pro cpu up.
I (594) cpu_start: Starting app cpu, entry point is 0x40081404
0x40081404: call_start_cpu1 at /Users/aghyaddeeb/esp/esp-idf/components/esp_system/port/cpu_start.c:148

I (0) cpu_start: App cpu up.
I (610) cpu_start: Pro cpu start user code
I (610) cpu_start: cpu freq: 160000000
I (610) cpu_start: Application information:
I (615) cpu_start: Project name:     hello_world
I (620) cpu_start: App version:      04fba14-dirty
I (626) cpu_start: Compile time:     Jul  9 2023 13:31:58
I (632) cpu_start: ELF file SHA256:  d673c1daf3f0f9da...
I (638) cpu_start: ESP-IDF:          v4.4.4
I (643) heap_init: Initializing. RAM available for dynamic allocation:
I (650) heap_init: At 3FFAFF10 len 000000F0 (0 KiB): DRAM
I (656) heap_init: At 3FFB6388 len 00001C78 (7 KiB): DRAM
I (662) heap_init: At 3FFB9A20 len 00004108 (16 KiB): DRAM
I (668) heap_init: At 3FFDB9A0 len 00004660 (17 KiB): DRAM
I (674) heap_init: At 3FFE0440 len 00003AE0 (14 KiB): D/IRAM
I (681) heap_init: At 3FFE4350 len 0001BCB0 (111 KiB): D/IRAM
I (687) heap_init: At 4009945C len 00006BA4 (26 KiB): IRAM
I (695) spi_flash: detected chip: generic
I (698) spi_flash: flash io: dio
W (702) spi_flash: Detected size(4096k) larger than the size in the binary image header(2048k). Using the size in the binary image header.
I (720) cpu_start: Starting scheduler on PRO CPU.
I (0) cpu_start: Starting scheduler on APP CPU.
I (796) BTDM_INIT: BT controller compile version [8020d24]
I (798) system_api: Base MAC address is not set
I (798) system_api: read default base MAC address from EFUSE
I (806) phy_init: phy_version 4670,719f9f6,Feb 18 2021,17:07:07
BT available: 22

Inner while: 8

press release: 13

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 8

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 5

press release: 9

BT available: 59

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 18

Inner while: 0

press release: 9

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 59

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 60

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 60

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 48

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 46

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 0

press release: 9

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 4

press release: 9

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 4

press release: 9

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 4

press release: 8

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 59

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 45

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 43

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 8

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 60

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 45

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 45

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 28

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 48

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 32

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 24

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 9

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 11

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 9

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 59

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 60

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 13

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 45

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 53

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 10

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 18

Inner while: 0

press release: 9

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 46

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 5

press release: 8

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 45

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 5

press release: 8

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 12

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 48

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 46

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 5

press release: 8

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 59

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 4

press release: 8

BT available: 14

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 48

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 22

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 5

press release: 8

BT available: 14

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 60

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 18

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 48

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 46

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 60

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 0

press release: 9

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 9

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 18

Inner while: 0

press release: 9

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 52

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 50

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 8

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 12

press release: 12

BT available: 183

Inner while: 1

press release: 1

BT available: 2

W (26840) BT_HCI: hcif conn complete: hdl 0x80, st 0x0
Inner while: 13

press release: 8

BT available: 26

Inner while: 5

press release: 9

W (26875) BT_HCI: hcif link supv_to changed: hdl 0x80, supv_to 8000
BT available: 7

Inner while: 13

press release: 12

BT available: 126

Inner while: 1

press release: 1

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 9

BT available: 14

Inner while: 9

press release: 5

BT available: 6

Inner while: 1

press release: 12

BT available: 22

Inner while: 9

press release: 5

BT available: 10

Inner while: 1

press release: 4

BT available: 23

Inner while: 4

press release: 8

BT available: 10

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 18

Inner while: 1

press release: 9

BT available: 6

Inner while: 5

press release: 5

BT available: 10

Inner while: 1

press release: 5

BT available: 10

Inner while: 1

press release: 5

BT available: 14

Inner while: 1

press release: 5

BT available: 10

Inner while: 1

press release: 5

BT available: 10

Inner while: 9

press release: 13

BT available: 22

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 9

press release: 9

BT available: 15

Inner while: 1

press release: 5

BT available: 12

Inner while: 0

press release: 9

BT available: 10

Inner while: 1

press release: 4

BT available: 10

Inner while: 1

press release: 5

BT available: 2

Inner while: 13

press release: 112

BT available: 19

Inner while: 0

press release: 5

BT available: 10

Inner while: 9

press release: 9

BT available: 6

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 13

BT available: 19

Inner while: 9

press release: 5

BT available: 2

Inner while: 1

W (27111) BT_APPL: new conn_srvc id:26, app_id:255
press release: 87

BT available: 19

Inner while: 8

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 29

Inner while: 1

press release: 5

BT available: 18

Inner while: 9

press release: 13

BT available: 3

Inner while: 1

press release: 5

BT available: 18

Inner while: 0

press release: 35

BT available: 2

Inner while: 1

press release: 5

BT available: 47

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 29

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 22

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 28

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 60

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 131

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 49

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 10

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 11

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 11

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 131

BT available: 11

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 132

BT available: 11

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 133

BT available: 11

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 133

BT available: 11

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 133

BT available: 11

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 80

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 28

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

timeBeforeUntil: 672

timeBeforeTrim: 29



insideif

timeBeforeIf: 381194



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 383448

Inner while: 985158

press release: 12

timeBeforeUntil: 10002

timeBeforeTrim: 30

timeBeforeIf: 9



Reciecve: 

BT available: 10491

Inner while: 1

press release: 4

BT available: 2

Inner while: 108718

press release: 5

BT available: 2

Inner while: 195815

press release: 5

BT available: 2

Inner while: 110893

press release: 5

BT available: 2

Inner while: 195900

press release: 5

BT available: 2

Inner while: 112852

press release: 5

BT available: 2

Inner while: 194815

press release: 12

timeBeforeUntil: 484

timeBeforeTrim: 29



insideif

timeBeforeIf: 2344



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 4943

Inner while: 5

press release: 5

timeBeforeUntil: 10007

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10446

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 9

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 45

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 78

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 45

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 13

timeBeforeUntil: 612

timeBeforeTrim: 29



insideif

timeBeforeIf: 366232



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 368707

Inner while: 110194

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 29

timeBeforeIf: 105



Reciecve: 

BT available: 10638

Inner while: 1

press release: 5

BT available: 2

Inner while: 195688

press release: 5

BT available: 3

Inner while: 110908

press release: 5

BT available: 2

Inner while: 194772

press release: 5

BT available: 2

Inner while: 109900

press release: 5

BT available: 2

Inner while: 195823

press release: 29

BT available: 3

Inner while: 113900

press release: 13

timeBeforeUntil: 470

timeBeforeTrim: 29



insideif

timeBeforeIf: 1807



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 4931

Inner while: 0

press release: 5

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10492

Inner while: 5

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 51

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 22

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 47

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 118

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 13

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 82

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 9

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

timeBeforeUntil: 844

timeBeforeTrim: 29



insideif

timeBeforeIf: 380609



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 382896

Inner while: 194946

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 30

timeBeforeIf: 9



Reciecve: 

BT available: 10634

Inner while: 0

press release: 5

BT available: 2

Inner while: 109825

press release: 5

BT available: 2

Inner while: 194772

press release: 5

BT available: 2

Inner while: 109900

press release: 5

BT available: 2

Inner while: 195815

press release: 5

BT available: 2

Inner while: 110945

press release: 4

BT available: 2

Inner while: 195852

press release: 4

BT available: 2

Inner while: 111925

press release: 5

BT available: 2

Inner while: 194899

press release: 147

timeBeforeUntil: 576

timeBeforeTrim: 29



insideif

timeBeforeIf: 2367



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5010

Inner while: 5

press release: 4

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10566

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 52

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 80

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

timeBeforeUntil: 689

timeBeforeTrim: 29



insideif

timeBeforeIf: 387472



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 389568

Inner while: 105332

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 29

timeBeforeIf: 9



Reciecve: 

BT available: 10524

Inner while: 1

press release: 5

BT available: 2

Inner while: 196745

press release: 5

BT available: 2

Inner while: 111885

press release: 4

BT available: 3

Inner while: 194900

press release: 5

BT available: 2

Inner while: 110819

press release: 5

BT available: 2

Inner while: 194913

press release: 4

BT available: 2

Inner while: 110747

press release: 5

BT available: 2

Inner while: 195819

press release: 12

timeBeforeUntil: 467

timeBeforeTrim: 29



insideif

timeBeforeIf: 2209



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5043

Inner while: 5

press release: 5

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10609

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 59

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 31

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 0

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 25

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 139

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 13

timeBeforeUntil: 673

timeBeforeTrim: 30



insideif

timeBeforeIf: 392476



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 394477

Inner while: 112409

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 29

timeBeforeIf: 9



Reciecve: 

BT available: 10581

Inner while: 0

press release: 5

BT available: 3

Inner while: 194719

press release: 5

BT available: 2

Inner while: 97941

press release: 4

BT available: 2

Inner while: 195751

press release: 5

BT available: 2

Inner while: 110815

press release: 5

BT available: 2

Inner while: 195913

press release: 13

timeBeforeUntil: 632

timeBeforeTrim: 29



insideif

timeBeforeIf: 2435



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5079

Inner while: 13

press release: 4

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10574

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 48

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 82

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 162

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 9

press release: 181

timeBeforeUntil: 745

timeBeforeTrim: 33



insideif

timeBeforeIf: 373196



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 376295

Inner while: 113484

press release: 13

timeBeforeUntil: 9978

timeBeforeTrim: 30

timeBeforeIf: 9



Reciecve: 

BT available: 10656

Inner while: 1

press release: 5

BT available: 2

Inner while: 194790

press release: 5

BT available: 3

Inner while: 110722

press release: 5

BT available: 2

Inner while: 194815

press release: 12

timeBeforeUntil: 561

timeBeforeTrim: 53



insideif

timeBeforeIf: 2316



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 4955

Inner while: 5

press release: 5

timeBeforeUntil: 10006

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10444

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 51

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 128

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 8

press release: 13

timeBeforeUntil: 746

timeBeforeTrim: 29



insideif

timeBeforeIf: 394433



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 397478

Inner while: 114372

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 29

timeBeforeIf: 98



Reciecve: 

BT available: 10632

Inner while: 0

press release: 4

BT available: 2

Inner while: 195775

press release: 5

BT available: 3

Inner while: 111870

press release: 5

BT available: 2

Inner while: 194900

press release: 5

BT available: 2

Inner while: 114815

press release: 12

timeBeforeUntil: 504

timeBeforeTrim: 55



insideif

timeBeforeIf: 2342



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 4955

Inner while: 5

press release: 5

timeBeforeUntil: 10009

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10447

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

timeBeforeUntil: 872

timeBeforeTrim: 29



insideif

timeBeforeIf: 395130



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 397510

Inner while: 195216

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 29

timeBeforeIf: 9



Reciecve: 

BT available: 10750

Inner while: 0

press release: 5

BT available: 2

Inner while: 110820

press release: 5

BT available: 2

Inner while: 194900

press release: 5

BT available: 2

Inner while: 111822

press release: 4

BT available: 2

Inner while: 196681

press release: 5

BT available: 2

Inner while: 116850

press release: 12

timeBeforeUntil: 616

timeBeforeTrim: 29



insideif

timeBeforeIf: 2393



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5051

Inner while: 5

press release: 4

timeBeforeUntil: 10001

timeBeforeTrim: 3

timeBeforeIf: 5



Reciecve: 

BT available: 10541

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 69

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 8

press release: 13

timeBeforeUntil: 866

timeBeforeTrim: 30



insideif

timeBeforeIf: 376372



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 379171

Inner while: 195703

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 30

timeBeforeIf: 9



Reciecve: 

BT available: 10589

Inner while: 1

press release: 5

BT available: 2

Inner while: 110816

press release: 5

BT available: 2

Inner while: 194896

press release: 5

BT available: 2

Inner while: 110894

press release: 5

BT available: 2

Inner while: 196896

press release: 13

timeBeforeUntil: 465

timeBeforeTrim: 30



insideif

timeBeforeIf: 2510



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5034

Inner while: 5

press release: 5

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10644

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 11

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 94

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 10

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 13

timeBeforeUntil: 538

timeBeforeTrim: 29



insideif

timeBeforeIf: 394451



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 396321

Inner while: 112506

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 30

timeBeforeIf: 225



Reciecve: 

BT available: 10741

Inner while: 1

press release: 5

BT available: 2

Inner while: 197651

press release: 4

BT available: 2

Inner while: 111874

press release: 4

BT available: 3

Inner while: 194883

press release: 5

BT available: 2

Inner while: 110815

press release: 5

BT available: 2

Inner while: 198898

press release: 13

timeBeforeUntil: 678

timeBeforeTrim: 29



insideif

timeBeforeIf: 2404



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 4992

Inner while: 4

press release: 5

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 4



Reciecve: 

BT available: 10654

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 170

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 150

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 0

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 13

timeBeforeUntil: 618

timeBeforeTrim: 140



insideif

timeBeforeIf: 394557



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 396992

Inner while: 114840

press release: 13

timeBeforeUntil: 9997

timeBeforeTrim: 30

timeBeforeIf: 8



Reciecve: 

BT available: 10842

Inner while: 0

press release: 4

BT available: 2

Inner while: 195736

press release: 5

BT available: 2

Inner while: 113770

press release: 5

BT available: 2

Inner while: 195784

press release: 5

BT available: 2

Inner while: 110898

press release: 5

BT available: 2

Inner while: 193900

press release: 5

BT available: 2

Inner while: 111900

press release: 5

BT available: 2

Inner while: 195898

press release: 13

timeBeforeUntil: 673

timeBeforeTrim: 30



insideif

timeBeforeIf: 2430



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5082

Inner while: 5

press release: 78

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10790

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 3

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 51

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 20

timeBeforeUntil: 680

timeBeforeTrim: 29



insideif

timeBeforeIf: 396139



Reciecve: {"functionName":"drive","args":[1,1,"TRIANGLE"],"fingerToActivate":0}

BT available: 398373

Inner while: 114639

press release: 12

timeBeforeUntil: 9997

timeBeforeTrim: 30

timeBeforeIf: 9



Reciecve: 

BT available: 10586

Inner while: 0

press release: 4

BT available: 2

Inner while: 194797

press release: 5

BT available: 2

Inner while: 101822

press release: 5

BT available: 2

Inner while: 195730

press release: 5

BT available: 2

Inner while: 110815

press release: 5

BT available: 2

Inner while: 196898

press release: 13

timeBeforeUntil: 750

timeBeforeTrim: 29



insideif

timeBeforeIf: 2416



Reciecve: {"functionName":"stopDriving","fingerToStop":0}

BT available: 5182

Inner while: 4

press release: 4

timeBeforeUntil: 10001

timeBeforeTrim: 2

timeBeforeIf: 5



Reciecve: 

BT available: 10576

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 73

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 3

Inner while: 1

press release: 5

BT available: 72

Inner while: 1

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 104

BT available: 72

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 1

press release: 5

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 1

press release: 4

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0

press release: 5

BT available: 2

Inner while: 0


Done
aghyaddeeb@Aghyads-MacBook-Pro translation %      