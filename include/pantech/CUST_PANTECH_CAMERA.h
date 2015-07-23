#ifndef __CUST_PANTECH_CAMERA_H__
#define __CUST_PANTECH_CAMERA_H__


/*------------------------------------------------------------------------------

(1)  �ϵ���� ����
   
EF39S   : APQ8060, CE1612(8M ISP), S5K6AAFX13(1.3M)
EF40S/40K/65L   : APQ8060, CE1612(8M ISP), MT9D113(1.3M)
PRESTO  : APQ8060, MT9P111(5M SOC), MT9V113(VGA)
EF44S   : MSM8960, CE1502(13M ISP), YACD5C1SBDBC(2M)
MAGNUS   : MSM8960, CE1502(13M ISP), YACD5C1SBDBC(2M)
EF48S/49K/50L   : APQ8064, CE1502(13M ISP), YACD5C1SBDBC(2M)
EF56S/57K/58L   : MSM8974, IMX135(13M bayer), S5K6B2YX(2M FHD bayer)


(2)  ī�޶� ���� ��� kernel/userspace/android �α׸� ����

kernel/arch/arm/config/msm8660-perf-(�𵨸�)_(�������)_defconfig �� �����Ѵ�.

	# CONFIG_MSM_CAMERA_DEBUG is not set (default)

CUST_PANTECH_CAMERA.h ���� F_PANTECH_CAMERA_LOG_PRINTK �� #undef �Ѵ�.

	#define F_PANTECH_CAMERA_LOG_PRINTK (default)

��� �ҽ� ���Ͽ��� F_PANTECH_CAMERA_LOG_OEM �� ã�� �ּ� ó���Ѵ�.
	���� �� ���, �ش� ���Ͽ� ���� SKYCDBG/SKYCERR ��ũ�θ� �̿���
	�޽������� Ȱ��ȭ ��Ų��. (user-space only)

��� �ҽ� ���Ͽ��� F_PANTECH_CAMERA_LOG_CDBG �� ã�� �ּ� ó���Ѵ�.
	���� �� ���, �ش� ���Ͽ� ���� CDBG ��ũ�θ� �̿��� �޽�������
	Ȱ��ȭ ��Ų��. (user-space only)

��� �ҽ� ���Ͽ��� F_PANTECH_CAMERA_LOG_VERBOSE �� ã�� �ּ� ó���Ѵ�.
	���� �� ���, �ش� ���Ͽ� ���� LOGV/LOGD/LOGI ��ũ�θ� �̿���
	�޽������� Ȱ��ȭ ��Ų��. (user-space only)


(4)  �ȸ��ν� ���� ��� ���� ȯ��

vendor/qcom/android-open/libcamera2/Android.mk �� �����Ѵ�.
	3rd PARTY �ַ�� ��� ���θ� �����Ѵ�.

	PANTECH_CAMERA_FD_ENGINE := 0		������
	PANTECH_CAMERA_FD_ENGINE := 1		�ö���� �ַ�� ���
	PANTECH_CAMERA_FD_ENGINE := 2		��Ÿ �ַ�� ���

CUST_PANTECH_CAMERA.h ���� F_PANTECH_CAMERA_ADD_CFG_FACE_FILTER �� #undef �Ѵ�.
	�ȸ��ν� ��� ���� �������̽� ���� ���θ� �����Ѵ�.

libOlaEngine.so �� ���� libcamera.so �� ��ũ�ϹǷ� ���� ��� libcamera.so ��
ũ�Ⱑ �����Ͽ� ��ũ ������ �߻� �����ϸ�, �� ��� �Ʒ� ���ϵ鿡��
liboemcamera.so �� ������ �ٿ� libcamera.so �� ������ Ȯ���� �� �ִ�.

build/core/prelink-linux-arm-2G.map (for 2G/2G)
build/core/prelink-linux-arm.map (for 1G/3G)

------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*  MODEL-SPECIFIC                                                            */
/*  �ش� �𵨿��� ����Ǵ� �Ǵ� �ش� �𵨿����� ������ FEATURE ���           */
/*----------------------------------------------------------------------------*/
#if defined(CONFIG_SKY_EF39S_BOARD)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF39S
#define F_PANTECH_CAMERA_SKT
#elif defined(CONFIG_SKY_EF40S_BOARD)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF40S
#define F_PANTECH_CAMERA_SKT
#elif defined(CONFIG_SKY_EF40K_BOARD)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF40K
#elif defined(CONFIG_PANTECH_PRESTO_BOARD)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_PRESTO
#define F_PANTECH_CAMERA_PRESTO
/* AT&T���� ��� �߰��Ǿ�� �ϴ� Featrue */
#define F_PANTECH_CAMERA_ATT
#elif defined(T_EF45K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF45K
#define F_PANTECH_CAMERA_EF47S_45K_46L
#elif defined(T_EF46L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF46L
#define F_PANTECH_CAMERA_EF47S_45K_46L
#elif defined(T_EF47S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF47S
#define F_PANTECH_CAMERA_EF47S_45K_46L
#elif defined(T_SVLTE)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_SVLTE
#elif defined(T_CSFB)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_CSFB
#elif defined(T_CHEETAH)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_CHEETAH
#elif defined(T_STARQ)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_STARQ
#define F_PANTECH_CAMERA_ATT
#elif defined(T_OSCAR)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_OSCAR
#define F_PANTECH_CAMERA_ATT
#elif defined(T_VEGAPVW)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_VEGAPVW
/* AT&T���� ��� �߰��Ǿ�� �ϴ� Featrue */
#define F_PANTECH_CAMERA_ATT
#elif defined(T_ZEPPLIN)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_ZEPPLIN
#elif defined(T_RACERJ)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_RACERJ
#elif defined(T_SIRIUSLTE)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_SIRIUSLTE
#elif defined(T_EF44S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF44S
#define F_PANTECH_CAMERA_SKT
#elif defined(T_MAGNUS)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_MAGNUS
#elif defined(T_EF48S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF48S
#define F_PANTECH_CAMERA_EF48S_49K_50L
#define F_PANTECH_CAMERA_SKT
#elif defined(T_EF49K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF49K
#define F_PANTECH_CAMERA_EF48S_49K_50L
#define F_PANTECH_CAMERA_KT
#elif defined(T_EF50L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF50L
#define F_PANTECH_CAMERA_EF48S_49K_50L
#define F_PANTECH_CAMERA_LGT
#elif defined(T_EF51S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF51S
#define F_PANTECH_CAMERA_EF51S_51K_51L
#define F_PANTECH_CAMERA_SKT
#elif defined(T_EF51K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF51K
#define F_PANTECH_CAMERA_EF51S_51K_51L
#define F_PANTECH_CAMERA_KT
#elif defined(T_EF51L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF51L
#define F_PANTECH_CAMERA_EF51S_51K_51L
#define F_PANTECH_CAMERA_LGT
#elif defined(T_EF52S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF52S
#define F_PANTECH_CAMERA_EF52S_52K_52L
/* #define F_PANTECH_CAMERA_SKT */
#elif defined(T_EF52K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF52K
#define F_PANTECH_CAMERA_EF52S_52K_52L
#define F_PANTECH_CAMERA_KT
#elif defined(T_EF52L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF52L
#define F_PANTECH_CAMERA_EF52S_52K_52L
#define F_PANTECH_CAMERA_LGT
#elif defined(T_EF52W)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF52W
#define F_PANTECH_CAMERA_EF52S_52K_52L
/* #define F_PANTECH_CAMERA_SKT */
#elif defined(T_EF52W)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF52W
#define F_PANTECH_CAMERA_EF52S_52K_52L
/* #define F_PANTECH_CAMERA_SKT */
#elif defined(T_EF56S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF56S
#define F_PANTECH_CAMERA_EF56S_57K_58L
#define F_PANTECH_CAMERA_SKT
#elif defined(T_EF57K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF57K
#define F_PANTECH_CAMERA_EF56S_57K_58L
#elif defined(T_EF58L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF58L
#define F_PANTECH_CAMERA_EF56S_57K_58L
#elif defined(T_EF59S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF59S
#define F_PANTECH_CAMERA_EF59S_59K_59L
#define F_PANTECH_CAMERA_SKT
#elif defined(T_EF59K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF59K
#define F_PANTECH_CAMERA_EF59S_59K_59L
#elif defined(T_EF59L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF59L
#define F_PANTECH_CAMERA_EF59S_59K_59L
#elif defined(T_EF60S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF60S
#define F_PANTECH_CAMERA_EF60S_61K_62L
#define F_PANTECH_CAMERA_SKT
#elif defined(T_EF61K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF61K
#define F_PANTECH_CAMERA_EF60S_61K_62L
#elif defined(T_EF62L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF62L
#define F_PANTECH_CAMERA_EF60S_61K_62L
#elif defined(T_NAMI)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_NAMI
#elif defined(T_EF63S)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF63S
#define F_PANTECH_CAMERA_EF63SS
#define F_PANTECH_CAMERA_SKT
#elif defined(T_EF63K)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF63K
#define F_PANTECH_CAMERA_EF63SS
#elif defined(T_EF63L)
#define F_PANTECH_CAMERA
#define F_PANTECH_CAMERA_TARGET_EF63L
#define F_PANTECH_CAMERA_EF63SS
#endif

#ifdef F_PANTECH_CAMERA

#ifndef CONFIG_PANTECH_CAMERA
#define CONFIG_PANTECH_CAMERA
/* #define CONFIG_PANTECH_CAMERA_TUNER */
#endif

/*******************************************************************
 * 
 *           SENSOR ( sensor name or external ISP name)
 *
 *******************************************************************/

#ifdef F_PANTECH_CAMERA_TARGET_EF39S
/* ISP backend camera ISP */
#if (CONFIG_BOARD_VER == CONFIG_PT10)
#define F_PANTECH_CAMERA_ICP_HD
#else
#define F_PANTECH_CAMERA_CE1612
#endif
/* 1.3M front camera sensor */
#define F_PANTECH_CAMERA_S5K6AAFX13
#endif

#ifdef F_PANTECH_CAMERA_TARGET_PRESTO
#if (CONFIG_BOARD_VER >= CONFIG_WS20)
#define F_PANTECH_CAMERA_S5K4ECGX
#else
#define F_PANTECH_CAMERA_MT9P111
#endif
#define F_PANTECH_CAMERA_MT9V113
#endif

#if defined(F_PANTECH_CAMERA_TARGET_EF40S) || \
    defined(F_PANTECH_CAMERA_TARGET_EF40K)
#if (CONFIG_BOARD_VER >= CONFIG_WS20)
#define F_PANTECH_CAMERA_MT9D113
#else
#define F_PANTECH_CAMERA_S5K6AAFX13
#endif
#define F_PANTECH_CAMERA_CE1612
#endif

#if defined(F_PANTECH_CAMERA_TARGET_EF45K) || \
    	defined(F_PANTECH_CAMERA_TARGET_EF46L) || \
	defined(F_PANTECH_CAMERA_TARGET_EF47S) || \
	defined(F_PANTECH_CAMERA_TARGET_OSCAR) || \
	defined(F_PANTECH_CAMERA_TARGET_VEGAPVW)
#define F_PANTECH_CAMERA_OV8820	
#define F_PANTECH_CAMERA_YACD5C1SBDBC
#endif	

#if defined(F_PANTECH_CAMERA_TARGET_CHEETAH) || \
	defined(F_PANTECH_CAMERA_TARGET_ZEPPLIN) 
#define F_PANTECH_CAMERA_S5K4ECGX
#define F_PANTECH_CAMERA_S5K6AAFX13	
#endif

#ifdef F_PANTECH_CAMERA_TARGET_STARQ
#define F_PANTECH_CAMERA_S5K4ECGX
#define F_PANTECH_CAMERA_MT9V113	
#endif

#if defined(F_PANTECH_CAMERA_TARGET_SVLTE) || \
    defined(F_PANTECH_CAMERA_TARGET_CSFB)
#define F_PANTECH_CAMERA_CE1612	
#define F_PANTECH_CAMERA_S5K6AAFX13	
#endif

#if defined(F_PANTECH_CAMERA_TARGET_EF44S) || defined(F_PANTECH_CAMERA_EF48S_49K_50L)
#define F_PANTECH_CAMERA_CE1502
#define F_PANTECH_CAMERA_YACD5C1SBDBC
#endif

#if defined(F_PANTECH_CAMERA_TARGET_EF51S) || defined(F_PANTECH_CAMERA_TARGET_EF51K) || defined(F_PANTECH_CAMERA_TARGET_EF51L) || defined(F_PANTECH_CAMERA_TARGET_EF52S) || defined(F_PANTECH_CAMERA_TARGET_EF52K) || defined(F_PANTECH_CAMERA_TARGET_EF52L) || defined(F_PANTECH_CAMERA_TARGET_EF52W)
#define F_PANTECH_CAMERA_CE1502
#define F_PANTECH_CAMERA_AS0260
#endif

#if defined(F_PANTECH_CAMERA_TARGET_MAGNUS)
#define F_PANTECH_CAMERA_CE1502
#define F_PANTECH_CAMERA_YACD5C1SBDBC
#endif

#if defined(F_PANTECH_CAMERA_TARGET_SIRIUSLTE)
#define F_PANTECH_CAMERA_CE1612
#define F_PANTECH_CAMERA_YACD5C1SBDBC
#endif

#if defined(F_PANTECH_CAMERA_EF56S_57K_58L) || defined(F_PANTECH_CAMERA_EF59S_59K_59L) || defined(F_PANTECH_CAMERA_EF60S_61K_62L) || (defined(F_PANTECH_CAMERA_EF63SS) && (CONFIG_BOARD_VER == CONFIG_PT10))
#define F_PANTECH_CAMERA_IMX135
#endif

#if defined(F_PANTECH_CAMERA_EF56S_57K_58L) || defined(F_PANTECH_CAMERA_EF59S_59K_59L) || defined(F_PANTECH_CAMERA_EF60S_61K_62L) || defined(F_PANTECH_CAMERA_EF63SS)
#define F_PANTECH_CAMERA_S5K6B2YX
#endif

#if (defined(F_PANTECH_CAMERA_EF63SS) && (CONFIG_BOARD_VER > CONFIG_PT10))
#define F_PANTECH_CAMERA_IMX214
#endif


/*******************************************************************
 * 
 *           ACTUATOR
 *
 *******************************************************************/
 
#if defined(F_PANTECH_CAMERA_EF56S_57K_58L) || defined(F_PANTECH_CAMERA_EF59S_59K_59L) || defined(F_PANTECH_CAMERA_EF60S_61K_62L) || (defined(F_PANTECH_CAMERA_EF63SS) && (CONFIG_BOARD_VER == CONFIG_PT10))
#define F_PANTECH_CAMERA_ACT_WV560
#endif

#if defined(F_PANTECH_CAMERA_EF63SS)
#define F_PANTECH_CAMERA_ACT_RUMBA_SA
#endif

/*******************************************************************
 * 
 *           SENSOR TYPE
 *
 *******************************************************************/

#if defined(F_PANTECH_CAMERA_IMX135) || defined(F_PANTECH_CAMERA_S5K6B2YX) || defined(F_PANTECH_CAMERA_IMX214)
#define F_PANTECH_CAMERA_SENSOR_BAYER
#endif

/*******************************************************************
 * 
 *           SENSOR SPECIFICs
 *
 *******************************************************************/

#ifdef F_PANTECH_CAMERA_CE1612
#define F_PANTECH_CAMERA_CFG_WDR
#define F_PANTECH_CAMERA_ADD_CFG_UPDATE_ISP
#define F_PANTECH_CAMERA_ADD_CFG_READ_REG

#define F_PANTECH_CAMERA_CFG_STOP_CAPTURE
#endif

#if !defined(F_PANTECH_CAMERA_OV8820)
#define F_PANTECH_CAMERA_BACKFACE_YUV
#endif

#ifdef F_PANTECH_CAMERA_CE1502
#define F_PANTECH_CAMERA_CFG_GET_FRAME_INFO
#define F_PANTECH_CAMERA_CFG_YUV_ZSL_FLASH
#define F_PANTECH_CAMERA_ADD_CFG_OJT
#endif

#if defined(F_PANTECH_CAMERA_IMX135) || defined(F_PANTECH_CAMERA_IMX214)
/* 
 * EEPROM feature code 
*/
#define F_PANTECH_CAMERA_EEPROM
#endif

#if defined(F_PANTECH_CAMERA_IMX214)
#define F_PANTECH_CAMERA_ADD_OIS
#ifdef F_PANTECH_CAMERA_ADD_OIS
#define CONFIG_PANTECH_CAMERA_ADD_OIS
#endif
#endif

#ifndef T_BUILD_USER
/*#ifndef FEATURE_PANTECH_RELEASE */
/* Ŀ�� ���� �ڵ忡�� SKYCDBG/SKYCERR ��ũ�θ� ����Ͽ� ��µǴ� �޽�������
 * Ȱ��ȭ ��Ų��. 
 * kernel/arch/arm/mach-msm/include/mach/camera.h 
 * �� ���Ͽ��� #define F_PANTECH_CAMERA_LOG_PRINTK�� �����Ͽ� �α׸� �� �� �ִ�.
*/
/* ���� ����(vendor)�� SKYCDBG/SKYCERR �޼��� on off */
#define F_PANTECH_CAMERA_LOG_OEM		

/* vendor/qcom/proprietary/mm-camera/mm-camera2/include/camera_dbg.h 
 * vendor/qcom/proprietary/mm-camera/mm-camera2/media-controller/modules/sensors/module/sensor_dbg.h 
 * vendor/qcom/proprietary/mm-camera/mm-camera2/media-controller/modules/imglib/components/include/img_dbg.h 
 * �� ���ϵ鿡�� #define F_PANTECH_CAMERA_LOG_PRINTK�� �����Ͽ� �α׸� �� �� �ִ�.
 * ���� ����(vendor)�� CDBG �޼��� on off 
 * ������� ���� �� ���Ͽ��� �α׸� ���� ����ϸ�, �� ������ �α� ������ ���� �α׸� ��� �� �� �ִ�.
 * camera_dbg.h : CDBG_LEVEL (0 ~ 2)
 * sensor_dbg.h : SLOG_HIGH, SLOG_LOW
 * img_dbg.h : IDBG_LOG_LEVEL (1 ~ 4)
*/
/*#define F_PANTECH_CAMERA_LOG_CDBG*/

/* ���� ������ LOGV/LOGD/LOGI �޼��� on off */
#define F_PANTECH_CAMERA_LOG_VERBOSE
#endif
/*
 * ī�޶� Preview �� ���� ������ �ݺ� �Ǵ� �α׸� �����Ѵ�.
 * preview �� ���ʿ��� �ݺ� �α׷� ���� �ٸ� �α׸� ���Ⱑ ��ư� ������� ��ư� �ϹǷ� �����Ѵ�.
*/
#define F_PANTECH_CAMERA_ERASE_PREVIEW_LOGS

/*
 * Bayer tuning�� ���� chromatix ������ load �ؼ� �����ϵ��� �� ���
 * Tuning �Ϸ� �� ���� �ʿ�
*/
#ifdef F_PANTECH_CAMERA_SENSOR_BAYER
#define LOAD_CHROMATIX_DATA_FROM_FILE
#define F_PANTECH_CAMERA_TUNING

/*
 * 2013.11.01.
 * Bayer Camera sensor ���� analog gain �� �Բ� digital gain�� ��� �� �� �ֵ��� �ڵ� ����.
 * real gain���� ���� ���� analog gain�� �Բ� digital gain�� sensor�� user driver���� ���� �ϵ��� �Ͽ��� �Ѵ�.
 * EF56/59/60 �迭������ IMX135 sensor������ digigal gain�� ���� �Ͽ���.
*/
#define F_PANTECH_CAMERA_TUNING_CFG_DIGITAL_GAIN
#endif



/*----------------------------------------------------------------------------*/
/*  PANTECH CUSTOMIZATION                                                             */
/*  ���� Device �Ǵ� �𵨿� �°� ���� �Ǵ� ����ȭ                             */
/*----------------------------------------------------------------------------*/

/* ���� ������ �Կ� �ػ� ���̺��� �����Ѵ�. 
 *
 * HAL ������ ��ȿ�� �Կ� �ػ󵵸� ���̺� ���·� �����ϰ� ���̺� ���Ե� 
 * �ػ� �̿��� ���� ��û�� ������ ó���Ѵ�. */
#define F_PANTECH_CAMERA_CUST_PICTURE_SIZES

/* �ܸ����� �Կ��� ������ EXIF TAG ���� �� ������ ���� ������ �����Ѵ�. */
#define F_PANTECH_CAMERA_CUST_OEM_EXIF_TAG

/* UI���� "num-snaps-per-shutter" parameter�� set �����ν� burst shot�� ������ �� 
 * takePicture�� ���� burst shot�� �Կ� �� �� �ֵ��� �Ѵ�.
 *
 * burst shot �Կ��� �Կ����� single shot�� ���������� Camera Service���� play ��
 * ���� �Ѵ�.
 * �ػ� �̿��� ���� ��û�� ������ ó���Ѵ�. */
#define F_PANTECH_CAMERA_CUST_BURSTSHOT

#ifdef F_PANTECH_CAMERA_CUST_BURSTSHOT
/* 
 * burst shot �� UI�� ���� stop command�� �޾� ó���ϵ��� �Ѵ�.
 * UI�� Camera.java�� stopBurstShot(int numBurst) �� ȣ�� �� �� �ִ�.
 * StopBurstShot command�� ������ numBurst ��ŭ jpeg callback�� �Ϸ�
 * �� �� cancelPicture�� ȣ�� �Ͽ� BurstShot�� ���� �� �� �ִ�.
*/
#define F_PANTECH_CAMERA_CUST_STOP_BURSTSHOT

/* 
 * burst shot�� ��� �Կ����� CameraService���� �߻����� �ʰ�,
 * UI���� �Կ����� ����ϵ��� �Ѵ�.
 * "pantech-burst-sound" �� "disable" �� ������ �ϸ� burst shot
 * �� ��� �Կ����� ������� �ʴ´�. ��, shutter callback�� �߻�
 * �Ѵ�.
*/
#define F_PANTECH_CAMERA_CUST_BURST_UI_SOUND
#endif

/* 
 * ���� command flash test�� ���� �߰��� flash mode : FLASH_MODE_TORCH_FLASH
 * tourch mode �� �ƴ϶� flash mode�� �׽�Ʈ �� �� �ִ�.
 * flash mode�� ���� �߱� �� �Ŀ��� ���� �ð� �� �ڵ����� flash off �ǵ��� �Ѵ�.
*/
#define F_PANTECH_CAMERA_CUST_TORCH_FLASH

/* 
 * CameraHAL���� ISP(VFE) ���� �ʱ� ���� �����Ѵ�.
 * initDefaultParameters() �� ���� �� Pantech�� default ��翡 �°� ������ �κ� ��
 * ��Ȯ�� ���� �� ī�޶� ���� �ӵ� ����ȭ�� ���� UI�� default �� �׸��� ISP(VFE)��
 * default ���� ���� ��ġ�ϵ��� �Ͽ��� �Ѵ�.
 * Ư�� ISP(VFE)�� �ʱⰪ�� ��ġ�ϴ��� Ȯ�� �Ͽ� ���� �Ѵ�. */
#define F_PANTECH_CAMERA_CUST_INIT_DEFAULT_PARAM

 /* 
 * Android Gingerbread ���� ���������� "preview-frame-rate" ���� fixed fps�� ���� �Ͽ���.
 * Android Gingerbread ���� ���ʹ� "preview-fps-range-values" �� �߰� �Ǿ�����, min_fps 
 * �� max_fps�� ���� �ϵ��� �Ѵ�. 
 * "preview-fps-range-values"�� ���� frame rate�� ���� �� �� ������, min, max�� ���� ���
 * ���� fixed fps�� ������ �ȴ�.
 * ���� "preview-fps-range-values"�� ��� �� ���� ���� ������ ������ "preview-frame-rate"
 * ���� ������ �ϰ� �� �Ķ���͸� ���� ���µ� �浹�� ������ ���� �κ��� ���� �Ѵ�. */
#define F_PANTECH_CAMERA_CUST_FPS


#define F_PANTECH_CAMERA_CUST_VT_TUNING

/* 2014.01.08. jjhwang
 * AF�� �÷����� �����ǵ��� �ϴ� ����� �߰��ϱ� ���� feature
 * ��ġ AF�� ����Ͽ� �Ϲ� AF�ÿ��� �÷��� ��忡 ���� AF ������ ���� �÷����� ������.
 * continuous AF �ÿ��� �÷��� ���� ������� AF search�ÿ� �÷����� ������� �ʴ´�.
 * AF mode�� continuous AF�� ��쿡�� �Կ��ÿ� flash mode�� ���� flash+AF �� �����Ͽ�
 * AF�� �ٽ� ��� �Կ� �Ѵ�.
 * �ش� ����� MSM8974 �� ���� �����ϴ�. (EF56 ����)
*/
/* #define F_PANTECH_CAMERA_CUST_AF_FLASH */
#ifdef F_PANTECH_CAMERA_CUST_AF_FLASH
#define F_PANTECH_CAMERA_CUST_AF_FLASH_QBUG
#endif

 /* 
 *  VT�� �����信�� ����� �ϴ� preview �ػ󵵸� �߰� ���� �Ѵ�.
 *  VT������ LCD�� ���� ������ �ػ󵵸� ����ϵ��� ������ preview �ػ󵵿� �߰� ����
 *  �ʰ� ���� table�� ����� ����Ѵ�.
 *  ���� pantech�� VT app������ �ػ󵵸� ��� �Ѵ�. */
#define F_PANTECH_CAMERA_FIX_VT_PREVIEW

/* 
 * stagefright�� ���ڵ� �� �������� KT���� ������ �ȵǴ� ����
 * ������ Ʈ�� ����� "pasp" �κ��� KT�������� �Ľ��� ���ϴ� ������ �������� SKT�� LG�⿡���� ���������� ������ �Ǿ���
 * KT���� ��� ���� ������ �Ұ��� ��Ȳ�� ����Ͽ� ����� �ش� �κ��� ���� �ʵ��� ��. �� �� KT���� ���� �� �� �ִ� ����
 * pasp �� ��� ���� �����Ƿ� ��Ż� ��� ���� �������� �Ѵ�.
 */
#define F_PANTECH_CAMERA_FIX_MMS_PASP

/***********************************************************
2014.04.09 
AE issue when FLASH ON TO OFF
Added by H/W Platform
************************************************************/
#define F_PANTECH_CAMERA_CUST_TUNING_FLASH_ON_TO_OFF

/*
 * Moving the location calling releaseSound() from ~Client() to removeClientByRemote().
 * The pid of caller on Client is different from ~Client. so Sound pool can't remove the shutter sound object because pids are different.
 * the pid of Client is application's but the pid of ~Client is MediaServer's.
*/
#define F_PANTECH_CAMERA_FIX_MEDIAPLAYER_CALLING_PID

/* SKYķ�ڴ� ��ȭ������ Qparser�� Ȯ�ν� �����߻�.(deocde thumnail�Ҽ�����)
 * ķ�ڴ� ���ڵ��� ����ķ�ڴ��� SKYķ�ڴ��� ������ ��??��
 * app���� �������� stagefrightrecorder�� mMaxFileDurationUs ���̴�.
 * (SKYķ�ڴ�: 3600000000(us)=1�ð� / ����ķ�ڴ�: 600000000(us)=10��.)
 * mMaxFileDurationUs�� ���̷����� Mpeg4write����
 * SKYķ�ڴ��� 64bitfileoffset / ����ķ�ڴ��� 32bitfileoffset�� ����ϰ� �ȴ�.
 * �̸� 32bitfileoffset���� �����ϰ� �����ϱ� ���ؼ� �ش�κ��� �����Ѵ�.
 * �ӽ÷� �����Ǵ� �κ��̹Ƿ� �߰� ���� �� �������� ����͸��� �ʿ���.
 * EF52 ���Ŀ����� max recording size�� 4GB�� �ø��� ���� 64bitfileoffset���� ����
 * �Ͽ�����, �ٸ�, MMS�� ��쿡�� 32bitfileoffset ���� recording �ϵ��� �Ѵ�.
*/
#define F_PANTECH_CAMERA_VIDEO_REC_FILEOFFSET


/* �Կ� �ӵ� ������ ���� sound file load ������ camera client �����ð� �ƴ϶� 
 * camera service �����÷� �ű�
*/
#define F_PANTECH_CAMERA_MOVE_LOAD_SOUND

/*
 * WFD(wifi-display)�� ����� �ϴ� ��� ���� �Ѵ�.
 * WFD ����ϴ� ��� ��� ������ ����Ʈ�� ���۵Ǿ� �� ��� ī�޶� �Կ����� ���� �Կ��� ��
 * ���� ������ �Ҹ��� ���� �ʰ� ����Ʈ �ܸ����� �Ҹ��� ��
 * ī�޶� �������� �׻� �Կ��� ������ �Ҹ��� ���� �ϹǷ�, ���ÿ��� �Ҹ������� ���� �ڵ� ����
*/
#define F_PANTECH_CAMERA_PLAYSOUND_IN_WFD


/* MDM ��å�� ���� ī�޶� ���� ���θ� �����Ѵ� */
#define F_PANTECH_CAMERA_MDM_CHECK


/*----------------------------------------------------------------------------*/
/*  PANTECH ADD FEATURE                                                       */
/*  ���� Device �Ǵ� �𵨿� Ư���� ���� ��� �Ǵ� API �߰�                    */
/*----------------------------------------------------------------------------*/

/* ������ ��ȭ �� recordig file size �� app ���� ������ �ش�. */
#define F_PANTECH_CAMERA_ADD_EVT_RECSIZE

/*
 * jpeg file exif ���� �߰�
*/
#define F_PANTECH_CAMERA_ADD_EXIF_DATA

/* 2014.01.02. manual focus 
 * focus-mode�� manual mode�� �߰� �Ͽ� UI���� lens ��ġ�� Ư�� ��ġ�� �̵� ��ų �� �ֵ��� �Ѵ�.
 * focus-mode�� manual�� �����ϰ� pantech-focus-step�� 0 ~ 9 ���� ���� �Ͽ� lens�� �̵���Ų��.
 * focus step�� max 80������� 10�ܰ�� ��������.
 * �߰��� manaul focus ����� �̿��Ͽ� EF60 �迭�� ���� ���̽� ī�޶� ���� focus�� UI���� �߰� �Ѵ�.
*/
#define F_PANTECH_CAMERA_ADD_MANUAL_FOCUS

/*Morpho HDR���� ����ϴ� feature
 *
 * HDR on���� ������ ��� 3 ���� ������ ����Ͽ� HDR processing�� �Ѵ�.
*/
#ifndef F_PANTECH_CAMERA_TARGET_NAMI
#define F_PANTECH_CAMERA_CFG_HDR

/*
 *HDR checker
 *evaluate preview and set aebracket
*/
#define F_PANTECH_CAMERA_HDR_CHECKER

/*
 * HDR �Կ� �� thumbnail �� main image �� ���� �����.
 * ��Ȥ main image �� thumbnail �� �ٸ� ��찡 ���ܼ� �̿� ���� ���� ��.
 */
#define F_PANTECH_CAMERA_HDR_THUMBNAIL

/*
 * recording pause �Ŀ� ���Ű�� ������ ī�޶� ����Ǵ� ���� ����
*/
#define F_PANTECH_CAMERA_RECORDING_PAUSE

/*
 * MSM8974 KK ���� 90,270 rotation ���� HDR �Կ� �� thumbnail �� ��� ����Ǵ� ���� ����
*/
#define F_PANTECH_CAMERA_HDR_THUMBNAIL_KK

#if defined(F_PANTECH_CAMERA_EF63SS)
/****************************************************************
 * Description : ������ �Կ��� �����Ѵ�. (LOW LIGHT SHOT)
                        5�� �Կ� Multi Processing ó��.
 * Creation Date : 2014/2/14
 * Added By : Leehwanhee
 ****************************************************************/
#define F_PANTECH_CAMERA_CFG_LLS 
#endif
#endif

/* F_PANTECH_CAMERA_TODO, SKT FOTA DCMO (Device Control Management Object)
 * SKT �⿡�� ����Ǹ�, UI VOB������ define�� ����.
 * "pantech/development/sky_fota/sky_fota.h" ������ �־�� �Ѵ�.
*/
/* #define F_PANTECH_CAMERA_FOTA_DCMO_CAMERA_LOCK */

/* AOT(Always On Top) CAMERA �߰� ����.
 * ī�޶� ���ۻ��¸� üũ�ϵ��� CameraService::isRunning() �Լ� �߰�.
*/
#define F_PANTECH_CAMERA_AOT_ISRUNNING

/* F_PANTECH_CAMERA_TODO
 * �����ν� ���� Feature.
 * Preview buffer�� frame ���� �ʵ��� ����
*/
#if defined(F_PANTECH_CAMERA_EF59S_59K_59L) || defined(F_PANTECH_CAMERA_EF60S_61K_62L) || defined(F_PANTECH_CAMERA_EF63SS)
#define F_PANTECH_CAMERA_VTS
#endif

/*
  *raw capture �� dual isp ���� �������� �ʾ� raw capture �ÿ��� single isp �� �����ȯ�� �Ѵ�.
*/
#define F_PANTECH_CAMERA_SINGLE_ISP

 /*
  * MSM8974 ���� ���� ī�޶� �Կ� �� thumbnail �� ������ �ٸ��� �����Ǿ� ����Ǵ� ���� ����
  */
#define F_PANTECH_CAMERA_THUMBNAIL_FLIP

/* 
 * Flip Cover�� window���� ���� �Ǵ� SmartFlipCamera�� �����ϱ� ���� ���.
 * window�� size �� ������ �Ϲ������� ��� �Ǵ� ���� �ƴϹǷ�, preview/snapshot/recording 
 * table�� �ػ󵵸� �߰� ���� �ʰ� SmartFlipCamera ���ÿ����� ��� �� �� �ֵ��� �Ѵ�.
 * window�� size�� �𵨺��� �Ǵ� ���� �� ���� �� ���� �����Ƿ� ������ ���� �� �ػ󵵸� UI
 * ���� ���������� ������ �ߴٰ� ������ �ϰ� �ػ󵵸� ���� check ���� �ʵ��� �Ѵ�.
 * ���� �Ķ���� - "pantech-window-camera" : "enable"/"disable"
*/
#define F_PANTECH_CAMERA_CUST_FLIP_COVER_CAMERA

 /*
  * ������ ī�޶� ���Խ� ���� ī�޶� ���� �ϵ����ϰ� 
  * flash app�� ��� ī�޶� ���Խ� flash ���� �ϵ��� ����.
 */
#define F_PANTECH_CAMERA_DEVICE_CONNECT_FAIL_FIXED

/*----------------------------------------------------------------------------*/
/*  Qualcomm BUGS                                                             */
/*  Qualcomm bug�� �ַ� SR, ��ġ�� ����.                             */
/*  �� �� Qualcomm main stream�� �ݿ����� �ֽð� �ʿ� ��.                     */
/*----------------------------------------------------------------------------*/

/* 2014.01.28.
 * sensor mode ���ýÿ� Qualcomm source bug�� ���� ����ȭ�� mode�� ���� �Ǿ����� ����.
 * bug �����Ͽ� ������ ���� ����ȭ�� mode�� ���� �Ǿ������� ����.
*/
#define F_PANTECH_CAMERA_QBUG_SENSOR_PICK_RES

/* case#01169476 
 * ��/�ĸ� ī�޶� ���ÿ� ��� �ϱ� ���� MSM8974���� Dual VFE�� �����Ѵ�. 
 * Dual VFE ��� �� simultaneous camera feature�� �߰� �Ǿ�����, ���� �� 
 * 1023 release�� bug�� �־� �������� ���� ��ġ�� �޾� ���� �Ͽ���.
 * Ŀ�� ������ ���� ������ �������� Ȯ�� �����ϴ�.
 * #if(n)def CONFIG_PANTECH_CAMERA // case#01169476 simultaneous camera
 */
#define F_PANTECH_CAMERA_QBUG_SIMULTANEOUS_CAM

/* case#01187023 
 * 13M@24fps ZSL�� �����ϱ� ���� 8974�� highperformance(dual vfe)��
 * �����ϸ鼭 �߻��� ������ �����ϱ� ���� ������ �ڵ�
 * �̽� : ZSL OFF/ON ������ VFE0�� VFE1�� frame sync�� ���� �ʴ� ����
 *
 * 1 : 2013-05-14 : �̽� ������ ������ CASE�� ���� ���� �ڵ�
 */
#define F_PANTECH_CAMERA_QBUG_HIGH_PERFORMANCE

/* 
 * ZSL ĸ�ĵ� �̹����� ������ ���� ���� ����.
 * ���� �����Ӱ� ���� �������� �߰��� �߷��� �ϳ��� frame���� ���� �Ǵ� ���� ��.
*/
#define F_PANTECH_CAMERA_FIX_QBUG_BROCKEN_IMAGE


/*
 * ���� PNG file �� decoding �� ��, skia decoder ���� fail�� �߻� �ϰ�,
 * �̷� ���� �ַ������� ������ ���� �Ǵ� ����
*/
#define F_PANTECH_CAMERA_FIX_PNG_DECORDING_ERROR_WIH_BROKEN_DATA

/*
 * Snapshot dump img �� ���η� �Կ� �� ���������� ������ �ʴ� ���� ����
*/
#define F_PANTECH_CAMERA_QBUG_DUMP_IMAGE

/*
 *fix wrong image capture problem, the cause was wrong buffer count
 *case # 01466765
*/
#define F_PANTECH_CAMERA_QBUG_WRONG_IMAGE_CAPTURE

/*
 * stop preview error during dual camera recording stop
 *fix SIGSEGV in mct_pipeline_check_stream, case#01473686
*/
#define F_PANTECH_CAMERA_QBUG_STOP_PREVIEW

/*
 * 2014/03/11
 * case#01473540
 * increasing meta buffer cnt from 8 to 10
*/
#define F_PANTECH_CAMERA_QBUG_PREPARE_SNAPSHOT

/****************************************************************
 * Description : case#01504004
fix prepare snapshot done problem
 * Creation Date : 2014/04/21
 * Added By : Ha Dong Jin
 ****************************************************************/
#define F_PANTECH_CAMERA_QBUG_PREPARE_SNAPSHOT_DONE

/*
* 2013/12/02, Ha Dong Jin
* EF61K PLM#664, CASE#1349270, CR#522939
* Clean-up the msm camera generic buff queue on userspace
* crash to avoid invalid memory access in next session
* which might lead to corruption in other modules
* and system stability issues and also avoid memory leak.
*/
#define F_PANTECH_CAMERA_QBUG_CLEANUP_MSM_GENERIC_BUF


/*
 * Effect Recording �����ϸ� Effect �� ������� ��ȭ�Ǵ� ���� SR �� ���� case# 01215481
*/
#define F_PANTECH_CAMERA_QBUG_EFFECT_RECORDING

/*
 * focus mode�� "continuous-video" ���� "auto"�� ���� �Ͽ��� ��,
 * continuous af�� stop ���� �ʴ� ���� ����.
 * camcorder caf file�� ���� algo type�� �߸� load �ϰ� �Ǹ�, ��
 * ������ caf_state ������ caf�� stop ���� �ʴ� ���� ��.
*/
#define F_PANTECH_CAMERA_QBUG_CONTINUOUS_VIDEO_STOP


#ifdef F_PANTECH_CAMERA_IMX135
/*
 * IMX135 sensor���� �����ϴ� ������HDR ��� ����� imx135_fill_awb_hdr_array
 * ȣ�� ���� �ʴ� ���� ����
*/
#define F_PANTECH_CAMERA_QBUG_MOVIE_HDR

/*
 * IMX135 sensor���� �����ϴ� ������HDR ��� ����ȭ�� ����
 * customizing
*/
#define F_PANTECH_CAMERA_CUST_MOVIE_HDR
#endif

/*
 * ī�޶� ĸ�Ľ� shutter callback �����Ͽ� ������ �ڵ� �κ� ����
 * shutter callback�� sound play ���θ� �Ǵ� �Ͽ� 1ȸ�� ���Ͽ� 
 * callback �� �ǵ��� ���� �Ѵ�.
*/
#define F_PANTECH_CAMERA_QBUG_SHUTTER_CALLBACK

/*
 * ī�޶� �Կ� �� Home Key�� ���� stopPreview command �߻��� ī�޶� halt �Ǵ�
 * ���� ����
 * OMX Jpeg encoder release �� halt �Ǵ� ����
*/
#define F_PANTECH_CAMERA_QBUG_STOP_ON_SNAPSHOT

/*
 *Start preview ���� flash or movie mode ������ ���� �ȵǴ�
 *���� workaround ����
 */
#define F_PANTECH_CAMERA_QBUG_LED_MODE

/* ������ ��ȭ ����/���Ḧ ������ �ݺ��ϰų�, �̾����� ������ ���¿��� �����Կ�
 * ���� �Կ��� ���, MediaPlayer �� �������ϸ鼭 HALT �߻��Ѵ�.
 *
 * MediaPlayer �� ���, ������ ������ ��� �߿� �� �ٽ� ��� �õ��� ��� 100%
 * �������ϹǷ� ���� ������ �����Ͽ� ����ؾ� �� ���, �ݵ�� ���� ����� �Ϸ�
 * �Ǿ����� ���θ� Ȯ�� �� ����ؾ� �Ѵ�. 
 * 
 * 2014/02/19, sangwon, prevented this feature to resolve a PLM(61K_KK,#00654) issue that is related to burst shot in case of using SD storage.
 * this issue is occured when takePicture command rapidly because the duration time of calling playSound() is shorter than play time of shutter sound.
 * to replay shutter sound we needed to add calling pause() because of the bug of mediaPlayer but it was very long time ago and MediaPlayer don't have to be called pause CameraService included in MediaServer.
 */
//#define F_PANTECH_CAMERA_QBUG_SKIP_CAMERA_SOUND  

/*
* �ʱ� ���Խ� Sharpness ������� �ʴ� ���� ����.
*/
#define F_PANTECH_CAMERA_QBUG_SHARPNESS

/*
 *MSM8974 KK ���� �߻��ϴ� thumbnail rotation ������ �����ϱ� ���� QC patch code ����, case# 01438139
*/
#define F_PANTECH_CAMERA_QBUG_THUMB_ROTATION


#define F_PANTECH_CAMERA_QBUG_FIX_GOOFY_FACE_RECORD

/*
* Recording ���۽� Effect ������� �ʴ� ���� ����.
*/
#define F_PANTECH_CAMERA_QBUG_EFFECT


/*
* CPL patch�� camera start/stop preview���� map/unmap �� hold �Ǵ� ����
*/
#define F_PANTECH_CAMERA_QBUG_HOLD_DURING_MAP_UNMAP

/*
* The camera mode is picked up according to resolution and fps but the snapshot chromatix in the orignal code is just set with MSM_SENSOR_RES_FULL is 0.
* So, modified code is selecte snapshot chromatix according to camera mode selected.
*/
#define F_PANTECH_CAMERA_QBUG_WRONG_SNAPSHOT_CHROMATIX

/*
 * live shot �Կ��� live shot �ػ󵵸� picture size�� �ƴ϶�, recording size�� ��� �ϵ��� ����
 */
 #define F_PANTECH_CAMERA_CUST_LIVESNAPSHOT

/*
* [2014/01/09, CASE : 01413457]
* VFE MAX clock ���� ���� �߸� �޾ƿ��� ���� ����
*/
#define F_PANTECH_CAMERA_QBUG_VFE_MAX_CLOCK_SETTING

/*
* 2013/12/19/ case : 01388126
* Qualcomm fixes for known FD leakage issues in camera side
*/
#define F_PANTECH_CAMERA_QBUG_FD_LEAKAGE

/*
* 2013/12/19/ case : 01388126
* Qualcomm fix memory leak in luma adaptation 
*/
/* #define F_PANTECH_CAMERA_QBUG_LUMA_LEAKAGE */

/*
* 2014.01.23. - case#01428626
* ī�޶� stability �̽�, stream on �Ҷ� fail �߻�. �Ʒ� error log ���
*       mm-camera stats_port_event: Failure posting to the bus!
*       mm-camera isp_ch_util_streamon_ack: error, ISP_HW_ACTION_CODE_STREAM_START_ACK, sessid = 1, vfe_id = 0, rc = -1
* ISP Buffer manager ���� mutex ���� handling�� ������ �־� ���� patch code ����
* MSM8974 JB���� ���� �̽��� patch ���� �Ͽ�����, KK���� �Ϻ� ���� �� �ڵ� �������� ���� JB patch ���� ���ϰ�
* LINUX build ID LNX.LA.3.5-07510-8x74.0-1 base�� patch code �޾Ƽ� ����.
*/
#define F_PANTECH_CAMERA_QBUG_MUTEX_FOR_ISP_BUFMGR

/*
 *2014/2/18 case : 01452485
 *fix module_imglib_clear_session_params fail
*/
#define F_PANTECH_CAMERA_QBUG_IMGLIB_CLEAR

/* 2014/3/18 case : 01484820
 * destroy super buf cmd thread  
*/
#define F_PANTECH_CAMERA_QBUG_RELEASE_THREAD

/*
* 2014/02/13  lee sangwon
* video size 4k x 2k(UHD) support is enabled
*/
#define F_PANTECH_CAMERA_SUPPORT_4K2K_UHD


/*
* 2014.03.27. case:01475905
* stream on fail issue when preview is started
* in issue case, below fail log is occured.
* "QCameraStream Failed to config stream, rc = -1"
* Additionally, you can see only the log for enterance of preview_start without ending of start_preview.
*/
#define F_PANTECH_CAMERA_QBUG_STREM_ON_FAIL

/*
* 2014/02/28  lee sangwon
* Added the QCom Patch about High Speed Recording (CR605405), Case#01460192
*/
#if defined(F_PANTECH_CAMERA_EF63SS)
#define F_PANTECH_CAMERA_SUPPORT_HSR
#endif

/*
* 2014/02/28  lee junhee
* Fix Camcoder Recording File Audio not Sync
* Because Add H/W ACC Encoder use code in StageFrightRecorder.cpp by Post CR Patch
*/
#define F_PANTECH_CAMERA_FIX_CAM_AUDIO_SYNC

/*
 *2014/03/10
 *Fix mms recording problem. The track header size is too big in mms recording case.
 *So set it to 6KB.
*/
#define F_PANTECH_CAMERA_MMS_RECORDING

/****************************************************************
 * Description : fixed issue that jpeg exif data is not seen as flash fired in torch mode.
 * Creation Date : 2014/03/24
 * Added By : lee hwanhee
 ****************************************************************/
#define F_PANTECH_CAMERA_JPEG_EXIF_DATA_IN_TORCH_MODE

/****************************************************************
 * Description : bug fixed for recording stopping during liveshot
 * Creation Date : 2014/04/21
 * Added By : lee hwanhee
 ****************************************************************/
#define F_PANTECH_CAMERA_RECORDING_STOP_DURING_LIVESHOT

/*----------------------------------------------------------------------------*/
/*  MODEL-SPECIFIC CONSTANTS                                                  */
/*  �� ���� ��� ����                                              */
/*----------------------------------------------------------------------------*/

/* camera select enum */
#define C_PANTECH_CAMERA_SELECT_MAIN_CAM 		0
#define C_PANTECH_CAMERA_SELECT_SUB_CAM 		1

#ifndef F_PANTECH_CAMERA_TARGET_NAMI
//P11232 US4 CAMERA
#define F_PANTECH_CAMERA_CFG_IPL_SKY_PROCESSING
#ifdef F_PANTECH_CAMERA_CFG_IPL_SKY_PROCESSING
#define F_PANTECH_CAMERA_CFG_CAMNOTE
#define F_PANTECH_CAMERA_CFG_MINIATURE
#define F_PANTECH_CAMERA_CFG_COLOREXTRACTION
#endif
#endif

#ifdef F_PANTECH_CAMERA_CUST_OEM_EXIF_TAG
#define C_PANTECH_CAMERA_EXIF_MAKE		"PANTECH"
#define C_PANTECH_CAMERA_EXIF_MAKE_LEN		8		/* including NULL */
#ifdef F_PANTECH_CAMERA_TARGET_EF39S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A800S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF40S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A810S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF40K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A810K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_PRESTO
#define C_PANTECH_CAMERA_EXIF_MODEL		"PRESTO"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		7		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF45K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A830K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF46L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A830L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF47S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A830S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_SVLTE
#define C_PANTECH_CAMERA_EXIF_MODEL		"SVLTE"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		6		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_CSFB
#define C_PANTECH_CAMERA_EXIF_MODEL		"CSFB"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		5		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_CHEETAH
#define C_PANTECH_CAMERA_EXIF_MODEL		"CHEETAH"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		8		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_STARQ
#define C_PANTECH_CAMERA_EXIF_MODEL		"STARQ"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		6		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_OSCAR
#define C_PANTECH_CAMERA_EXIF_MODEL		"OSCAR"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		6		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_VEGAPVW
#define C_PANTECH_CAMERA_EXIF_MODEL		"ADR930L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		8		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_ZEPPLIN
#define C_PANTECH_CAMERA_EXIF_MODEL		"ZEPPLIN"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		8		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_SIRIUSLTE
#define C_PANTECH_CAMERA_EXIF_MODEL		"SIRIUSLTE"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		10		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF44S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A840S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_MAGNUS
#define C_PANTECH_CAMERA_EXIF_MODEL		"P9090"		//MAGNUS
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		6		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF48S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A850S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF49K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A850K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF50L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A850L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF51S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A860S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF51K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A860K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF51L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A860L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF52S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A851L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF52K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A851L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF52L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A851L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF52W
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A851L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF56S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A880S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF57K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A880K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF58L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A880L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF59S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A890S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF59K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A890K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF59L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A890L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF60S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A900S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF61K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A900K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF62L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A900L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_NAMI
#define C_PANTECH_CAMERA_EXIF_MODEL		"NAMI"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		5		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF63S
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A910S"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF63K
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A910K"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#ifdef F_PANTECH_CAMERA_TARGET_EF63L
#define C_PANTECH_CAMERA_EXIF_MODEL		"IM-A910L"
#define C_PANTECH_CAMERA_EXIF_MODEL_LEN		9		/* including NULL */
#endif
#endif

#endif /* F_PANTECH_CAMERA */

#endif /* CUST_PANTECH_CAMERA.h */
