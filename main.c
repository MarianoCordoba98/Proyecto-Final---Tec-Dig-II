#include "project.h" //Inclusión de librerias
#include "stdio.h"

//Declaración de Función Datos
void datos();

//Variables Globales
int32 entero, voltaje;
int gas, temp;
int x = 600;
char outgas[10], blue[10];
char8 dato;
uint8 pinStateMax, pinStateMin;

//Definición de la Función Interrupción
CY_ISR(interruptRx){
    dato= UART_GetChar();
    datos();//Llamamos a la función para procesar el comando recibido
}

//Función Inicio de Pantalla
void inicio() {
    char v[] = {"INICIANDO . . ."}; //Vector para guardar la palabra
    int i, f=0, c=0;
    
       LCD_I2C_clear();             //Limpiamos los datos del modulo LCD
       for(i=0; i<15; i++){
        LCD_I2C_setCursor(c,f);
        LCD_I2C_write(v[i]);        //Comienza a escribir
        c++;                        //Incrementa el nro de columna
        CyDelay(300);               
    }
      CyDelay(2000);
      LCD_I2C_clear();
      LCD_I2C_setCursor(4,0);
      LCD_I2C_print("UTN - FRT");
      LCD_I2C_setCursor(2,1);
      LCD_I2C_print("TEC. DIG. II");
    
      CyDelay(2000);
      LCD_I2C_noDisplay();           //Apaga la pantalla LCD
      CyDelay(1000);           
      LCD_I2C_display();             //Enciende la pantalla LCD
      CyDelay(1000);
    
      LCD_I2C_clear();
      LCD_I2C_setCursor(0,0);
      LCD_I2C_print("VERA");
      LCD_I2C_setCursor(6,0);
      LCD_I2C_print("- CORDOBA");
      LCD_I2C_setCursor(4,1);
      LCD_I2C_print("TARTALO");
      CyDelay(2000);
      LCD_I2C_clear();
      CyDelay(1000);
}
  
//Función Datos para recibir datos por Bluetooth
void datos(){ 
    if(dato=='0'){             //Encender Cooler por Bluetooth
        LCD_I2C_clear();
        LCD_I2C_print("VENTILACION ON");
        Cooler_Write(1);
        CyDelay(3000);
        Cooler_Write(0);
    } else if(dato=='1'){      //Apagar Cooler por Bluetooth
        LCD_I2C_clear();
        LCD_I2C_print("VENTILACION OFF");
        Cooler_Write(0);
        CyDelay(3000);
        Cooler_Write(0);
    } else if(dato=='2'){      //Encender Bomba de Agua por Bluetooth
        LCD_I2C_clear();
        LCD_I2C_print("BOMBA ON");
        Bomba_Write(1);
        CyDelay(3000);
        Bomba_Write(1);
    } else if(dato=='3'){      //Apagar Bomba de Agua por Bluetooth
        LCD_I2C_clear();
        LCD_I2C_print("BOMBA OFF");
        Bomba_Write(0);
        CyDelay(3000);
        Bomba_Write(1);
    } else if(dato=='4'){      //Cerrar Válvula por Bluetooth
        LCD_I2C_clear();
        LCD_I2C_print("VALVULA OFF");
        for(x=600; x<=2700; x+=100){
            PWM_WriteCompare(x);
            x++;
            CyDelay(100);
        }
        PWM_WriteCompare(0); //Paramos el servo
        
    } else if(dato=='5'){      //Abrir Válvula por Bluetooth
        LCD_I2C_clear();
        LCD_I2C_print("VALVULA ON");
        for(x=2700; x>=600; x-=100){
            PWM_WriteCompare(x);
            x--;
            CyDelay(100);
        }
        PWM_WriteCompare(0); //Paramos el servo
    
    } else if(dato=='6'){       //Imprimir información en Pantalla por Bluetoth
        CyDelay(2000);
        LCD_I2C_clear();
        LCD_I2C_setCursor(4,0);
        LCD_I2C_print("UTN - FRT");
        LCD_I2C_setCursor(2,1);
        LCD_I2C_print("TEC. DIG. II");
        CyDelay(2000);
        LCD_I2C_noDisplay();
        CyDelay(1000);
        LCD_I2C_display();
        CyDelay(1000);
        
        LCD_I2C_clear();
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("VERA");
        LCD_I2C_setCursor(6,0);
        LCD_I2C_print("- CORDOBA");
        LCD_I2C_setCursor(4,1);
        LCD_I2C_print("TARTALO");
        CyDelay(2000);
        LCD_I2C_clear();
        CyDelay(1000);
    }
    dato=0; //Reseteamos el comando despues del procesamiento
}
 
//Función para Imprimir los valores de Gas en pantalla LCD
 void print(){
    LCD_I2C_setCursor(0,0);
    LCD_I2C_print("VALORES DE GAS");
    LCD_I2C_setCursor(0,1);
    sprintf(outgas,"ppm: %d ",gas);
    LCD_I2C_print(outgas);
    sprintf(blue, "/nppm: %d ",gas);
    CyDelay(2000);
}

//Función para la ventilación 
 void vent(){
    if(gas>=1000){
        //Cerrar la Válvula y activar la ventilación
        Buzzer_Write(1);
        CyDelay(1000);
        Buzzer_Write(0);
        LCD_I2C_clear();
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("FUGA DE GAS");
        LCD_I2C_setCursor(0,1);
        LCD_I2C_print("VALVULA OFF");
        CyDelay(1000);
        
        //Mover el servo para cerrar la Válvula 
        for(x=600; x<=2700; x+=100){
            PWM_WriteCompare(x);
            x++;
            CyDelay(100);
        } 
        PWM_WriteCompare(0); //Stop para parar el servo
        
        LCD_I2C_clear();
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("VENTILACION ON");
        CyDelay(500);
        Cooler_Write(1);
        CyDelay(4000);
        LCD_I2C_clear(); 
    }    
    
    if(gas < 1000){
        //Detenemos la ventilación
        LCD_I2C_clear();
        Cooler_Write(0);
        CyDelay(500);
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("VALORES");
    }
}

//Función para Control de la Bomba de Agua
void bomb(){
    if(pinStateMax ==  1 && pinStateMin == 1){
        CyDelay(1000);
        Buzzer_Write(0);
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("TANQUE LLENO");
        LCD_I2C_setCursor(0,1);
        LCD_I2C_print("BOMBA OFF");
        Bomba_Write(0);
        CyDelay(4000);
        LCD_I2C_clear();
    }
        if(pinStateMin == 1){
        Buzzer_Write(1);
        CyDelay(1000);
        Buzzer_Write(0);
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("TANQUE ENCIMA");
        LCD_I2C_setCursor(5,1);
        LCD_I2C_print("DE 70%");
        CyDelay(4000);
        LCD_I2C_clear();
    }
    if(pinStateMin ==  0){
        Buzzer_Write(0);
        CyDelay(1000);
        LCD_I2C_clear();
        LCD_I2C_setCursor(0,0);
        LCD_I2C_print("TANQUE DEBAJO DE");
        LCD_I2C_setCursor(0,1);
        LCD_I2C_print("70% - BOMBA ON");
        Bomba_Write(1);
        CyDelay(4000);
        LCD_I2C_clear();
    }
}

//Iniciar todos los Componentes
int main(){
        CyGlobalIntEnable;
        I2C_Start();
        LCD_I2C_start();
        UART_Start();
        RXint_StartEx(interruptRx);
        Opamp_Start();
        ADC_Start();
        PWM_Start();
        Clock_Start();
        
        inicio();       //Ejecuto la función de Inicio
        
        for(;;){
            datos();
            ADC_StartConvert();
            ADC_IsEndConversion(ADC_WAIT_FOR_RESULT); //Convertir los valores analógicos del sensor a digitales
            entero = ADC_GetResult32();
            ADC_StopConvert();
            
            voltaje = ADC_CountsTo_mVolts(entero);
            gas = (voltaje -500);
            pinStateMax = NivelMax_Read();
            pinStateMin = NivelMin_Read();
            
            
            vent();
            bomb();
            print();
            
            
        }
    }