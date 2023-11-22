#include "UART.h"


// UART Ports:
// ===================================================  
// PA2 = USART1_TX (AF7)  |  PA3 = USART1_RX (AF7) 


void UART2_Init(void) {
	// Enable the clock of USART 1 & 2
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;  // Enable USART 2 clock		
	
	
	UART2_GPIO_Init();
	USART_Init(USART2);
	
	//NVIC_SetPriority(USART2_IRQn, 0);			// Set Priority to 1
	//NVIC_EnableIRQ(USART2_IRQn);					// Enable interrupt of USART1 peripheral
}

void UART2_GPIO_Init(void) {
	
	// Enable the peripheral clock of GPIO Port
		RCC -> AHB1ENR |= GPIOAEN;
	
	// ********************** USART 2 ***************************
	// PA2 = USART2_TX (AF7)
	// PA3 = USART2_RX (AF7)
	// Alternate function, High Speed, Push pull, Pull up
	// **********************************************************
	// Input(00), Output(01), AlterFunc(10), Analog(11)
	//Set PA2, PA3 mode to alternate function
	GPIOA->MODER 	 |= (2<<4);   // Bits (5:4)= 1:0 --> Alternate Function for Pin PA2
	GPIOA->MODER 	 |= (2<<6);   // Bits (7:6)= 1:0 --> Alternate Function for Pin PA3
	
	//Set PA2 alternate function type to UART_TX (AF07)
	GPIOA -> AFR[0] |= (7U<<8);
	
	//Set PA3 alternate function type to UART_RX (AF07)
	GPIOA -> AFR[0] |= (7U<<12);
	
	// GPIO Speed: Low speed (00), Medium speed (01), Fast speed (10), High speed (11)
	GPIOA->OSPEEDR |=   0xF<<4||(3<<6); 					 	
	
	// GPIO Push-Pull: No pull-up, pull-down (00), Pull-up (01), Pull-down (10), Reserved (11)
	GPIOA->PUPDR   &= ~(0xF<<4);
	GPIOA->PUPDR   |=   0x5<<4;    				
	
	// GPIO Output Type: Output push-pull (0, reset), Output open drain (1) 
	GPIOA->OTYPER  &=  ~(0x3<<2) ;       	
}


void USART_Init (USART_TypeDef * USARTx) {
	// Default setting: 
	//     No hardware flow control, 8 data bits, no parity, 1 start bit and 1 stop bit		
	USARTx->CR1 &= ~USART_CR1_UE;  // Disable USART
	
	// Configure word length to 8 bit
	USARTx->CR1 &= ~USART_CR1_M;   // M: 00 = 8 data bits, 01 = 9 data bits, 10 = 7 data bits
	
	// Configure oversampling mode: Oversampling by 16 
	USARTx->CR1 &= ~USART_CR1_OVER8;  // 0 = oversampling by 16, 1 = oversampling by 8
	
	// Configure stop bits to 1 stop bit
	//   00: 1 Stop bit;      01: 0.5 Stop bit
	//   10: 2 Stop bits;     11: 1.5 Stop bit
	USARTx->CR2 &= ~USART_CR2_STOP;   
	
	//Disable parity control enable
	USARTx -> CR1 &= ~USART_CR1_PCE;
                                    
	// CSet Baudrate to 9600 using APB frequency (16,000,000 Hz)
	// If oversampling by 16, Tx/Rx baud = f_CK / USARTDIV,  
	// If oversampling by 8,  Tx/Rx baud = 2*f_CK / USARTDIV
  // When OVER8 = 0, BRR = USARTDIV
	// USARTDIV = 16MHz/9600 = 104
	USARTx -> BRR = 0<<0| 104<<4;//16000000/(16*9600) = 104, Mantisa = 104, Fraction = 0 

	USARTx->CR1  |= (USART_CR1_RE | USART_CR1_TE);  	// Transmitter and Receiver enable
	
	USARTx->CR1  |= USART_CR1_UE; // USART enable                 
	
}


uint8_t USART_Read (USART_TypeDef * USARTx) {
	// SR_RXNE (Read data register not empty) bit is set by hardware
	while (!(USARTx->SR & USART_SR_RXNE));  // Wait until RXNE (RX not empty) bit is set
	// USART resets the RXNE flag automatically after reading DR
	return ((uint8_t)(USARTx->DR & 0xFF));
	// Reading USART_DR automatically clears the RXNE flag 
		
}

void USART_Write(USART_TypeDef * USARTx, uint8_t *buffer, uint32_t nBytes) {
	//C2
	/* 	1.Write the data to send in the USART_DR register (this clears the TXE bit). Repeat this
		for each data to be transmitted in case of single buffer.
			2. After writing the last data into the USART_DR register, wait until TC=1. This indicates
					that the transmission of the last frame is complete. This is required for instance when
					the USART is disabled or enters the Halt mode to avoid corrupting the last
						transmission.
	*/
	int i;
	// TXE is cleared by a write to the USART_DR register.
	// TXE is set by hardware when the content of the TDR 
	// register has been transferred into the shift register.
	for (i = 0; i < nBytes; i++) {
		while (!(USARTx->SR & USART_SR_TXE));   	// wait until TXE (TX empty) bit is set
		// Writing USART_DR automatically clears the TXE flag 	
		USARTx->DR = buffer[i] & 0xFF;

	}
	while (!(USARTx->SR & USART_SR_TC));   		  // wait until TC bit is set
	USARTx->SR &= ~USART_SR_TC;
}   
 





