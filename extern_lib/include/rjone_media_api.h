


#ifndef _RJONE_MEDIA_API_
#define _RJONE_MEDIA_API_

#ifdef __cplusplus
extern "C" {
#endif

#include "rjone_type.h"
#include "rjone_err.h"
#include "rjone.h"


#define RJONE_MEDIA_SYS_VER  (0x01000001)
#define RJONE_MAX_MEDIA_NUM (5)





typedef enum 
{
    HISI_GPIO_0=0,
    HISI_GPIO_1,
    HISI_GPIO_2,
    HISI_GPIO_3,
    HISI_GPIO_4,
    HISI_GPIO_5,
    HISI_GPIO_6,
    HISI_GPIO_7,
    HISI_GPIO_8,
    HISI_GPIO_9,
    HISI_GPIO_10,
    HISI_GPIO_11,
}GPIO_ID_E;

typedef enum 
{
    HISI_GPIO_WORK_MODE_INPUT=0,
    HISI_GPIO_WORK_MODE_OUTPUT,
}GPIO_WORK_MODE_E;

typedef struct _hisi_gpio_st_
{
	GPIO_ID_E uGpioId;                             			/** GPIO 号  如 GPIO_0  GPIO1 **/
	GPIO_WORK_MODE_E uGpioWorkMode;			/** GPIO 输入模式或者输出模式**/
	unsigned char uGpioMask;						/** 起作用管脚 掩码 如 0x01->GPIO_0_1    0x80->GPIO_0_7     0x03->(GPIO_0_1 and GPIO_0_2) **/
	unsigned char uGpioValue;						/** GPIO 值，如果GPIO处于输入模式， uGpioValue  返回 GPIO_VALUE & uGpioMask  **/
}HISI_GPIO_ST;



#define RJONE_MAX_VIDEO_BUF_SIZE				(524288) /* (512*1024)*/
#define RJONE_MAX_AUDIO_BUF_SIZE				(8192) /* (512*1024)*/

typedef enum
{
	CHIP_TYPE_BASE=0,
    	CHIP_TYPE_HI3518E,
    	CHIP_TYPE_GM8126,
}RJONE_CHIP_TYPE_E;


typedef enum
{
	SENSOR_TYPE_BT656 = 0,
	SENSOR_TYPE_AR0130,
	SENSOR_TYPE_OV9712,
	SENSOR_TYPE_GC_1004,
	SENSOR_TYPE_SOI_H22,
	SENSOR_TYPE_OV2710,
}RJONE_SENSOR_TYPE_E;




typedef enum
{
	MEDIA_TYPE_BASE = 98,
    	MEDIA_TYPE_VIDEO,
    	MEDIA_TYPE_AUDIO,
}RJONE_MEDIA_TYPE_E;


typedef enum
{

    RJONE_VENC_RC_MODE_H264CBR = 1,    
    RJONE_VENC_RC_MODE_H264VBR,        
    RJONE_VENC_RC_MODE_H264ABR,        
    RJONE_VENC_RC_MODE_H264FIXQP,      
    RJONE_VENC_RC_MODE_MJPEGCBR,    
    RJONE_VENC_RC_MODE_MJPEGVBR,     
    RJONE_VENC_RC_MODE_MJPEGABR,     
    RJONE_VENC_RC_MODE_MJPEGFIXQP,  
    RJONE_VENC_RC_MODE_MPEG4CBR,    
    RJONE_VENC_RC_MODE_MPEG4VBR,       
    RJONE_VENC_RC_MODE_MPEG4ABR,       
    RJONE_VENC_RC_MODE_MPEG4FIXQP,  
    RJONE_VENC_RC_MODE_H264CBRv2,
    RJONE_VENC_RC_MODE_H264VBRv2,
    RJONE_VENC_RC_MODE_BUTT,
}RJONE_VENC_RC_MODE_E;








typedef struct _media_video_attr_
{
	RJONE_CODE_TYPE encType;               /* 压缩格式		*/
	RJONE_VENC_RC_MODE_E rcMode;		/* 码流控制方式*/	
	int iPicWidth; 		 /*视频 图像宽度   */
	int iPicHeight;		/* 视频图像高度*/	
	int iFrameRate;		/* 帧率 fps */
	int iBitRate;			/* 码流大小*/
	int iGop;				/* 关键帧间隔*/
}RJONE_VIDEO_ATTR;




typedef struct _snap_jpg_pic_
{
	char * pPicPtr;
	int iPicLen;
}SNAP_JPG_PIC;


typedef enum _audio_sampel_rate_ 
{ 
    RJONE_AUDIO_SAMPLE_RATE_8000   = 8000,    /* 8K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_12000  = 12000,   /* 12K samplerate*/    
    RJONE_AUDIO_SAMPLE_RATE_11025  = 11025,   /* 11.025K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_16000  = 16000,   /* 16K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_22050  = 22050,   /* 22.050K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_24000  = 24000,   /* 24K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_32000  = 32000,   /* 32K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_44100  = 44100,   /* 44.1K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_48000  = 48000,   /* 48K samplerate*/
    RJONE_AUDIO_SAMPLE_RATE_BUTT,
}RJONE_AUDIO_SAMPLE_RATE_E; 



typedef enum _audio_bit_width_
{
    RJONE_AUDIO_BIT_WIDTH_8   = 0,   /* 8bit width */
    RJONE_AUDIO_BIT_WIDTH_16  = 1,   /* 16bit width*/
    RJONE_AUDIO_BIT_WIDTH_32  = 2,   /* 32bit width*/
    RJONE_AUDIO_BIT_WIDTH_BUTT,
} RJONE_AUDIO_BIT_WIDTH_E;


typedef enum  _aio_sound_mode_
{
     RJONE_AUDIO_SOUND_MODE_MONO   =0,/*mono*/
     RJONE_AUDIO_SOUND_MODE_STEREO =1,/*stereo*/
     RJONE_AUDIO_SOUND_MODE_BUTT    
} RJONE_AUDIO_SOUND_MODE_E;




typedef struct _media_audio_attr_
{
	RJONE_CODE_TYPE encType;               /* 压缩格式		*/	
	RJONE_AUDIO_SAMPLE_RATE_E sampleRate; 		 /*音频采样率  */
	RJONE_AUDIO_BIT_WIDTH_E bitWidth;			/* 音频位宽*/	
	RJONE_AUDIO_SOUND_MODE_E soundMode;		/* 音频模式 mono or stereo*/
	int iPtNumPerFrm;			/* 每帧的采样点数 (80/160/240/320/480/1024/2048) */
	int iChnCnt; 				/* 声道数*/
}RJONE_AUDIO_ATTR;



typedef struct media_attr_s
{	
	int iMediaId;					/* 与此media_attr 对应的media Id 值 */
	RJONE_MEDIA_TYPE_E mediaType;   /* media is video or audio type.  */
	union
	{
		RJONE_VIDEO_ATTR videoAttr; 
		RJONE_AUDIO_ATTR audioAttr;
	};
}RJONE_MEDIA_ATTR_S;


typedef struct media_sys_param
{  
    RJONE_CHIP_TYPE_E chipType;        	/*使用的芯片型号*/
    RJONE_SENSOR_TYPE_E sensorType; 	/*  使用的sensor型号*/ 
    RJONE_VIDEO_NORM_E videoNorm;		/* 视频制式*/
    int iMediaNum;					/* 系统初始化时，启用media 数量*/ 
    RJONE_MEDIA_ATTR_S mediaAttr[RJONE_MAX_MEDIA_NUM];     /* media 属性 */   
}RJONE_MEDIA_SYS_PARAM;


typedef struct video_frame_header_s
{
       int iCode;                                           // 压缩格式
	int iIsKeyFrame;					/* 是不是I 帧*/
	int iFrameDataLen;				/* 帧数据长度*/	
	UINT8 u8FrameIndex;
	int iFramerate;					// 帧率
}VIDEO_FRAME_HEADER_S;

typedef struct audio_frame_header_s
{
       INT8 iCode;                                           // 压缩格式
      	UINT8 u8AudioSamplerate;				//采样率 RJONE_AUDIO_SAMPLERATE
	UINT8 u8AudioBits;						//采样位宽RJONE_AUDIO_DATABITS
	UINT8 u8AudioChannel;					//通道		RJONE_AUDIO_CHANNEL		
	int iRawAudioDataLen;			/*  原始音频数据长度(未压缩的音频数据)*/
	int iEncAudioDataLen;			/*  原始音频数据压缩后数据长度*/		
	UINT8 u8FrameIndex;
}AUDIO_FRAME_HEADER_S;


typedef struct _media_frame_head_s_
{
	RJONE_MEDIA_TYPE_E mediaType;   /* 视频帧或者音频帧*/
	struct timeval  timeStamp;	
	union
	{
		VIDEO_FRAME_HEADER_S videoFrameHead; 
		AUDIO_FRAME_HEADER_S audioFrameHead;
	};		
	char reserved[4];
}RJONE_MEDIA_FRAME_HEAD_S;


typedef struct _motion_detect_buf_s_
{
	unsigned short * buf;
	int mdWidth;
	int mdHeigth;
	int isTriggerMotion;
}MOTION_DETECT_BUF_S;


/************************************************************************
 函数名:RJONE_GetMediaSystemVer
 功能: 得到media system 版本号
 输入:	无
 输出:无
 返回:成功返回 
 		MedisSystem Ver(UINT)   "Version: %d.%d.%d.%d", (Ver & 0xFF000000)>>24, (Ver & 0x00FF0000)>>16, (Ver & 0x0000FF00)>>8, (Ver & 0x000000FF) >> 0 )
 		
 		错误返回 
 		RJONE_FAILED
 说明:
************************************************************************/
unsigned int RJONE_GetMediaSystemVer();  


/************************************************************************
 函数名:RJONE_InitMediaSystem
 功能:  初始化media 系统
 输入:
 		pstMediaSysParam   结构体指针
 		RecvCallBackFunc    回调函数指针，获得视频和音频数据。
 		int (*RecvCallBackFunc)(RJONE_MEDIA_FRAME_HEAD_S * pFrameHead,char * pFrameBuf,int iMediaId); 
 		输入参数
 			pFrameHead  帧头结构体
 			pFrameBuf    帧数据
 			iMediaId   产生此帧的媒体ID号
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_InitMediaSystem(RJONE_MEDIA_SYS_PARAM * pstMediaSysParam,int (*RecvCallBackFunc)(RJONE_MEDIA_FRAME_HEAD_S * ,char * ,int ));  


/************************************************************************
 函数名:RJONE_MediaSystemStartWork
 功能: media 系统开始工作
 输入:
 		无
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_MediaSystemStartWork();  

/************************************************************************
 函数名:RJONE_MediaSystemStopWork
 功能: media 系统停止工作
 输入:
 		无
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_MediaSystemStopWork();  


/************************************************************************
 函数名:RJONE_DestroyMediaSystem
 功能: 关闭media 系统
 输入:
 		无
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_DestroyMediaSystem();  



/************************************************************************
 函数名:RJONE_GetMediaSystemParam
 功能:  获得media系统参数
 输入:
 		无
 输出:
 		pstMediaSysParam  用来存放获得的结构体数据
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_GetMediaSystemParam(J_OUT RJONE_MEDIA_SYS_PARAM * pstMediaSysParam); 



/************************************************************************
 函数名:RJONE_SetVideoEncode
 功能:设置视频压缩引擎参数
 输入:
 		iMediaId   与RJONE_MEDIA_ATTR_S 结构体中对应的iMediaId.
 		iFrameRate  	设置的帧率
 		iBitRate		设置的码流
 		iGop			设置的I帧间隔
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_SetVideoEncode(int iMediaId,int iFrameRate,int iBitRate,int iGop);




/************************************************************************
 函数名:RJONE_SendDataToAudioDec
 功能:播放音频数据
 输入: 		
 		pAudioData  	音频数据指针
 		iDataLen		音频数据长度 		
 		enEncodeType  音频编码格式
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_SendDataToAudioDec(void * pAudioData,int iDataLen , RJONE_CODE_TYPE enEncodeType);



/************************************************************************
 函数名:RJONE_EnableAec
 功能:启用回声抵消
 输入:
 		无
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_EnableAec();


/************************************************************************
 函数名:RJONE_DisableAec
 功能:关闭回声抵消
 输入:
 		无	
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_DisableAec();



/************************************************************************
 函数名:RJONE_GetSnapPictureData
 功能:抓图
 输入:无	
 输出:
 		pStorePicData  	获取	SNAP_JPG_PIC 结构数据。
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_GetSnapPictureData(J_OUT SNAP_JPG_PIC * pStorePicData);


/************************************************************************
 函数名:RJONE_ReleaseSnapPictureData
 功能:抓图
 输入: 		
 		pStorePicData  要释放内存的抓图结构体。
 输出:无
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_ReleaseSnapPictureData(SNAP_JPG_PIC * pStorePicData);


/************************************************************************
 函数名:RJONE_GetGammaTable
 功能: 获得当前Gamma Type 值
 输入: 无
 输出:
 		peGamaType 获得当前GamaType 值。
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_GetGammaTable(J_OUT RJONE_GAMMA_TYPE * peGamaType);

/************************************************************************
 函数名:RJONE_SetGammaTable
 功能: 设置图像处理的GAMA 表
 输入: 		
 		eGamaType  使用那种GAMA模式
 		pSelfGameTable  当eGamaType = GAMMA_TYPE_SELF 时，用户GamaTable 指针。
 输出:无
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_SetGammaTable(RJONE_GAMMA_TYPE eGamaType,void * pSelfGameTable);


/************************************************************************
 函数名:RJONE_GetViCSCAttr
 功能:  获得图像参数
 输入:无	 		
 输出:
 		piLumaVal  	亮度值  luminance: [0 ~ 100] 
 		piContrVal		对比度  contrast : [0 ~ 100] 
 		piHueVal		色差	    hue : [0 ~ 100
 		piSatuVal         饱和度  satuature: [0 ~ 100]
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_GetViCSCAttr(J_OUT int * piLumaVal,J_OUT int * piContrVal,J_OUT int * piHueVal,J_OUT int * piSatuVal);




/************************************************************************
 函数名:RJONE_SetViCSCAttr
 功能:  设置图像参数
 输入: 		
 		iLumaVal  	亮度值  luminance: [0 ~ 100] 
 		iContrVal		对比度  contrast : [0 ~ 100] 
 		iHueVal		色差	    hue : [0 ~ 100
 		iSatuVal         饱和度  satuature: [0 ~ 100]
 输出:无
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_SetViCSCAttr(int iLumaVal,int iContrVal,int iHueVal,int iSatuVal);



/************************************************************************
 函数名:RJONE_GPIO_OP
 功能:控制GPIO 管脚
 输入:
 		pGpioData GPIO 控制结构体指针
 输出:
 		pGpioData 当设置GPIO为输入工作模式时，它将获得GPIO 管脚读取的值。 
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_GPIO_OP(J_IN J_OUT HISI_GPIO_ST  * pGpioData);



/************************************************************************
 函数名:RJONE_Get_Adc0_Value
 功能:读取adc0 采集的数据
 输入:
 		无
 输出:
 		pU8Value 取得数据值的指针。
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_Get_Adc0_Value(J_OUT UINT8  * pU8Value);


/************************************************************************
 函数名:RJONE_Set_Video_Mirror_Flip
 功能:对采集图像进行水平和垂直翻转
 输入:
 		无
 输出:
 		pU8Value 取得数据值的指针。
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_Set_Video_Mirror_Flip(int iMirror,int iFlip);



/************************************************************************
 函数名:RJONE_CreateIKeyFrame
 功能: 视频产生即时I 帧
 输入: 无
 输出:
 		iMediaId   与RJONE_MEDIA_ATTR_S 结构体中对应的iMediaId.
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_CreateIKeyFrame(int iMediaId);


/************************************************************************
 函数名:RJONE_ShowOsd
 功能: 在视频图像上显示OSD
 输入: 
 		id  OSD id 范围是[0 - 7]
 		chan  视频通道 [0 - 1] 
 		screen_x  OSD 显示的坐标左上角 x 值
 		screen_y  OSD 显示的坐标左上角 y �
 		show_buf  OSD上要显示的图片数据地址，图片格式为ARGB1555
 		show_pic_witdh  显示的图片 的宽度
 		show_pic_witdh  显示的图片 的高度
 		u32BgAlpha   背景颜色透明度 范围 [0-128]    值越小越透明
 		u32FgAlpha    前景颜色透明度 范围[0-128]  值越小越透明
 输出:
 		无
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_ShowOsd(int id,int chan,int screen_x,int screen_y,char * show_buf,int show_pic_witdh, int show_pic_height,unsigned int u32BgAlpha,unsigned int u32FgAlpha);


/************************************************************************
 函数名:RJONE_GetMotionInfo
 功能:  获取移动检测信息
 输入:
 		无
 输出:
 		pBufSt  			返回移动检测结构体指针 		
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_GetMotionInfo( J_OUT MOTION_DETECT_BUF_S  * pBufSt);


/************************************************************************
 函数名:RJONE_SetWorkFrequency
 功能:   设置设备的工作频率
 输入:
 		enVideoNorm  工作频率
 输出:
 		无	
 返回:成功返回RJONE_SUCCESS
 说明:
************************************************************************/
int RJONE_SetWorkFrequency( J_IN RJONE_VIDEO_NORM_E  enVideoNorm);


/************************************************************************
 函数名:RJONE_CloseOsd
 功能: 关闭指定 OSD,让其不显示
 输入: 
 		id  OSD id 范围是[0 - 7]
 输出:
 		无
 返回:成功返回RJONE_SUCCESS 	     
 说明:
************************************************************************/
int RJONE_CloseOsd(int id);

#ifdef __cplusplus
}
#endif

#endif 

