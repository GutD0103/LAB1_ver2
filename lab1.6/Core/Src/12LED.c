/*
 * 12LED.c
 *
 *  Created on: Sep 27, 2022
 *      Author: ntdat
 */


#include "main.h"
#include "12LED.h"
void clearAllClock (){
	HAL_GPIO_WritePin ( H0_GPIO_Port , H0_Pin ,SET );
	HAL_GPIO_WritePin ( H1_GPIO_Port , H1_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H2_GPIO_Port , H2_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H3_GPIO_Port , H3_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H4_GPIO_Port , H4_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H5_GPIO_Port , H5_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H6_GPIO_Port , H6_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H7_GPIO_Port , H7_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H8_GPIO_Port , H8_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H9_GPIO_Port , H9_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H10_GPIO_Port , H10_Pin ,SET ) ;
	HAL_GPIO_WritePin ( H11_GPIO_Port , H11_Pin ,SET ) ;

};
void setNumberOnClock(int num){
	switch(num) {
	  case 0:
		  HAL_GPIO_WritePin ( H0_GPIO_Port , H0_Pin ,RESET ) ;
		break;
	  case 1:
		  HAL_GPIO_WritePin ( H1_GPIO_Port , H1_Pin ,RESET ) ;
	    break;
	  case 2:
		  HAL_GPIO_WritePin ( H2_GPIO_Port , H2_Pin ,RESET ) ;
	    break;
	  case 3:
		  HAL_GPIO_WritePin ( H3_GPIO_Port , H3_Pin ,RESET ) ;
	    break;
	  case 4:
		  HAL_GPIO_WritePin ( H4_GPIO_Port , H4_Pin ,RESET ) ;
	    break;
	  case 5:
		  HAL_GPIO_WritePin ( H5_GPIO_Port , H5_Pin ,RESET ) ;
	    break;
	  case 6:
		  HAL_GPIO_WritePin ( H6_GPIO_Port , H6_Pin ,RESET ) ;
	    break;
	  case 7:
		  HAL_GPIO_WritePin ( H7_GPIO_Port , H7_Pin ,RESET ) ;
	    break;
	  case 8:
		  HAL_GPIO_WritePin ( H8_GPIO_Port , H8_Pin ,RESET ) ;
	    break;
	  case 9:
		  HAL_GPIO_WritePin ( H9_GPIO_Port , H9_Pin ,RESET ) ;
	    break;
	  case 10:
		  HAL_GPIO_WritePin ( H10_GPIO_Port , H10_Pin ,RESET ) ;
	    break;
	  case 11:
		  HAL_GPIO_WritePin ( H11_GPIO_Port , H11_Pin ,RESET ) ;
	    break;
	  case 12:
		  HAL_GPIO_WritePin ( H0_GPIO_Port , H0_Pin ,RESET ) ;
	    break;
	  default:
	    break;
	}
};

void clearNumberOnClock(int num){
	switch(num) {
	  case 0:
		  HAL_GPIO_WritePin ( H0_GPIO_Port , H0_Pin ,SET ) ;
		break;
	  case 1:
		  HAL_GPIO_WritePin ( H1_GPIO_Port , H1_Pin ,SET ) ;
	    break;
	  case 2:
		  HAL_GPIO_WritePin ( H2_GPIO_Port , H2_Pin ,SET ) ;
	    break;
	  case 3:
		  HAL_GPIO_WritePin ( H3_GPIO_Port , H3_Pin ,SET ) ;
	    break;
	  case 4:
		  HAL_GPIO_WritePin ( H4_GPIO_Port , H4_Pin ,SET ) ;
	    break;
	  case 5:
		  HAL_GPIO_WritePin ( H5_GPIO_Port , H5_Pin ,SET ) ;
	    break;
	  case 6:
		  HAL_GPIO_WritePin ( H6_GPIO_Port , H6_Pin ,SET ) ;
	    break;
	  case 7:
		  HAL_GPIO_WritePin ( H7_GPIO_Port , H7_Pin ,SET ) ;
	    break;
	  case 8:
		  HAL_GPIO_WritePin ( H8_GPIO_Port , H8_Pin ,SET ) ;
	    break;
	  case 9:
		  HAL_GPIO_WritePin ( H9_GPIO_Port , H9_Pin ,SET ) ;
	    break;
	  case 10:
		  HAL_GPIO_WritePin ( H10_GPIO_Port , H10_Pin ,SET ) ;
	    break;
	  case 11:
		  HAL_GPIO_WritePin ( H11_GPIO_Port , H11_Pin ,SET ) ;
	    break;
	  case 12:
		  HAL_GPIO_WritePin ( H0_GPIO_Port , H0_Pin ,SET ) ;
	    break;
	  default:
	    break;
	}
};
