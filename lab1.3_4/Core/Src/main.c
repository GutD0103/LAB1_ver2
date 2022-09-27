/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "display.h"
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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int time_red_x = 10;
      int time_yellow_x = 8;
      int time_green_x = 5;
      int time_red_y = 5;
      int time_yellow_y = 3;
      int time_green_y = 10;
      int counter = 3;
      HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_5 ,0 ) ;
      HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_6 ,1 ) ;
      HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_7 ,1 ) ;
      HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_8 ,1 ) ;
      HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_9 ,1 ) ;
      HAL_GPIO_WritePin ( GPIOA , GPIO_PIN_10 ,0 ) ;
      while (1)
      {

    	  if(time_red_x == 0){
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_6) ;  /* tat den vang */
    	  	  		 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_5) ;  /* bat den do */
    	  	  		 time_red_x = 10;
    	  	  	  }
    	  if(time_yellow_x == 0){
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_7) ; /* tat den xanh */
    	  	  		 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_6) ; /* bat den vang */
    	  	  		 time_yellow_x = 10;
    	  	  	  }
    	  if(time_green_x == 0){
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_5) ; /* tat den do*/
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_7) ; /* bat den xanh */
    	  		  	 time_green_x = 10;
    	  	  	  }
    	  if(time_red_y == 0){
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_9) ;
    	  	  		 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_8) ;
    	  	  		 time_red_y = 10;
    	  	  		 counter = 5;
    	  	  	  }
    	  if(time_yellow_y == 0){
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_10) ;
    	  	  		 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_9) ;
    	  	  		 time_yellow_y = 10;
    	  	  		 counter =2;
    	  	  	  }
    	  if(time_green_y == 0){
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_8) ;
    	  		  	 HAL_GPIO_TogglePin (GPIOA , GPIO_PIN_10) ;
    	  		  	 time_green_y = 10;
    	  		  	 counter =3;
    	  	  	  }
    	  time_red_x--;
    	  time_yellow_x --;
    	  time_green_x --;
    	  time_red_y--;
    	  time_yellow_y --;
    	  time_green_y --;

  // ############################
    	if( counter < 0) counter = 9;
    	    	  	display7SEG ( counter --) ;

    	  HAL_Delay (1000) ;
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, G_Pin|F_Pin|E_Pin|D_Pin
                          |C_Pin|B_Pin|A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA5 PA6 PA7 PA8
                           PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : G_Pin F_Pin E_Pin D_Pin
                           C_Pin B_Pin A_Pin */
  GPIO_InitStruct.Pin = G_Pin|F_Pin|E_Pin|D_Pin
                          |C_Pin|B_Pin|A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
