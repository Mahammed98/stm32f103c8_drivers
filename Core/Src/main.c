/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "delay.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "EXTI_interface.h"
#include "Systick_interface.h"
#include "DMA_interface.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
//static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

volatile u32 arr1[500];
volatile u32 arr2[500];

void App_void_ToggleLed(void);
void fun(void);

int main(void)
{
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  //HAL_Init();
  /* Configure the system clock */
  //SystemClock_Config();
  //M_SysTick_void_Init();
  //M_SysTick_voidSetIntervalPeriodic(500000,fun);
  M_RCC_Void_ClkSourceInit();
  M_RCC_Void_EnableClock(APB2,IOPAEN);
  M_RCC_Void_EnableClock(AHB1,DMA1EN);    // enable DMA
  //MX_GPIO_Init();
  M_GPIO_void_SetPinMode(PORTA_GPIO, 4, OUTPUT_MAX_SPEED_10MHZ, GPO_PUSH_PULL);  // output
  M_GPIO_void_SetPinMode(PORTA_GPIO, 3, OUTPUT_MAX_SPEED_10MHZ, GPO_PUSH_PULL);  // output

  /*  initialize DMA */
  M_DMA_void_Init(1,MEMORY_TO_MEMORY_MODE, READ_FROM_PERIPHERAL, PERIPHERAL_SIZE_32_BIT, MEMORY_SIZE_32_BIT, CHANNEL_PRIORITY_HIGH);
  M_DMA_void_SendData(1, arr1, arr2, 500);
  M_DMA_void_SetCallBack(fun,1);
  /*   enable interrupt for DMA  */
  NVIC_EnableIRQ(DMA1_Channel1_IRQn);
  NVIC_SetPriority(DMA1_Channel1_IRQn,1);
  __enable_irq();   //enable global interrupt

  /*  fill source array */
for (u16 i = 0; i < 499; i++)
{
	arr1[i] = i;
}
	arr1[499] = 1;

	M_DMA_void_EnableDma(1);
	//while(M_DMA_u8_ReadTransferCompleteFlag(1) == 0);


  while(1)
  {
	  //M_GPIO_void_WritePinBSRR(PORTA_GPIO,4,HIGH);
	 // M_SysTick_DelayMs(2000);
	 //M_GPIO_void_WritePinBSRR(PORTA_GPIO,4,LOW);
	  //M_SysTick_DelayMs(2000);
  }
}

void fun(void)
{
	if(M_DMA_u8_ReadTransferCompleteFlag(1))
	{
		M_GPIO_void_WritePinBSRR(PORTA_GPIO,3,arr2[499]);   // indicator for transferring all data reaching to end of arr1
		M_GPIO_void_WritePinBSRR(PORTA_GPIO,4,HIGH);
		M_DMA_void_ClearTransferCompleteFlag(1);  // clear GIF, AND TCF
	}
}









/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}
/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
 */
/*static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};


  //__HAL_RCC_GPIOC_CLK_ENABLE();
  //__HAL_RCC_GPIOD_CLK_ENABLE();
  //__HAL_RCC_GPIOA_CLK_ENABLE();

  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);

  GPIO_InitStruct.Pin = GPIO_PIN_4;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


}*/

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
