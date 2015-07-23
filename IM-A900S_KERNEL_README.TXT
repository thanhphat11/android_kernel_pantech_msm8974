How to Build:

    1. Get Toolchain (arm-eabi-4.7) and install
       (Visit android git server or codesourcery)

    2. Modify below lines in Kernel Build Script "build_ef60s.sh" and run
        1) Modify below lines
            $ export ARCH=arm
            $ export PATH=$(pwd)/../../toolchain_arm-eabi-4.7/arm-eabi-4.7/bin:$PATH
            $ export CROSS_COMPILE=arm-eabi-
        2) Run Kernel Build Script
            $ ./build_ef60s.sh

    3. Output Files
        - kernel : kernel/zImaze
        - module : kernel/drivers/*/*.ko

    4. wlan download
        - https://www.codeaurora.org/cgit/quic/la/platform/vendor/qcom-opensource/wlan/prima/tag/?h=LNX.LA.2.7.3&id=LNX.LA.3.5.1-09210-8x74.0
