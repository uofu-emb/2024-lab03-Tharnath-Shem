#include <stdio.h>
#include <FreeRTOS.h>
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include <unity.h>
#include "signaling.h"



void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data){

                                return;
                               }

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data){
                                        xSemaphoreTake(request, portMAX_DELAY);
                                        data->output = data->input + 5;
                                        xSemaphoreGive(request);
                                        return ;
                                    }