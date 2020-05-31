/**
   
   timer_example.ino

-----------------------------------------------------

   Copyright 2018 Emanuele Giacomini
   
   Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at
   
       http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an 
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and limitations under the License.
**/

#include "phoenix_timer.h"

struct Timer* test1;

void setup() {
  cli();
  Serial.begin(9600);
  Serial.println("Serial initialized...");

  struct Timer* idle_test=Timer_create(100, &testTimerFn, 0);
  Timer_start(idle_test);
  Timer_init();
  Serial.println("Timer initialized...");  
  sei();
}

volatile unsigned long idle_time=0;

void testTimerFn() {
  Serial.println(idle_time);
  idle_time=0;
}

void loop() {
  idle_time++;
}
