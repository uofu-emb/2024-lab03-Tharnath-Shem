#include <stdio.h>
#include <FreeRTOS.h>
#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>
#include <unity.h>
#include "signaling.h"



void signal_handle_calculation(SemaphoreHandle_t request,
                               SemaphoreHandle_t response,
                               struct signal_data *data){
                                printf("Waiting for Semaphore\n");
                                xSemaphoreTake(request, portMAX_DELAY);
                                printf("Handling Semaphores\n");
                                data->output = data->input+5; //in Signals.h data has ip&op
                                vTaskDelay(10);
                                printf("Sending Result\n");
                                xSemaphoreGive(response);

                                return;
                               }

BaseType_t signal_request_calculate(SemaphoreHandle_t request,
                                    SemaphoreHandle_t response,
                                    struct signal_data *data){
                                       // xSemaphoreTake(request, portMAX_DELAY);
                                        printf("Giving Semaphore\n");
                                        xSemaphoreGive(request);
                                        BaseType_t res = xSemaphoreTake(response,portMAX_DELAY);
                                        printf("- Result ready\n");
                                        return res;
                                    }