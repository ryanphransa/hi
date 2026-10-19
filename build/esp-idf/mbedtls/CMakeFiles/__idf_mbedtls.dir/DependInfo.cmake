
# Consider dependencies only in project.
set(CMAKE_DEPENDS_IN_PROJECT_ONLY OFF)

# The set of languages for which implicit dependencies are needed:
set(CMAKE_DEPENDS_LANGUAGES
  "ASM"
  )
# The set of files for implicit dependencies of each language:
set(CMAKE_DEPENDS_CHECK_ASM
  "/home/noise/Projects/hi/build/x509_crt_bundle.S" "/home/noise/Projects/hi/build/esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/__/__/x509_crt_bundle.S.obj"
  )
set(CMAKE_ASM_COMPILER_ID "GNU")

# Preprocessor definitions for this target.
set(CMAKE_TARGET_DEFINITIONS_ASM
  "ESP_PLATFORM"
  "ESP_PSA_ITS_AVAILABLE"
  "IDF_VER=\"v6.1-dev-8554-g064f8278ef2\""
  "MBEDTLS_CONFIG_FILE=\"mbedtls/esp_config.h\""
  "MBEDTLS_MAJOR_VERSION=4"
  "SOC_MMU_PAGE_SIZE=CONFIG_MMU_PAGE_SIZE"
  "SOC_XTAL_FREQ_MHZ=CONFIG_XTAL_FREQ"
  "TF_PSA_CRYPTO_USER_CONFIG_FILE=\"mbedtls/esp_config.h\""
  "_GLIBCXX_HAVE_POSIX_SEMAPHORE"
  "_GLIBCXX_USE_POSIX_SEMAPHORE"
  "_GNU_SOURCE"
  "_POSIX_READER_WRITER_LOCKS"
  "__STDC_WANT_LIB_EXT1__=0"
  )

# The include file search paths:
set(CMAKE_ASM_TARGET_INCLUDE_PATH
  "config"
  "/home/noise/esp-idf/components/mbedtls/port/include"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/include"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/library"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/core"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/src"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/extras"
  "/home/noise/esp-idf/components/mbedtls/esp_crt_bundle/include"
  "/home/noise/esp-idf/components/mbedtls/port/psa_driver/include"
  "/home/noise/esp-idf/components/mbedtls/port/psa_crypto_storage/include"
  "/home/noise/esp-idf/components/esp_libc/platform_include"
  "/home/noise/esp-idf/components/freertos/config/include"
  "/home/noise/esp-idf/components/freertos/config/include/freertos"
  "/home/noise/esp-idf/components/freertos/config/xtensa/include"
  "/home/noise/esp-idf/components/freertos/FreeRTOS-Kernel/include"
  "/home/noise/esp-idf/components/freertos/FreeRTOS-Kernel/portable/xtensa/include"
  "/home/noise/esp-idf/components/freertos/FreeRTOS-Kernel/portable/xtensa/include/freertos"
  "/home/noise/esp-idf/components/freertos/esp_additions/include"
  "/home/noise/esp-idf/components/esp_hw_support/include"
  "/home/noise/esp-idf/components/esp_hw_support/include/soc"
  "/home/noise/esp-idf/components/esp_hw_support/ldo/include"
  "/home/noise/esp-idf/components/esp_hw_support/debug_probe/include"
  "/home/noise/esp-idf/components/esp_hw_support/etm/include"
  "/home/noise/esp-idf/components/esp_hw_support/power_supply/include"
  "/home/noise/esp-idf/components/esp_hw_support/modem/include"
  "/home/noise/esp-idf/components/esp_hw_support/port/esp32/include"
  "/home/noise/esp-idf/components/esp_hw_support/port/esp32/."
  "/home/noise/esp-idf/components/heap/include"
  "/home/noise/esp-idf/components/heap/tlsf"
  "/home/noise/esp-idf/components/log/include"
  "/home/noise/esp-idf/components/soc/include"
  "/home/noise/esp-idf/components/soc/esp32"
  "/home/noise/esp-idf/components/soc/esp32/include"
  "/home/noise/esp-idf/components/soc/esp32/register"
  "/home/noise/esp-idf/components/hal/platform_port/include"
  "/home/noise/esp-idf/components/hal/esp32/include"
  "/home/noise/esp-idf/components/hal/include"
  "/home/noise/esp-idf/components/esp_rom/include"
  "/home/noise/esp-idf/components/esp_rom/esp32/include"
  "/home/noise/esp-idf/components/esp_rom/esp32/include/esp32"
  "/home/noise/esp-idf/components/esp_rom/esp32"
  "/home/noise/esp-idf/components/esp_common/include"
  "/home/noise/esp-idf/components/esp_system/include"
  "/home/noise/esp-idf/components/esp_system/port/soc"
  "/home/noise/esp-idf/components/esp_system/port/include/private"
  "/home/noise/esp-idf/components/esp_stdio/include"
  "/home/noise/esp-idf/components/xtensa/esp32/include"
  "/home/noise/esp-idf/components/xtensa/include"
  "/home/noise/esp-idf/components/xtensa/deprecated_include"
  "/home/noise/esp-idf/components/vfs/include"
  "/home/noise/esp-idf/components/esp_hal_gpio/include"
  "/home/noise/esp-idf/components/esp_hal_gpio/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_usb/include"
  "/home/noise/esp-idf/components/esp_hal_pmu/include"
  "/home/noise/esp-idf/components/esp_hal_pmu/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_regi2c/include"
  "/home/noise/esp-idf/components/esp_hal_regi2c/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_uart/include"
  "/home/noise/esp-idf/components/esp_hal_uart/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_debug_assist/include"
  "/home/noise/esp-idf/components/esp_hal_debug_assist/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_cache/include"
  "/home/noise/esp-idf/components/esp_hal_cache/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_ana_conv/include"
  "/home/noise/esp-idf/components/esp_hal_ana_conv/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_dma/include"
  "/home/noise/esp-idf/components/esp_hal_i2s/include"
  "/home/noise/esp-idf/components/esp_hal_i2s/esp32/include"
  "/home/noise/esp-idf/components/lwip/include"
  "/home/noise/esp-idf/components/lwip/include/apps"
  "/home/noise/esp-idf/components/lwip/lwip/src/include"
  "/home/noise/esp-idf/components/lwip/port/include"
  "/home/noise/esp-idf/components/lwip/port/freertos/include"
  "/home/noise/esp-idf/components/lwip/port/esp32xx/include"
  "/home/noise/esp-idf/components/lwip/port/esp32xx/include/arch"
  "/home/noise/esp-idf/components/lwip/port/esp32xx/include/sys"
  "/home/noise/esp-idf/components/esp_security/include"
  "/home/noise/esp-idf/components/esp_hal_security/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_security/include"
  "/home/noise/esp-idf/components/esp_pm/include"
  "/home/noise/esp-idf/components/esp_driver_dma/include"
  "/home/noise/esp-idf/components/esp_mspi/include"
  "/home/noise/esp-idf/components/esp_mspi/mspi_timing_tuning/include"
  "/home/noise/esp-idf/components/esp_mspi/mspi_timing_tuning/tuning_scheme_impl/include"
  "/home/noise/esp-idf/components/esp_mspi/mspi_intr/include"
  "/home/noise/esp-idf/components/esp_mspi/esp_mspi_align/include"
  "/home/noise/esp-idf/components/esp_mspi/mspi_mem_barrier/include"
  "/home/noise/esp-idf/components/esp_hal_mspi/include"
  "/home/noise/esp-idf/components/esp_hal_mspi/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_gpspi/include"
  "/home/noise/esp-idf/components/esp_hal_gpspi/esp32/include"
  "/home/noise/esp-idf/components/esp_hal_clock/include"
  "/home/noise/esp-idf/components/esp_hal_clock/esp32/include"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/drivers/builtin/include"
  "esp-idf/mbedtls/mbedtls/tf-psa-crypto/include"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/drivers/everest/include"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/drivers/p256-m/p256-m"
  "/home/noise/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/drivers/pqcp/include"
  )

# The set of dependency files which are needed:
set(CMAKE_DEPENDS_DEPENDENCY_FILES
  "/home/noise/esp-idf/components/mbedtls/esp_crt_bundle/esp_crt_bundle.c" "esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/esp_crt_bundle/esp_crt_bundle.c.obj" "gcc" "esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/esp_crt_bundle/esp_crt_bundle.c.obj.d"
  "/home/noise/esp-idf/components/mbedtls/port/esp_mem.c" "esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/port/esp_mem.c.obj" "gcc" "esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/port/esp_mem.c.obj.d"
  "/home/noise/esp-idf/components/mbedtls/port/psa_crypto_storage/esp_psa_key_file.c" "esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/port/psa_crypto_storage/esp_psa_key_file.c.obj" "gcc" "esp-idf/mbedtls/CMakeFiles/__idf_mbedtls.dir/port/psa_crypto_storage/esp_psa_key_file.c.obj.d"
  )

# Targets to which this target links which contain Fortran sources.
set(CMAKE_Fortran_TARGET_LINKED_INFO_FILES
  )

# Targets to which this target links which contain Fortran sources.
set(CMAKE_Fortran_TARGET_FORWARD_LINKED_INFO_FILES
  )

# Fortran module output directory.
set(CMAKE_Fortran_TARGET_MODULE_DIR "")
